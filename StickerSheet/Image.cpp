#include <stdio.h>
#include "Image.h"
#include "cs225/PNG.h"
#include "cs225/HSLAPixel.h"
#include <string>
#include <cmath>
namespace cs225{
  void Image::lighten(){
    for (unsigned int x = 0;x<this->width();x++){
      for (unsigned int y = 0;y<this->height();y++){
        HSLAPixel & pixel = this->getPixel(x,y);
        if(pixel.l<=1&&pixel.l>=0){
          pixel.l+=0.1;
        }
        if(pixel.l>1){
          pixel.l = 1;
        }
      }
    }
  }
  void Image::lighten(double amount){
    for (unsigned int x = 0;x<this->width();x++){
      for (unsigned int y = 0;y<this->height();y++){
        HSLAPixel & pixel = this->getPixel(x,y);
        if(pixel.l<=1&&pixel.l>=0){
          pixel.l+=amount;
        }
        if(pixel.l>1){
          pixel.l = 1;
        }
      }
    }
  }
  void Image::darken(){
    for (unsigned int x = 0;x<this->width();x++){
      for (unsigned int y = 0;y<this->height();y++){
        HSLAPixel & pixel = this->getPixel(x,y);
        if(pixel.l<=1&&pixel.l>=0){
          pixel.l-=0.1;
        }
        if(pixel.l<0){
          pixel.l = 0;
        }
      }
    }
  }
  void Image::darken(double amount){
    for (unsigned int x = 0;x<this->width();x++){
      for (unsigned int y = 0;y<this->height();y++){
        HSLAPixel & pixel = this->getPixel(x,y);
        if(pixel.l<=1&&pixel.l>=0){
          pixel.l-=amount;
        }
        if(pixel.l<0){
          pixel.l = 0;
        }
      }
    }
  }
  void Image::saturate(){
    for (unsigned int x = 0;x<this->width();x++){
      for (unsigned int y = 0;y<this->height();y++){
        HSLAPixel & pixel = this->getPixel(x,y);
        if(pixel.s<=1&&pixel.l>=0){
          pixel.s+=0.1;
        }
      }
    }
  }
  void Image::saturate(double amount){
    for (unsigned int x = 0;x<this->width();x++){
      for (unsigned int y = 0;y<this->height();y++){
        HSLAPixel & pixel = this->getPixel(x,y);
        if(pixel.s<=1&&pixel.l>=0){
          pixel.s+=amount;
        }
      }
    }
  }
  void Image::desaturate(){
    for (unsigned int x = 0;x<this->width();x++){
      for (unsigned int y = 0;y<this->height();y++){
        HSLAPixel & pixel = this->getPixel(x,y);
        if(pixel.s<=1&&pixel.l>=0){
          pixel.s-=0.1;
        }
      }
    }
  }
  void Image::desaturate(double amount){
    for (unsigned int x = 0;x<this->width();x++){
      for (unsigned int y = 0;y<this->height();y++){
        HSLAPixel & pixel = this->getPixel(x,y);
        if(pixel.s<=1&&pixel.l>=0){
          pixel.s-=amount;
        }
      }
    }
  }
  void Image::grayscale(){
    for (unsigned int x = 0;x<this->width();x++){
      for (unsigned int y = 0;y<this->height();y++){
        HSLAPixel & pixel = this->getPixel(x,y);
        pixel.s = 0;
        }
      }
    }


  void Image::illinify(){
    for (unsigned int x = 0;x<this->width();x++){
      for (unsigned int y = 0;y<this->height();y++){
        HSLAPixel & pixel = this->getPixel(x,y);
        if(pixel.h>216){
          if((pixel.h-216)>(371-pixel.h)){
            pixel.h = 11;
          }else{
            pixel.h =216;
          }
        }
      }
    }
  }
  void Image::rotateColor(double degrees){
    for (unsigned int x = 0;x<this->width();x++){
      for (unsigned int y = 0;y<this->height();y++){
        HSLAPixel & pixel = this->getPixel(x,y);
        pixel.h = pixel.h+degrees;
        while(pixel.h<0){
          pixel.h+=360;
        }
        pixel.h = std::fmod(pixel.h,360.00);
      }
    }
  }

  void Image::scale(double factor){
    unsigned int width_a = this->width();
    unsigned int height_a = this->height();
    cs225::PNG png(width_a*factor,height_a*factor);
    for (unsigned x=0;x<width_a;x++){
      for(unsigned y = 0;y<height_a;y++){
        HSLAPixel &target = this->getPixel(x,y);
        for (unsigned i = factor*x;i<factor*x+factor;i++){
          for(unsigned j = factor*y;j<factor*(y+1);j++){
            png.getPixel(i,j) = target;
          }
        }
      }
    }
    this->resize(width_a*factor,height_a*factor);

    for (unsigned int x1 = 0;x1<this->width();x1++){
      for (unsigned int y1 = 0;y1<this->height();y1++){
        HSLAPixel& pixel = this->getPixel(x1,y1);
        HSLAPixel& pixel2 = png.getPixel(x1,y1);
        pixel = pixel2;
      }
    }
  }

  void Image::scale (unsigned w, unsigned h){
    Image & tempImage = *this;
    unsigned int width_a = tempImage.width();
    unsigned int height_a = tempImage.height();
    double factor_a = w / width_a;
    double factor_b = h / height_a;
    cs225::PNG png(width_a*factor_a,height_a*factor_b);
    for (unsigned x=0;x<width_a;x++){
      for(unsigned y = 0;y<height_a;y++){
        HSLAPixel &target = this->getPixel(x,y);
        for (unsigned i = factor_a*x;i<factor_a*(x+1);i++){
          for(unsigned j = factor_b*y;j<factor_b*(y+1);j++){
            png.getPixel(i,j) = target;
          }
        }
      }
    }
    this->resize(w,h);

    for (unsigned int x1 = 0;x1<this->width();x1++){
      for (unsigned int y1 = 0;y1<this->height();y1++){
        HSLAPixel& pixel = this->getPixel(x1,y1);
        HSLAPixel& pixel2 = png.getPixel(x1,y1);
        pixel = pixel2;
      }
    }
  }
}
