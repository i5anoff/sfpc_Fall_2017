

//---------------------------------------------------------------


#include "textSqueez2.h"

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
void textSqueez2::setup(){
    myType.load("GT-America-Trial-Compressed-Bold.otf", 500);
    bound1.set(myType.getStringBoundingBox("HUMAN", 0, 0));
    
    startTime = ofGetElapsedTimef();
    durationS = 1.5;
    counter = 0;
    counter2 = 0;

    
    widthA = 1;
    widthB = 0.0;
    
}

//---------------------------------------------------------------
void textSqueez2::update(){

    
    float elapsedTime = ofGetElapsedTimef() - startTime;
    float pctS = elapsedTime / durationS;
    pctS = function_DoubleExponentialSigmoid(elapsedTime / durationS, 0.8);
    if(pctS > 0.99){startTime = ofGetElapsedTimef();
        counter += 1;};
    
    bound1.set(myType.getStringBoundingBox("HUMAN", 0, 0));
    bound2.set(myType.getStringBoundingBox("BEING", 0, 0));
    diffW1to2 = bound1.width / bound2.width;
    
    scaleA1 = ofMap((pctS-1) * widthA + pctS * widthB, -1, -0, 1, 0);
    scaleA2 = ofMap((pctS-1) * widthA + pctS * widthB, -1, -0, 0, 1);
    
    scaleB1 = ofMap((pctS-1) * widthA + pctS * widthB, -1, -0, 0, diffW1to2);
    scaleB2 = ofMap((pctS-1) * widthA + pctS * widthB, -1, -0, diffW1to2, 0);
    
}

//---------------------------------------------------------------
void textSqueez2::draw(int counterIn){
    ofSetColor(15);
    
    float mod = counter % 2;
    cout << mod <<  endl;
    
    counter += counterIn;
    
    ofTranslate(0, bound1.height);
    
    
    if( counter % 2 == 0){
        ofPushMatrix();
        ofScale(scaleB2, 1);

        myType.drawString("BEING", -bound2.x, 0);
        ofPopMatrix();
        
        ofPushMatrix();
        ofTranslate(bound2.getWidth() * scaleB2, 0);
        ofScale(scaleA2, 1);

        myType.drawString("HUMAN", -bound2.x, 0);
        ofPopMatrix();
    }else{
        ofPushMatrix();
        ofScale(scaleA1, 1);

        myType.drawString("HUMAN", -bound1.x, 0);
        ofPopMatrix();
        
        ofPushMatrix();
        ofTranslate(bound1.getWidth() * scaleA1, 0);
        ofScale(scaleB1, 1);

        myType.drawString("BEING", -bound2.x, 0);
        ofPopMatrix();
    }
}

