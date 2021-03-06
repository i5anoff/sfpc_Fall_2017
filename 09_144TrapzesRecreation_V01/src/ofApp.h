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
    
        float gridW;
        float gridH;
        ofxFloatSlider framePad;
        float gridUnitW;
        float gridUnitH;
        float rectCopy;
        float rectCopyScaleX;
        float rectCopyScaleY;
        ofxFloatSlider rectSize;
    
        ofxFloatSlider randMin;
        ofxFloatSlider randMax;
        float random;
        bool  printPDF;
    
        ofxPanel gui;
    
};
