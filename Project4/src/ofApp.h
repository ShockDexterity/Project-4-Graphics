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

	ofMesh cone{};
	ofMesh cube{};
	ofMesh cylinder{};
	ofMesh sphere{};
	ofMesh torus{};

	ofShader shader{};

	MySceneGraph graph {};

	int prevX { 0 };
	int prevY { 0 };
	const float mouseSensitivity { 0.02f };

	const glm::vec3 vX { 1, 0, 0 };
	const glm::vec3 vY { 0, 1, 0 };
	glm::vec3 velocity { 0, 0, 0 };

	// Position of the camera in world space
	Camera camera{ glm::vec3(0, 0, 2) };

	float cameraHead { 0 };
	float cameraPitch { 0 };
	void updateCameraRotation(float dx, float dy);

	bool shadersNeedReload { true };
	void reloadShaders();
};
