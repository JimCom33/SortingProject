#pragma once

#include "ofMain.h"
#include "vector"

class ofApp : public ofBaseApp{
	private:
		vector<int> circles;


	public:
		void setup();
		void update();
		void draw();
		void generateRandomNumbers();
		void triBulles();
		void triInsertion();
		void triFusion(std::vector<int>& arr, int left, int right);
		void fusion(std::vector<int>& arr, int left, int mid, int right);
		void triRapid(std::vector<int>& arr, int low, int high);
		int partition(std::vector<int>& arr, int low, int high);

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
		
};
