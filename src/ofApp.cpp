#include "ofApp.h"
#include <iostream>
#include <vector>
using namespace std;

//initalize vector of x and y locations to draw grid lines
std::vector<float> gridx;
std::vector<float> gridy;

//--------------------------------------------------------------
void ofApp::setup(){
	//set the window size variables and make the window
	windowx = 800.0f;
	windowy = 800.0f;
	//set the cell size
	ell = 200.0f;
	//calculate how many cells I have across x and y
	celli_x = ceil(windowx / ell);
	celli_y = ceil(windowy / ell);
	//when there are incomplete cells I need to make sure to expand the window apropriatley
	windowx = celli_x * ell;
	windowy = celli_y * ell;
	//now the window expands to fit incomplete cells even if theres not enought room
	//add a little bit of padding to see right most grid lines
	ofSetWindowShape(windowx + 10, windowy + 10);
	//print function to see how many cells are where
	std::printf("number of x cells: %i\n",celli_x);
	std::printf("number of y cells: %i\n", celli_y);
	//setup the squiggle, this populates the points for now
	ofVec3f cent(windowx / 2, windowy / 2, 0.0);
	S.setup(200,200.0f,cent);
}

//--------------------------------------------------------------
void ofApp::update(){
	//calculate grid drawing values
	calcGrid();
	//update the squiggle
	S.update();
}

//--------------------------------------------------------------
void ofApp::draw(){
	//draw the grid
	drawGrid();
	//draw the squiggle
	S.draw();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}

//custom method to draw grid lines based on contents of gridx and gridy
void ofApp::drawGrid() {
	//loop over gridx and gridy to actualy draw the grid lines
	for (int i = 0; i < gridx.size(); i++)
	{
		//these are verticle lines
		ofDrawLine(gridx[i], 0, gridx[i], windowy);
	}
	for (int i = 0; i < gridy.size(); i++)
	{
		//these are horizontal lines
		ofDrawLine(0, gridy[i], windowx, gridy[i]);
	}
	//since the above only realy draws the left most grid lines i need to also draw one extra, this is going simply with gridx[-1]+ell and gridy[-1]+ell
	ofDrawLine(gridx.back() + ell, 0.0f, gridx.back() + ell, windowy);
	ofDrawLine(0, gridy.back() + ell, windowx, gridy.back() + ell);
}

void ofApp::calcGrid() {
	//use the cell size and number of cells along x and y to calcuate the xs and ys of the cell
	for (int i = 0; i < celli_x; i++) {
		//here i need to add multiples of ell as x coordinates for verticle grid lines
		gridx.push_back(ell*i);
	}

	for (int i = 0; i < celli_y; i++)
	{
		//here i need to add multiples of ell as y coordinates for the horizontal grid lines
		gridy.push_back(ell*i);
	}
	//now gridx and gridy each have the left side coordinate of a cell
}