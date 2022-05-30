#include "ofApp.h"
#include <iostream>
#include <vector>


//--------------------------------------------------------------
void ofApp::setup(){
	//set fps
	ofSetFrameRate(25);
	//set vsync
	ofSetVerticalSync(true);
	//set the bg
	ofSetBackgroundColor(0.0f, 0.0f, 0.0f);
	//setuo gui
	gui.setup();
	//add elements to the gui
	gui.add(radius_slider.setup("radius", 140, 10, 300));
	gui.add(res.setup("arc dist", 10, 0.1, 100));
	gui.add(var.setup("variance", 2, 0.1, 5.0));
	gui.add(theta.setup("theta", 5, 0.1, 10.0));
	gui.add(spacing.setup("spacing", 25, 1, 100.0));
	gui.add(rfac2.setup("Perspecitve",false));
	gui.add(pause.setup("Pause", true));
	//panel should show
	hidepanel = false;
	//by default mouse is not in deleting mode
	isDeleting = false;
	//set frame num value
	fnum = 0;
	//boolean for frame saving
	recording = false;

	//setup the temp squiggle 
	temp_S.setup(res, radius_slider, var, theta, mouseX, mouseY);
}

float persp(float r) {
	float nw = ofMap(r, 0.0f, ofGetScreenHeight(), 0.3f, 1.0f);
	return nw;
}

//--------------------------------------------------------------
void ofApp::update(){
	if (!pause) {
		//update all the squiggles
		MS.update();
	}

	//save the frames if desired
	if (recording)
	{
		ofSaveScreen("screen/"+std::to_string(fnum) + ".png");
		fnum += 1;
	}

	//remkae the temp path via resample by spacing
	if (temp_path.size() > 1) {
		temp_path = temp_path.getResampledBySpacing(spacing);
	}

	//setup the temp_squiggle with current paramaters
	//the radius needs to be scaled aproproetly if using perspective mode
	if (rfac2) {
		//setup the squiggle with the current paramaters
		temp_S.setup(res, persp(mouseY)*radius_slider , var, theta, mouseX, mouseY );
		//update the squiggle once
		temp_S.update();
	}
	else {
		//setup the squiggle with the current paramaters
		temp_S.setup(res,radius_slider,var,theta,mouseX,mouseY);
		//update the squiggle once
		temp_S.update();
	}
}

//--------------------------------------------------------------
void ofApp::draw(){
	// should the gui control hiding?
	if (!hidepanel) {
		gui.draw();
	}

	//based on is deleting color cursor differently
	if (!isDeleting) {
		ofSetColor(255, 255, 255, 255.0/3);
	}
	else {
		ofSetColor(255, 0, 0, 255.0/3);
	}
	ofDrawCircle(ofVec2f(mouseX, mouseY), 10);

	temp_path.draw();

	//draw circles on vertices of temp path
	for (int i = 0; i < temp_path.size(); i++)
	{
		ofDrawCircle(temp_path[i], 10);
	}

	if (!isDeleting) {
		temp_S.draw();
	}

	//draw any squiggles
	MS.draw();

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
	if (key == 'h') {
		hidepanel = !hidepanel;
	}

	if (key == 'd') {
		isDeleting = !isDeleting;
	}

	if (key == 's') {
		recording = !recording;
	}

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){
}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){
	//when the mouse is dragged add to the temp_path polyline
	temp_path.addVertex(ofVec3f(x,y,0.0f) );
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
	//when the mouse is pressed add to the temp_path polyline
	temp_path.addVertex(ofVec3f(x,y,0.0f));
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
	if (!isDeleting) {
		//get the list of radius scaled by y coordinate in temp_path
		vector<float> rs;
		for (int i = 0; i < temp_path.size(); i++)
		{
			//convert the y coordinate into a scaler
			float rmod = persp(temp_path[i].y);
			rs.push_back(rmod);
		}
		//if were doing perspective send the rmod vector into the added squiggles
		if (rfac2) {
			MS.AddSquiggles(res, rs ,radius_slider, var, theta, temp_path);
		}
		else {
			MS.AddSquiggles(res, radius_slider, var, theta, temp_path);
		}
	}
	else {
		MS.DeleteSquiggles(temp_path);
	}
	//clear the polyline
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

