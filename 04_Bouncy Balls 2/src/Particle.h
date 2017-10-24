#pragma once

#define SPEED 0.3

#include "ofMain.h"

class Particle {
    
public:
    
    void setup(float xIn, float yIn);
    void update();
    void draw();
    
    float x;
    float y;
    float speedX;
    
    float radii[3];
    int radiusSelector;
    int radius;
    
    float resolutions[3];
    int resulutionSelector;
    
    string color[3];
    int colorSelect;
};
