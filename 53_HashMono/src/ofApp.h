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
    
    // type basics
    hashMono t;
    ofxIntSlider unit;
    float w;
    float h;
    float lineHeight;
    float leading;
    float blank;
    
    // animation
    int patOff;
    float startTime;
    float elapsedTime;
    float duration;
    float pct;
    float noise;
    bool bIsPrevUpdate;
    ofxFloatSlider amp;
    ofxFloatSlider speed;
    void prevUpdate();
    
    void inActiveAnimation();
    bool bIsInactive;
    float inactStartTime;
    float inactElapsedTime;
    float inactPct;
    int modInact;

    
    // type manipulation
    ofxIntSlider mod1;
    ofxIntSlider mod2;
    ofxIntSlider mod3;
    ofxIntSlider mod4;
    ofxIntSlider mod5;

    vector < float > width;
    vector < bool > horAlt;
    vector < bool > downStrokeAlt;
    vector < bool > cirAlt;
    
    vector < float > widthPrev;

    
    
    // type position
    vector < string > letters;
    vector < string > blanks;
    vector < string > lines;
    vector < float > xPos;
    vector < float > yPos;
    void blanksAndLinesNull();
    void xyUpdate();
    
    //layout
    float padding;
    
    
    
};
