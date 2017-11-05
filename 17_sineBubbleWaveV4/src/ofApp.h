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
   
    int xElements;
    int yElements;
    float drawElement(float xIn, float yIn, float hIn, float scaleIn);
    ofRectangle containerElement;

    float drawYElements(float xIn, float yIn, float wIn, float hIn, float scaleIn);
    ofRectangle containerYElements;
    
    float x[500];
    float w[500];
    float scale[500];
    float totalWidth;

    float frame;
    float frameWidth;
    float frameHeight;
    
    
};

