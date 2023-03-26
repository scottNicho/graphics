#version 330 core
 uniform sampler2D diffuseTex;
 uniform sampler2D diffuseTex2;
 int i =2;
 in Vertex {
 vec2 texCoord;
 } IN;

 out vec4 fragColour;
 void main(void) {
 if (i >3){
 fragColour = texture(diffuseTex2 , IN.texCoord );
 } else{
 fragColour = (texture(diffuseTex , IN.texCoord )*0.7) + (texture(diffuseTex2 , IN.texCoord )) ;
 }
 }