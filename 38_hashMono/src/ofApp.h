#pragma once

#include "ofMain.h"

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
    
    float drawChar(int ascii, float widthIn);
    
    ofRectangle charGrid;
    float gridX;
    float gridY;
    float gridW;

    float ascLine;
    float capLine;
    float baseLine;
    float desLine;
    
    vector < int > text;
    float leading;
    float lineHeight;
    float lineNum;
    float cursorXPos[500];
    float cursorYPos[500];

    float widthIn[100];
    float widthValue;
		
};
