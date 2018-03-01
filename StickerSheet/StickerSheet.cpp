#include "StickerSheet.h"
<<<<<<< HEAD
#include <stido.h>
#include <iostream>

using namespace cs225;
using namespace std;

StickerSheet::StickerSheet(const Image & picture,unsigned max){
  head_ = new Node(picture);
  Max = max;
}
StickerSheet::~StickerSheet(){
  for (Node* ptr = head;head;head = head->next){/*if head=NULL, linked list cleared
                                                  completely*/
    delete ptr;
  }
}
/*StickerSheet::Node::Copy_(const Node &other){
  this->data = other.data;
  Node* temp =new Node();
  
  this->Next = other.Next;
}*/
StickerSheet::StickerSheet(const StickerSheet &other){
  head_ = new Node();
  Node* temp2;
  temp2 = head_;
  Node* temp;
  temp = other.head_;
  while(temp->Next != NULL){
    temp2->Copy_(*temp);
    temp = temp->Next;
    temp2->next = NULL
  }
=======
using namespace cs225;
using namespace std;
#include <iostream>
StickerSheet::StickerSheet (const Image &picture, unsigned max){

  *data_ = picture;//set the background pic
  newwidth = picture.width();
  newheight = picture.height();
  max_ = max;
  head_ = NULL;
}

StickerSheet::~StickerSheet (){
  Node *list = head_;
  if (list == NULL) {
    if (data_ != NULL) {
      delete data_;
    }
  }else{
  Node *temp = list;//list->next;
  for (unsigned i = 0; i < max_; i++) {
    if (temp == NULL) {
      break;
    }
    delete temp->nodedata;
    list = temp->next;
    delete temp;
    temp = list;
  }
  delete data_;
  }
}

StickerSheet::StickerSheet (const StickerSheet &other){

  //Node* test2 = this->head_;
  /*while(temp!=NULL){
    cout<<"Pass"<<endl;
    temp = temp->next;
  }*/
  /*data_ = other.data_;
  newwidth = other.newwidth;
  newheight =  other.newheight;
  this->max_ = other.max_;
  this->head_= copy(*other.head_);
  if(other.head_ == NULL){
    this->head_ = NULL;
  }else{
    this->head_ = copy(*(other.head_));
  }//copy the head;

  Node* othercur = other.head_->next;
  Node* thiscur = this->head_;
  while(othercur!= NULL){
    thiscur->next = copy(*othercur);
    thiscur = thiscur->next;
    othercur = othercur->next;
  }*/
  /*Node* test = this->head_;


  while(test!=NULL){
    cout<<"Pass"<<endl;
    test = test->next;
  }*/
  Node* p1 = 0;
  Node* p2 = 0;

  this->max_ = other.max_;
  this->newwidth = other.newwidth;
  this->newheight = other.newheight;
  this->data_ = other.data_;
  if(other.head_==0){
    head_ = 0;
  }else{
    head_ =new Node;
    head_->x_ = other.head_->x_;
    head_->y_ = other.head_->y_;
    head_->w_ = other.head_->w_;
    head_->h_ = other.head_->h_;
    head_->nodedata = other.head_->nodedata;

    p1 = head_;
    p2 = other.head_->next;
  }
  while(p2){
    p1->next = new Node;
    p1=p1->next;
    p1->x_ = p2->x_;
    p1->y_ = p2->y_;
    p1->w_ = p2->w_;
    p1->h_ = p2->h_;
    p1->nodedata = p2->nodedata;

    p2 = p2->next;
  }
  p1 -> next = 0;
}

const StickerSheet & 	StickerSheet::operator= (const StickerSheet &other){
  /*output->max_ = other.max_;
  output->newwidth = other.newwidth;
  output->newheight = other.newheight;
  output->data_ = other.data_;
  output->head_ = copy(*other.head_);
  Node* temp = other.head_->next;
  Node*temp2 = output->head_;
  while(temp!=NULL){
    temp2->next = copy(*temp);
    temp2 = temp2->next;
    temp = temp->next;

  }*/
  this->~StickerSheet();
  Node* p1 = 0;
  Node* p2 = 0;

  this->max_ = other.max_;
  this->newwidth = other.newwidth;
  this->newheight = other.newheight;
  this->data_ = other.data_;
  if(other.head_==0){
    this->head_ =0;
  }else{
    this->head_ =new Node;
    this->head_->x_ = other.head_->x_;
    this->head_->y_ = other.head_->y_;
    this->head_->w_ = other.head_->w_;
    this->head_->h_ = other.head_->h_;
    this->head_->nodedata = other.head_->nodedata;

    p1 = this->head_;
    p2 = other.head_->next;
  }
  while(p2){
    p1->next = new Node;
    p1=p1->next;
    p1->x_ = p2->x_;
    p1->y_ = p2->y_;
    p1->w_ = p2->w_;
    p1->h_ = p2->h_;
    p1->nodedata = p2->nodedata;

    p2 = p2->next;
  }
  p1 -> next = 0;
  return *this;
}

void 	StickerSheet::changeMaxStickers (unsigned max){
  max_ = max;
}

int 	StickerSheet::addSticker (Image &sticker, unsigned x, unsigned y){
  if (head_ == NULL && max_ >= 1) {
    Node * list = new Node;
    head_ = list;
    list->next = NULL;
    Image *new_ = new Image(sticker);
    list->nodedata = new_;
    list->x_ = x;
    list->y_ = y;
    list->w_ = sticker.width();
    list->h_ = sticker.height();
    return 0;
  }//add the first Node
  Node *temp = head_;
  for (unsigned i = 0; i < max_ - 1; i++) {
    if (temp->next == NULL) {
      Node * _new = new Node;
      temp->next = _new;
      _new->next = NULL;
      Image *new_ = new Image(sticker);
      _new->nodedata = new_;
      _new->x_ = x;
      _new->y_ = y;
      _new->w_ = sticker.width();
      _new->h_ = sticker.height();
      //cout<<"add"<<endl;
      return i + 1;
    }
    temp = temp->next;
  }
  return -1;

}

bool 	StickerSheet::translate (unsigned index, unsigned x, unsigned y){
  Node *temp = head_;
  for (unsigned i = 0; i < max_; i++) {
    if (temp == NULL) {
      break;
    }
    if ( i == index) {
      temp->x_ = x;
      temp->y_ = y;
      return 1;
    }
    temp = temp->next;
  }
  return 0;
}

void 	StickerSheet::removeSticker (unsigned index){
  Node *temp = head_;
  Node *previous = head_;
  if ( index == 0 && temp != NULL) {
    previous = head_->next;
    delete head_;
    head_ = previous;
    //cout<<"head"<<endl;
  } else{
    /*temp = temp->next;
    for (unsigned i = 1; i < max_; i++) {
      if (temp == NULL) {
        break;
      }
    if ( i == index ) {
      previous->next = temp->next;
      delete temp->nodedata;
      delete temp;
      max_--;
      break;
    }
    previous = temp;
    temp = temp->next;
    }
  }*/
    temp = head_->next;
    for(unsigned int i = 1;i<index;i++){
      temp=temp->next;
      previous =previous->next;
      //cout<<i<<endl;
    }
    previous->next = temp->next;
    if(temp->next!=NULL){
      //cout<<"NULL"<<endl;
    }
    delete temp;
  }
  cout<<"delete"<<endl;
}

Image * 	StickerSheet::getSticker (unsigned index) const{
  Node *temp = head_;
  for (unsigned i = 0; i < max_; i++) {
    if (temp == NULL) {
      break;
    }
    if ( i == index ) {
      Image * retSticker = temp->nodedata;
      return retSticker;
    }
    temp = temp->next;
  }
  return NULL;
}

Image 	StickerSheet::render () const{
  cout<<"rendered"<<endl;
  Node * temp = head_;
  unsigned newWidth = newwidth;
  if (newWidth==0){
    cout<<"ERROR 1"<<endl;

  }

  unsigned newHeight = newheight;
  if (newHeight==0){
    cout<<"ERROR 2"<<endl;
  }
  data_->scale(newWidth,newHeight);
  for (unsigned int i = 0; i < max_; i++) {
    /*Begin*/
    if (temp == NULL) {
      break;
    }
    unsigned width = temp->w_;
    unsigned height = temp->h_;
    unsigned x = temp->x_;
    unsigned y = temp->y_;
    if ((x + width) > newWidth) {
      newWidth = x + width;
    }
    if ( (y + height) > newHeight) {
      newHeight = y + height;
    }
    //data_->scale(newWidth,newHeight);
    /*Start to render*/
    for (unsigned i = 0; i < newWidth; i++) {
      for (unsigned j = 0; j < newHeight; j++) {
        HSLAPixel &Pixel = data_->getPixel(i,j);
        if ( x <= i && i < x + temp->w_) {
          if ( y <= j && j < y + temp->h_) {
            HSLAPixel &tempPixel = temp->nodedata->getPixel(i-x,j-y);
            if (tempPixel.a > 0) {
              Pixel = tempPixel;
            }
          }
        }

      }
    }
    temp = temp->next;
  }
  cout<<"rendered"<<endl;
  return *data_;

>>>>>>> 28797f99abe97a708314adb248db5c6f71e34a6b
}
