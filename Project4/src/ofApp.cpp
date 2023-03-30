#include "ofApp.h"
#include "CameraMatrices.h"

using namespace glm;

void ofApp::reloadShaders()
{
	shadersNeedReload = false;

	// reload shaders
	hatShader.load("shaders/hat.vert", "shaders/hat.frag");
	robotShader.load("shaders/robot.vert", "shaders/robot.frag");
	propellerShader.load("shaders/propeller.vert", "shaders/propeller.frag");
}

//--------------------------------------------------------------
void ofApp::setup()
{
	// important
	ofDisableArbTex();
	ofEnableDepthTest();

	cone.load("models/cone.ply");
	cube.load("models/cube.ply");
	cylinder.load("models/cylinder.ply");
	sphere.load("models/sphere.ply");

	reloadShaders();

	graph.setup(cone, cube, cylinder, sphere, hatShader, robotShader, propellerShader);
}

//--------------------------------------------------------------
void ofApp::update()
{
	if (shadersNeedReload) { reloadShaders(); }

	// time since last frame
	const float dt { static_cast<float>(ofGetLastFrameTime()) };

	// update position
	camera.position += mat3(rotate(cameraHead, yAxis)) * velocity * dt;
	camera.rotation = rotate(cameraHead, yAxis) * rotate(cameraPitch, xAxis);

	// Update scene graph
	graph.rootNode.updateSceneGraph(dt);
	graph.lighting.spotLight = graph.spotLightNode->spotLight;
}

void ofApp::updateCameraRotation(float dx, float dy)
{
	cameraHead -= dx;
	cameraPitch -= dy;
	cameraPitch = glm::clamp(cameraPitch, radians(-89.0f), radians(89.0f));
}

//--------------------------------------------------------------
void ofApp::draw()
{
	// aspect ratio
	const float width { static_cast<float>(ofGetViewportWidth()) };
	const float height { static_cast<float>(ofGetViewportHeight()) };
	const float aspect { width / height };

	CameraMatrices camMatrices { camera, aspect, 0.1f, 10.0f };
	/*const mat4 model {};
	const mat4 mv { camMatrices.getView() * model };
	const mat4 mvp { camMatrices.getProj() * mv };*/

	graph.rootNode.drawSceneGraph(camMatrices);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key)
{
	const int vel { 5 };
	switch (key)
	{
		case '`': shadersNeedReload = true; break;

		case 'a': velocity.x = -vel; break;
		case 'A': velocity.x = -vel; break;
		case OF_KEY_LEFT: velocity.x = -vel; break;

		case 'd': velocity.x = vel; break;
		case 'D': velocity.x = vel; break;
		case OF_KEY_RIGHT: velocity.x = vel; break;

		case 'q': velocity.y = -vel; break;
		case 'Q': velocity.y = -vel; break;
		case 'e': velocity.y = vel; break;
		case 'E': velocity.y = vel; break;

		case 'w': velocity.z = -vel; break;
		case 'W': velocity.z = -vel; break;
		case OF_KEY_UP: velocity.z = -vel; break;

		case 's': velocity.z = vel; break;
		case 'S': velocity.z = vel; break;
		case OF_KEY_DOWN: velocity.z = vel; break;

		default: break;
	}
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key)
{
	switch (key)
	{
		case 'a': velocity.x = 0; break;
		case 'A': velocity.x = 0; break;
		case OF_KEY_LEFT: velocity.x = 0; break;

		case 'd': velocity.x = 0; break;
		case 'D': velocity.x = 0; break;
		case OF_KEY_RIGHT: velocity.x = 0; break;

		case 'q': velocity.y = 0; break;
		case 'Q': velocity.y = 0; break;
		case 'e': velocity.y = 0; break;
		case 'E': velocity.y = 0; break;

		case 'w': velocity.z = 0; break;
		case 'W': velocity.z = 0; break;
		case OF_KEY_UP: velocity.z = 0; break;

		case 's': velocity.z = 0; break;
		case 'S': velocity.z = 0; break;
		case OF_KEY_DOWN: velocity.z = 0; break;

		default: break;
	}
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y)
{
	if (prevX != 0 && prevY != 0)
	{
		//update camera rotation based on mouse movement
		int dx { x - prevX }, dy { y - prevY };

		updateCameraRotation(mouseSensitivity * dx, mouseSensitivity * dy);
	}

	//remember where the mouse was this frame
	prevX = x;
	prevY = y;
}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button)
{ }

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button)
{ }

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button)
{ }

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y)
{ }

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y)
{ }

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h)
{ }

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg)
{ }

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo)
{ }
