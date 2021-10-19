#version 430 
layout(location = 0) in vec3 inPosition;
layout(location = 1) in vec3 vertexColor;

layout(location = 0) uniform vec3 offset;

out vec3 outputColor;
void main()
{
	vec3 position = inPosition + offset;
	gl_Position = vec4(position.xy, (position.z - 50.0) / 100.0, position.z);
	outputColor = vertexColor;
}