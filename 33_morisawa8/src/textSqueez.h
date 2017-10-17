#pragma once

#define SPEED 0.3

#include "ofMain.h"

class textSqueez{
    
public:
    
    void setup();
    void update();
    void draw(int counterIn);

    ofTrueTypeFont myType;
    ofRectangle bound1;
    ofRectangle bound2;
    float diffB1B2;
    
    float startTime;
    float durationP;
    float durationS;
    int counter;
    int counter2;
    
    float widthA;
    float widthB;
    float scale1a;
    float scale1b;
    float scale2a;
    float scale2b;
};

