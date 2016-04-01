#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {
	ofSetLogLevel(OF_LOG_VERBOSE);
	serialOK = false;
	sender.setup("192.168.10.255", 5250);
	playlistMode = false;
	serial.listDevices();
//	if (!serial.setup())
//		ofLogWarning(__func__) << "ofSerial Not Ready";
}

//--------------------------------------------------------------
void ofApp::update() {

}

//--------------------------------------------------------------
void ofApp::draw() {

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key) {
	switch (key) {
	case 'p':
		sendMessage("/all/play");
		break;
	case ' ':
		sendMessage("/key/space");
		break;
	case OF_KEY_DOWN:
		sendMessage("/key/down");
		break;
	case OF_KEY_UP:
		sendMessage("/key/up");
		break;
	case OF_KEY_RETURN:
		sendMessage("/key/return");
		break;
	case OF_KEY_BACKSPACE:
		sendMessage("/key/backspace");
		break;
	case OF_KEY_F1:
		if (playlistMode){
			sendMessage("/defaultPlayer/playlistSelectionMode/enter");
		}else{
			sendMessage("/defaultPlayer/playlistSelectionMode/quit");
		}
		playlistMode = !playlistMode;
		break;
	case 'r':
		sendMessage("/all/restart");
		break;
	default:
		break;
	}
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key) {

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y) {

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button) {

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button) {

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button) {

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y) {

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y) {

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h) {

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg) {

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo) {

}

void ofApp::sendMessage(std::string address, std::string msg) {
	ofxOscMessage message;
	message.setAddress(address);
	message.addStringArg(msg);
	sender.sendMessage(message);
}

void ofApp::exit() {
	ofLogWarning(__func__) << "exiting...";
//	if(serialOK)
//	serial.close();
}
