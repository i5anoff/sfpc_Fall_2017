

#include "Particle.h"

//---------------------------------------------------------------
void Particle::setup(float xIn, float yIn){
    
    x = xIn;
    y = yIn;
    speedX = ofRandom(0, 1);
    if (speedX >= 0.5) {
        speedX = ofRandom(30, 60);
    }else {
        speedX = ofRandom(-30, -60);
    }
    
    radii[0] = 2;
    radii[1] = 6;
    radii[2] = 18;
    radiusSelector = ofRandom(0, 3);
    radius = radii[radiusSelector];
  
    resolutions[0] = 3;
    resolutions[1] = 6;
    resolutions[2] = 9;
    resulutionSelector = ofRandom(0, 3);
    


}

//---------------------------------------------------------------
void Particle::update(){
    x = x + speedX * SPEED;
    

    if(x > ofGetWidth()){
        speedX = -speedX;
        radius = radius * 2.5;
    } else if (x < 0){
        speedX = -speedX;
        radius = radius * 2.5;
    }
}

//---------------------------------------------------------------
void Particle::draw(){
    ofDrawCircle(x, y, radius);
    
// ofSetHexColor(int colors[colorSelect]);
    ofSetCircleResolution(resolutions[resulutionSelector]);
}
