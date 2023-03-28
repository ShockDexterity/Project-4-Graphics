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
	cubeAnimNode = rootNode.childNodes.back();

	// Attach cube mesh node to the animated node
	cubeAnimNode->childNodes.emplace_back(new SimpleDrawNode { cubeMesh, shader });

	// Cube mesh is most recent node added
	auto cubeMeshNode { cubeAnimNode->childNodes.back() };
	cubeMeshNode->localTransform = scale(vec3(1.0f, 0.25f, 1.0f));

	cubeAnimNode->childNodes.emplace_back(new SimpleDrawNode{ cubeMesh, shader });
	
	auto legMeshNode{ cubeAnimNode->childNodes.back() };
	legMeshNode->localTransform = translate(vec3(0.75f, -1.0f, 0.0f)) * scale(vec3(0.25f, 1.0, 0.25f)) ;

	cubeAnimNode->childNodes.emplace_back(new SimpleDrawNode{ cubeMesh, shader });

	auto leg2MeshNode{ cubeAnimNode->childNodes.back() };
	leg2MeshNode->localTransform = translate(vec3(-0.75f, -1.0f, 0.0f)) * scale(vec3(0.25f, 1.0, 0.25f));

	legMeshNode->childNodes.emplace_back(new SimpleDrawNode{ coneMesh, shader });
	auto cone1Mesh{ legMeshNode->childNodes.back() };
	cone1Mesh->localTransform = translate(vec3(0, -1, 0)) * scale(vec3(1, -1, 1));


	leg2MeshNode->childNodes.emplace_back(new SimpleDrawNode{ coneMesh, shader });
	auto cone2Mesh{ leg2MeshNode->childNodes.back() };
	cone2Mesh->localTransform = translate(vec3(0, -1, 0)) * scale(vec3(1, -1, 1));

	

	
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