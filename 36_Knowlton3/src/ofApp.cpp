#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(255);
    myPlayer.load("skeleton.mov");
    myPlayer.play();
    resolution = 1;
    

}

//--------------------------------------------------------------
void ofApp::update(){

    myPlayer.update();
}

//--------------------------------------------------------------
void ofApp::draw(){
 
    myPlayer.getTexture();
    // Window Position
    float frame = 0.75;
    float imgScale = ofGetWidth() * frame / myImage.getWidth();
    float imgWidth = myImage.getWidth() * imgScale;
    float imgHeight = myImage.getHeight() * imgScale;
    ofTranslate((ofGetWidth() - imgWidth) / 2, (ofGetHeight() - imgHeight) / 2);
    ofScale(imgScale, imgScale);

    // Layout
    int lineNum = 4;
    float lineHeight = myImage.getHeight() / lineNum;

    int lineCount = 0;
    float yOffset = 0;

    for (int k = 0; k < lineNum; k++) {
        if(lineCount % 2 == 1){yOffset = -lineHeight;
        }else{yOffset = lineHeight;}

        for (int i = 0; i < myImage.getWidth(); i += resolution) {
//            float yCurve = ofMap(sin((ofGetElapsedTimef()*2) + i*0.025), -1, 1, -20, 20);
//            ofPushMatrix();
//                ofTranslate(0, yCurve);
            for (int j = 0; j < lineHeight; j += resolution){
                ofColor c = myImage.getColor(i, j + (lineCount * lineHeight));
                ofPushMatrix();
                    ofTranslate(i,j + (lineHeight * lineCount) + yOffset);
                    ofSetColor(c);
                    ofDrawRectangle(0, 0, resolution, resolution);
                ofPopMatrix();
            }
//            ofPopMatrix();
        }
        lineCount += 1;
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

