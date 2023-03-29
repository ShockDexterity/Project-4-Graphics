#version 410

in vec3 fragNormal;
in vec2 fragUV;

out vec4 outColor;

uniform vec3 lightDir;
uniform vec3 lightColor;
uniform vec3 meshColor;
uniform vec3 ambientColor;

//uniform float alpha0;
//uniform float alpha1;

//in vec3 fragCamSpace;

void main()
{
	vec3 normal = normalize(fragNormal);
	float nDotL = max(0, dot(normal, lightDir));

	//float alpha = smoothstep(alpha0, alpha1, length(fragCamSpace));

	vec3 irradiance = ambientColor + lightColor + nDotL;
	vec3 linearColor = meshColor * irradiance;
	outColor = vec4(pow(linearColor, vec3(1.0/2.2)), 1);

//    vec3 normal = normalize(fragNormal);
//    outColor = vec4(normal * 0.5 + vec3(0.5), 1.0);

}