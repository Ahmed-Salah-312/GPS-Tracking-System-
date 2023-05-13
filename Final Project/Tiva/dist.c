#include <math.h>
#define PI 3.14159265358979323846

const double EARTH_RADIUS = 6371000;
/*
float ToDegree (float angle){
int degree = (int)angle / 100;
float minutes = angle - (float)degree*100;
return (degree+ (minutes/60));
} */

float ToRad (double angle) {
	return angle * PI / 180;
}

float GPS_getDistance(float currentLong, float currentLat, float destLong, float destLat) {
float currentLongRad = ToRad(currentLong/100);
float currentLatRad = ToRad(currentLat/100);
float destLongRad = ToRad(destLong/100);
float destLatRad = ToRad(destLat/100);

float longDiff = destLongRad - currentLongRad; 
float latDiff = destLatRad - currentLatRad;

float a = pow(sin(latDiff/2),2)+cos(currentLatRad)*cos(destLatRad)*pow(sin(longDiff/2),2);
double c = 2 * atan2(sqrt(a), sqrt(1 - a));
return EARTH_RADIUS * c;
}	

