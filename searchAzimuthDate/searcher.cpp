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

String^ Searcher::runSearch(String^location,String^ startTimeStamp, String^ objCoord, double sAzi, double aziR)
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

	double azimuth, altitude;

	int i;
	double r1U = sAzi - aziR;
	double r1O = sAzi;
	double r2U = sAzi;
	double r2O = sAzi + aziR;
	if (r1U < 0.0)
	{
		r1U += 360;
		r1O = 360;
	}
	if (r2O > 360.)
	{
		r2U = 0;
		r2O -= 360.;
	}
	for (i = 0; i < 366; ++i)
	{
		astroC->raDec2000ToAzAlt(DEG2RAD * ra2000, DEG2RAD * de2000, DEG2RAD * locLon, DEG2RAD * locLat, runTimeUTCMjd, azimuth, altitude);
		azimuth = azimuth * RAD2DEG + 180.;
		altitude = altitude * RAD2DEG;
		if (azimuth > 360.0)
		{
			azimuth -= 360.;
		}
		if ((r1U <= azimuth && azimuth < r1O) || (r2U <= azimuth && azimuth < r2O))
		{
			break;
		}
		runTimeUTCMjd += 1.0;
	}
	int jj, mm, dd, hh, mi;
	double ss;

	astroC->convertMjdToDatum(runTimeUTCMjd, jj, mm, dd, hh, mi, ss);

	String^ strReturn = gcnew String("");
	int iss = (int)(timeTest.second_+0.5);
	if (iss > 59)
		iss = 0;

	double huk = locLat + de2000 - 90;
	double dec = 2. * locLat - huk;
	if (dec < 90)
	{
		strReturn += String::Format("Object: {0} runs not to south culmination at {1,8:F1}\r\n", objCoord, dec);
	}

	if (i < 366)
	{
		strReturn += String::Format("Object: {0}\nAzimuth: {1,8:F1}   Altitude: {2,8:F1}  DateTime: {3,4:0000}-{4,2:00}-{5,2:00} {6,2:00}:{7,2:00}:{8,2:00}\r\n\r\n",
			objCoord, azimuth, altitude, jj, mm, dd, timeTest.hour_, timeTest.minute_, iss);
	}
	else
	{
		strReturn += String::Format("For Object: {0} no azimuth {1,8:F1} found\r\n\r\n", objCoord, sAzi);
	}


	return strReturn;
}

String^ Searcher::runTrack(String^ location, String^ startTimeStamp, String^ objCoord, double sAzi)
{
	char timeStampS[32];
	char objCoordS[32];
	string2char(startTimeStamp, timeStampS, sizeof(timeStampS));
	string2char(objCoord, objCoordS, sizeof(objCoordS));

	TimeOwn timeTest;

	astroC->timeOwnInit(timeStampS, timeTest);
	timeTest.hour_ = 0;
	timeTest.minute_ = 0;
	timeTest.second_ = 0;
	astroC->CalcMjd(timeTest);
	runTimeUTCMjd = timeTest.timeMjd_;

	double ra2000, de2000;
	astroC->direction2AzAlt(objCoordS, ra2000, de2000, true);

	double locLon;
	double locLat;
	convertLocation(location, locLon, locLat);


	String^ strReturn = gcnew String("");
	strReturn += String::Format("Object: {0} \r\n", objCoord);

	int hh = 0;
	int mm = 0;
	for (int i = 0; i < 48; ++i)
	{
		double azimuth, altitude;
		astroC->raDec2000ToAzAlt(DEG2RAD * ra2000, DEG2RAD * de2000, DEG2RAD * locLon, DEG2RAD * locLat, runTimeUTCMjd, azimuth, altitude);
		azimuth = azimuth * RAD2DEG + 180.;
		altitude = altitude * RAD2DEG;
		if (azimuth > 360.0)
		{
			azimuth -= 360.;
		}
		strReturn += String::Format("{0,4:0000}-{1,2:00}-{2,2:00} ; {3,2:00}:{4,2:00}:{5,2:00} ; {6,10:F1} ; {7,10:F1}\r\n",
			timeTest.year_, timeTest.month_, timeTest.day_, hh, mm, 0, azimuth, altitude);
		runTimeUTCMjd += 1. / 48.;
		if (mm == 0)
		{
			mm = 30;
		}
		else
		{
			mm = 0;
			++hh;
		}
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
