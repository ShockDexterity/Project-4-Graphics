#pragma once
#include "SceneGraphNode.h"

class MySceneGraph
{
public:
	void setup(const ofMesh& coneMesh, const ofMesh& cubeMesh, const ofMesh& cylinderMesh, const ofMesh& sphereMesh, const ofShader& shader);

	// Root node of the scene graph
	SceneGraphNode rootNode {};

private:
	std::shared_ptr<SceneGraphNode> translationAnimNode;
	std::shared_ptr<SceneGraphNode> legAnimNode;
};
