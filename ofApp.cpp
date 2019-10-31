#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {

	ofSetFrameRate(30);
	ofSetWindowTitle("openframeworks");

	ofBackground(239);
	ofSetBackgroundAuto(false);
	ofSetColor(239);
	ofNoFill();
}

//--------------------------------------------------------------
void ofApp::update() {

	this->mesh_list.clear();

	vector<ofColor> color_list = {ofColor(39), ofColor(239)};
	ofColor color_1, color_2;
	int len = 200;

	for (auto x = 120; x < 720; x += 240) {

		for (auto y = 120; y < 720; y += 240) {

			ofMesh mesh;
			color_1 = color_list[int(ofRandom(color_list.size()))];
			color_2 = color_list[int(ofRandom(color_list.size()))];

			int param = ofRandom(100);

			if (ofRandom(1) < 0.5) {

				mesh.addVertex(glm::vec3(x, y, 0) + glm::vec3(this->make_point(len, param), 0));
				mesh.addColor(color_1);
				mesh.addVertex(glm::vec3(x, y, 0) + glm::vec3(this->make_point(len, param + 2), 0));
				mesh.addColor(color_1);
				mesh.addVertex(glm::vec3(x, y, 0) + glm::vec3(this->make_point(len, 100 - param - 2), 0));
				mesh.addColor(color_2);
				mesh.addVertex(glm::vec3(x, y, 0) + glm::vec3(this->make_point(len, 100 - param), 0));
				mesh.addColor(color_2);
			}
			else {

				mesh.addVertex(glm::vec3(x, y, 0) + glm::vec3(this->make_point(len, param), 0));
				mesh.addColor(color_1);
				mesh.addVertex(glm::vec3(x, y, 0) + glm::vec3(this->make_point(len, param + 2), 0));
				mesh.addColor(color_1);
				mesh.addVertex(glm::vec3(x, y, 0) + glm::vec3(this->make_point(len, 75 - param + 75 - 2), 0));
				mesh.addColor(color_2);
				mesh.addVertex(glm::vec3(x, y, 0) + glm::vec3(this->make_point(len, 75 - param + 75), 0));
				mesh.addColor(color_2);
			}

			mesh.addIndex(0);
			mesh.addIndex(1);
			mesh.addIndex(3);

			mesh.addIndex(1);
			mesh.addIndex(2);
			mesh.addIndex(3);

			this->mesh_list.push_back(mesh);
		}
	}
}

//--------------------------------------------------------------
void ofApp::draw() {

	for (auto& mesh : this->mesh_list) {

		mesh.draw();

		ofBeginShape();
		for (auto& vertex : mesh.getVertices()) {

			ofVertex(vertex);
		}
		ofEndShape(true);
	}
}

//--------------------------------------------------------------
glm::vec2 ofApp::make_point(int len, int param) {

	param = param % 100;
	if (param < 25) {

		return glm::vec2(ofMap(param, 0, 25, -len * 0.5, len * 0.5), -len * 0.5);
	}
	else if (param < 50) {

		return glm::vec2(len * 0.5, ofMap(param, 25, 50, -len * 0.5, len * 0.5));
	}
	else if (param < 75) {

		return glm::vec2(ofMap(param, 50, 75, len * 0.5, -len * 0.5), len * 0.5);
	}
	else {

		return glm::vec2(-len * 0.5, ofMap(param, 75, 100, len * 0.5, -len * 0.5));
	}
}

//--------------------------------------------------------------
int main() {

	ofSetupOpenGL(720, 720, OF_WINDOW);
	ofRunApp(new ofApp());
}