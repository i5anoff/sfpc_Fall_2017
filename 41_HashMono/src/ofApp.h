#pragma once

#include "ofMain.h"
#include "ofxGui.h"
#include "hashMono.h"

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
  
    vector < letter > letters;
    letter E;
    letter H;
    letter L;
    letter O;   
    vector < float > w;
    float h;

    
    ofxPanel gui;
    
    float FirstTimeStamp;
    vector < float > timeStamp;
    ofxIntSlider typeSpeedMin;
    ofxIntSlider typeSpeedMax;
    
    
    
    
};

