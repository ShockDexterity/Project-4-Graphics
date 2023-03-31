#pragma once
#include "DirectionalLight.h"
#include "SpotLight.h"

struct Lighting
{
public:
	SpotLight spotLight;
	PointLight pointLight;
	glm::vec3 ambientLight;
	DirectionalLight dirLight;
};