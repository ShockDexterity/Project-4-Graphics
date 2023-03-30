#include "MySceneGraph.h"
//#include "SimpleDrawNode.h"
#include "SimpleAnimationNode.h"
#include "SimpleJointAnimNode.h"
#include "SimpleTranslationNode.h"
#include "LitDrawNode.h"

void MySceneGraph::setup(
	const ofMesh& coneMesh,
	const ofMesh& cubeMesh,
	const ofMesh& cylinderMesh,
	const ofMesh& sphereMesh,
	const ofShader& hatShader,
	const ofShader& robotShader,
	const ofShader& propellerShader
)
{
	using namespace glm;

	/************************** INIT **************************/

	//lighting.dirLight.direction = vec3(0.25, -1, -0.5);
	//lighting.dirLight.color = vec3(0.9, 0.9, 0.75);
	//lighting.dirLight.intensity = 1;
	lighting.ambientLight = vec3(0.1, 0.1, 0.25);
	std::shared_ptr<LitDrawNode> cubeMeshNode { new LitDrawNode { cubeMesh, robotShader, lighting } };
	std::shared_ptr<LitDrawNode> coneMeshNode { new LitDrawNode { coneMesh, robotShader, lighting } };

	cubeMeshNode->meshColor = vec3(0.5);

	// Initialize scene graph
	rootNode.childNodes.emplace_back(new SimpleTranslationNode(0.0f, -zAxis));

	// Animated torus node is the most recent node added to the scene graph at this point
	auto translationAnimNode { rootNode.childNodes.back() };


	/************************** HEAD **************************/

	translationAnimNode->childNodes.emplace_back(new SceneGraphNode {});
	auto headMeshNode { translationAnimNode->childNodes.back() };
	headMeshNode->localTransform = scale(vec3(1.0f, 0.25f, 1.0f));
	headMeshNode->childNodes.push_back(cubeMeshNode);


	/************************** LEFT LEG **************************/

	float legSpeed { 1.0f };

	// left leg animation node
	translationAnimNode->childNodes.emplace_back(new SimpleJointAnimNode { legSpeed, xAxis });

	// left upper leg
	auto upperLeftLegMeshNode { translationAnimNode->childNodes.back() };
	upperLeftLegMeshNode->localTransform = translate(vec3(0.75f, -1.0f, 0.0f)) * scale(vec3(0.25f, 1.0, 0.25f));
	upperLeftLegMeshNode->childNodes.push_back(cubeMeshNode);

	

	// left lower leg
	upperLeftLegMeshNode->childNodes.emplace_back(new SceneGraphNode {});
	auto lowerLeftLegMeshNode { upperLeftLegMeshNode->childNodes.back() };
	lowerLeftLegMeshNode->localTransform = translate(vec3(0, -1, 0)) * scale(vec3(1, -1, 1));
	lowerLeftLegMeshNode->childNodes.push_back(coneMeshNode);


	/************************** RIGHT LEG **************************/

	// right leg animation node
	translationAnimNode->childNodes.emplace_back(new SimpleJointAnimNode { -legSpeed, xAxis });

	// right upper leg
	auto upperRightLegMeshNode { translationAnimNode->childNodes.back() };
	upperRightLegMeshNode->localTransform = translate(vec3(-0.75f, -1.0f, 0.0f)) * scale(vec3(0.25f, 1.0, 0.25f));
	upperRightLegMeshNode->childNodes.push_back(cubeMeshNode);


	// right lower leg
	upperRightLegMeshNode->childNodes.emplace_back(new SimpleDrawNode { coneMesh, robotShader });
	auto lowerRightLegMeshNode { upperRightLegMeshNode->childNodes.back() };
	lowerRightLegMeshNode->localTransform = translate(vec3(0, -1, 0)) * scale(vec3(1, -1, 1));
	lowerRightLegMeshNode->childNodes.push_back(coneMeshNode);


	/************************** HAT **************************/

	// hat sphere
	headMeshNode->childNodes.emplace_back(new SimpleDrawNode { sphereMesh, hatShader });
	auto hatMeshNode { headMeshNode->childNodes.back() };
	hatMeshNode->localTransform = translate(vec3(0.0f, 1.0f, 0.0f)) * scale(vec3(0.95f, 0.5f, 0.95f));

	// propeller stem
	hatMeshNode->childNodes.emplace_back(new SimpleDrawNode { cylinderMesh, propellerShader });
	auto propellerStemMeshNode { hatMeshNode->childNodes.back() };
	propellerStemMeshNode->localTransform = scale(vec3(0.125f, 1.5f, 0.125f));

	// blades
	propellerStemMeshNode->childNodes.emplace_back(new SimpleAnimationNode { 2.0f, yAxis });
	auto propellerAnimNode { propellerStemMeshNode->childNodes.back() };

	for (int i { 0 }; i < 8; ++i)
	{
		propellerAnimNode->childNodes.emplace_back(new SimpleDrawNode { cubeMesh, propellerShader });
		auto blade { propellerAnimNode->childNodes.back() };

		blade->localTransform = scale(vec3(0.2f, 0.005f, 3.5f)) * blade->localTransform;
		blade->localTransform = translate(vec3(0.0f, 0.9f, 3.0f)) * blade->localTransform;
		blade->localTransform = rotate(radians(-5.0f), zAxis) * blade->localTransform;
		blade->localTransform = rotate(radians(45.0f * i), yAxis) * blade->localTransform;
	}

	return;
}