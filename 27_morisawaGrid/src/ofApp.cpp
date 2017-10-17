#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    myRect.set(0, 0, 300, 100);
}

//--------------------------------------------------------------
void ofApp::update(){
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    ofSetBackgroundColor(15);
    ofSetColor(240);
    ofNoFill();
    
    float frame = 0.9;
    float width = ofGetWidth() * frame;
    float height = ofGetHeight() * frame;
    ofTranslate((ofGetWidth() - width) * 0.5, (ofGetHeight() - height) * 0.5);
    
    float totalHeight = 0;
    float y = 0;
    
    for (int i = 0; totalHeight < height ; i++) {
        float numElements = 1+i;
        float grid = width / numElements;
        float scale = grid / myRect.width;
        float x = 0;
        
        for (int j = 0; j < numElements; j++) {
            ofPushMatrix();
            // position in grid
            ofTranslate(x , y);

            //align top and left
            ofTranslate(scale * myRect.width * 0.5,
                        scale * myRect.height * 0.5);
            
            //draw from center and scale
            ofScale(scale, scale);
            ofTranslate(-myRect.width * 0.5, -myRect.height * 0.5);
            ofDrawRectangle(myRect);
            ofPopMatrix();
            x += scale * myRect.width;
        }
        y += scale * myRect.height;
        totalHeight += myRect.height * scale;
        cout << totalHeight << endl;
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
