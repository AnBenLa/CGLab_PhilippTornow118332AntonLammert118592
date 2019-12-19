#version 150

varying vec3 pass_Normal, pass_Position, pass_Camera_Position;
out vec4 out_Color;
uniform vec3 planetColor;

void main() {
  
  vec3 normal = normalize(pass_Normal);
  vec3 specular_color = vec3(1.0,1.0,1.0);
  float ambient_light_strength = 0.07;
  float light_strength = 0.8;
  vec3 light_Position = vec3(0.0, 0.0, 0.0);
  float diffuse_reflection_factor = 0.9;
  float specular_reflection_factor = 0.6;
  int n = 6;

  vec3 camera_Position = pass_Camera_Position;

  vec3 light_Direction = normalize(light_Position - pass_Position);
  vec3 view_Direction = normalize(camera_Position - pass_Position);
  vec3 h = normalize(view_Direction + light_Direction);

  float diffuse_light_strength = light_strength*diffuse_reflection_factor*max(dot(normal,light_Direction),0.0);
  float spec = pow(max(dot(h,normal),0.0),n);
  float specular_light_strength = light_strength*specular_reflection_factor*spec;
  
  vec3 ambient = planetColor * ambient_light_strength;
  vec3 diffuse = planetColor * diffuse_light_strength;
  vec3 specular = specular_color * specular_light_strength;
  //diffuse and specular not wirking properly most likely because of the light_Direction, the view_Direction or the normal
  out_Color = vec4(ambient + diffuse + specular, 1.0);
}
