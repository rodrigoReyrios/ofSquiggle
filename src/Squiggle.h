#pragma once
//include the open framewokrs main functions
#include "ofMain.h"
#include <random>
class Squiggle
{
public:
	//squiggle class should have its points
	vector<ofVec2f> Points;
	//it should aliso have a polyline object that is going to be updated with Points before drawing
	ofPolyline perim;
	ofVec3f cent;
	ofVec3f cent_orig;
	//squiggle should have a constructor
	Squiggle();
	//were going to treat squiggle objects like openframeworks methods, each should have a setup, update, and draw method
	void setup(int,float,ofVec2f);
	void update();
	void draw();
	//this function is meant to return a normaly draw value
	float NextGaussian();
	void PointsToPerim();
};

