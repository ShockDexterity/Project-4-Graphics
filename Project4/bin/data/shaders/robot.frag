#version 410

in vec3 fragNormal;
in vec2 fragUV;
in vec3 objectPos;
out vec4 outColor;

//uniform vec3 lightDir;
//uniform vec3 lightColor;
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
	vec3 tempColor;
	vec3 normal = normalize(fragNormal);
	float nDotL = max(0, dot(normal, dirLightDir));
	vec3 irradiance = ambientColor + dirLightColor + nDotL;

	vec3 toSpotLight = spotLightPos - objectPos;
	vec3 spotLightDir = normalize(toSpotLight);
	float cosAngle = dot(spotLightDir, -spotLightConeDir);
	float falloff = 1.0 / dot(toSpotLight, toSpotLight);
	vec3 spotLightIrr = falloff * spotLightColor * max(0, dot(normal, spotLightDir)); 

	if (cosAngle > spotLightCutoff)
	{
		irradiance += spotLightIrr;
	}
	vec3 linearColor = meshColor * irradiance;
	outColor = vec4(pow(linearColor, vec3(1.0/2.2)), 1);

//    vec3 normal = normalize(fragNormal);
//    outColor = vec4(normal * 0.5 + vec3(0.5), 1.0);

}