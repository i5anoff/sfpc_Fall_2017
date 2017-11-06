#pragma once

#include "ofMain.h"
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
    
        void drawRectangle( ofPoint a, ofPoint b, ofPoint c, ofPoint d);
    
        ofxIntSlider grid;
        float gridW;
        float gridH;
        ofxFloatSlider framePad;
        float gridUnitW;
        float gridUnitH;
        ofxFloatSlider rectCopy;
        float rectCopyScaleX;
        float rectCopyScaleY;
        float scale;
        float rectSizeX;
        float rectSizeY;

        ofxFloatSlider randMin;
        ofxFloatSlider randMax;
        int random;
    
    float timeStamp;
    
        ofxPanel gui;
};
