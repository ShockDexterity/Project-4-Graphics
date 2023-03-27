#include "SimpleTranslationNode.h"

using namespace glm;

SimpleTranslationNode::SimpleTranslationNode(float translationSpeed, vec3 translationDir)
	: speed { translationSpeed }, direction { translationDir }
{ }

void SimpleTranslationNode::updateNode(float dt, const mat4& model)
{
	// Update local transform by appending incremental translation.
	this->localTransform = translate(direction * speed * dt) * this->localTransform;
}