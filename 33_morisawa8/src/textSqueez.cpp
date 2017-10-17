

#include "textSqueez.h"

float function_DoubleExponentialSigmoid (float x, float a){
    float min_param_a = 0.0 + FLT_EPSILON;
    float max_param_a = 1.0 - FLT_EPSILON;
    a = ofClamp(a, min_param_a, max_param_a);
    a = 1-a;
    
    float y = 0;
    if (x<=0.5){
        y = (pow(2.0*x, 1.0/a))/2.0;
    }
    else {
        y = 1.0 - (pow(2.0*(1.0-x), 1.0/a))/2.0;
    }
    return y;
}


//---------------------------------------------------------------
void textSqueez::setup(){
    myType.load("GT-America-Trial-Compressed-Bold.otf", 1000);
    bound1.set(myType.getStringBoundingBox("HUMAN", 0, 0));
    
    widthA = 1;
    widthB = 0.0;
    
    startTime = ofGetElapsedTimef();
    durationS = 1.5;
    counter = 0;
    counter2 = 0;
}

//---------------------------------------------------------------
void textSqueez::update(){
    float elapsedTime = ofGetElapsedTimef() - startTime;
    float pct = function_DoubleExponentialSigmoid(elapsedTime / durationS, 0.8);

    if(pct > 0.99){
        startTime = ofGetElapsedTimef();
        counter += 1;
        pct = 0;
    }
    
    bound1.set(myType.getStringBoundingBox("HUMAN", 0, 0));
    bound2.set(myType.getStringBoundingBox("BEING", 0, 0));
    diffB1B2 = bound1.width / bound2.width;
    
    scale1a = ofMap((pct-1) * widthA + pct * widthB, -1, -0, 1, 0);
    scale1b = ofMap((pct-1) * widthA + pct * widthB, -1, -0, 0, 1);
    
    scale2a = ofMap((pct-1) * widthA + pct * widthB, -1, -0, 0, diffB1B2);
    scale2b = ofMap((pct-1) * widthA + pct * widthB, -1, -0, diffB1B2, 0);
}

//---------------------------------------------------------------
void textSqueez::draw(int counterIn){
    ofSetColor(15);
    counter += counterIn;
    ofTranslate(0, bound1.height);
    
    if( counter % 2 == 0){
        ofPushMatrix();
            ofScale(scale1a, 1);
            myType.drawString("HUMAN", -bound1.x, 0);
        ofPopMatrix();
        
        ofPushMatrix();
            ofTranslate(bound1.getWidth() * scale1a, 0);
            ofScale(scale2a, 1);
            myType.drawString("BEING", -bound2.x, 0);
        ofPopMatrix();
    }else{
        ofPushMatrix();
            ofScale(scale2b, 1);
            myType.drawString("BEING", -bound2.x, 0);
        ofPopMatrix();
    
        ofPushMatrix();
            ofTranslate(bound2.getWidth() * scale2b, 0);
            ofScale(scale1b, 1);
            myType.drawString("HUMAN", -bound2.x, 0);
        ofPopMatrix();
    }
}

