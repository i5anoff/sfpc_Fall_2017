#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetFrameRate(60);
    ofSetBackgroundColor(15);
    ofSetColor(240);
    numCopys = 40;
    
    //layout
    numElement = 1;
    
    //save svg
    saveSVG = false;
    
    
}

//--------------------------------------------------------------
void ofApp::update(){
    
    // layout
    frame = 0.9;
    scaleElement = 0.8;
    width = ofGetWidth() * frame / numElement;
    height = ofGetHeight() * frame / numElement;
    
}

void ofApp::lissajous(float xIn, float yIn, float widthIn, float heightIn, float angleIn){
    
    radius = widthIn * 0.35;
    speed = 1.5 * ofMap(ofGetMouseX(), 0, ofGetWidth(), 1, 3);
    adder = ofMap(ofGetMouseY(), 50, ofGetHeight() - 50, 1, 4);
    xOrigin = xIn + widthIn * 0.5 ;
    yOrigin = yIn + heightIn * 0.5;
    sinAngle = ofGetElapsedTimef() * speed;
    cosAngle = ofGetElapsedTimef() * speed * adder;
    
    myLine = ofPolyline();
    
    for (int i =0; i < 500; i++) {
        float increment = (float)i * 0.01;
        myLine.addVertex(xOrigin + radius * sin(angleIn + increment * speed * (int) adder + sinAngle),
                         yOrigin + radius * cos(increment * speed));
    }
    
    ofSetLineWidth(widthIn * 0.01);
    myLine.draw();
}



//--------------------------------------------------------------
void ofApp::draw(){
    
    if(saveSVG == true){
        ofBeginSaveScreenAsSVG("lissajous1_"+ofGetTimestampString()+".svg");
    }
    
    ofTranslate((ofGetWidth() - ofGetWidth() * frame) * 0.5,
                (ofGetHeight() - ofGetHeight() * frame) * 0.5);
    
    for (int i = 0; i < numElement; i++) {
        for (int j = 0; j < numElement; j++) {
            for (int k = 0; k < numCopys; k++) {
                
                container.set(0 + i * width, 0 + j * height, width, height);
                container.scaleFromCenter(scaleElement);
                container.scaleFromCenter(ofMap(k, 0, numCopys, 1, 0));
                
                ofSetColor(240 - k * 10);
                
                lissajous(container.getX() + k * ofMap(sin(ofGetElapsedTimef() * 1.25) ,
                           -1, 1, -container.getWidth() * 0.025, container.getWidth() * 0.025),
                          container.getY(),
                          container.getWidth(),
                          container.getHeight(),
                          i * 0.25 + (j * 0.5));
            }
        }
    }
    
    if (saveSVG == true) {
        ofEndSaveScreenAsSVG();
        saveSVG = false;
    }
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    
    //layout
    if (key == '1') {
        numElement = 1;
    }
    if (key == '2') {
        numElement = 2;
    }
    if (key == '3') {
        numElement = 3;
    }
    if (key == '4') {
        numElement = 4;
    }
    if (key == '5') {
        numCopys = 1;
    }
    if (key == '6') {
        numCopys = 10;
    }
    if (key == '7') {
        numCopys = 40;
    }
    
    //save svg
    if (key == 's') {
        saveSVG = true;
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

