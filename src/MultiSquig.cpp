#include "MultiSquig.h"

//constructor definition
MultiSquig::MultiSquig() {
}

//setup function needs a set of points to know where to draw the squiggles, the base radius of the squiggles, and points per squiggle
void MultiSquig::setup(vector<ofVec3f> locs, float rad, int res) {
	//set the rad multiplier per y location
	float maxx = ofGetScreenWidth();
	float maxy = ofGetScreenHeight();
	float rmin = 0.25;
	float rmax = 1.25;
	// loop over the list of locaruions since these are supossed to be centers of squiggles
	for (int i = 0; i < locs.size(); i++)
	{
		//initalize a squiggle
		Squiggle squig;
		//calculate the radius by mapping the y value on the range (0,ymax) to a multiplier on range (1,r_min)
		float rmult = ofMap(locs[i].y,0,maxy,rmin,rmax);
		//setup the squig
		squig.setup(res, rad*rmult, ofVec2f(locs[i].x, locs[i].y));
		//add the squig to the squig vector
		Squigs.push_back(squig);
	}

}

void MultiSquig::update() {
	//update each squiggle in the squig
	for (int i = 0; i < Squigs.size(); i++)
	{
		Squigs[i].update();
	}
}

void MultiSquig::draw() {
	//update each squiggle in the squig
	for (int i = 0; i < Squigs.size(); i++)
	{
		Squigs[i].draw();
	}
}