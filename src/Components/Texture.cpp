#include "Components/Texture.h"

#define STB_IMAGE_IMPLEMENTATION
#include "Dependencies/stb_image.h"

#include <iostream>
#include <GL/glew.h>

Texture::Texture(std::string textureImagePath)
{
  glGenTextures(1, &texture);
  glBindTexture(GL_TEXTURE_2D, texture);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
  
  unsigned char* data = stbi_load(&textureImagePath[0], &width, &height, &channelCount, 0);
  if(data)
  {
    glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
    if(channelCount == 3)
      glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
    if(channelCount == 4)
      glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);
    glGenerateMipmap(GL_TEXTURE_2D);
  }
  else
  {
    std::cout << "Failed to load texture: " << textureImagePath << std::endl;
  }
  stbi_image_free(data);
}

unsigned int Texture::getTexture()
{
  return texture;
}