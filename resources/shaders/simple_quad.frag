#version 150

in vec2 pass_TexCoord;

out vec4 out_Color;

uniform sampler2D screenTexture;

uniform bool horizontalMirroring;
uniform bool verticalMirroring;
uniform bool greyscale;
uniform bool blur;

vec2 tex_coords = pass_TexCoord;

void main() {

	if(horizontalMirroring) {
		tex_coords.y = 1.0-tex_coords.y;
	}

	if(verticalMirroring) {
		tex_coords.x = 1.0-tex_coords.x;
	}
	out_Color = texture(screenTexture, tex_coords);
}