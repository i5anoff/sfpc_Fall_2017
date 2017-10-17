#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    random = 0;
    printSVG = false;
    
    gui.setup();
    gui.add(framePad.setup("frame", 0.86, .1, 1));
    gui.add(grid.setup("number elements", 3, 1, 50));
    gui.add(rectSizeX.setup("element size x", 0.62, .1, 1));
    gui.add(rectSizeY.setup("element size y", 0.62, .1, 1));
    gui.add(rectCopy.setup("inner copys", 32, 1, 100));
    gui.add(randMin.setup("distortion max value", 200, 0, 200));
    gui.add(randMax.setup("distortion min value", -35, 0, -200));
    
}
//--------------------------------------------------------------
void ofApp::update(){

    gridW = grid;
    gridH = grid;
    gridUnitW = ofGetWidth() * framePad / (gridW);
    gridUnitH = ofGetHeight() * framePad / (gridH);
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
    
    cout << printSVG << endl;

    if(printSVG == true){
        ofBeginSaveScreenAsSVG("screenshot-"+ofGetTimestampString()+".svg");
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

                ofScale(rectSizeX, rectSizeY);
            
                ofPoint a = ofPoint(0 + ofRandom(randMin, randMax), 0);                   // draw from 0, 0
                ofPoint b = ofPoint(gridUnitW + ofRandom(randMin, randMax), 0);
                ofPoint c = ofPoint(0 + ofRandom(randMin, randMax), gridUnitH);
                ofPoint d = ofPoint(gridUnitW + ofRandom(randMin, randMax), gridUnitH);
                drawRectangle(a, b, c, d);

            ofPopMatrix();
        }
    }
    
    
    if (printSVG == true) {
        ofEndSaveScreenAsSVG();
        printSVG = false;
    }
    
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    
    if(key =='r'){
        random += 1;
    }
    
    if (key =='p'){
        printSVG = true;
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
