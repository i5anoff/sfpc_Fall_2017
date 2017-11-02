#pragma once

#include "ofMain.h"
#define LETTERARGUMENTS x, y, width, height, multiLine, r, dist

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
    
    // if line!
    letterPoint pts[2];
    
    // if curve:
    letterPoint center;
    float radius;
    float startAngle;
    
    void draw(float x, float y, float w, float h, float multiLine, int r, float dist){
        
        float lineWidth = 1;
        float lineWidthStrong = 15;
        
            if (bIsLine){
                
                ofPoint ptA = pts[0].getPointFor(x,y,w,h);
                ofPoint ptB = pts[1].getPointFor(x,y,w,h);
                


                if (bIsMultiLine){
                    
                    for(int i = 0; i < multiLine; i++){
                        ofPushStyle();
                            float tempLw = ofMap(i, 0, multiLine, 2, 0.5);
                            ofSetLineWidth(lineWidth);
                        if (i == 0) ofSetLineWidth(lineWidthStrong);
                        if (i > 1) ofSetColor(120);
                            ofPushMatrix();
                       
                        ofTranslate(x + w * 0.5 + i * (w * dist), y);
//                        if (i > 0) ofScale(-i*0.15, -i*0.15);
                        if (multiLine > 1) ofRotateZ(r*(i*0.5));
                        ofTranslate(i * (w * dist), 0);
                        ofTranslate(-x - (w * 0.5) - i * (w * dist),-y);
                        

                                ofLine(ptA, ptB);
                            ofPopMatrix();
                        ofPopStyle();
                    }

                }else {
                    ofPushStyle();
                        ofSetLineWidth(lineWidth);
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
                    ofSetLineWidth(lineWidth);
                    line.draw();
                ofPopStyle();
            }
    }
    
};

class letter {
    
public:
    
    vector < letterShape > shapes;
    float kerning;
    void draw( float x, float y, float w, float h, int multiLine, int r, float dist){
        
        
        for (int i = 0; i < shapes.size(); i++){
            shapes[i].draw(x + (w * kerning),y,w,h, multiLine, r, dist);
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
              float dist);
    
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

