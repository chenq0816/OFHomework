#include "ofApp.h"
#include "Box.hpp"


//--------------------------------------------------------------
void ofApp::setup(){
    gui.setup();
    gui.add(Boxsize.setup("Box Size", 1, .5, 2));
    gui.add(lsc.setup("Star Color1", 1, .001, 1));
    gui.add(lsc2.setup("Star Color2", 1, .001, 1));
    gui.add(lsc3.setup("Star Color3", 1, .8, 1));
    

      star.load("star.png");
    ofSetBackgroundColor(0);
    ofSetFrameRate(60);
    

    ofSetVerticalSync(true);

    cam.setOrientation( ofVec3f(65,-10,-10));

    cam.setDistance(800);

    //cam.setPosition( ofVec3f(-ofGetWidth() * 0.5, 0,0));
    
    for(int i = 0; i <20000; i++){
        Box b;
        mybox.push_back(b);
        mybox[i].setup(ofPoint(ofRandom(-ofGetWidth() * cos(i) *0.5,ofGetWidth()) * cos(i)*0.5,ofRandom(-ofGetHeight() * sin(i)*0.5,ofGetHeight() * sin(i)*0.5),0));

    }
    
    
    
   
    ofEnableAlphaBlending();
    
    rotationX = 0.0;
    rotationY = 0.0;
    rotationZ = 0.0;
    

    
    
    
    
    
 
    
}


//--------------------------------------------------------------
void ofApp::update(){

        float time = ofGetElapsedTimef();
    rotationZ = rotationZ + ofRandom(5,10);
        rotationX = rotationX + ofRandom(5,10);
        rotationY = rotationY + ofRandom(5,10);
    
    if (star2 == 1){
 for(int i = 0; i <12000; i++){
     
     
     ofPoint noiseReadPos = (mybox[i].pos + mybox[i].noiseRandomOffset);
     
     ofPoint forceP(0,0,0);
     forceP.x +=ofSignedNoise(noiseReadPos.x, noiseReadPos.y, time);
     forceP.y +=ofSignedNoise(noiseReadPos.y, time, noiseReadPos.z);
     forceP.z +=ofSignedNoise(time,noiseReadPos.z, noiseReadPos.x);

     
     mybox[i].addAttractionForce(ofPoint(0, 0,0),300,.01);
     mybox[i].addForce(forceP);
     mybox[i].update();
 }
    }
    
    for(int n = 0; n <20; n++){
        
        constellation[n] = constellation[n] + ofPoint(2,20,2);
//        constellation[n] = constellation[n] + ofPoint(ofRandom(-1,1), ofRandom(-1,1), ofRandom(-1,1));

    }
        
}




//--------------------------------------------------------------
void ofApp::draw(){
    
    cam.begin();
//    ofEnableDepthTest();

    ofDisableDepthTest();
    star.draw(-1920/2, -1080/2, 0);
    
    ofSetColor(255);
    ofEnableDepthTest();

    ofPushMatrix();
        ofRotateYDeg(90);
        ofDrawGridPlane();
    ofPopMatrix();
    
    ofPushMatrix();

    
    ofSetColor(255, 255, 255, 100);
    
    ofTranslate(-400, 200,200);
    
        ofRotateXDeg(rotationX);
        ofRotateYDeg(rotationY);
    ofRotateZDeg(rotationZ);
        ofDrawBox(0,0,0,30);
        ofPopMatrix();
    
     ofPushMatrix();
    ofTranslate(-300, -300,10);
    ofRotateXDeg(rotationX * 0.5);
    ofRotateYDeg(rotationY * 0.5);
    ofRotateZDeg(rotationZ * 0.5);
        ofDrawBox(0,0,0,80);
    ofPopMatrix();
    
    
    ofPushMatrix();
    ofTranslate(500, 1300,400);
    ofRotateXDeg((rotationX) * 2);
    ofRotateYDeg((rotationY) * 2);
    ofRotateZDeg((rotationZ) * 2);
    ofDrawBox(0,0,0,50);
    ofPopMatrix();
    
    
    ofPushMatrix();
    ofTranslate(800, 1300,200);
    ofRotateXDeg((rotationX) * 4);
    ofRotateYDeg((rotationY) * 4);
    ofRotateZDeg((rotationZ) * 4);
    ofDrawBox(0,0,0,50);
    ofPopMatrix();
    
    
    
    ofPushMatrix();
     ofTranslate(600, 200,-100);
    ofRotateXDeg(rotationX);
    ofRotateYDeg(rotationY);
    ofRotateZDeg(rotationZ);
    ofDrawBox(0,0,0,60);
    ofPopMatrix();
    
    ofPushMatrix();
    ofTranslate(800, 200,-100);
    ofRotateXDeg((rotationX) * 2);
    ofRotateYDeg((rotationY) * 2);
    ofRotateZDeg((rotationZ) * 2);
    ofDrawBox(0,0,0,30);
    ofPopMatrix();
    
    
    
   //star.draw(-400, -100,-50);
    
    ofSetColor(255);
     ofDrawSphere(-800,900, 0, 20);
    
    ofPushMatrix();
    ofTranslate(-800,900, 0);
    ofRotateZDeg(rotationZ);
      ofSetColor(136,227,255);
    ofDrawSphere(-100,100, 0, 5);
       ofDrawSphere(-50,100, 0, 5);
    ofPopMatrix();
    
    
    ofNoFill();
    
    ofSetColor(200,180,255);
     ofPushMatrix();
    ofTranslate(1200,400, -800);
    ofRotateZDeg(rotationZ);
    ofDrawSphere(0,0, 0, 90);
       ofPopMatrix();
    
    ofPushMatrix();
    ofTranslate(1200,400, -800);
    ofRotateZDeg(rotationZ);
    ofSetColor(255);
    ofDrawSphere(-100,100, 0, 15);
    ofDrawSphere(-250,100, 0, 15);
    ofPopMatrix();
    
    
    

    for(int i = 0; i <12000; i++){

        

        ofPushMatrix();
        ofSetColor(ofRandom(180,240) * lsc   , ofRandom(182,200) * lsc2, 255 * lsc3);

        mybox[i].draw();
        ofSetColor(255);
        ofNoFill();

        
        ofTranslate(0, 0,0);
        ofRotateZDeg(rotationZ);
        ofDrawSphere(0,0, 0, 80 * Boxsize);

        ofFill();
        ofPopMatrix();

    

           }
    if (star1 == 1){
        
    
    for(int n = 0; n < 7; n++){
       

        ofDrawSphere(constellation[n].x, constellation[n].y, constellation[n].z, 5);
            ofDrawLine(constellation[n].x, constellation[n].y, constellation[n].z,constellation[n + 1].x, constellation[n +1].y, constellation[n +1].z);
    
    }
    }

 
    
    cam.end();
    ofDisableDepthTest();
    gui.draw();

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    star1 = star1 * -1;
//    star2 = star2 * -1;
    for(int n = 0; n <20; n++){
        

        
        constellation[n] = ofPoint(stella1,stella2,stella3);
        stella1 = 0.4 * ofRandom(-ofGetWidth()/2,ofGetWidth()/2);
        stella2 = 0.4 * ofRandom(-ofGetHeight()/2,0);
        stella3 = 0.4 * ofRandom(-500,500);
        
        
        
        
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
