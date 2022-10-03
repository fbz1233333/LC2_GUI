#version 330 core
layout (location = 0) in vec4 vertex; // <vec2 pos, vec2 tex>
out vec2 TexCoords;
 
uniform mat4 projection;
uniform vec2 o_scale;

void main()
{
    gl_Position = projection * vec4(
				vertex.x*o_scale.x,vertex.y*o_scale.y, 
				0.0, 1.0);
    TexCoords = vertex.zw;
}