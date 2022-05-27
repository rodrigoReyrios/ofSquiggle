#include "ofApp.h"
#include <iostream>
#include <vector>

//initalize a temporary path which is a vector of points
vector<ofVec3f> temp_path;

//--------------------------------------------------------------
void ofApp::setup(){
	//set background color
	ofSetBackgroundColor(0, 0, 0);
	//set fps
	ofSetFrameRate(35);
	//set the window size variables and make the window
	windowx = 900.0f;
	windowy = 900.0f;
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
}

//make an integer that stores the last size of wholepaths
int lastpaths = 0;

//--------------------------------------------------------------
void ofApp::update(){
	
	//only update polys, when weve detected an additional path in whole paths
	if (wholepaths.size() != lastpaths) {
		//as wholepaths get updated I want to send any currently completed paths polys
		for (int i = lastpaths; i < wholepaths.size(); i++)
		{
			//initalize a polyline
			ofPolyline curve;
			//look over the points contained in this whole paths
			for (int j = 0; j < wholepaths[i].size(); j++)
			{
				curve.addVertex(wholepaths[i][j]);
			}
			//now that the curve is made add it to the polys vector
			polys.push_back(curve);
		}
		//reset size of last paths
		lastpaths = wholepaths.size();
	}

	//update all the Multisquigs objects
	for (int i = 0; i < MS.size(); i++)
	{
		MS[i].update();
	}

}

int imgnum = 0;
//--------------------------------------------------------------
void ofApp::draw(){

	//draw all the Multisquigs objects
	for (int i = 0; i < MS.size(); i++)
	{
		MS[i].draw();
	}

	string filename;
	filename = "screen/screen" + ofToString(imgnum) + ".png";
	ofSaveScreen(filename);
	imgnum++;

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
	//when a mouse is pressed make a point and add it to the temporary path
	ofVec3f p(x, y,0);
	temp_path.push_back(p);
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
	//once the mouse is released I want to send the temp path to the allPaths vector
	wholepaths.push_back(temp_path);
	//I also want to construct a Multisquig and then send it to MS vector
	MultiSquig ms;
	//make sure to setup with the remade path
	ms.setup( reformat(temp_path,15) , 100.0f, 150);
	MS.push_back(ms);
	//and reset the temp_path
	temp_path.clear();

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

//function to reformat a path that is to sporadic
vector<ofVec3f> ofApp::reformat(vector<ofVec3f> oldpath, float ellprime) {
	//make a new vector
	vector<ofVec3f> newpath;
	for (int i = 0; i < oldpath.size()-1; i++)
	{
		//get this point and the next point
		ofVec3f pthis = oldpath[i];
		ofVec3f pnext = oldpath[i+1];
		//add the first point to the newpath
		newpath.push_back(pthis);
		//get the vector between these
		ofVec3f dp = pnext - pthis;
		//get the unit of the diffrence
		ofVec3f dpunit = dp.getNormalized();
		//get the length of the diffrence between these two points
		float ell = (dp).length();
		//when the distance between these points is to far
		if (ell > ellprime) {
			//calculate how many cuts there needs to be
			int cutnum = floor((ell / ellprime) - 1);
			for (int j = 0; j < cutnum; j++)
			{
				//add a new point
				newpath.push_back(pthis+( (j+1)*ellprime*dpunit ) );
			}
		}
		else if (ell < ellprime/2) {
			//when the next path is to close just skip
			i += 1;
		}
	}
	//return the new path
	return newpath;
}