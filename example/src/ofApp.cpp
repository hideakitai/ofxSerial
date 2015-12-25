#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup()
{
	 serial.setup("/dev/tty.usbmodem1451", 9600); // mac
//	serial.setup("COM3", 9600); // windows

	serial.setDataBits(OFXSERIAL_DATABIT_8);
//	serial.setDataBits(OFXSERIAL_DATABIT_7);
//	serial.setDataBits(OFXSERIAL_DATABIT_6);
//	serial.setDataBits(OFXSERIAL_DATABIT_5);
	
//	serial.setParity(OFXSERIAL_PARITY_NONE);
	serial.setParity(OFXSERIAL_PARITY_EVEN);
//	serial.setParity(OFXSERIAL_PARITY_ODD);
	
//	serial.setStopBits(OFXSERIAL_STOPBIT_1);
	serial.setStopBits(OFXSERIAL_STOPBIT_2);
}

//--------------------------------------------------------------
void ofApp::update()
{
	while (serial.available()) {
		cout << (char)serial.readByte();
	}
	serial.writeByte((unsigned char)ofGetFrameNum());
}

//--------------------------------------------------------------
void ofApp::draw(){

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
