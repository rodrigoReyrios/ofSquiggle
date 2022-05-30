#pragma once

#include "ofMain.h"
#include "Squiggle.h"
#include "MultiSquig.h"
#include "ofxGui.h"
class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);

		//ofx paramater options
		bool hidepanel;
		ofxFloatSlider radius_slider;
		ofxIntSlider res;
		ofxFloatSlider var;
		ofxFloatSlider theta;
		ofxFloatSlider spacing;
		ofxPanel gui;

		//a multisquig to contain all the squiggles
		MultiSquig MS;

		//booleans for mouse options
		bool isDeleting;

		//integer to keep track of frame number
		int fnum;

		//boolean for saving frames
		bool recording;

		//boolean for saving temp path
		ofPolyline temp_path;

		//boolean for pausing updates
		ofxToggle pause;

		//boolean for radius scaling
		ofxToggle rfac2;

		//temp squiggle to show current squiggle params
		Squiggle temp_S;
};

