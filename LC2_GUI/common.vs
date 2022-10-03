#version 330
layout (location=0) in vec3 aPos;
layout (location=1) in vec3 aNormals;
layout (location=2) in vec3 aTexCoords;

uniform vec2 pos;
uniform vec2 size;
uniform float zDepth;
uniform vec2 o_scale;

void main(){

	gl_Position = vec4(size.x* aPos.x+ pos.x,
						  size.y* aPos.y +pos.y,
						zDepth, 1.0);
}

