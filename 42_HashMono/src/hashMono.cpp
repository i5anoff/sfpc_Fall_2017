

#include "hashMono.h"

//---------------------------------------------------------------
void hashMono::setup(){
    
    float unit = 0.071;
    float w12 = 12 * unit;
    float w11 = 11 * unit;

    float h5 = 10 * unit;
    float r1 =  15;
    
    letterShape tempA;
    
    letterShape tempB;
    
    letterShape tempC;
        tempC.bIsLine = true; // l vert
        tempC.pts[0].set(1,0, 1, r1,0,0, 0,0);
        tempC.pts[1].set(1,0, 1, 0,0,0, 1,-r1);
        C.shapes.push_back(tempC);
    
        tempC.bIsLine = true; // t hor
        tempC.pts[0].set(1, r1, 1, 0, 0, 0, 0, 0);
        tempC.pts[1].set(1, 0, 1, 0, w12, -r1, 0, 0);
        C.shapes.push_back(tempC);
    
        tempC.bIsLine = true; //b hor
        tempC.pts[0].set(1, r1, 1, 0, 0, 0, 1, 0);
        tempC.pts[1].set(1, 0, 1, 0, w12, -r1, 1, 0);
        C.shapes.push_back(tempC);
    
        tempC.bIsLine = false; // tl
        tempC.center.set(1,r1, 1, r1,0,0, 0,0);
        tempC.startAngle = PI;
        tempC.radius = r1;
        C.shapes.push_back(tempC);
    
        tempC.bIsLine = false; // tr
        tempC.center.set(1,0, 1, r1, w12,-r1, 0,0);
        tempC.startAngle = 3*PI/2.0;
        tempC.radius = r1;
        C.shapes.push_back(tempC);
    
        tempC.bIsLine = false; // bl
        tempC.center.set(1,r1, 1, 0,0,0, 1,-r1);
        tempC.startAngle = PI/2.0;
        tempC.radius = r1;
        C.shapes.push_back(tempC);
    
        tempC.bIsLine = false; // br
        tempC.center.set(1,0, 1, -r1, w12, -r1, 1, 0);
        tempC.startAngle = 0;
        tempC.radius = r1;
        C.shapes.push_back(tempC);
    
    letterShape tempD;
    
    letterShape tempE;
        tempE.bIsLine = true; // l vert
        tempE.pts[0].set(1,0, 1, 0,0,0, 0,0);
        tempE.pts[1].set(1,0, 1, 0,0,0, 1,0);
        E.shapes.push_back(tempE);

        tempE.bIsLine = true; // t hor
        tempE.pts[0].set(1,0, 1, 0,0,0, 0 ,0);
        tempE.pts[1].set(1,0, 1, 0,w12,0, 0,0);
        E.shapes.push_back(tempE);
    
        tempE.bIsLine = true; // m hor
        tempE.pts[0].set(1,0, 1, 0,0,0, 0.5,0);
        tempE.pts[1].set(1,0, 1, 0,w11,0, 0.5,0);
        E.shapes.push_back(tempE);
    
        tempE.bIsLine = true; // b hor
        tempE.pts[0].set(1,0, 1, 0,0,0, 1,0);
        tempE.pts[1].set(1,0, 1, 0,w12,0, 1,0);
        E.shapes.push_back(tempE);
    
    letterShape tempF;
        tempF.bIsLine = true; // l vert
        tempF.pts[0].set(1,0, 1, 0,0,0, 0,0);
        tempF.pts[1].set(1,0, 1, 0,0,0, 1,0);
        F.shapes.push_back(tempF);
    
        tempF.bIsLine = true; // t hor
        tempF.pts[0].set(1,0, 1, 0,0,0, 0 ,0);
        tempF.pts[1].set(1,0, 1, 0,w12,0, 0,0);
        F.shapes.push_back(tempF);
    
        tempF.bIsLine = true; // m hor
        tempF.pts[0].set(1,0, 1, 0,0,0, 0.5,0);
        tempF.pts[1].set(1,0, 1, 0,w11,0, 0.5,0);
        F.shapes.push_back(tempF);
    
    letterShape tempG;
    
    letterShape tempH;
        tempH.bIsLine = true; // l vert
        tempH.pts[0].set(1,0, 1, 0,0,0, 0,0);
        tempH.pts[1].set(1,0, 1, 0,0,0, 1,0);
        H.shapes.push_back(tempH);
    
        tempH.bIsLine = true; // r ver
        tempH.pts[0].set(1,0, 1, 0,w12,0, 0,0);
        tempH.pts[1].set(1,0, 1, 0,w12,0, 1,0);
        H.shapes.push_back(tempH);
    
        tempH.bIsLine = true; // hor
        tempH.pts[0].set(1,0, 1, 0,0,0, 0.5,0);
        tempH.pts[1].set(1,0, 1, 0,w12,0, 0.5,0);
        H.shapes.push_back(tempH);
    
    letterShape tempI;
    
    letterShape tempJ;
    
    letterShape tempK;
    
    letterShape tempL;
    
    letterShape tempM;
    
    letterShape tempN;
    
    letterShape tempO;
        tempO.bIsLine = true; // l vert
        tempO.pts[0].set(1,0, 1, r1,0,0, 0,0);
        tempO.pts[1].set(1,0, 1, 0,0,0, 1,-r1);
        O.shapes.push_back(tempO);
    
        tempO.bIsLine = true; // r ver
        tempO.pts[0].set(1,0, 1, r1,w12,0, 0,0);
        tempO.pts[1].set(1,0, 1, 0,w12,0, 1,-r1);
        O.shapes.push_back(tempO);
    
        tempO.bIsLine = true; // t hor
        tempO.pts[0].set(1, r1, 1, 0, 0, 0, 0, 0);
        tempO.pts[1].set(1, 0, 1, 0, w12, -r1, 0, 0);
        O.shapes.push_back(tempO);
    
        tempO.bIsLine = true; //b hor
        tempO.pts[0].set(1, r1, 1, 0, 0, 0, 1, 0);
        tempO.pts[1].set(1, 0, 1, 0, w12, -r1, 1, 0);
        O.shapes.push_back(tempO);
    
        tempO.bIsLine = false; // tl
        tempO.center.set(1,r1, 1, r1,0,0, 0,0);
        tempO.startAngle = PI;
        tempO.radius = r1;
        O.shapes.push_back(tempO);
    
        tempO.bIsLine = false; // tr
        tempO.center.set(1,0, 1, r1, w12,-r1, 0,0);
        tempO.startAngle = 3*PI/2.0;
        tempO.radius = r1;
        O.shapes.push_back(tempO);
    
        tempO.bIsLine = false; // bl
        tempO.center.set(1,r1, 1, 0,0,0, 1,-r1);
        tempO.startAngle = PI/2.0;
        tempO.radius = r1;
        O.shapes.push_back(tempO);
    
        tempO.bIsLine = false; // br
        tempO.center.set(1,0, 1, -r1, w12, -r1, 1, 0);
        tempO.startAngle = 0;
        tempO.radius = r1;
        O.shapes.push_back(tempO);
    
    letterShape tempP;
    
    letterShape tempQ;
    
    letterShape tempR;
    
    letterShape tempS;
    
    letterShape tempT;
    
    letterShape tempU;
        tempU.bIsLine = true; // l vert
        tempU.pts[0].set(1,0, 1, 0,0,0, 0,0);
        tempU.pts[1].set(1,0, 1, 0,0,0, 1,-r1);
        U.shapes.push_back(tempU);
        
        tempU.bIsLine = true; // r ver
        tempU.pts[0].set(1,0, 1, 0,w12,0, 0,0);
        tempU.pts[1].set(1,0, 1, 0,w12,0, 1,-r1);
        U.shapes.push_back(tempU);
        
        
        tempU.bIsLine = true; //b hor
        tempU.pts[0].set(1, r1, 1, 0, 0, 0, 1, 0);
        tempU.pts[1].set(1, 0, 1, 0, w12, -r1, 1, 0);
        U.shapes.push_back(tempU);
        
        
        tempU.bIsLine = false; // bl
        tempU.center.set(1,r1, 1, 0,0,0, 1,-r1);
        tempU.startAngle = PI/2.0;
        tempU.radius = r1;
        U.shapes.push_back(tempU);
        
        tempU.bIsLine = false; // br
        tempU.center.set(1,0, 1, -r1, w12, -r1, 1, 0);
        tempU.startAngle = 0;
        tempU.radius = r1;
        U.shapes.push_back(tempU);
    
    letterShape tempV;
    
    letterShape tempW;
    
    letterShape tempX;
    
    letterShape tempY;
    
    letterShape tempZ;
    
    
    

    

}


