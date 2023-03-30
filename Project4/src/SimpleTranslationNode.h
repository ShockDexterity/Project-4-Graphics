#pragma once
#include "SceneGraphNode.h"

class SimpleTranslationNode : public SceneGraphNode
{
public:
	SimpleTranslationNode(float translationSpeed, const glm::vec3& translationDir);

protected:
	virtual void updateNode(float dt, const glm::mat4& model) override;

private:
	float speed {};
	glm::vec3 direction {};
};