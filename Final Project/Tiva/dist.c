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