//---------------------------------------------------------------
void hashMono::update(){
}


//---------------------------------------------------------------
void hashMono::draw(string letter, float x, float y, float width, float height){
    if (letter == "A") {
        A.draw(x, y, width, height);
    }
    if (letter == "B") {
        B.draw(x, y, width, height);
    }
    if (letter == "C") {
        C.draw(x, y, width, height);
    }
    if (letter == "D") {
        D.draw(x, y, width, height);
    }
    if (letter == "E") {
        E.draw(x, y, width, height);
    }
    if (letter == "F") {
        F.draw(x, y, width, height);
    }
    if (letter == "G") {
        G.draw(x, y, width, height);
    }
    if (letter == "H") {
        H.draw(x, y, width, height);
    }
    if (letter == "I") {
        I.draw(x, y, width, height);
    }
    if (letter == "J") {
        J.draw(x, y, width, height);
    }
    if (letter == "K") {
        K.draw(x, y, width, height);
    }
    if (letter == "L") {
        L.draw(x, y, width, height);
    }
    if (letter == "M") {
        M.draw(x, y, width, height);
    }
    if (letter == "N") {
        N.draw(x, y, width, height);
    }
    if (letter == "O") {
        O.draw(x, y, width, height);
    }
    if (letter == "P") {
        P.draw(x, y, width, height);
    }
    if (letter == "Q") {
        Q.draw(x, y, width, height);
    }
    if (letter == "R") {
        R.draw(x, y, width, height);
    }
    if (letter == "S") {
        S.draw(x, y, width, height);
    }
    if (letter == "T") {
        T.draw(x, y, width, height);
    }
    if (letter == "U") {
        U.draw(x, y, width, height);
    }
    if (letter == "V") {
        V.draw(x, y, width, height);
    }
    if (letter == "W") {
        W.draw(x, y, width, height);
    }
    if (letter == "X") {
        X.draw(x, y, width, height);
    }
    if (letter == "Y") {
        Y.draw(x, y, width, height);
    }
    if (letter == "Z") {
        Z.draw(x, y, width, height);
    }

}
