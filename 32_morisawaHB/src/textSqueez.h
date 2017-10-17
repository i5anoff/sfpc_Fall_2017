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
    float diffW1to2;
    
    float startTime;
    float durationP;
    float durationS;
    int counter;
    int counter2;
    
    float widthA;
    float widthB;
    float scaleA1;
    float scaleA2;
    float scaleB1;
    float scaleB2;
    
    vector <ofMesh> word1;
    vector <ofMesh> word2;
};

