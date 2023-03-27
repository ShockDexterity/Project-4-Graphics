#pragma once
#include "SceneGraphNode.h"

class SimpleTranslationNode : public SceneGraphNode
{
public:
	SimpleTranslationNode(float translationSpeed, glm::vec3 translationAxis);

protected:
	virtual void updateNode(float dt, const glm::mat4& model) override;

private:
	float speed;
	glm::vec3 direction;
};