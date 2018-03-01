#include <cstdlib>
#include <cmath>

#include "cs225/PNG.h"
#include "cs225/HSLAPixel.h"
using namespace cs225;

// sets up the output image
PNG* setupOutput(unsigned w, unsigned h) {
    PNG* image = new PNG(w, h);
    return image;
}

// Returns my favorite color
HSLAPixel* myFavoriteColor(double saturation) {
    HSLAPixel *pixel = new HSLAPixel(76, saturation, 0.5);
    return pixel;
}

void sketchify(std::string inputFile, std::string outputFile) {
    // Load in.png
    PNG* original=new PNG;
    cout<<"Reach"<<__LINE__<<endl;
    bool a = original->readFromFile(inputFile);
    cout<<a<<endl;

    double width = original->width();
    double height = original->height();
    cout<<"Reach"<<__LINE__<<endl;
    // Create out.png
    PNG* output=NULL;
    //cout<<"Reach"<<__LINE__<<endl;
    output=setupOutput(width, height);
    // Load our favorite color to color the outline
    //cout<<"Reach"<<__LINE__<<endl;
    HSLAPixel* myPixel = myFavoriteColor(0.5);
    // Go over the whole image, and if a pixel differs from that to its upper
    // left, color it my favorite color in the output
    //cout<<"Reach"<<__LINE__<<endl;
    for (int y = 1; y < height; y++) {
        for (int x = 1; x < width; x++) {
            // Calculate the pixel difference
            HSLAPixel & prev = original->getPixel(x - 1, y - 1);
            HSLAPixel & curr = original->getPixel(x, y);
            //cout<<"Reach"<<__LINE__<<endl;

            double diff = std::fabs(curr.h - prev.h);
            //cout<<"Reach"<<__LINE__<<endl;
            // If the pixel is an edge pixel,
            // color the output pixel with my favorite color
            cout<<"Reach"<<__LINE__<<endl;
            HSLAPixel *currOutPixel = &(output->getPixel(x, y));

            if (diff > 20) {
                *currOutPixel=*myPixel;
            }
        }
    }
    //cout<<"Reach"<<__LINE__<<endl;
    // Save the output file
    output->writeToFile(outputFile);

    // Clean up memory
    delete myPixel;
    delete output;
    delete original;
}
