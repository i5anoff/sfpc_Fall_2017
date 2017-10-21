#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(240);
    myImage.load("IMG_9121SQ.JPEG");
    resolution = 1;
 lineNum = 2;

}

//--------------------------------------------------------------
void ofApp::update(){

    
}

//--------------------------------------------------------------
void ofApp::draw(){
 
    // Window Position
    float frame = 0.9;
    float imgScale = ofGetWidth() * frame / myImage.getWidth();
    float imgWidth = myImage.getWidth() * imgScale;
    float imgHeight = myImage.getHeight() * imgScale;
    ofTranslate((ofGetWidth() - imgWidth) / 2, (ofGetHeight() - imgHeight) / 2);
    ofScale(imgScale, imgScale);
    ofSetColor(255);

    // Layout
    float lineHeight = myImage.getHeight() / lineNum;

    int lineCount = 0;
    float yOffset = 0;
    float xOffset = 0;

    for (int k = 0; k < lineNum; k++) {
        if(lineCount % 2 == 1){yOffset = -lineHeight;
        }else{yOffset = lineHeight;}
       
        for (int i = 0; i < myImage.getWidth(); i += resolution) {
           
                for (int j = 0; j < lineHeight; j += resolution){
                    float duplicate = ofMap(ofGetMouseY(), 0, ofGetHeight(), 0, + lineHeight);
                    ofColor c = myImage.getColor(i, j + (lineCount * lineHeight));
                    
                    ofPushMatrix();
                        ofTranslate(i ,j + (lineHeight * lineCount) + yOffset);
                        ofSetColor(c);
                 
                        if(lineCount % 2 == 1){
                            ofDrawRectangle(0, 0, resolution, resolution);
                        }else{
                            ofDrawRectangle(0, 0, resolution, resolution);
                        }
                    
                    ofPopMatrix();
                }
        }
        lineCount += 1;
    }
    

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if (key == '1') {
        lineNum = 2;
        
    }
    if (key == '2') {
        lineNum = 4;
        
    }
    if (key == '3') {
        lineNum = 6;
        
    }
    if (key == '4') {
        lineNum = 8;
        
    }
    if (key == '5') {
        lineNum = 16;
        
    }
    if (key == '6') {
        lineNum = 24;
        
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

