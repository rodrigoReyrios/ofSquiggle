#pragma once

#include "ofMain.h"
#include "MultiSquig.h"
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
		//declare window size as global variable
		float windowx;
		float windowy;
		//also declare the cell size and number of cells
		float ell;
		int celli_x;
		int celli_y;
		//a temporary vector to store vectors of points
		vector<vector<ofVec3f>> wholepaths;
		//make a vector of Polylines that eventualy get drawn
		vector<ofPolyline> polys;
		//make a vector of MultiSquigs
		vector<MultiSquig> MS;
		vector<ofVec3f> reformat(vector<ofVec3f>, float);
};

