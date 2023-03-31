#version 410

in vec2 fragUV;
in vec3 fragNormal;

out vec4 outColor;

in vec3 objectPos;

uniform vec3 meshColor;
uniform vec3 ambientColor;

uniform vec3 dirLightDir;
uniform vec3 dirLightColor;

uniform vec3 spotLightColor;
uniform vec3 spotLightConeDir;
uniform vec3 spotLightPos;
uniform float spotLightCutoff;

void main()
{
	//directional light and ambient light
	vec3 tempColor;
	vec3 normal = normalize(fragNormal);
	float nDotL = max(0, dot(normal, dirLightDir));
	vec3 irradiance = ambientColor + dirLightColor + nDotL;

	//spotlight calculations
	vec3 toSpotLight = spotLightPos - objectPos;
	vec3 spotLightDir = normalize(toSpotLight);
	float cosAngle = dot(spotLightDir, -spotLightConeDir);
	float falloff = 1.0 / dot(toSpotLight, toSpotLight);
	vec3 spotLightIrr = falloff * spotLightColor * max(0, dot(normal, spotLightDir)); 

	if (cosAngle > spotLightCutoff) // only lit if inside cutoff
	{
		irradiance += spotLightIrr;
	}
	vec3 linearColor = meshColor * irradiance;
	outColor = vec4(pow(linearColor, vec3(1.0/2.2)), 1);

}