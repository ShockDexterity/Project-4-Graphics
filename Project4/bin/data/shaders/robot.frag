#version 410

in vec3 fragNormal;
in vec2 fragUV;
in vec3 objectPos;
out vec4 outColor;

uniform vec3 meshColor;
uniform vec3 ambientColor;

uniform vec3 dirLightDir;
uniform vec3 dirLightColor;

uniform vec3 spotLightColor;
uniform vec3 spotLightConeDir;
uniform vec3 spotLightPos;
uniform float spotLightCutoff;

uniform vec3 pointLightColor;
uniform vec3 pointLightPos;

void main()
{
	//directional light and ambient light
	vec3 tempColor;
	vec3 normal = normalize(fragNormal);
	float nDotL = max(0, dot(normal, dirLightDir));
	vec3 irradiance = ambientColor + dirLightColor + nDotL;

	//Spotlight calculations
	vec3 toSpotLight = spotLightPos - objectPos;
	vec3 spotLightDir = normalize(toSpotLight);
	float cosAngle = dot(spotLightDir, -spotLightConeDir);
	float sFalloff = 1.0 / dot(toSpotLight, toSpotLight);
	vec3 spotLightIrr = sFalloff * spotLightColor * max(0, dot(normal, spotLightDir));

	//PointLight calculations
	vec3 toPointLight = pointLightPos - objectPos;
	vec3 pointLightDir = normalize(toPointLight);
	float pFalloff = 1.0 / dot(toPointLight, toPointLight);
	vec3 pointLightIrr = pFalloff * pointLightColor * max(0, dot(normal, pointLightDir));


	if (cosAngle > spotLightCutoff) //only lit if inside cutoff
	{
		irradiance += spotLightIrr;
	}

	irradiance += pointLightIrr;

	vec3 linearColor = meshColor * irradiance;
	outColor = vec4(pow(linearColor, vec3(1.0/2.2)), 1);
}