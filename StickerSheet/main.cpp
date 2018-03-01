

#include "Image.h"
#include "StickerSheet.h"
#include "cs225/PNG.h"
Image *transfer(cs225::PNG& png);
int main() {

 //
 // Reminder:
 //   Before exiting main, save your creation to disk as myImage.png
 //
 cs225::PNG picture;
 /*add picture*/
 picture.readFromFile("expected-scale2x.png");
 Image *whatever = transfer(picture);
 StickerSheet sheet(*whatever, 6);
 delete whatever;
 /*add sticker*/
 picture.readFromFile("i.png");
 whatever = transfer(picture);
 sheet.addSticker(*whatever,200,800);
 delete whatever;

 picture.readFromFile("i.png");
 whatever = transfer(picture);
 sheet.addSticker(*whatever,800,800);
 delete whatever;
 /*Finish add sticker*/
 picture.readFromFile("i.png");
 whatever = transfer(picture);
 sheet.addSticker(*whatever,800,20);
 delete whatever;
 picture.readFromFile("i.png");
 whatever = transfer(picture);
 sheet.addSticker(*whatever,1200,20);
 delete whatever;

 Image result = sheet.render();
 result.writeToFile("myImage");
 return 0;

}

Image* transfer(cs225::PNG &png){
 Image * temp = new Image();
 //temp->scale(png.width(),png.height());
 temp->resize(png.width(),png.height());
 for (unsigned int i = 0; i < png.width(); i++){
   for (unsigned int j = 0;j < png.height(); j++){
     cs225::HSLAPixel& pixel = temp->getPixel(i,j);
     cs225::HSLAPixel& pixel2 = png.getPixel(i,j);
     pixel = pixel2;
   }
 }
 return temp;
}
