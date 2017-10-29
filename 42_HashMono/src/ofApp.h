#pragma once

#include "ofMain.h"
#include "hashMono.h"
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
    
    ofxPanel gui;
    
    hashMono t;
    float unit;
    vector < float > w;
//    float w;
    float h;
    float leading;
    float space;
    
    vector < string > letters;
    float xPos;
    float yPos;
    
    vector < float > timeStamp;
    ofxIntSlider typeSpeedMin;
    ofxIntSlider typeSpeedMax;
    
};
