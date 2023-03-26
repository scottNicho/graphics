#version 330 core

 uniform mat4 modelMatrix;
 uniform mat4 viewMatrix;
 uniform mat4 projMatrix;
 uniform vec4 nodeColour;

 in vec3 position;
 in vec2 texCoord;

 out Vertex {
 //float y_height;
 vec2 texCoord;
 vec4 colour;
 } OUT;

 void main(void) {
 gl_Position = (projMatrix * viewMatrix * modelMatrix) *
 vec4(position , 1.0);
 //y_height = position.y;
 //OUT.y_height = y_height;
 OUT.texCoord = texCoord;
 OUT.colour = nodeColour;
 }