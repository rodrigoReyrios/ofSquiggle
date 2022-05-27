#pragma once
#include "ofMain.h"
#include "Squiggle.h"
class MultiSquig
{
public:
	//constructor
	MultiSquig();
	//multi squig is going to need a vector of squiggles
	vector<Squiggle> Squigs;
	//its going to need an initalization, setup and draw function
	void setup(vector<ofVec3f>, float, int);
	void update();
	void draw();
	//vector to store mouse location
	ofVec2f rm;
	//vector to store common squiggle origin
	ofVec2f r0;
};

