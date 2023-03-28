#include "MySceneGraph.h"
#include "SimpleDrawNode.h"
#include "SimpleAnimationNode.h"
#include "SimpleTranslationNode.h"

void MySceneGraph::setup(const ofMesh& coneMesh, const ofMesh& cubeMesh, const ofMesh& cylinderMesh, const ofMesh& sphereMesh, const ofShader& shader)
{
	using namespace glm;

	/************************** INIT **************************/

	// Initialize scene graph
	rootNode.childNodes.emplace_back(new SimpleTranslationNode(0.0f, vec3(0, 0, -1)));

	// Animated torus node is the most recent node added to the scene graph at this point
	translationAnimNode = rootNode.childNodes.back();


	/************************** HEAD **************************/

	translationAnimNode->childNodes.emplace_back(new SimpleDrawNode { cubeMesh, shader });
	auto headMeshNode { translationAnimNode->childNodes.back() };
	headMeshNode->localTransform = scale(vec3(1.0f, 0.25f, 1.0f));


	/************************** LEFT LEG **************************/

	// left leg animation node
	translationAnimNode->childNodes.emplace_back(new SimpleDrawNode { cubeMesh, shader });

	// left upper leg
	auto upperLeftLegMeshNode { translationAnimNode->childNodes.back() };
	upperLeftLegMeshNode->localTransform = translate(vec3(0.75f, -1.0f, 0.0f)) * scale(vec3(0.25f, 1.0, 0.25f));

	// left lower leg
	upperLeftLegMeshNode->childNodes.emplace_back(new SimpleDrawNode { coneMesh, shader });
	auto lowerLeftLegMeshNode { upperLeftLegMeshNode->childNodes.back() };
	lowerLeftLegMeshNode->localTransform = translate(vec3(0, -1, 0)) * scale(vec3(1, -1, 1));


	/************************** RIGHT LEG **************************/

	// right leg animation node
	translationAnimNode->childNodes.emplace_back(new SimpleDrawNode { cubeMesh, shader });

	// right upper leg
	auto upperRightLegMeshNode { translationAnimNode->childNodes.back() };
	upperRightLegMeshNode->localTransform = translate(vec3(-0.75f, -1.0f, 0.0f)) * scale(vec3(0.25f, 1.0, 0.25f));

	// right lower leg
	upperRightLegMeshNode->childNodes.emplace_back(new SimpleDrawNode { coneMesh, shader });
	auto lowerRightLegMeshNode { upperRightLegMeshNode->childNodes.back() };
	lowerRightLegMeshNode->localTransform = translate(vec3(0, -1, 0)) * scale(vec3(1, -1, 1));


	/************************** HAT **************************/

	// hat sphere
	translationAnimNode->childNodes.emplace_back(new SimpleDrawNode { sphereMesh, shader });
	auto hatMeshNode { translationAnimNode->childNodes.back() };
	hatMeshNode->localTransform = translate(vec3(0.0f, 0.25f, 0.0f)) * scale(vec3(1.0f, 0.25f, 1.0f));

	// propellor stem
	hatMeshNode->childNodes.emplace_back(new SimpleDrawNode { cylinderMesh,shader });
	auto propellorStemMeshNode { hatMeshNode->childNodes.back() };
	propellorStemMeshNode->localTransform = scale(vec3(0.125f, 1.5f, 0.125f));


}