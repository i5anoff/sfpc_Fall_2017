#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    random = 0;
    
    gui.setup();
    
    scale =  0.613;
    framePad = 0.82;

    gui.add(grid.setup("number elements", 3, 1, 50));

    gui.add(rectCopy.setup("inner copys", 32, 1, 100));
    gui.add(randMin.setup("distortion max value", 200, 0, 200));
    gui.add(randMax.setup("distortion min value", -35, 0, -200));
    
    timeStamp = ofGetElapsedTimef();
    

    
}
//--------------------------------------------------------------
void ofApp::update(){


    
    rectSizeX = scale;
    rectSizeY = scale * 1.25;
    gridW = grid;
    gridH = grid;
    gridUnitW = ofGetWidth() * framePad / (gridW);
    gridUnitH = ofGetHeight() * framePad / (gridH);
    
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

void ofApp::drawRectangle( ofPoint a, ofPoint b, ofPoint c, ofPoint d){
    
    
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


//--------------------------------------------------------------
void ofApp::draw(){
    
    gui.draw();
    
    
    ofSetBackgroundColor(15);
    ofSetColor(240);
    
    ofSeedRandom(random);
    
    
    ofTranslate((ofGetWidth() - (ofGetWidth() * framePad)) / 2,         //push grid in center
                 (ofGetHeight() - (ofGetHeight() * framePad)) / 2);

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
    }
    
    
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

    
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){
}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){


}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
