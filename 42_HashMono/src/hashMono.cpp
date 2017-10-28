

#include "hashMono.h"

//---------------------------------------------------------------
void hashMono::setup(){
    
    float unitX = 0.071;
    float w2 = 2 * unitX;
    float w3 = 3 * unitX;
    float w6 = 6 * unitX;
    float w7 = 7 * unitX;
    float w10 = 10 * unitX;
    float w12 = 12 * unitX;

    float unitY = 0.05;
    float h9 = 9 * unitY;
    float h10 = 10 * unitY;
    float h11 = 11 * unitY;
    float h14 = 14 * unitY;

    float r1 =  15;
    float r2 =  20;

    letterShape tempA;
        tempA.bIsLine = true; // l vert
        tempA.pts[0].set(1,0, 1, 0,w7,0, 0,0);
        tempA.pts[1].set(1,0, 1, 0,0,0, 1,0);
        A.shapes.push_back(tempA);
        
        tempA.bIsLine = true; // r ver
        tempA.pts[0].set(1,0, 1, 0,w7,0, 0,0);
        tempA.pts[1].set(1,0, 1, 0,1,0, 1,0);
        A.shapes.push_back(tempA);
        
        tempA.bIsLine = true; // hor
        tempA.pts[0].set(1,0, 1, 0,w2,0, h14,0);
        tempA.pts[1].set(1,0, 1, 0,w12,0, h14,0);
        A.shapes.push_back(tempA);
    
    letterShape tempB;
        tempB.bIsLine = true; // l vert
        tempB.pts[0].set(1,0, 1, 0,0,0, 0,0);
        tempB.pts[1].set(1,0, 1, 0,0,0, 1,0);
        B.shapes.push_back(tempB);
    
        tempB.bIsLine = true; // r vert
        tempB.pts[0].set(1,0, 1, 0,w12,0, 0,r1);
        tempB.pts[1].set(1,0, 1, 0,w12,0, h10,-r1);
        B.shapes.push_back(tempB);
    
        tempB.bIsLine = true; // t hor
        tempB.pts[0].set(1, 0, 1, 0, 0, 0, 0, 0);
        tempB.pts[1].set(1, 0, 1, 0, w12, -r1, 0, 0);
        B.shapes.push_back(tempB);
    
        tempB.bIsLine = true; // m hor
        tempB.pts[0].set(1, 0, 1, 0, 0, 0, h10, 0);
        tempB.pts[1].set(1, 0, 1, 0, w12, -r1, h10, 0);
        B.shapes.push_back(tempB);
    
        tempB.bIsLine = false; // tr
        tempB.center.set(1,0, 1, r1, w12,-r1, 0,0);
        tempB.startAngle = 3*PI/2.0;
        tempB.radius = r1;
        B.shapes.push_back(tempB);
    
        tempB.bIsLine = false; // mr
        tempB.center.set(1,0, 1, -r1, w12, -r1, h10, 0);
        tempB.startAngle = 0;
        tempB.radius = r1;
        B.shapes.push_back(tempB);
    
        tempB.bIsLine = false; // mr2
        tempB.center.set(1,0, 1, r1, w12,-r1, h10,0);
        tempB.startAngle = 3*PI/2.0;
        tempB.radius = r1;
        B.shapes.push_back(tempB);
    
        tempB.bIsLine = true; // r vert2
        tempB.pts[0].set(1,0, 1, 0,w12,0, h10,r1);
        tempB.pts[1].set(1,0, 1, 0,w12,0, 1,-r1);
        B.shapes.push_back(tempB);
    
        tempB.bIsLine = false; // mr
        tempB.center.set(1,0, 1, -r1, w12, -r1, 1, 0);
        tempB.startAngle = 0;
        tempB.radius = r1;
        B.shapes.push_back(tempB);
    
        tempB.bIsLine = true; // b hor
        tempB.pts[0].set(1, 0, 1, 0, 0, 0, 1, 0);
        tempB.pts[1].set(1, 0, 1, 0, w12, -r1, 1, 0);
        B.shapes.push_back(tempB);
    
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
        tempD.bIsLine = true; // l vert
        tempD.pts[0].set(1,0, 1, 0,0,0, 0,0);
        tempD.pts[1].set(1,0, 1, 0,0,0, 1,0);
        D.shapes.push_back(tempD);
        
        tempD.bIsLine = true; // r vert
        tempD.pts[0].set(1,0, 1, 0,w12,0, 0,r2);
        tempD.pts[1].set(1,0, 1, 0,w12,0, 1,-r2);
        D.shapes.push_back(tempD);
    
        tempD.bIsLine = true; // t hor
        tempD.pts[0].set(1, 0, 1, 0, 0, 0, 0, 0);
        tempD.pts[1].set(1, 0, 1, 0, w12, -r2, 0, 0);
        D.shapes.push_back(tempD);
        
        tempD.bIsLine = false; // tr
        tempD.center.set(1,0, 1, r2, w12,-r2, 0,0);
        tempD.startAngle = 3*PI/2.0;
        tempD.radius = r2;
        D.shapes.push_back(tempD);
        
        tempD.bIsLine = false; // mr
        tempD.center.set(1,0, 1, -r2, w12, -r2, 1, 0);
        tempD.startAngle = 0;
        tempD.radius = r2;
        D.shapes.push_back(tempD);
    
        tempD.bIsLine = true; // b hor
        tempD.pts[0].set(1, 0, 1, 0, 0, 0, 1, 0);
        tempD.pts[1].set(1, 0, 1, 0, w12, -r2, 1, 0);
        D.shapes.push_back(tempD);
    
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
        tempE.pts[0].set(1,0, 1, 0,0,0, h9,0);
        tempE.pts[1].set(1,0, 1, 0,w10,0, h9,0);
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
        tempF.pts[0].set(1,0, 1, 0,0,0, h9,0);
        tempF.pts[1].set(1,0, 1, 0,w10,0, h9,0);
        F.shapes.push_back(tempF);
    
    letterShape tempG;
        tempG.bIsLine = true; // l vert
        tempG.pts[0].set(1,0, 1, r1,0,0, 0,0);
        tempG.pts[1].set(1,0, 1, 0,0,0, 1,-r1);
        G.shapes.push_back(tempG);
    
        tempG.bIsLine = true; // t hor
        tempG.pts[0].set(1, r1, 1, 0, 0, 0, 0, 0);
        tempG.pts[1].set(1, 0, 1, 0, w12, -r1, 0, 0);
        G.shapes.push_back(tempG);
    
        tempG.bIsLine = true; //b hor
        tempG.pts[0].set(1, r1, 1, 0, 0, 0, 1, 0);
        tempG.pts[1].set(1, 0, 1, 0, w12, -r1, 1, 0);
        G.shapes.push_back(tempG);
    
        tempG.bIsLine = false; // tl
        tempG.center.set(1,r1, 1, r1,0,0, 0,0);
        tempG.startAngle = PI;
        tempG.radius = r1;
        G.shapes.push_back(tempG);
    
        tempG.bIsLine = false; // tr
        tempG.center.set(1,0, 1, r1, w12,-r1, 0,0);
        tempG.startAngle = 3*PI/2.0;
        tempG.radius = r1;
        G.shapes.push_back(tempG);
    
        tempG.bIsLine = true; // m hor
        tempG.pts[0].set(1, 0, 1, 0, w7, 0, h11, 0);
        tempG.pts[1].set(1, 0, 1, 0, w12, 0, h11, 0);
        G.shapes.push_back(tempG);
    
        tempG.bIsLine = true; // r vert
        tempG.pts[0].set(1,0, 1, 0,w12,0, h11,0);
        tempG.pts[1].set(1,0, 1, 0,w12, 0, 1,0);
        G.shapes.push_back(tempG);
    
        tempG.bIsLine = false; // bl
        tempG.center.set(1,r1, 1, 0,0,0, 1,-r1);
        tempG.startAngle = PI/2.0;
        tempG.radius = r1;
        G.shapes.push_back(tempG);
    
        tempG.bIsLine = false; // br
        tempG.center.set(1,0, 1, -r2, w12, -r2, 1, 0);
        tempG.startAngle = 0;
        tempG.radius = r2;
        G.shapes.push_back(tempG);
    
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
        tempH.pts[0].set(1,0, 1, 0,0,0, h10,0);
        tempH.pts[1].set(1,0, 1, 0,w12,0, h10,0);
        H.shapes.push_back(tempH);
    
    letterShape tempI;
        tempI.bIsLine = true; // c vert
        tempI.pts[0].set(1,0, 1, 0,w6,0, 0,0);
        tempI.pts[1].set(1,0, 1, 0,w6,0, 1,0);
        I.shapes.push_back(tempI);
    
        tempI.bIsLine = true; // t hor
        tempI.pts[0].set(1,0, 1, 0,0,0, 0 ,0);
        tempI.pts[1].set(1,0, 1, 0,w12,0, 0,0);
        I.shapes.push_back(tempI);
   
        tempI.bIsLine = true; // t hor
        tempI.pts[0].set(1,0, 1, 0,0,0, 1 ,0);
        tempI.pts[1].set(1,0, 1, 0,w12,0, 1,0);
        I.shapes.push_back(tempI);
    
    letterShape tempJ;
        tempJ.bIsLine = true; // r ver
        tempJ.pts[0].set(1,0, 1, 0,w12,0, 0,0);
        tempJ.pts[1].set(1,0, 1, 0,w12,0, 1,-r1);
        J.shapes.push_back(tempJ);
    
        tempJ.bIsLine = true; //b hor
        tempJ.pts[0].set(1, r1, 1, 0, 0, 0, 1, 0);
        tempJ.pts[1].set(1, 0, 1, 0, w12, -r1, 1, 0);
        J.shapes.push_back(tempJ);
    
        tempJ.bIsLine = false; // bl
        tempJ.center.set(1,r1, 1, 0,0,0, 1,-r1);
        tempJ.startAngle = PI/2.0;
        tempJ.radius = r1;
        J.shapes.push_back(tempJ);
    
        tempJ.bIsLine = false; // br
        tempJ.center.set(1,0, 1, -r1, w12, -r1, 1, 0);
        tempJ.startAngle = 0;
        tempJ.radius = r1;
        J.shapes.push_back(tempJ);
    
    letterShape tempK;
    
    letterShape tempL;
        tempL.bIsLine = true; // l vert
        tempL.pts[0].set(1,0, 1, 0,0,0, 0,0);
        tempL.pts[1].set(1,0, 1, 0,0,0, 1,0);
        L.shapes.push_back(tempL);
    
        tempL.bIsLine = true; // b hor
        tempL.pts[0].set(1,0, 1, 0,0,0, 1,0);
        tempL.pts[1].set(1,0, 1, 0,w12,0, 1,0);
        L.shapes.push_back(tempL);
    
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
        tempP.bIsLine = true; // l vert
        tempP.pts[0].set(1,0, 1, 0,0,0, 0,0);
        tempP.pts[1].set(1,0, 1, 0,0,0, 1,0);
        P.shapes.push_back(tempP);
    
        tempP.bIsLine = true; // r vert
        tempP.pts[0].set(1,0, 1, 0,w12,0, 0,r1);
        tempP.pts[1].set(1,0, 1, 0,w12,0, h11,-r1);
        P.shapes.push_back(tempP);
    
        tempP.bIsLine = true; // t hor
        tempP.pts[0].set(1, 0, 1, 0, 0, 0, 0, 0);
        tempP.pts[1].set(1, 0, 1, 0, w12, -r1, 0, 0);
        P.shapes.push_back(tempP);
    
        tempP.bIsLine = true; // m hor
        tempP.pts[0].set(1, 0, 1, 0, 0, 0, h11, 0);
        tempP.pts[1].set(1, 0, 1, 0, w12, -r1, h11, 0);
        P.shapes.push_back(tempP);
    
        tempP.bIsLine = false; // tr
        tempP.center.set(1,0, 1, r1, w12,-r1, 0,0);
        tempP.startAngle = 3*PI/2.0;
        tempP.radius = r1;
        P.shapes.push_back(tempP);
    
        tempP.bIsLine = false; // mr
        tempP.center.set(1,0, 1, -r1, w12, -r1, h11, 0);
        tempP.startAngle = 0;
        tempP.radius = r1;
        P.shapes.push_back(tempP);
    
    letterShape tempQ;
    
    letterShape tempR;
        tempR.bIsLine = true; // l vert
        tempR.pts[0].set(1,0, 1, 0,0,0, 0,0);
        tempR.pts[1].set(1,0, 1, 0,0,0, 1,0);
        R.shapes.push_back(tempR);
    
        tempR.bIsLine = true; // r vert
        tempR.pts[0].set(1,0, 1, 0,w12,0, 0,r1);
        tempR.pts[1].set(1,0, 1, 0,w12,0, h11,-r1);
        R.shapes.push_back(tempR);
    
        tempR.bIsLine = true; // t hor
        tempR.pts[0].set(1, 0, 1, 0, 0, 0, 0, 0);
        tempR.pts[1].set(1, 0, 1, 0, w12, -r1, 0, 0);
        R.shapes.push_back(tempR);
    
        tempR.bIsLine = true; // m hor
        tempR.pts[0].set(1, 0, 1, 0, 0, 0, h11, 0);
        tempR.pts[1].set(1, 0, 1, 0, w12, -r1, h11, 0);
        R.shapes.push_back(tempR);
    
        tempR.bIsLine = false; // tr
        tempR.center.set(1,0, 1, r1, w12,-r1, 0,0);
        tempR.startAngle = 3*PI/2.0;
        tempR.radius = r1;
        R.shapes.push_back(tempR);
    
        tempR.bIsLine = false; // mr
        tempR.center.set(1,0, 1, -r1, w12, -r1, h11, 0);
        tempR.startAngle = 0;
        tempR.radius = r1;
        R.shapes.push_back(tempR);
    
        tempR.bIsLine = true; // r dia
        tempR.pts[0].set(1,0, 1, 0,w12, -r1, h11,0);
        tempR.pts[1].set(1,0, 1, 0,w12, 0, 1,0);
        R.shapes.push_back(tempR);
    
    letterShape tempS;
    
    letterShape tempT;
        tempT.bIsLine = true; // l vert
        tempT.pts[0].set(1,0, 1, 0,w7,0, 0,0);
        tempT.pts[1].set(1,0, 1, 0,w7,0, 1,0);
        T.shapes.push_back(tempT);
    
        tempT.bIsLine = true; // t hor
        tempT.pts[0].set(1,0, 1, 0,0,0, 0 ,0);
        tempT.pts[1].set(1,0, 1, 0,1,0, 0,0);
        T.shapes.push_back(tempT);
    
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
