#include "Squiggle.h"

//define constructor
Squiggle::Squiggle() {

}

//define a setup function
void Squiggle::setup(float d,float rad,float random, float diff, float x, float y) {
	
	Points.clear();
	
	//squiggle knows the distance between points at setup and radius
	//use thes to calculate the number of vertices squiggle should have
	int vnum = floor((2* PI*rad)/d) ;
	//make sure that vnum is atleast 3 or more
	vnum = max(3, vnum);
	//use the number of vertices to calculate dtheta per point
	float dtheta = 2 * PI / vnum;
	float theta = 0.0f;
	//loop until theta is completed and add points each turn
	while (theta < 2 * PI) {
		//for now points are in polar <r,theta> instead of <x,y>
		Points.push_back( ofVec3f(rad,theta) );
		theta += dtheta;
	}
	//set the D and sig constant
	D = diff;
	sig = random;
	//set the center of the squiggle
	cent = ofVec3f(x, y, 0.0);
	//make squiggel remmeber its original radius
	rad_orig = rad;


	poly.clear();
	//loop over points and readd them to polyline
	for (int i = 0; i < Points.size(); i++)
	{
		//get time since last frame passed

		float dt = ofGetLastFrameTime();
		//get the point efore and after this one
		ofVec3f p_last = Points[(i - 1) % Points.size()];
		ofVec3f p_next = Points[(i + 1) % Points.size()];
		//get average x coordinate of these points
		float mu = (p_last.x + p_next.x) / 2;
		//jiggle point
		Points[i].x += (D*(mu - Points[i].x)*dt) + (sig*NextGaussian());

		//add to polyline, remmber thus far points are in <r,theta> not <x,y>
		ofVec3f p = ofVec3f(Points[i].x*cos(Points[i].y), Points[i].x*sin(Points[i].y), 0.0f);
		//offset by the center
		poly.addVertex(p + cent);
	}
	//close the polyline
	poly.close();
}

//deinfe the update function
void Squiggle::update() {
	//clear the polyline
	poly.clear();
	//loop over points and readd them to polyline
	for (int i = 0; i < Points.size(); i++)
	{
		//get time since last frame passed

		float dt = 1.0f/25.0f ;
		//get the point efore and after this one
		ofVec3f p_last = Points[ (i-1)% Points.size()];
		ofVec3f p_next = Points[ (i+1)% Points.size()];
		//get average x coordinate of these points
		float mu = (p_last.x + p_next.x) / 2;
		//jiggle point
		Points[i].x += (D*(mu - Points[i].x)*dt) + (sig*NextGaussian());

		//add to polyline, remmber thus far points are in <r,theta> not <x,y>
		ofVec3f p = ofVec3f(Points[i].x*cos(Points[i].y), Points[i].x*sin(Points[i].y), 0.0f);
		//offset by the center
		poly.addVertex(p+cent);
	}
	//close the polyline
	poly.close();
}

//define the draw function
void Squiggle::draw() {
	//draw the polyline
	ofSetColor(255, 255, 255, 255.0);
	poly.draw();
}


float Squiggle::NextGaussian()
{
	std::random_device rd;
	std::mt19937 mt(rd());
	std::normal_distribution<float> distribution(0.0f, 1.0f);
	return distribution(mt);
}
