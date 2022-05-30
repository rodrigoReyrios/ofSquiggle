#pragma once
#include "ofMain.h"
#include "Squiggle.h"
class MultiSquig
{
public:
	//constructor
	MultiSquig();
	//multi squig is going to need a vector to keep squiggles
	vector<Squiggle> Squigs;
	//its going to need an initalization, setup and draw function
	void setup();
	void update();
	void draw();
	//function to add squiggles to the squiggles vector
	void AddSquiggles(float, float, float, float, float, float);
	void AddSquiggles(float, float, float, float, ofPolyline);
	void AddSquiggles(float, vector<float>,float, float, float, ofPolyline);
	//function to delete all the squiggles along a common point
	void DeleteSquiggles(float , float);
	void DeleteSquiggles(ofPolyline);
};

