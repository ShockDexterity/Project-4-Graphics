#version 410

in vec2 fragUV;
in vec3 fragNormal;

in float xCoord;
in float zCoord;

out vec4 outColor;

bool between(float val, float bot, float top);
vec4 getColor(float cosine);

void main()
{
    vec2 v = vec2(xCoord, zCoord);
    vec2 o = vec2(1, 0);

    float cosine = dot(v, o) / (length(v) * length(o));

    outColor = getColor(cosine);
}

bool between(float val, float bot, float top)
{
    if (bot <= val && val <= top)
    {
        return true;
    }
    return false;
}

vec4 getColor(float cosine)
{
    if (between(cosine, 0.5, 1.0))
    {
        if (zCoord >= 0)
        {
            // r 0->60
            return vec4(179.0, 7.0, 21.0, 255.0) / 255.0;
        }
        else
        {
            // v 300->360
            return vec4(59.0, 39.0, 51.0, 255.0) / 255.0;
        }
    }

    if (between(cosine, -0.5, 0.5))
    {
        if (zCoord > 0)
        {
            // o 60->120
            return vec4(254.0, 99.0, 51.0, 255.0) / 255.0;
        }
        else
        {
            // b 240->300
            return vec4(53.0, 63.0, 176.0, 255.0) / 255.0;
        }
    }

    if (between(cosine, -1.0, -0.5))
    {
        if (zCoord >= 0)
        {
            // y 120->180
           return vec4(246.0, 198.0, 90.0, 255.0) / 255.0;
        }
        else
        {
            // g 180->240
            return vec4(48.0, 161.0, 133.0, 255.0) / 255.0;
        }
    }
    return vec4(0.0, 0.0, 0.0, 1.0);
}