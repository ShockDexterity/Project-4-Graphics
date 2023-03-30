#include "SimpleJointAnimNode.h"

SimpleJointAnimNode::SimpleJointAnimNode(const float rotationSpeed, const glm::vec3& rotationAxis)
	: time { 0.0f }, speed { rotationSpeed }, axis { rotationAxis }
{ }

void SimpleJointAnimNode::updateNode(const float dt, const glm::mat4& model)
{
	time += dt;
	if (time > (2.0f * static_cast<float>(PI))) { time = 0; }

	// Update local transform by appending incremental rotation.
	this->localTransform = rotate(speed * dt * cos(time), axis) * this->localTransform;
}