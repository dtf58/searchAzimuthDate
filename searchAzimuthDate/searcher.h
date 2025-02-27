#include <array>
#include "AstroCalc.h"
using namespace std;
#using <System.dll>

using namespace System;

#pragma once
ref class Searcher
{
public:
	explicit Searcher();
	~Searcher();
	void string2char(String^ strIn, char* buffer, int len);
	String^ runSearch(String^ location, String^ startTimeStamp, String^ objCoord, double sAzi, double aziR);
	String^ runTrack(String^ location, String^ startTimeStamp, String^ objCoord, double sAzi);
	void convertLocation(String^ locTotal, double& lon, double& lat);

	double runTimeUTCMjd;
	AstroCalc* astroC;
};
