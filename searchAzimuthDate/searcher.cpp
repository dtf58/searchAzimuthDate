#include "pch.h"
#include "searcher.h"
#include <ctime>

Searcher::Searcher()
{
	astroC = new AstroCalc();
}

Searcher::~Searcher()
{
	delete astroC;
}

void Searcher::string2char(String^ strIn, char* buffer, int len)
{
	int length = strIn->Length;
	if (length > len - 1)
	{
		length = len - 1;
	}
	int i = 0;
	for (i = 0; i < length; ++i)
	{
		buffer[i] = (char)strIn[i];
	}
	buffer[i] = 0;
}

String^ Searcher::runSearch(String^location,String^ startTimeStamp, String^ objCoord, double sAzi)
{
	char timeStampS[32];
	char objCoordS[32];
	string2char(startTimeStamp, timeStampS, sizeof(timeStampS));
	string2char(objCoord, objCoordS, sizeof(objCoordS));

	TimeOwn timeTest;

	astroC->timeOwnInit(timeStampS, timeTest);

	runTimeUTCMjd = timeTest.timeMjd_;

	double ra2000, de2000;
	astroC->direction2AzAlt(objCoordS, ra2000, de2000, true);

	double locLon;
	double locLat;
	convertLocation(location, locLon, locLat);

	double azimuthPrev, altitudePrev;
	double azimuth, altitude;
	astroC->raDec2000ToAzAlt(DEG2RAD*ra2000, DEG2RAD*de2000, DEG2RAD*locLon, DEG2RAD*locLat, runTimeUTCMjd, azimuth, altitude);
	azimuthPrev = azimuth*RAD2DEG + 180.;
	altitudePrev = altitude*RAD2DEG;
	if (azimuthPrev > 360.0)
	{
		azimuthPrev -= 360.;
	}
	double runTimeUTCMjdPrev = runTimeUTCMjd;
	int i;
	for (i = 0; i < 366; ++i)
	{
		runTimeUTCMjd += 1.0;
		astroC->raDec2000ToAzAlt(DEG2RAD * ra2000, DEG2RAD * de2000, DEG2RAD * locLon, DEG2RAD * locLat, runTimeUTCMjd, azimuth, altitude);
		azimuth = azimuth * RAD2DEG + 180.;
		altitude = altitude * RAD2DEG;
		if (azimuth > 360.0)
		{
			azimuth -= 360.;
		}
		if (azimuthPrev <= sAzi && azimuth > sAzi)
		{
			break;
		}
		azimuthPrev = azimuth;
		altitudePrev = altitude;
		runTimeUTCMjdPrev = runTimeUTCMjd;
	}
	int jj, mm, dd, hh, mi;
	double ss;

	astroC->convertMjdToDatum(runTimeUTCMjdPrev, jj, mm, dd, hh, mi, ss);

	String^ strReturn = gcnew String("");
	int iss = timeTest.second_+0.5;
	if (iss > 59)
		iss = 0;

	if (i < 366)
	{
		strReturn = String::Format("Object: {0}\nAzimuth: {1,8:F1}   Altitude: {2,8:F1}  DateTime: {3,4:0000}-{4,2:00}-{5,2:00} {6,2:00}:{7,2:00}:{8,2:00}\r\n\r\n",
			objCoord, azimuthPrev, altitudePrev, jj, mm, dd, timeTest.hour_, timeTest.minute_, iss);
	}
	else
	{
		strReturn = String::Format("For Object: {0} no azimuth {1,8:F1} found\r\n\r\n", objCoord, sAzi);
	}


	return strReturn;
}

void Searcher::convertLocation(String^ locTotal, double& locLon, double& locLat)
{
	cli::array<wchar_t>^ sep = { ' ',';' };
	cli::array<String^>^ subs = locTotal->Split(sep, StringSplitOptions::RemoveEmptyEntries);

	cli::array<unsigned char>^ sb = gcnew cli::array<unsigned char>(32);

	double lat = Convert::ToDouble(subs[2]);

	if (subs[3] == "S")
	{
		locLat = -lat;
	}
	else
	{
		locLat = lat;
	}

	double lon = Convert::ToDouble(subs[0]);

	if (subs[0] == "W")
	{
		locLon = -lon;
	}
	else
	{
		locLon = lon;
	}
 }
