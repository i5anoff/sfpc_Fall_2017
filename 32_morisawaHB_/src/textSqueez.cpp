

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
    
//    const std::string& _filename, int _fontSize, bool _bAntiAliased, bool _bFullCharacterSet, bool _makeContours, float _simplifyAmt, int _dpi
    
    myType.load("GT-America-Trial-Compressed-Bold.otf", 1000, true, false, true);
    bound1.set(myType.getStringBoundingBox("HUMAN", 0, 0));
    
    
    word1.clear();
    word2.clear();
    vector<ofTTFCharacter> path1 = myType.getStringAsPoints("HUMAN");
    for(int i = 0; i < path1.size(); i++){
        word1.push_back(path1[i].getTessellation());
    }
 
    vector<ofTTFCharacter> path2 = myType.getStringAsPoints("BEING");
    for(int i = 0; i < path2.size(); i++){
        word2.push_back(path2[i].getTessellation());
    }

    startTime = ofGetElapsedTimef();
    durationS = 1;
    counter = 0;
    counter2 = 0;
    
    widthA = 1;
    widthB = 0.0;
    
}

//---------------------------------------------------------------
void textSqueez::update(){
    
    
    float elapsedTime = ofGetElapsedTimef() - startTime;
    float  pctS = elapsedTime / durationS;
    pctS = powf(pctS, .5);
    if(pctS > 0.99){
        startTime = ofGetElapsedTimef();
        counter += 1;
        pctS = 0;
    }
    cout << pctS << endl;
    
    if(pctS > 0.99){
        startTime = ofGetElapsedTimef();
        counter += 1;
        pctS = 0;
    }
    
//    float elapsedTime = ofGetElapsedTimef() - startTime;
//    float  pctS = function_DoubleExponentialSigmoid(elapsedTime / durationS, 0.85);
//
//    if(pctS > 0.99){
//        startTime = ofGetElapsedTimef();
//        counter += 1;
//        pctS = 0;
//    }
    
    bound1.set(myType.getStringBoundingBox("HUMAN", 0, 0));
    bound2.set(myType.getStringBoundingBox("BEING", 0, 0));
    diffW1to2 = bound1.width / bound2.width;
    
    scaleA1 = ofMap((pctS-1) * widthA + pctS * widthB, -1, -0, 1, 0);
    scaleA2 = ofMap((pctS-1) * widthA + pctS * widthB, -1, -0, 0, 1);
    
    scaleB1 = ofMap((pctS-1) * widthA + pctS * widthB, -1, -0, 0, diffW1to2);
    scaleB2 = ofMap((pctS-1) * widthA + pctS * widthB, -1, -0, diffW1to2, 0);
    

    
}

//---------------------------------------------------------------
void textSqueez::draw(int counterIn){
   
    ofSetColor(15);
    
    counter += counterIn;
    
    ofTranslate(0, bound1.height);

    if( counter % 2 == 0){
        ofPushMatrix();
            ofScale(scaleA1, 1);
            ofTranslate(-bound1.x, 0);
            for(int i = 0; i < word1.size(); i++){
                word1[i].draw();
            }
        ofPopMatrix();
        
        ofPushMatrix();
            ofTranslate(bound1.getWidth() * scaleA1, 0);
            ofScale(scaleB1, 1);
            ofTranslate(-bound2.x, 0);
            for(int i = 0; i < word2.size(); i++){
                word2[i].drawWireframe();
            }
        ofPopMatrix();
    }else{
        ofPushMatrix();
            ofScale(scaleB2, 1);
//            myType.drawString("BEING", -bound2.x, 0);
            ofTranslate(-bound2.x, 0);
            for(int i = 0; i < word2.size(); i++){
                word2[i].drawWireframe();
            }

        ofPopMatrix();
    
        ofPushMatrix();
            ofTranslate(bound2.getWidth() * scaleB2, 0);
            ofScale(scaleA2, 1);
//            myType.drawString("HUMAN", -bound2.x, 0);
            ofTranslate(-bound2.x, 0);
            for(int i = 0; i < word1.size(); i++){
                word1[i].draw();
            }

        ofPopMatrix();
    }
    
}

