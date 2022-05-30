#include "MultiSquig.h"

//constructor definition
MultiSquig::MultiSquig() {
}
	
//setup function needs a set of points to know where to draw the squiggles, the base radius of the squiggles, and points per squiggle
void MultiSquig::setup() {

}

void MultiSquig::AddSquiggles(float d, float rad, float random, float diff,float x, float y) {
	//make a squiggle object
	Squiggle S;
	//setup the squiggle
	S.setup(d, rad, random, diff,x,y);
	//add the squiggle to the squiggles vector
	Squigs.push_back(S);
}

//add squiggles function taking in multiple points
void MultiSquig::AddSquiggles(float d, float rad, float random, float diff, ofPolyline points) {
	//broadcast AddSquiggles over points
	for (int i = 0; i < points.size(); i++)
	{
		float x = points[i].x;
		float y = points[i].y;
		AddSquiggles(d, rad, random, diff, x, y);
	}
}

//add squiggles function using multiple points and radii
void MultiSquig::AddSquiggles(float d, vector<float> rad,float baserad, float random, float diff, ofPolyline points) {
	//broadcast AddSquiggles over points
	for (int i = 0; i < points.size(); i++)
	{
		float r = rad[i];
		float x = points[i].x;
		float y = points[i].y;
		AddSquiggles(d, r*baserad, random, diff, x, y);
	}
}



//function to delete squiggles that find themselves around an input point
void MultiSquig::DeleteSquiggles(float x, float y)
{
	//make a vector that contains indices of elements that need to be removed
	vector<int> removelist;
	//loop over the squiggles and and identify the ones near x,y that need to be removed
	for (int i = 0; i < Squigs.size(); i++)
	{
		//get the distance between the Squiggles center and the deleteion point
		float dr = (ofVec3f(x, y, 0.0f) - Squigs[i].cent).length();
		if (dr < Squigs[i].rad_orig) {
			removelist.push_back(i);
		}
	}
	//now removelist has a list of indices of Squigs that I want to remove
	std::sort(removelist.begin(), removelist.end());  // Make sure the container is sorted
	for (auto &i = removelist.rbegin(); i != removelist.rend(); ++i)
	{
		Squigs.erase(Squigs.begin() + *i);
	}
}

void MultiSquig::DeleteSquiggles(ofPolyline points) {
	//broadcast delete squiggles across points
	for (int i = 0; i < points.size(); i++)
	{
		float x = points[i].x;
		float y = points[i].y;
		DeleteSquiggles(x, y);
	}
}

void MultiSquig::update() {
	//loop through the squiggles vector and update each squiggle individualy
	for (int i = 0; i < Squigs.size(); i++)
	{
		Squigs[i].update();
	}
}

void MultiSquig::draw() {
	//loop through the squiggles vector and draw each squiggle individualy
	for (int i = 0; i < Squigs.size(); i++)
	{
		Squigs[i].draw();
	}
}