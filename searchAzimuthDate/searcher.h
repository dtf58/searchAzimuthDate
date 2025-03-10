#include <iostream>
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
	String^ runTrack10s(String^ location, String^ startTimeStamp, String^ objCoord, double sAzi);
	void convertLocation(String^ locTotal, double& lon, double& lat);
	String^ outSplitAngleHour(double angleHour, double factor, bool degFlag);
	double runTimeUTCMjd;
	void splitAngle(double angle, int& grd, int& min, int& sec);
	AstroCalc* astroC;
};
