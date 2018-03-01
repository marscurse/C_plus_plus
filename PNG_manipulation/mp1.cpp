#include "cs225/PNG.h"
#include "cs225/HSLAPixel.h"
#include <string>
#include <cmath>

using namespace cs225;


void rotate(std::string inputFile, std::string outputFile) {
  // Part 2
  cs225::PNG png;
  png.readFromFile(inputFile);
  unsigned int width_ = png.width();
  unsigned int height_ = png.height();
  cs225::PNG result(width_,height_);
  for (unsigned x = 0; x< width_; x++){
    for (unsigned y = 0; y <height_; y++){
      HSLAPixel *target = png.getPixel(x,y);
      HSLAPixel *destination = result.getPixel(width_-1-x,height_-1-y);
      destination->h = target->h;
      destination->s = target->s;
      destination->l = target->l;
      destination->a = target->a;
    }
  }
  result.writeToFile(outputFile);
}

PNG myArt(unsigned int width, unsigned int height) {
  PNG png(width, height);
  // Part 3
  for (unsigned int r = 0;r<height;r++){
    for (unsigned int c = 0;c<width;c++){
      HSLAPixel* back1 = png.getPixel(r,c);
      back1->h = 225;
      back1->s = 0.5;
      back1->l = 0;
      back1->a = 1;
    }
  }//the background

  for (unsigned int r = 99;r<250;r++){
    for(int c = 74;c<115;c++){
      HSLAPixel* back1 = png.getPixel(r,c);
      back1->h = 225;
      back1->s = 0.5;
      back1->l = 0.5;
      back1->a = 1;
    }
  }
  for (unsigned int r = 99;r<140;r++){
    for(int c = 100;c<350;c++){
      HSLAPixel* back1 = png.getPixel(r,c);
      back1->h = 225;
      back1->s = 0.5;
      back1->l = 0.5;
      back1->a = 1;
    }
  }
  for (unsigned int r = 99;r<230;r++){
    for(int c = 199;c<240;c++){
      HSLAPixel* back1 = png.getPixel(r,c);
      back1->h = 225;
      back1->s = 0.5;
      back1->l = 0.5;
      back1->a = 1;
    }
  }
//the cap F

  for (unsigned int r = 300;r<331;r++){
    for(int c = 74;c<350;c++){
      HSLAPixel* back1 = png.getPixel(r,c);
      back1->h = 225;
      back1->s = 0.5;
      back1->l = 0.5;
      back1->a = 1;
    }
  }
  for (unsigned int r = 300;r<450;r++){
    for(int c = 325;c<350;c++){
      HSLAPixel* back1 = png.getPixel(r,c);
      back1->h = 225;
      back1->s = 0.5;
      back1->l = 0.5;
      back1->a = 1;
    }
  }
  for (unsigned int r = 419;r<450;r++){
    for(int c = 74;c<350;c++){
      HSLAPixel* back1 = png.getPixel(r,c);
      back1->h = 225;
      back1->s = 0.5;
      back1->l = 0.5;
      back1->a = 1;
    }
  }
    //the cap U
  for(int c = 475;c<740;c++){
    for(int i = 300;i<331;i++){
      HSLAPixel* back1 = png.getPixel(i+235+(c*.5-475),c);
      back1->h = 225;
      back1->s = 0.5;
      back1->l = 0.5;
      back1->a = 1;
    }
  }
  for(int c = 475;c<740;c++){
    for(int i = 331;i<360;i++){
      HSLAPixel* back1 = png.getPixel(i-145-(c*.5-475),c);
      back1->h = 225;
      back1->s = 0.5;
      back1->l = 0.5;
      back1->a = 1;
    }
  }

  //the X

  for(int c = 475;c<740;c++){
    for(int i = 530;i<561;i++){
      HSLAPixel* back1 = png.getPixel(i+235+(c*.5-475),c);
      back1->h = 225;
      back1->s = 0.5;
      back1->l = 0.5;
      back1->a = 1;
    }
  }
  for(int c = 475;c<740;c++){
    for(int i = 561;i<590;i++){
      HSLAPixel* back1 = png.getPixel(i-145-(c*.5-475),c);
      back1->h = 225;
      back1->s = 0.5;
      back1->l = 0.5;
      back1->a = 1;
    }
  }

//the X
for (unsigned int r = 300;r<331;r++){
  for(int c = 77;c<350;c++){
    HSLAPixel* back1 = png.getPixel(r+220,c);
    back1->h = 225;
    back1->s = 0.5;
    back1->l = 0.5;
    back1->a = 1;
  }
}
for (unsigned int r = 419;r<445;r++){
  for(int c = 74;c<350;c++){
    HSLAPixel* back1 = png.getPixel(r+225,c);
    back1->h = 225;
    back1->s = 0.5;
    back1->l = 0.5;
    back1->a = 1;
  }
}
for(int c = 475;c<750;c++){
  for(int i = 530;i<570;i++){
    HSLAPixel* back1 = png.getPixel(i+275+(c*.4-475),c-400);
    back1->h = 225;
    back1->s = 0.5;
    back1->l = 0.5;
    back1->a = 1;
  }
}


  for(int c = 475;c<740;c++){
    for(int i = 530;i<561;i++){
      HSLAPixel* back1 = png.getPixel(i+235-430+(c*.5-475),c);
      back1->h = 225;
      back1->s = 0.5;
      back1->l = 0.5;
      back1->a = 1;
    }
  }
  for(int c = 475;c<740;c++){
    for(int i = 561;i<590;i++){
      HSLAPixel* back1 = png.getPixel(i-145-430-(c*.5-475),c);
      back1->h = 225;
      back1->s = 0.5;
      back1->l = 0.5;
      back1->a = 1;
    }
  }


for (unsigned int r = 0;r<height;r++){
  for (unsigned int c = 0;c<width;c++){
    HSLAPixel* back1 = png.getPixel(r,c);
    int distance = sqrt(r*r+c*c);
    if(r>500&&c<400||(r<300&&c>400)){
      if(back1->l==0.5){
        back1->l = 1;
      }
    }
    if(back1->l==0.5){
      back1->h = back1->h+distance%360;
    }

  }
}//the background

  return png;
}
