#version 410

in vec2 fragUV;
in vec3 fragNormal;

out vec4 outColor;

void main()
{
    outColor = vec4(vec3(192.0)/255.0, 1.0);
}