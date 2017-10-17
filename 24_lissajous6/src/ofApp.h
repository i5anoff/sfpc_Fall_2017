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
    
    //layout
    float frame;
    float numElement;
    float scaleElement;
    ofRectangle container;
    float width;
    float height;
    
    //issajous
    void lissajous(float xIn, float yIn, float widthIn, float heightIn, float angleIn);
    ofPolyline myLine;
    float radius;
    float speed;
    float adder;
    float xOrigin;
    float yOrigin;
    float sinAngle;
    float cosAngle;
    float numCopys;
    
    //save svg
    bool saveSVG;
    
};

