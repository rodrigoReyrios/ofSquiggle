#pragma once
//include the open framewokrs main functions
#include "ofMain.h"
#include <random>
class Squiggle
{
public:
	//constrructor
	Squiggle();
	//squiggle class should have its points
	vector<ofVec3f> Points;
	//squiggle should have a polyline
	ofPolyline poly;
	//constants that scale the term before mu-r and the variance of the gaussain
	float D, sig;
	//squiggle keeps its origian lradius
	float rad_orig;
	//vector of the suiggle center
	ofVec3f cent;
	//and basic stup, update, draw functions
	void setup(float, float, float, float, float, float);
	void update();
	void draw();
	//draw a number from a guassian
	float NextGaussian();
};

