#version 400
layout (location = 0) in vec3 in_position;
layout (location = 1) in vec3 in_normal;
layout (location = 2) in vec2 in_uv;

uniform mat4 harpia_WorldToObject;
uniform mat4 harpia_ObjectToCamera;

out vec3 vs_normal;
out vec2 vs_uv;

void main() {
    vec4 pos = harpia_WorldToObject * vec4(in_position, 1.0);
    float v = 35.0f;
    gl_Position = harpia_ObjectToCamera * pos;//(round(pos*v)/v);
    vs_normal = (harpia_ObjectToCamera * harpia_WorldToObject * vec4(normalize(in_normal), 0.0)).xyz;
    vs_uv = in_uv;
}