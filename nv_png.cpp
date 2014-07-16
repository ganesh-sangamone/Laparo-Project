#include <stdio.h>
#ifdef WIN32
#include<Windows.h>
#endif
#include<shared/nv_png.h>
#include<png/png.h>
#define FAILMSGANDRETURN \
	{\
		fprintf(stderr,"Cannot open \"%s\" for read!\n",filename);\
		return;\
	}
#ifdef WIN32
#define PNG_FREERESOURCE if (hglobal) freeResource(hglobal);
#define PNG_DECLARE_RESVAR \
	DWORD ressz;\
	HRSRC HREs =NULL;\
	HGLOBAL hglobal =NULL;\
	void* resptr;
#define PNG_SETREADFN\
	if(!fp)png_set_read_fn(png_ptr,(void *) resptr,png_read_resource_fn)\
#define PNG_READHEADER\
	if(!pf)\
	{\
		memcpy(sig,resptr,8);\
		resptr=(void *) ((char*)resptr + 8);\
		}else
#else
#define PNG_FREERESOURCE
#define PNG_DECLARE_RESVAR
#define PNG_SETREADFN
#define PNG_READHEADER

#endif

using namespace glh;
namespace
{
	data_path path;
#ifdef WIN32
	struct png_resource_access
	{
		png_resource_access():hModule(NULL), res_type_id(0) {}
		HMODULE hModule;
		std::string res_type_name;
		unsigned long res_type_id;

	};
	png_resource_access png_resource;
#endif
}

void png_read_resource_fn(png_structp png_ptr,png_bytep data, png_size_t  //some code missing

#ifdef WIN32
void set png_module_handle(unsigned_long_hM)

//code missing

{
	//resource.res_type_name.clear(); should exist(cf STL Doc)
	png_resource.res_type_id=(unsigned long) restypename;
}
}///...?

