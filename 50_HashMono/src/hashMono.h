#pragma once

#include "ofMain.h"
#define LETTERARGUMENTS x, y, width, height, multiLine, r, dist, horAlt

class letterPoint {
    
public:
    
    float xScale;
    float xOffset;
    
    float yScale;
    float yOffset;
    
    float wScale;
    float wOffset;
    
    float hScale;
    float hOffset;
    
    void set(float _xScale, float _xOffset,
             float _yScale, float _yOffset,
             float _wScale, float _wOffset,
             float _hScale, float _hOffset){
        
        xScale = _xScale;
        yScale = _yScale;
        wScale = _wScale;
        hScale = _hScale;
        
        xOffset = _xOffset;
        yOffset = _yOffset;
        wOffset = _wOffset;
        hOffset = _hOffset;
        
    }
    
    ofPoint getPointFor(float x, float y, float w, float h){
        ofPoint pos;
        pos.x = (x*xScale + xOffset) + (w*wScale + wOffset);
        pos.y = (y*yScale + yOffset) + (h*hScale + hOffset);
        return pos;
    }
    
};


class letterShape {
    
public:
    
    bool bIsLine;
    bool bIsMultiLine;
    bool bIsHorAlt;
    
    
    // if line!
    letterPoint pts[2];
    
    // if curve:
    letterPoint center;
    float radius;
    float startAngle;
    
    
    void lineType(bool line, bool multiLine = false, bool horAlt = false){
        bIsLine = line;
        bIsMultiLine = multiLine;
        bIsHorAlt = horAlt;
    }
    
    void draw(float x, float y, float w, float h, float multiLine, int r, float dist, bool horAltIn){
        
        float lineS = 1;
        float lineM = 7;
        float lineL = 15;
        ofSetColor(240);
        
        if (bIsLine){
            
            ofPoint ptA = pts[0].getPointFor(x,y,w,h);
            ofPoint ptB = pts[1].getPointFor(x,y,w,h);
            
            if (bIsMultiLine){
                for(int i = 0; i < multiLine; i++){
                    
                    if ( multiLine > 1){
                        
                        ofPolyline lineTemp;
                        lineTemp.addVertex( ptA );
                        lineTemp.addVertex( ptB );
                        
                        ofPolyline lineRsTemp = lineTemp.getResampledByCount(15);
                        ofPolyline lineRs;
                        
                        
                        lineRs.clear();
                        for (int j = 0; j < lineRsTemp.size(); j++){
                            
                            float noise = 0;
                            if (i > 1)  noise = ofMap(ofNoise(j*0.7, ofGetElapsedTimef()*0.5),
                                                      0, 1, 0, i*0.35);
                            lineRs.addVertex(lineRsTemp[j].x + noise, lineRsTemp[j].y);
                        }
                        
                        ofPushStyle();
                        float tempLw = ofMap(i, 0, multiLine, 2, 0.5);
                        ofSetLineWidth(lineS);
                        if (i == 0) ofSetLineWidth(lineL);
                        if (bIsMultiLine && i > 1) ofSetColor(80);
                        ofPushMatrix();
                        ofTranslate(x + w * 0.5 + i * (w * dist), y);
                        if (multiLine > 1) ofRotateZ(r*(i*0.5));
                        ofTranslate(i * (w * dist), 0);
                        ofTranslate(-x - (w * 0.5) - i * (w * dist),-y);
                        
                        lineRs.draw();
                        
                        ofPopMatrix();
                        ofPopStyle();
                    }
                    else {
                        ofLine(ptA, ptB);
                    }
                }
            }
            if (bIsHorAlt && horAltIn == true){
                ofPolyline lineTemp;
                lineTemp.addVertex( ptA );
                lineTemp.addVertex( ptB );
                
                ofPolyline lineRsTemp = lineTemp.getResampledByCount(25);
                ofPolyline lineRs;
                
                lineRs.clear();
                for (int i = 0; i < lineRsTemp.size(); i++){
                    float noise = 0;
                    noise = ofMap(sin((ofGetElapsedTimef() + i * 1.9) * 3.1)*0.25,0, 1, 0, 10);
                    lineRs.addVertex(lineRsTemp[i].x, lineRsTemp[i].y + noise);
                }
                
                ofPushStyle();
                ofSetLineWidth(lineS);
                lineRs.draw();
                ofPopStyle();
                
            }
            else {
                ofPushStyle();
                ofSetLineWidth(lineS);
                ofLine(ptA, ptB);
                ofPopStyle();
                
            }
        }
        
        else {
            ofPoint pt = center.getPointFor(x,y,w,h);
            ofPolyline line;
            for (int i = 0; i < 30; i++){
                float angle = startAngle + ofMap(i, 0, 29, 0, PI/2);
                line.addVertex( pt + radius * ofPoint(cos(angle), sin(angle)));
            }
            ofPushStyle();
            ofSetLineWidth(lineS);
            line.draw();
            ofPopStyle();
        }
    }
    
};

class letter {
    
public:
    
    vector < letterShape > shapes;
    float kerning;
    void draw( float x, float y, float w, float h, int multiLine, int r, float dist, bool horAltIn){
        
        
        for (int i = 0; i < shapes.size(); i++){
            shapes[i].draw(x + (w * kerning),y,w,h, multiLine, r, dist, horAltIn);
        }
        
    }
};

class hashMono {
    
public:
    
    void setup();
    void update();
    void draw(string letter,
              float x,
              float y,
              float width,
              float height,
              int multiLine,
              int r,
              float dist,
              bool horAltIn);
    
    letter A;
    letter B;
    letter C;
    letter D;
    letter E;
    letter F;
    letter G;
    letter H;
    letter I;
    letter J;
    letter K;
    letter L;
    letter M;
    letter N;
    letter O;
    letter P;
    letter Q;
    letter R;
    letter S;
    letter T;
    letter U;
    letter V;
    letter W;
    letter X;
    letter Y;
    letter Z;
    
    
};
