#include "Squiggle.h"

//define constructor
Squiggle::Squiggle() {

}

//define a setup function
void Squiggle::setup( int d = 100, float rad = 100.0f, ofVec2f cent_ = ofVec3f(50.,50.,0.0)) {
	//I need to populate points
	//initaly points are populated based on a discretized circle
	//get d angles that span (0,2pi)
	float dtheta = TWO_PI / d;
	float theta_i = 0.0f;
	while (theta_i < TWO_PI) {
		//i dont actualy want to store <x,y> points i want to store <r,\theta> points
		ofVec2f vi(rad,theta_i);
		//ill convert these back into <x,y>'s before using them in drawing
		Points.push_back(vi);
		theta_i += dtheta;
	}
	//now Points is populated with ofVec2's having <r,\theta>
	//make sure to set the cent variable
	cent = cent_;
	//setup the seed
	//srand(100);

}

//deinfe the update function
void Squiggle::update() {
	//to start clear the points
	perim.clear();
	//add the points to the polyline object
	for (int i = 0; i < Points.size(); i++)
	{
		//get this point and 4 points next to it
		ofVec2f vi = Points[i];
		ofVec2f v_m1 = Points[(i-1)% Points.size()];
		ofVec2f v_m2 = Points[(i - 2) % Points.size()];
		ofVec2f v_p1 = Points[(i + 1) % Points.size()];
		ofVec2f v_p2 = Points[(i + 2) % Points.size()];
		//get average r as the average of the 4 points next to this point
		float r_mu = (v_m1.x+v_m2.x+v_p1.x+v_p2.x)/4;
		//here is kind of a pseudo ornstein-uhrbek process
		Points[i].x += ((r_mu - vi.x)*1.5) + (1.0*NextGaussian());
		//now add to the perim in <x,y> form and offset by the cent
		perim.addVertex(ofVec3f(Points[i].x*cos(Points[i].y), Points[i].x*sin(Points[i].y),0.0f)+cent);
	}

	//close the polyline
	perim.close();
}

//define the draw function
void Squiggle::draw() {
	//draw the polyline
	perim.draw();
}


float Squiggle::NextGaussian()
{
	std::random_device rd;
	std::mt19937 mt(rd());
	std::normal_distribution<float> distribution(0.0f, 1.0f);
	return distribution(mt);
}

