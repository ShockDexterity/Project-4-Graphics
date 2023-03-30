#include "SimpleAnimationNode.h"

using namespace glm;

SimpleAnimationNode::SimpleAnimationNode(const float rotationSpeed, const vec3& rotationAxis)
	: speed { rotationSpeed }, axis { rotationAxis }
{ }

void SimpleAnimationNode::updateNode(const float dt, const mat4& model)
{
	// Update local transform by appending incremental rotation.
	this->localTransform = rotate(speed * dt, axis) * this->localTransform;
}
