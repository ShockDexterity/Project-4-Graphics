#pragma once
#include "SceneGraphNode.h"

class SimpleJointAnimNode : public SceneGraphNode
{ 
public: 
	SimpleJointAnimNode(float rotationSpeed, const glm::vec3& rotationAxis);

protected:
	virtual void updateNode(float dt, const glm::mat4& model) override;

private:
	float time {};
	float speed {};
	glm::vec3 axis {};
};