R"glsl(

#version 330 core

out vec4 fragment_color;

in vec4 out_color;

void main()
{
    fragment_color = out_color;
}

)glsl"
