#pragma once
#include "SceneGraphNode.h"
#include "Lighting.h"
#include "SpotLightNode.h"
#include "PointLightNode.h"

class MySceneGraph
{
public:
	void setup(
		const ofMesh& coneMesh,
		const ofMesh& cubeMesh,
		const ofMesh& cylinderMesh,
		const ofMesh& sphereMesh,
		const ofShader& hatShader,
		const ofShader& robotShader,
		const ofShader& propellerShader
	);

	// Root node of the scene graph
	Lighting lighting {};
	SceneGraphNode rootNode {};
	std::shared_ptr<SpotLightNode> stillSpotLightNode {};
	std::shared_ptr<SpotLightNode> animSpotLightNode {};
	std::shared_ptr<PointLightNode> pointLightNode {};

private:
	const glm::vec3 xAxis { 1.0f, 0.0f, 0.0f };
	const glm::vec3 yAxis { 0.0f, 1.0f, 0.0f };
	const glm::vec3 zAxis { 0.0f, 0.0f, 1.0f };
};
