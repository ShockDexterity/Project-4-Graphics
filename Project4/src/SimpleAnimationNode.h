#pragma once
#include "SceneGraphNode.h"

class SimpleAnimationNode : public SceneGraphNode
{
public:
	SimpleAnimationNode(float rotationSpeed, const glm::vec3& rotationAxis);

protected:
	virtual void updateNode(float dt, const glm::mat4& model) override;

private:
	float speed {};
	glm::vec3 axis {};
};