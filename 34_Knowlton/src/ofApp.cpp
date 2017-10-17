#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    myImage.load("peace.png"); // thats the big emoji
    myImage.setImageType(OF_IMAGE_GRAYSCALE);
    mosaic.load("fingers.png"); // thats the small emoji

}

//--------------------------------------------------------------
void ofApp::update(){

    
    resolution = ofMap(ofGetMouseX(), 0, ofGetWindowWidth(), 5, 100);
    maxScale = resolution / mosaic.getWidth();
    minScale = 1 / mosaic.getWidth();
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    ofBackground(255);
 
    
    ofSetRectMode(OF_RECTMODE_CENTER);
    
        for (int i = 0; i < myImage.getWidth(); i += resolution){
            for (int j = 0; j < myImage.getHeight(); j += resolution){
                ofColor c = myImage.getColor(i, j);
                float bright = c.getBrightness();
    
                ofPushMatrix();
                    ofTranslate(i,j);
                    float scale = ofMap(bright, 0, 255, minScale, maxScale);
                    ofScale(scale, scale);
                    mosaic.draw(0, 0);
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

