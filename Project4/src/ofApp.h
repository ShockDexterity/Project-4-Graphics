#pragma once

#include "ofMain.h"
#include "Camera.h"
#include "MySceneGraph.h"

class ofApp : public ofBaseApp
{
public:
	void setup();
	void update();
	void draw();

	void keyPressed(int key);
	void keyReleased(int key);
	void mouseMoved(int x, int y);
	void mouseDragged(int x, int y, int button);
	void mousePressed(int x, int y, int button);
	void mouseReleased(int x, int y, int button);
	void mouseEntered(int x, int y);
	void mouseExited(int x, int y);
	void windowResized(int w, int h);
	void dragEvent(ofDragInfo dragInfo);
	void gotMessage(ofMessage msg);

private:
	// meshes
	ofMesh cone {};
	ofMesh cube {};
	ofMesh cylinder {};
	ofMesh sphere {};

	// shaders
	ofShader hatShader {};
	ofShader robotShader {};
	ofShader propellerShader {};

	// scene graph
	MySceneGraph graph {};

	// camera stuffs
	int prevX { 0 };
	int prevY { 0 };
	float cameraHead { 0 };
	float cameraPitch { 0 };
	glm::vec3 velocity { 0, 0, 0 };
	const float mouseSensitivity { 0.02f };
	Camera camera { glm::vec3(0.0f, 0.0f, 2.0f) }; // Position of the camera in world space

	void updateCameraRotation(float dx, float dy);

	// constant axes
	const glm::vec3 xAxis { 1.0f, 0.0f, 0.0f };
	const glm::vec3 yAxis { 0.0f, 1.0f, 0.0f };
	const glm::vec3 zAxis { 0.0f, 0.0f, 1.0f };

	// reloading shaders
	bool shadersNeedReload { true };
	void reloadShaders();
	
	bool isStill { true };
};
