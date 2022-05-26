#pragma once

#include "ofMain.h"
#include "Squiggle.h"
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
		//a single squiggle instans
		Squiggle S;
		//and declare some custom methods
		void drawGrid();
		void calcGrid();
};
