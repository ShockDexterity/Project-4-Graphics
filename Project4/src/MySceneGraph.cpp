#include "MySceneGraph.h"
#include "SimpleDrawNode.h"
#include "SimpleAnimationNode.h"
#include "SimpleTranslationNode.h"

void MySceneGraph::setup(const ofMesh& coneMesh, const ofMesh& cubeMesh, const ofMesh& cylinderMesh, const ofShader& shader)
{
	using namespace glm;

	// Initialize scene graph
	rootNode.childNodes.emplace_back(new SimpleTranslationNode(1.0f, vec3(0, 0, -1)));

	// Animated torus node is the most recent node added to the scene graph at this point
	translationAnimNode = rootNode.childNodes.back();

	// Attach cube mesh node to the animated node
	translationAnimNode->childNodes.emplace_back(new SimpleDrawNode { cubeMesh, shader });

	// add head
	auto headMeshNode { translationAnimNode->childNodes.back() };
	headMeshNode->localTransform = scale(vec3(1.0f, 0.25f, 1.0f));

	// left leg animation node
	translationAnimNode->childNodes.emplace_back(new SimpleDrawNode { cubeMesh, shader });

	// left upper leg
	auto upperLeftLegMeshNode { translationAnimNode->childNodes.back() };
	upperLeftLegMeshNode->localTransform = translate(vec3(0.75f, -1.0f, 0.0f)) * scale(vec3(0.25f, 1.0, 0.25f));

	// left lower leg
	upperLeftLegMeshNode->childNodes.emplace_back(new SimpleDrawNode { coneMesh, shader });
	auto lowerLeftLegMeshNode { upperLeftLegMeshNode->childNodes.back() };
	lowerLeftLegMeshNode->localTransform = translate(vec3(0, -1, 0)) * scale(vec3(1, -1, 1));

	// right leg animation node
	translationAnimNode->childNodes.emplace_back(new SimpleDrawNode { cubeMesh, shader });

	// right upper leg
	auto upperRightLegMeshNode { translationAnimNode->childNodes.back() };
	upperRightLegMeshNode->localTransform = translate(vec3(-0.75f, -1.0f, 0.0f)) * scale(vec3(0.25f, 1.0, 0.25f));

	// right lower leg
	upperRightLegMeshNode->childNodes.emplace_back(new SimpleDrawNode { coneMesh, shader });
	auto lowerRightLegMeshNode { upperRightLegMeshNode->childNodes.back() };
	lowerRightLegMeshNode->localTransform = translate(vec3(0, -1, 0)) * scale(vec3(1, -1, 1));




	// Create joint node
	/*torusAnimNode->childNodes.emplace_back(new SimpleAnimationNode { 2.0f, vec3(1, 0, 0) });
	auto jointNode { torusAnimNode->childNodes.back() };
	jointNode->localTransform = translate(vec3(1.5f, 0, 0)) * scale(vec3(0.5f));
	jointNode->childNodes.push_back(torusMeshNode);*/

	// Create joint node
	/*jointNode->childNodes.emplace_back(new SceneGraphNode());
	auto staticTranslation { jointNode->childNodes.back() };
	staticTranslation->localTransform = translate(vec3(1, 0, 0));

	staticTranslation->childNodes.emplace_back(new SimpleAnimationNode { 4.0f, vec3(0, 1, 0) });
	auto jointNode2 { staticTranslation->childNodes.back() };
	jointNode2->localTransform = translate(vec3(0.5f, 0, 0)) * scale(vec3(0.5f));
	jointNode2->childNodes.push_back(torusMeshNode);*/
}