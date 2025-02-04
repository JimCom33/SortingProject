#include "ofApp.h"
#include <cstdlib>
#include <ctime>
#include <vector>


//TOUT LES SORT DE TRI ON ÉTÉ FAIT AVEC L'AIDE DES NOTES DE COURS SEMAINE 4


//--------------------------------------------------------------
void ofApp::setup(){
	std::srand(std::time(0));
	generateRandomNumbers();
}

void ofApp::generateRandomNumbers() {
	circles.clear();
	for (int i = 0; i < 5; i++) {
		int n = 10 + std::rand() % 91;
		circles.push_back(n);
	}
}

void ofApp::triBulles() {
	bool swapped;
	for (int i = 0; i < circles.size() - 1; i++) {
		swapped = false;
		for (int j = 0; j < circles.size() - i - 1; j++) {
			if (circles[j] > circles[j + 1]) {
				std::swap(circles[j], circles[j + 1]);
				swapped = true;
			}
		}
		if (!swapped) break;
	}
}

void ofApp::triInsertion() {
	for (int i = 1; i < circles.size(); i++) {
		int key = circles[i];
		int j = i - 1;
		while (j >= 0 && circles[j] > key) {
			circles[j + 1] = circles[j];
			j--;
		}
		circles[j + 1] = key;
	}
}


void ofApp::triFusion(vector<int>& arr, int left, int right) {
	if (left >= right) return;

	int mid = left + (right - left) / 2;
	triFusion(arr, left, mid);
	triFusion(arr, mid + 1, right);
	fusion(arr, left, mid, right);
}

void ofApp::fusion(vector<int>& arr, int left, int mid, int right) {
    vector<int> leftPart(arr.begin() + left, arr.begin() + mid + 1);
    vector<int> rightPart(arr.begin() + mid + 1, arr.begin() + right + 1);

    int i = 0, j = 0, k = left;
    while (i < leftPart.size() && j < rightPart.size()) {											// aide chatgpt
        if (leftPart[i] <= rightPart[j]) {
            arr[k++] = leftPart[i++];
        } else {
            arr[k++] = rightPart[j++];
        }
    }
    while (i < leftPart.size()) arr[k++] = leftPart[i++];
    while (j < rightPart.size()) arr[k++] = rightPart[j++];
}

void ofApp::triRapid(std::vector<int>& arr, int low, int high) {
	if (low < high) {
		int pivot = partition(arr, low, high);
		triRapid(arr, low, pivot - 1);
		triRapid(arr, pivot + 1, high);
	}
}

int ofApp::partition(std::vector<int>& arr, int low, int high) {
	int pivot = arr[high];
	int i = low - 1;
	for (int j = low; j < high; j++) {
		if (arr[j] < pivot) {
			i++;
			std::swap(arr[i], arr[j]);
		}
	}
	std::swap(arr[i + 1], arr[high]);
	return i + 1;
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
	float spacing = ofGetWidth() / 6;
	float y = ofGetHeight() / 2;


	for (int i = 0; i < circles.size(); i++) {
		float x = (i + 1) * spacing;
		float radius = circles[i];

		ofSetColor(100, 100, 255);
		ofDrawCircle(x, y, circles[i]);

		ofSetColor(200);
		string text = ofToString(radius);	//avec aide de chatgpt
		ofDrawBitmapString(ofToString(radius), x - 5, y + 5);
	}
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
	if (key == 'r' || key == 'R') {
		generateRandomNumbers();
	}
	else if(key == 'b' || key == 'B') {
		triBulles();
	}
	else if (key == 'i' || key == 'I') {
		triInsertion();
	}
	else if (key == 'm' || key == 'M') {
		triFusion(circles, 0, circles.size() - 1);
	}
	else if (key == 'q' || key == 'Q') {
		triRapid(circles, 0, circles.size() - 1);
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
