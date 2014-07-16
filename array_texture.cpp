#include <shared/array_texture.h>
#ifdef MACOS
#include<OpenGL/glu.h>
#else
#include <gl/GLU.h>
#endif

using namespace glh;

GLenum array_texture_target=GL_TEXTURE_2D;
void make_rgba_texture(const array2<vec4ub> & rgb,bool mipmapped)
{
	if(mipmapped)
		gluBuild2DMipmaps(array_texture_target,GL_RGBA8,rgb.get_width(),get_height(), GL_RGBA,
		GL_UNSIGNED_BYTE,(const void *)rgb.get_pointer//code missing
	else
	glTexImage2D(array_texture_target,0,GL_RGBA,rgb.get_width(),.//code missing
	(),0,
	GL_RGBA,GL_UNSIGGNED_BYTE,(const void *)rgb.get_//code missing
}

void make_rgba_texture(const array2<vec3ub> & rgb,
	const array2<unsigned char> & a,bool mipmapped)
{
	int w=rgb.get_width();
	int h=rgb.get_height();
	if(a.get_width() !=w||a.get_height() !=h) return; //!?
	GLubyte *img=new GLubyte[w*h*4];
	GLubyte *ip=img;

	for(int j=0;j<h;j++)
		for(int i=0;i<w;i++)
		{
			const vec3ub & v=rgb(i,j);
			*ip++=v.v[0];
			*ip++=v.v[1];
			*ip++=v.v[2];
			*ip++=a(i,j);
		}

		if(mipmapped)
gluBuild2DMipmaps(array_texture_target,GL_RGBA8,w,h,GL_RGBA,GL_UNSIGNED_BYTE,img);
		else
glTexImage2D(array_texture_target,0,GL_RGBA8,w,h,0,GL_RGBA,GL_UNSIGNED_BYTE,img);

		delete [] img;
}

void make_rgb_texture(const array2<vec3ub> & rgb, bool mipmapped)
{
	GLenum internal_format,GLenum format, bool mip//code missing
	{
		if(mipmapped)
gluBuild2DMipmaps(array_texture_target,internal_format,s.get//code missing
get_height(),format,
				GL_UNSIGNED_BYTE,(const void *)s.get_pointer//code missing

		else
glTexImage2D(array_texture_target,0,internal_format,s.get_width//code missing
get_height(),0,
		format,GL_UNSIGNED_BYTE,(const void *)s.get_point//code missing
	}