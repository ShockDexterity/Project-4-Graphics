#include "SimpleJointAnimNode.h"

SimpleJointAnimNode::SimpleJointAnimNode(float rotationSpeed, glm::vec3 rotationAxis)
	: speed { rotationSpeed }, axis { rotationAxis }, time { 0.0f }
{ }

void SimpleJointAnimNode::updateNode(float dt, const glm::mat4& model)
{
	time += dt;
	if (time > 2 * PI) { time = 0; }

	// Update local transform by appending incremental rotation.
	this->localTransform = rotate(speed * dt * cos(time), axis) * this->localTransform;
}