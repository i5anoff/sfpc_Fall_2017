#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    random = 0;
    printPDF = false;
    
    gui.setup();
    gui.add(framePad.setup("frame", 0.7, 0, 1));
    gui.add(rectSize.setup("element size", 0.8, 0,1));
    gui.add(randMax.setup("distortion max value", 60, -100, 100));
    gui.add(randMin.setup("distortion min value", -30, -100, 100));
}
//--------------------------------------------------------------
void ofApp::update(){

    int grid = 12;
    gridW = grid;
    gridH = grid;
    gridUnitW = ofGetWidth() * framePad / (gridW);
    gridUnitH = ofGetHeight() * framePad /(gridH);

}

void ofApp::drawRectangle( ofPoint a, ofPoint b, ofPoint c, ofPoint d){
    
    
        ofPushMatrix();

            ofScale(rectSize, rectSize);
        
            ofTranslate(- gridUnitW * 0.5, - gridUnitH * 0.5); //  square center at 0, 0
    
            ofSetLineWidth(2);
            ofDrawLine(a, b);
            ofDrawLine(c, d);
            ofDrawLine(a, c);
            ofDrawLine(b, d);
    
        ofPopMatrix();
    
    }


//--------------------------------------------------------------
void ofApp::draw(){
    
    gui.draw();
    
    if(printPDF == true){
        ofBeginSaveScreenAsPDF("screenshot-"+ofGetTimestampString()+".pdf");
    }
    
    ofSetBackgroundColor(240);
    ofSetColor(15);
    
    ofSeedRandom(random);
    
    
    ofTranslate((ofGetWidth() - (ofGetWidth() * framePad)) / 2,         //push grid in center
                 (ofGetHeight() - (ofGetHeight() * framePad)) / 2);

    for (int i = 0; i < gridW; i++) {
        for (int j = 0; j < gridH; j++){

            ofPushMatrix();
            
                ofTranslate(i * gridUnitW, j * gridUnitH);              // move through the grid
                ofTranslate(+ gridUnitW * 0.5, + gridUnitH * 0.5);      // poisition disign at second grind unit

                ofScale(rectSize, rectSize);
            
                ofPoint a = ofPoint(0 + ofRandom(randMin, randMax), 0);                   // draw from 0, 0
                ofPoint b = ofPoint(gridUnitW + ofRandom(randMin, randMax), 0);
                ofPoint c = ofPoint(0 + ofRandom(randMin, randMax), gridUnitH);
                ofPoint d = ofPoint(gridUnitW + ofRandom(randMin, randMax), gridUnitH);
                drawRectangle(a, b, c, d);

            ofPopMatrix();
        }
    }
    
    
    if (printPDF == true) {
        ofEndSaveScreenAsPDF();
        printPDF = false;
    }
    
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    
    if(key =='r'){
        random += 1;
    }
    
    if (key =='p'){
        printPDF = true;
    }

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
