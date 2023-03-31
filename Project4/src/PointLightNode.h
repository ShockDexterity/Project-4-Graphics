#pragma once
#include "SceneGraphNode.h"
#include "PointLight.h"

class PointLightNode : public SceneGraphNode
{
public:
	PointLight pointLight;

protected:
	virtual void updateNode(float dt, const glm::mat4& model) override;
};