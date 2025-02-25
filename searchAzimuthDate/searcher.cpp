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

	double azimuth, altitude;
	astroC->raDec2000ToAzAlt(DEG2RAD*ra2000, DEG2RAD*de2000, DEG2RAD*locLon, DEG2RAD*locLat, runTimeUTCMjd, azimuth, altitude);

	azimuth *= RAD2DEG;
	altitude *= RAD2DEG;
	azimuth += 180.;
	if (azimuth > 360.0)
	{
		azimuth -= 360.;
	}

	String^ strReturn = gcnew String("");

	strReturn = String::Format("Azimuth: {0}   Altitude: {1}\r\n", azimuth, altitude);

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
