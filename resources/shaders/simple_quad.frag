#version 150

in vec2 pass_TexCoord;

out vec4 out_Color;

uniform sampler2D screenTexture;

void main() {
	out_Color = texture(screenTexture, pass_TexCoord);
}