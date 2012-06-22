
#version 120

uniform sampler2D texture;
varying vec4 mycol;

void main(void)
{
    gl_FragColor = texture2D(texture,gl_PointCoord) * mycol;
    
    //Linear fog 
    float fog = (gl_Fog.end - gl_FogFragCoord) * gl_Fog.scale;
//    float fog = exp(-gl_Fog.density * gl_FogFragCoord); // exp doesn't work
    fog = clamp(fog, 0, 1);     
    
    gl_FragColor = mix(gl_Fog.color, gl_FragColor, fog);
//    gl_FragColor = gl_Color;
}