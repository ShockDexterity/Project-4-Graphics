#include "PointLightNode.h"

void PointLightNode::updateNode(float dt, const glm::mat4& model)
{
	using namespace glm;
	pointLight.position = model[3]; // fourth column: translation; equivalent to model * vec4(0, 0, 0, 1)
}