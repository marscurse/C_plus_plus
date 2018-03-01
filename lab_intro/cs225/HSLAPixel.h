/**
 * @file HSLAPixel.h
 *
 * @author CS 225: Data Structures
 * @version 2018r1-lab1
 */

#ifndef CS225_HSLAPIXEL_H_
#define CS225_HSLAPIXEL_H_

#include <iostream>
#include <sstream>

namespace cs225 {
  class HSLAPixel{
    public:
  double h;   //[0,360)
  double s;   //[0,1]
  double l;   //[0.1]
  double a;   //[0,1]
  
  HSLAPixel();
  HSLAPixel(double hue, double saturation, double luminance);
  HSLAPixel(double hue, double saturation, double luminance, double alpha);

  };
}

#endif
