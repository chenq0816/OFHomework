#include "ofApp.h"
#include "Ball.hpp"

//--------------------------------------------------------------
void ofApp::setup(){
//    for(int i = 0; i<100; i++){
//        BoxPos.push_back(ofPoint(ofRandom(-10,10),ofRandom(-10,10),ofRandom(-10,10)));
//    }
    
     n = -1;
    
    light.setPosition(10, 10, 10);
    light.enable();
    
    for(int o = 0; o < 100; o++){
        
        ofPoint point(ofRandom(0,255),ofRandom(0,255),ofRandom(0,255));
        ballcolor.push_back(point);
       
//        ofSetColor(ofRandom(0,255),ofRandom(0,255),ofRandom(0,255));

    }

    
    for(int i = 0; i <100; i++){
        Ball b;
        myball.push_back(b);
//        myball[i].setup(ofPoint(ofRandom(-1, 1),ofRandom(-2, 2), ofRandom(0,20)));
        myball[i].setup(ofPoint(0,0,0));

                        
        
    }
    cam.setPosition(0,0,80);
    ofSetBackgroundColor(0);
    
    rotationX = 0.0;
    rotationY = 0.0;
    rotationZ = 0.0;
    
    ofEnableDepthTest();
    ofEnableAlphaBlending();
    ofSetVerticalSync(true);
    
    soundStream.printDeviceList();
    
    int bufferSize = 256;
    
    
    bufferCounter = 0;
    smoothedVol = 0.0;
    scaledVol = 0.0;
    
    
    ofSoundStreamSettings settings;
    auto devices = soundStream.getMatchingDevices("default");
    if(!devices.empty()){
        settings.setInDevice(devices[0]);
    }
    settings.setInListener(this);
    settings.sampleRate = 44100;
    settings.numOutputChannels = 0;
    settings.numInputChannels = 2;
    settings.bufferSize = bufferSize;
    soundStream.setup(settings);
    
    
    
    
    
    
    
    left.assign(bufferSize, 0.0);
    right.assign(bufferSize, 0.0);
//    volume.assign(boxPos.size(), 0.0);
}

//--------------------------------------------------------------
void ofApp::update(){
    
    scaledVol = ofMap(smoothedVol, 0, 0.17, 0, 3, true);
    
    rotationZ = (rotationZ + 0.2*(scaledVol+.1)*45);
    rotationX = (rotationX + 0.2*(scaledVol+.1)*45);
    rotationY = (rotationY + 0.2*(scaledVol+.1)*45);
    
//    rotationZ = (rotationZ + 0.2);
//    rotationX = (rotationX + 0.2);
//    rotationY = (rotationY + 0.2);
    
    for(int i = 0; i<100;i++){
           ofPoint forceP(0,0,0);
        myball[i].addForce(forceP);
        myball[i].update();
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    cam.begin();
//    for(int i = 0; i<100; i++){
//        
//        BoxPos[i].x = BoxPos[i].x + 0.1;
//        
//        
//        ofBoxPrimitive box;
////        box.set(ofRandom(0,1));
//        box.set(1);
//        box.setPosition(BoxPos[i]);
//        box.draw();
//    }
    
//    ofLog() << scaledVol;
    

    
    
    
    
    for(int i = 0; i < 100; i++){
        ofSetColor(ballcolor[i].x, ballcolor[i].y, ballcolor[i].z);
               myball[i].draw();
        //        if(myball[i].pos.x > 15 || myball[i].pos.x < -15){
        //            myball[i].addForce(ofPoint(-.001,0,0));
        //        }
        float diff = (myball[i].pos - ofPoint(0,0,0)).length();
        if(diff > 15){
            myball[i].vel = -myball[i].vel;
        }
        
    }

    
    ofPushMatrix();
    ofSetColor(255, 255, 255, 100);
    
    ofTranslate(0, 0, 0);
    
    ofRotateXDeg(rotationX);
    ofRotateYDeg(rotationY);
    ofRotateZDeg(rotationZ);
    ofNoFill();
    ofSetLineWidth(6);
    ofDrawBox(0,0,0,30);
    ofPopMatrix();
    ofFill();
   
    
    if( n == 1){
        
        ofPoint Pos2;
        ofPoint PosO = ofPoint(0,0,80);
        
        
        if(lel < 1)
        lel = lel + 0.01;
        
        Pos2 = (1-lel) * PosO + lel*myball[lookAtMe].pos;
        
        cam.setPosition(Pos2);
        
        ofLog()<<Pos2;
//    cam.setPosition(myball[n].pos);

    }else if(n == -1){
        ofPoint Pos3;
        ofPoint PosO = ofPoint(0,0,80);

        if(lel2 < 1)
            lel2 = lel2 + 0.0001;
        Pos3 =(1-lel2) * cam.getPosition() + lel2*PosO;

        cam.setPosition(Pos3);
    }
    cam.end();

}

void ofApp::audioIn(ofSoundBuffer & input){
    
    float curVol = 0.0;
    
    // samples are "interleaved"
    int numCounted = 0;
    
    //lets go through each sample and calculate the root mean square which is a rough way to calculate volume
    for (size_t i = 0; i < input.getNumFrames(); i++){
        left[i]		= input[i*2]*0.5;
        right[i]	= input[i*2+1]*0.5;
        
        curVol += left[i] * left[i];
        curVol += right[i] * right[i];
        numCounted+=2;
    }
    
    //this is how we get the mean of rms :)
    curVol /= (float)numCounted;
    
    // this is how we get the root of rms :)
    curVol = sqrt( curVol );
    
    smoothedVol *= 0.93;
    smoothedVol += 0.07 * curVol;
    
    bufferCounter++;




}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
//    lookAtMe= ofRandom(0,myball.size()-1);
////        cam.lookAt(myball[lookAtMe].pos);
//    cam.setPosition(myball[lookAtMe].pos);
    
    lookAtMe = ofRandom(0, myball.size()-1);
    n = n * -1;
    lel = 0.01;
     lel2 = 0.01;
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
    for(int i = 0; i < myball.size();i++){
        myball[i].goToStart = true;
    }
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
