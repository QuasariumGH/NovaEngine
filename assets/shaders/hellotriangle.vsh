#version 430 
layout(location = 0) in vec3 position;
layout(location = 1) in vec3 vertexColor;
out vec3 outputColor;
void main()
{
	gl_Position = vec4(position.xy, (position.z - 50.0) / 100.0, position.z);
	outputColor = vertexColor;
}