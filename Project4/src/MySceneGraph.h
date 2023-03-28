#pragma once
#include "SceneGraphNode.h"

class MySceneGraph
{
public:
	void setup(const ofMesh& coneMesh, const ofMesh& cubeMesh, const ofMesh& cylinderMesh, const ofShader& shader);

	// Root node of the scene graph
	SceneGraphNode rootNode {};

private:
	std::shared_ptr<SceneGraphNode> cubeAnimNode;
	std::shared_ptr<SceneGraphNode> legAnimNode;
};
