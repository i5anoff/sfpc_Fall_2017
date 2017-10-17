#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    myRect.set(0, 0, 300, 100);
    myText.setup();
}

//--------------------------------------------------------------
void ofApp::update(){
    myText.update();
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    ofSetBackgroundColor(240);
    ofSetColor(15);
    ofNoFill();
    
    int counter = 0;
    
    float frame = 0.95;
    float width = ofGetWidth() * frame;
    float height = ofGetHeight() * frame;
    ofTranslate((ofGetWidth() - width) * 0.5, (ofGetHeight() - height) * 0.5);
    float totalHeight = 0;
    
    float y = 0;
    
    for (int i = 0; i < 9 ; i++) {
        float numElements = +1;

//        if(numElements < 8){numElements += 1;}
//        if(numElements > 8){numElements /= 2;}
        float grid = width / numElements;
        float scale = grid / myText.bound1.getWidth();
       
        float x = 0;
        
        for (int j = 0; j < numElements; j++) {
            counter += 1;

            ofPushMatrix();
                // position in grid
                ofTranslate(x , y);

                //align top and left
                ofTranslate(scale * myText.bound1.getWidth() * 0.5,
                            scale * (myText.bound1.getHeight()*1.1) * 0.5);
            
                //draw from center and scale
                ofScale(scale, scale);
                ofTranslate(-myText.bound1.getWidth() * 0.5, -(myText.bound1.getHeight()*1.1) * 0.5);
                if (counter % 2 == 1) {myText.draw(+1);}
            ofPopMatrix();
            
            x += scale * myText.bound1.getWidth();
        }
        y += scale * (myText.bound1.getHeight()*1.1);
        totalHeight += (myText.bound1.getHeight()*1.1) * scale;
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
