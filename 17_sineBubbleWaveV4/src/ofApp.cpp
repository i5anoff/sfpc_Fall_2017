#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

}

float ofApp::drawElement(float xIn, float yIn, float hIn, float scaleIn){
    
    containerElement.set(xIn, yIn, hIn, hIn);
    containerElement.scaleFromCenter(scaleIn);

    ofPushMatrix();
    
        ofTranslate(xIn, yIn);
        ofTranslate(-xIn - (hIn *0.5), -yIn - (hIn * 0.5));

        ofDrawTriangle(containerElement.getX(),
                       containerElement.getY(),
                       containerElement.getX(),
                       containerElement.getY() + containerElement.getHeight(),
                       containerElement.getX() + containerElement.getWidth(),
                       containerElement.getY() + containerElement.getHeight() * 0.5);

    ofPopMatrix();
    
}

float ofApp::drawYElements(float xIn, float yIn, float wIn, float hIn, float scaleIn){
    
    containerYElements.set(xIn, yIn, wIn, hIn);
    containerYElements.scaleFromCenter(scaleIn, scaleIn);
    float yGrid = containerYElements.getHeight() / (yElements-1);
    float yGridHeight = yGrid * 0.7;
    
    ofPushMatrix();
        ofTranslate(-yGridHeight * 0.5, -yGridHeight * 0.5);
 
        for (int i =0; i < yElements; i++) {
            drawElement(containerYElements.getX() + (containerYElements.getWidth() * 0.5) + (ofMap(sin((ofGetElapsedTimef() + i * 1.9) * 3.1), -1, 1, -100, 100)),
                        containerYElements.getY() + i * yGrid,
                        yGridHeight,
                        scaleIn);
        }

    ofPopMatrix();
    
    return yGridHeight;
    
}

//--------------------------------------------------------------
void ofApp::update(){
    
    frame = .6;
    frameHeight = ofGetHeight() * frame;
    
    xElements = ofMap(ofGetMouseX(), 0, ofGetWidth(), 4, 400);
    yElements = ofMap(ofGetMouseY(), 0, ofGetHeight(), 3, 300);

    x[0] = 0;

    for (int i = 0; i < xElements; i++) {

        scale[i] = ofMap(sin((ofGetElapsedTimef() + i * 1.9) * 3.1), -1, 1, .8, 1.2);

        if (i > 0) {
            x[i] = (x[i-1] + (w[i-1] * 0.5) + (w[i] * 0.5) * scale[i] * 1.5);
        }
        w[i] = drawYElements(x[i], 0, 0, frameHeight, scale[i]);
        totalWidth = x[xElements-1];

    }


    
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    ofSetBackgroundColor(240);
    ofSetColor(15);
    
    ofTranslate((ofGetWidth() - totalWidth) * 0.5, (ofGetHeight() - frameHeight) * 0.5);

    for (int i = 0; i < xElements; i++) {
            drawYElements(x[i], 0, 0, frameHeight, scale[i]);
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

