/**
 * @file StickerSheet.h
 * Contains your declaration of the interface for the StickerSheet class.
 */
#ifndef STICKERSHEET_H_
#define STICKERSHEET_H_
<<<<<<< HEAD
#include <stdio.h>
#include <iostream>
#include "Image.h"
=======
#include "Image.h"
#include "cs225/PNG.h"

using namespace cs225;
class StickerSheet: public Image{
public:
  /*Constructor and Destructor*/
  StickerSheet (const Image &picture, unsigned max);
  ~StickerSheet ();
  StickerSheet (const StickerSheet &other);
  /*Member Function*/
  const StickerSheet & 	operator= (const StickerSheet &other);
  void 	changeMaxStickers (unsigned max);
  int 	addSticker (Image &sticker, unsigned x, unsigned y);
  bool 	translate (unsigned index, unsigned x, unsigned y);
  void 	removeSticker (unsigned index);
  Image *getSticker (unsigned index) const;
  Image 	render () const;
  //void Draw(Image &sticker, unsigned x, unsigned y);
  struct Node{
    Image *nodedata;
    unsigned x_;
    unsigned y_;
    Node * next;
    unsigned w_;
    unsigned h_;
  };
  //
  Node* copy(const Node& a){
    Node* out = new Node;
    Image *input = a.nodedata;
    out->nodedata = new Image(*input);
    out->x_ = a.x_;
    out->y_ = a.y_;
    out->w_ = a.w_;
    out->h_ = a.h_;
    out->next = NULL;
    return out;
  };
  void test(){
    Node* test2 = this->head_;
    while(test2!=NULL){
      cout<<"Contain number of elements"<<endl;
      test2 = test2->next;
    }
  };
private:
  Image * data_ = new Image;
  Node * head_;
  unsigned max_;
  unsigned newwidth;
  unsigned newheight;
};


>>>>>>> 28797f99abe97a708314adb248db5c6f71e34a6b

using namespace cs225;
using namespace std;
template <typename T>
class StickerSheet{
  public:
    StickerSheet(const Image & picture, unsigned max);
    ~StickerSheet();
    StickerSheet(const StickerSheet &other);
    const StickerSheet& operator = (const StickerSheet& other);
    void changeMaxStickers(unsigned max);
    int addSticker(Image &sticker,unsigned x,unsigned y);
    bool translate(unsigned index, unsigned x, unsigned y);
    void removeSticker(unsigned index);
    Image* getSticker(unsigned index) const;//image:PNG
    Image render() const;
  private:
    Node *head_; //POINTER TO THE HEAD NODE;
    int Max_;
    class Node{
      public:
        Copy_(Node &other);
        T & data;
        Node *Next;//pointer to the next node
        Node(T& data): data(data),next(NULL);//Constructor of one Node
    };

};

#endif
