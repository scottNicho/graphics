#version 330 core
 uniform mat4 modelMatrix;
 uniform mat4 viewMatrix;
 uniform mat4 projMatrix;

 in vec3 position;
 in vec4 colour;
 in vec3 normal; //New Attribute!
 in vec2 texCoord;
 

 out Vertex {
 vec4 colour;
 vec2 texCoord;
 vec3 normal;
 vec3 worldPos;
 float y_height;
 } OUT;

 void main(void) {
 OUT.y_height = position.y;
 OUT.colour = colour;
 OUT.texCoord = texCoord;

 mat3 normalMatrix = transpose(inverse(mat3(modelMatrix )));
 OUT.normal = normalize(normalMatrix * normalize(normal ));

 vec4 worldPos = (modelMatrix * vec4(position ,1));

 OUT.worldPos = worldPos.xyz;

 //OUT.y_height = y_height;

 gl_Position = (projMatrix * viewMatrix) * worldPos;
 }