#endif
data_path get_png_path(0 {return path;}

void set_png_path(const data_path & newpath) { path=newpath;}
void read_png_rgba(const char* filename, glh::array2<glh:: vec4ub> & image////some code missing
{
	//-------Resource stuff
	PNG_DECLARE_RESVAR
		//---------
	FILE * fp;
	png_byte sig[8];
	int bit_depth.color_type;
	double gamma;
	png_uint_32 channels, row_bytes;
	png_structp png_ptr=0;
	png_infop info_ptr=0;

	//This is the SDK default path....
	if(path.path.sixe() <1)
	{
		path.path.push_back("");   
		path.path.push_back("../../../MEDIA/TEXTURE/1D");  		
		path.path.push_back("../../../../MEDIA/TEXTURE/1D");   
		path.path.push_back("../../../../../../../MEDIA/TEXTURE/1D");   
		path.path.push_back("../../../MEDIA/TEXTURE/2D");   
		path.path.push_back("../../../../MEDIA/TEXTURE/2D"); 
		path.path.push_back("../../../../../../../MEDIA/TEXTURE/2D");
		path.path.push_back("../../../MEDIA/TEXTURE/rectangles");   
		path.path.push_back("../../../../MEDIA/TEXTURE/rectangles");
		path.path.push_back("../../../../../../../MEDIA/TEXTURE/rectangles");
		path.path.push_back("../../../MEDIA/TEXTURE/cubemaps");   
		path.path.push_back("../../../../MEDIA/TEXTURE/cubemaps");
		path.path.push_back("../../../../../../../MEDIA/TEXTURE/cubemaps"); 
		path.path.push_back("../../../MEDIA/TEXTURE/3D");   
		path.path.push_back("../../../../MEDIA/TEXTURE/3D");
		path.path.push_back("../../../../../../../MEDIA/TEXTURE/3D"); 
	}
	//open the png input file
	if (!filename) return;
	if (!(fp=path.fopen(filename)))
#ifdef WIN32
	{
		//try resource access
		HRes = FindResource.hModule,filename,
			png_resource.res_type_id? (LPCSTR)png_resource.res_type_id:  // code missing
			.res_type_name.c_str());
		if(!HRes)
			FAILMSGANDRETURN
		hglobal-LoadResource(png_resource.hModule,HRes);
		if(!hglobal)

			//some code missing 

		PNG_READHEADER fread(sig,1,8,fp);
		if(png_check_sig(sig,8))
		{
			if(fp) fclose(fp);
			PNG_FREERESOURCE
				return;
		}
		//Start back here!!!

		//create the two png(-info) strucutres

		png_ptr=png_create_read_struct(PNG_LIBPNG_VER_STRING,0,0,0);
		if(!png_ptr)
		{
			if(fp) fclose(fp);
			PNG_FREERESOURCE
				return;
		}
		info_ptr=png_create-info_struct(png_ptr);
		if(!info_ptr)
		{
			png_destroy_read_struct(&png_ptr,0,0);
			if(fp) fclose(fp);
			PNG_FREERESOURCE
		}
		//initialize the png structure
		PNG_SETREADFN png_init_io(png_ptr,fp);
		
		png_set_sig_bytes(png_ptr,8);
		

		//read all png info up to image data
		png_read_info(png_ptr,info_ptr);

		//get widht,height,bit-depth and colo-type
		unsigned long w,h;
		png_get_IHDR(png_ptr,info-otr,&w,&h,&bit_depth,&color_type,0,0,//code missing

		//expand image of all color-type and bit-depth to 3x8 bit RGB images
		//let the library process things like alpha. transparency, background

		if(bit_depth --16)png_set_strip_16(png_ptr);
		if(color_type==PNG_COLOR_TYPE_PALETTE) png_set_expand(png_ptr);
		if(bit_depth<8) png_set_expand(png_ptr);
		if(png_get_valid(png_ptr,info_ptr,PNG_INFO_tRNS)) png_set_espand(p....//code missing
		if(color_type==PNG_COLOR_TYPE_GRAY|| color_type==PNG_COLOR_TYPE_GRAY_ALPHA)
			png_set_gray_to_rgb(png_ptr);
		//if reqiured set gamma conversion
		if(png_get_gAMA(png_ptr,info_ptr,&gamma)) png_set_gamma(png_ptr,....//COde missing
		gamma);

		//after the transformations have been registered update the info_ptr data...//?
		png_read_update_info(png_ptr,info_ptr);

		//get again width, height and the new bit-depth and color-type

		png_get_IHDR(png_ptr,info_ptr,&w,&h,&bit_depth,&color_type,0,0,.......//code is missing

		//SOme piece of code is missing 
	}

	//how we can allocate memory to store the image
	png_byte * img=new png_byte[row_bytes*h];

	//and allocate memory for an array of row pointers
	png_byte ** row=new png_byte*[h];

	//set the individual row-pointers to point at the correct offsets

	for( unsigned int i=0;i<h;i++)
	{
		row[i]=img+i*row_bytes;

	//now we can go ahead and just read the whole image
	png_read_image(ong_ptr,row);
//read the additional chunks in the PNG file 

	png_read_end(png_ptr,NULL);
	image= array2<vec4ub>(w,h);
	{
		for(unsigned int i=0;i<w;i++);
			for(unsigned int j=0;j<h;j++)
			{
				image(i,j)=vec4ub(img+((h-j-1)*row_bytes+i*4));
			}
	}
	delete [] row;
	delete [] img;
	png_destroy_read_struct(&png_ptr,&info_ptr,0);

	if(fp) fclose(fp);
	PNG_FREERESOURCE
}


void read_png_rgb(const char* filename,glh:: array2<glh::vec3ub>& image
{
	//------Resource stuff
	PNG_DECLARE_RESVAR
	//-----
	FILE* fp;
	png_byte sig[8];
	int bit_depth,color_type;
	double gamma;
	png_uint_32 channels, row_bytes;
	png_structp png_ptr =0;
	png_infop info_ptr=0;

	//This is the SDK Default path....

	if(path,path.size()<1)
	{
		path.path.push_back("");  
	//Code is missing
		path.path.push_back("../../../../MEDIA/texture/cubemaps");
		path.path.push_back("../../../../../../../MEDIA/texture/cubemaps");
		path.path.push_back("../../../MEDIA/texture/3D");
		path.path.push_back("../../../../MEDIA/texture/3D");
		path.path.push_back("../../../../../../../MEDIA/texture/cubemaps");
	}
	//open the png input file
	if (!filename) return;
	if(!fp=path.fopen(filename)))

#ifdef WIN32
	{
		//Try reource access
		Hres= FindResource(png_resource.hModule,FileName,png_resource.res_type_id ? (LPCSTR)png_resource.res_type_id:
		.re_type_name.c_str());
		if(!HRes)
			FAILMSGANDRETURN
		hglobal=LoadResource(png_resource.hModule,HRes);
		if(!hglobal)
			FAILMSGANDRETURN
		ressz=SizeofResource(png_resource.hModule,Hres);
		resptr=(char*)LockResource(hglobal);
		if(!resptr)
			FAILMSGANDRETURN
	}
#else
		FAILMSGANDRETURN
#endif
		//first check the eight byte PNG signature
		PNG_READHEADER fread(sig,1,8,fp);
	if(!png_check_sig(sig,8))
	{
		if(fp) fclose(fp);
		PNG_FREERESOURCE
			return;
	}
	//start back here...!!!
	//create the two png(-info) structures
	png_ptr=png_create_read_struct(PNG_LIBPNG_VER_STRING,0,0,0);
	if(!png_ptr)
	{
		if(fp) fclose(fp);
		PNG_FREERESOURCE
		return;
	}
	info_ptr =png_create_info_struct(png_ptr);
	if(!info_ptr)
	{
		png_destroy_read_struct(&png_ptr,0,0);
		if(fp) fclose(fp);
		PNG_FREERESOURCE
	}
	//initialize the png structure
	//Code is missing

	//Expand images of all color type and bit_depth to 3x8 bit rgb image
	// let the library process things like alpha, transparency, background

	if(bit-depth==16) png_set_strip_16(png_ptr);
	if(color_type==PNG_COLOR_TYPE_PA:ETTE) png_set_expand(png_ptr);
	if(bit_depth<8)png_set_expand(png_ptr);
	if(png_get_valid(png_ptr,info_otr,PNG_INFO_tRNS))png_set_expand()//code missing..?
	if(color_type==PNG_COLOR_TYPE_GRAY ||
		color_type==PNG_COLOR_TYPE_GRAY_ALPHA)
		png_swet_gray_to_rgb(png_ptr);
	if(color_type==PNG_COLOR_TYPE_RGB_ALPHA)
		png_set_strip_alpha(png_ptr);

//if required set gamma conversion
	if( png_get_gAMA(png_ptr,info_ptr,&gamma))png_set_gamma(png_ptr,//code missing 
		gamma);
	//after the transformations have been registered update info_ptr///comment missing..??
	png_read_update_info(png_ptr,infp_ptr);
	//get again width, height and the new bit-depth and color type
	png_get_IHDR(png_ptr,info_ptr,&w,&h,&bit_depth,&color_type,0,....//code missing

	//row_bytes is the width x number of channels
	row_bytes=png_get_rowbytes(png_ptr,info_ptr);
	channels=png_get_channels(png_ptr,info_ptr);
	if(channels==40
	{
		fprintf(stderr,"Unable to open image of type RGBA \"%s\"using...//COde missing
		fprintf(stderr,"Try using read_png_rgba() instead!\n\n);
		return;
	}
	//now we can allocate memory to stroe the image
	png_byte* img= new png_byte[row_bytes* h];
	//and allocate memory for an array of row-pointers
	png_byte ** row=new png_byte * [h];
	//set the individual row_pointers to point at the correct offsets
	for(unsigned in ti=0;i<h;i++)
		row[i]=img+i * row_bytes;
	//now we can go ahead and just read the whole image
	png_read_image(png_ptr,row);

	//read the additional chunks in the PNG file (not really needed)
	png_read_end(png_ptr,NULL);
	image- arrray2<vec3ub>(w,h);


	//code is missing

	if(fp) fclose(fp);
	PNG_FREERESOURCE
}


//FIXME:LIBPNG expands to RGB and only R is Fetched.....

void read_png_grey(const char* filename, glh:: array2<unsigned char> &image.....//code missing
{
	//---Resource stuff
	PNG_DECLARE_RESVAR
	//------
	FILE * fp;
	png_byte sig[8];
	int bit_depth, color_type;
	double gamma;
	png_uint_32 channels,row_bytes;
	png_structp png_ptr=0;
	png_infop info_ptr=0;

	//This is the SDK default path....
	if(path.path.size()<1)
	{
		path.path.push_back("");   
		path.path.push_back("../../../MEDIA/TEXTURE/1D");  		
		path.path.push_back("../../../../MEDIA/TEXTURE/1D");   
		path.path.push_back("../../../../../../../MEDIA/TEXTURE/1D");   
		path.path.push_back("../../../MEDIA/TEXTURE/2D");   
		path.path.push_back("../../../../MEDIA/TEXTURE/2D"); 
		path.path.push_back("../../../../../../../MEDIA/TEXTURE/2D");
		path.path.push_back("../../../MEDIA/TEXTURE/rectangles");   
		path.path.push_back("../../../../MEDIA/TEXTURE/rectangles");
		path.path.push_back("../../../../../../../MEDIA/TEXTURE/rectangles");
		path.path.push_back("../../../MEDIA/TEXTURE/cubemaps");   
		path.path.push_back("../../../../MEDIA/TEXTURE/cubemaps");
		path.path.push_back("../../../../../../../MEDIA/TEXTURE/cubemaps"); 
		path.path.push_back("../../../MEDIA/TEXTURE/3D");   
		path.path.push_back("../../../../MEDIA/TEXTURE/3D");
		path.path.push_back("../../../../../../../MEDIA/TEXTURE/3D"); 
	}
	//open the png input file
	if (!filename) return;
	if (!(fp=path.fopen(filename)))
#ifdef WIN32
	{
		//try resource access
		HRes = FindResource.hModule,filename,
			png_resource.res_type_id? (LPCSTR)png_resource.res_type_id:  // code missing
			.res_type_name.c_str());
		if(!HRes)
			FAILMSGANDRETURN
		hglobal-LoadResource(png_resource.hModule,HRes);
		if(!hglobal)
			FAILMSGANDRETURN
		ressz=SizeofResource(png_resource.hModule,HRes);
		resptr=(char*) LockResource(hglobal);

		//Code missing


		PNG_FREERESOURCE
				return;
		}
		//Start back here!!!

		//create the two png(-info) strucutres

		png_ptr=png_create_read_struct(PNG_LIBPNG_VER_STRING,0,0,0);
		if(!png_ptr)
		{
			if(fp) fclose(fp);
			PNG_FREERESOURCE
				return;
		}
		info_ptr=png_create-info_struct(png_ptr);
		if(!info_ptr)
		{
			png_destroy_read_struct(&png_ptr,0,0);
			if(fp) fclose(fp);
			PNG_FREERESOURCE
		}
		//initialize the png structure
		PNG_SETREADFN png_init_io(png_ptr,fp);
		
		png_set_sig_bytes(png_ptr,8);
		

		//read all png info up to image data
		png_read_info(png_ptr,info_ptr);

		//get widht,height,bit-depth and colo-type
		unsigned long w,h;
		png_get_IHDR(png_ptr,info-otr,&w,&h,&bit_depth,&color_type,0,0,//code missing

		//expand image of all color-type and bit-depth to 3x8 bit RGB images
		//let the library process things like alpha. transparency, background

		if(bit_depth --16)png_set_strip_16(png_ptr);
		if(color_type==PNG_COLOR_TYPE_PALETTE) png_set_expand(png_ptr);
		if(bit_depth<8) png_set_expand(png_ptr);
		if(png_get_valid(png_ptr,info_ptr,PNG_INFO_tRNS)) png_set_espand(p....//code missing
		if(color_type==PNG_COLOR_TYPE_GRAY|| color_type==PNG_COLOR_TYPE_GRAY_ALPHA)
			png_set_gray_to_rgb(png_ptr);
		//if reqiured set gamma conversion
		if(png_get_gAMA(png_ptr,info_ptr,&gamma)) png_set_gamma(png_ptr,....//COde missing
		gamma);

		//after the transformations have been registered update the info_ptr data...//?
		png_read_update_info(png_ptr,info_ptr);

		//get again width, height and the new bit-depth and color-type

		png_get_IHDR(png_ptr,info_ptr,&w,&h,&bit_depth,&color_type,0,0,.......//code is missing

		//row_bytes is the width x number of channels
		row bytes= png_get_rowbytes(png_ptr,info_ptr);

		//Code missing

		//set the individual row-pointers to point at the correct offsets

	for( unsigned int i=0;i<h;i++)
	{
		row[i]=img+i*row_bytes;

	//now we can go ahead and just read the whole image
	png_read_image(ong_ptr,row);
//read the additional chunks in the PNG file 

	png_read_end(png_ptr,NULL);
	image= array2<vec4ub>(w,h);
	{
		for(unsigned int i=0;i<w;i++);
			for(unsigned int j=0;j<h;j++)
			{
				image(i,j)=vec4ub(img+((h-j-1)*row_bytes+i*4));
			}
	}
	delete [] row;
	delete [] img;
	png_destroy_read_struct(&png_ptr,&info_ptr,0);

	if(fp) fclose(fp);
	PNG_FREERESOURCE
}

/** 
read callback used by png library when using resource
**/
	void png_read_resource_fn(png_structp png_bytep data,png_size_t....//code missing
	{
		png_bytep src=(png_bytep)png_ptr->io_ptr;
		for(unsigned int i=0; i<leng;i++)
			data[i]=*SRCAND++;
		png_ptr->io_ptr=(void*)src;
	}

		

