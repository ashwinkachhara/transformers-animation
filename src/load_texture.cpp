#include "load_texture.hpp"

GLuint loadTexture(const char* filepath) {
  GLuint texture; 
  unsigned char header[54];
  unsigned int position = 54;
  unsigned int width;
  unsigned int height;
  unsigned int imagesize; 
  unsigned char* pixel;

  FILE * bmpfile;
  bmpfile  = fopen(filepath, "rb");
  if(!bmpfile) {printf("Image not found\n"); return 0;}
  fread(header,1,54,bmpfile);
  width = *(int*)&(header[18]);
  height = *(int*)&(header[22]);
  imagesize = width*height*3;

  pixel = new unsigned char[imagesize];
  fread(pixel,1,imagesize,bmpfile);
  fclose(bmpfile);

  glGenTextures(1, &texture);
  glBindTexture(GL_TEXTURE_2D, texture);
  
  glTexImage2D(GL_TEXTURE_2D, 0,GL_RGB, width, height, 0, GL_BGR, GL_UNSIGNED_BYTE, pixel);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
  return texture;
}
