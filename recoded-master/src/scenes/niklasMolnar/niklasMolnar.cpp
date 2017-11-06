
#include "niklasMolnar.h"

void niklasMolnar::setup(){
  
    random = 0;
    
    
    scale =  0.613;
    framePad = 0.82;
    
    grid.set("number elements", 3, 1, 50);
        parameters.add(grid);
    rectCopy.set("inner copys", 32, 1, 100);
        parameters.add(rectCopy);
    randMin.set("distortion max value", 200, 0, 200);
        parameters.add(randMin);
    randMax.set("distortion min value", -35, 0, -200);
        parameters.add(randMax);
    
    
    timeStamp = ofGetElapsedTimef();

    setAuthor("Niklas May");
    setOriginalArtist("Vera Monar");
    loadCode("scenes/niklasMolnar/exampleCode.cpp");
    
}

void niklasMolnar::update(){
    rectSizeX = scale;
    rectSizeY = scale * 1.25;
    gridW = grid;
    gridH = grid;
    gridUnitW = VISUALS_WIDTH * framePad / (gridW);
    gridUnitH = VISUALS_HEIGHT * framePad / (gridH);
    
    if (random % 3 == 0) {
        if (ofGetElapsedTimef() - timeStamp > 0.5){
            random += 1;
            timeStamp = ofGetElapsedTimef();
        }
    }else {
        if (ofGetElapsedTimef() - timeStamp > 0.25){
            random += 1;
            timeStamp = ofGetElapsedTimef();
        }
        
    }
}
void niklasMolnar::drawRectangle( ofPoint a, ofPoint b, ofPoint c, ofPoint d){
    
    
    for (int i = 0; i < rectCopy; i++) {
        
        ofPushMatrix();
        
        rectCopyScaleX = ofMap(i, 0, rectCopy, 0.075, 1);
        rectCopyScaleY = ofMap(i, 0, rectCopy, 0.5, 1);
        ofScale(rectCopyScaleX, rectCopyScaleY);
        
        ofTranslate(- gridUnitW * 0.5, - gridUnitH * 0.5); //  square center at 0, 0
        
        ofSetLineWidth(5);
        ofDrawLine(a, b);
        ofDrawLine(c, d);
        
        ofSetLineWidth(1);
        ofDrawLine(a, c);
        ofDrawLine(b, d);
        
        ofPopMatrix();
        
    };
    
}
void niklasMolnar::draw(){
    ofSetBackgroundColor(15);
    ofSetColor(240);
    
    ofSeedRandom(random);
    
    
    ofTranslate((VISUALS_WIDTH - (VISUALS_WIDTH * framePad)) / 2,         //push grid in center
                (VISUALS_HEIGHT - (VISUALS_HEIGHT * framePad)) / 2);
    
    for (int i = 0; i < gridW; i++) {
        for (int j = 0; j < gridH; j++){
            
            ofPushMatrix();
            
            ofTranslate(i * gridUnitW, j * gridUnitH);              // move through the grid
            ofTranslate(+ gridUnitW * 0.5, + gridUnitH * 0.5);      // poisition disign at second grind unit
            
            ofScale(rectSizeX, rectSizeY);
            
            ofPoint a = ofPoint(0 + ofRandom(randMin, randMax), 0);                   // draw from 0, 0
            ofPoint b = ofPoint(gridUnitW + ofRandom(randMin, randMax), 0);
            ofPoint c = ofPoint(0 + ofRandom(randMin, randMax), gridUnitH);
            ofPoint d = ofPoint(gridUnitW + ofRandom(randMin, randMax), gridUnitH);
            drawRectangle(a, b, c, d);
            
            ofPopMatrix();
        }
    }}
