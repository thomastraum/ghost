#version 120

attribute float point_size;
attribute vec4 col;
varying vec4 mycol;

void main()
{
    gl_Position = ftransform();
    gl_PointSize = point_size / (gl_Position.w * 0.001 );
    
	gl_TexCoord[0]  = gl_MultiTexCoord0;
	gl_FrontColor   = col; //gl_Color;
	gl_Position     = gl_ModelViewProjectionMatrix * gl_Vertex;
    
    vec4 eyePos = gl_ModelViewMatrix * gl_Vertex;
    gl_FogFragCoord = abs(eyePos.z/eyePos.w);
    
    mycol = col;
}