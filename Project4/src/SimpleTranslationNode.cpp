#include "SimpleTranslationNode.h"

using namespace glm;

SimpleTranslationNode::SimpleTranslationNode(const float translationSpeed, const vec3& translationDir)
	: speed { translationSpeed }, direction { translationDir }
{ }

void SimpleTranslationNode::updateNode(const float dt, const mat4& model)
{
	// Update local transform by appending incremental translation.
	this->localTransform = translate(direction * speed * dt) * this->localTransform;
}