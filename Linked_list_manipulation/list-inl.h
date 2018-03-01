#include <iostream>
/**
 * @file list.cpp
 * Doubly Linked List (MP 3).
 */

/**
 * Destroys the current List. This function should ensure that
 * memory does not leak on destruction of a list.
 */
template <class T>
List<T>::~List() {
  /// @todo Graded in MP3.1
  clear();
}

/**
 * Destroys all dynamically allocated memory associated with the current
 * List class.
 */
template <class T>
void List<T>::clear() {

  /// @todo Graded in MP3.1
  ListNode* temp;
  temp = head_;
  while(temp!=NULL){
    temp = temp->next;
  }
  tail_= NULL;
  length_ = 0;
}

/**
 * Inserts a new node at the front of the List.
 * This function **SHOULD** create a new ListNode.
 *
 * @param ndata The data to be inserted.
 */
template <class T>
void List<T>::insertFront(T const & ndata) {
  /// @todo Graded in MP3.1
  ListNode* temp = new ListNode(ndata);
  if(head_ == NULL){
    head_ = temp;
    tail_ = temp;
    length_ = 1;
  }else{
    length_++;
    temp->next = head_;
    temp->prev = NULL;
    head_->prev = temp;
    head_ = temp;
  }
}


/**
 * Inserts a new node at the back of the List.
 * This function **SHOULD** create a new ListNode.
 *
 * @param ndata The data to be inserted.
 */
template <class T>
void List<T>::insertBack(const T & ndata) {
  /// @todo Graded in MP3.1
  ListNode* temp = new ListNode(ndata);
  if(head_ == NULL){
    insertFront(ndata);
  }else{
    tail_->next = temp;
    temp->prev = tail_;
    temp->next = NULL;
    tail_ = temp;
    length_++;
  }
}

/**
 * Reverses the current List.
 */
template <class T>
void List<T>::reverse() {
  reverse(head_, tail_);
}

/**
 * Helper function to reverse a sequence of linked memory inside a List,
 * starting at startPoint and ending at endPoint. You are responsible for
 * updating startPoint and endPoint to point to the new starting and ending
 * points of the rearranged sequence of linked memory in question.
 *
 * @param startPoint A pointer reference to the first node in the sequence
 *  to be reversed.
 * @param endPoint A pointer reference to the last node in the sequence to
 *  be reversed.
 */
 template <class T>
 void List<T>::reverse(ListNode *& startPoint, ListNode *& endPoint) {
   /// @todo Graded in MP3.1
   /*if(startPoint==endPoint){
     return;
   }
   ListNode* temp = endPoint;
   endPoint = startPoint;
   startPoint = temp;
   reverse(startPoint->next,endPoint->prev);*/
    /// @todo Graded in MP3.1
    //first find the length of the reverse part
	//if(startPoint == endPoint||startPoint == NULL || endPoint == NULL)
 	     //  return;
	ListNode * startp = startPoint;
	ListNode * linkstart = startPoint->prev;
	ListNode * endp = endPoint;
	ListNode * linkend = endPoint->next;

  while(startPoint != endPoint)
	{
		ListNode * temp = startPoint->prev;
		startPoint->prev = startPoint->next;
		startPoint->next = temp;
		startPoint = startPoint->prev;
	}//put the whole list one by one after the next element

	ListNode * temp = startPoint->prev;
	startPoint->prev = linkstart;//reconnect head_
	startPoint->next = temp;
	endPoint = startp;
	endPoint->next = linkend;//reconnect end;
//base case
  if(linkstart == NULL)
    head_ = startPoint;
  else{
    linkstart->next = startPoint;}
  if(linkend == NULL){
    tail_ = endPoint;}
  else{
    linkend->prev = endPoint;}
}


/**
 * Reverses blocks of size n in the current List. You should use your
 * reverse( ListNode * &, ListNode * & ) helper function in this method!
 *
 * @param n The size of the blocks in the List to be reversed.
 */
template <class T>
void List<T>::reverseNth(int n) {
  /// @todo Graded in MP3.1
  if(head_==NULL){
    return;
  }
    ListNode* temp1 = head_;
    ListNode* temp2 = head_;
    while(temp2!=tail_){
      temp2 = temp1;
      for(int i=0;i<n-1;i++){
        if(temp2->next!=NULL){
          temp2 = temp2->next;
        }
      }
      //std::cout << temp1 << '\n';
      reverse(temp1,temp2);
      //std::cout << temp1 << '\n';
      temp1 = temp2->next;

    }

}

/**
 * Modifies the List using the waterfall algorithm.
 * Every other node (starting from the second one) is removed from the
 * List, but appended at the back, becoming the new tail. This continues
 * until the next thing to be removed is either the tail (**not necessarily
 * the original tail!**) or NULL.  You may **NOT** allocate new ListNodes.
 * Note that since the tail should be continuously updated, some nodes will
 * be moved more than once.
 */
template <class T>
void List<T>::waterfall() {
  /// @todo Graded in MP3.1
  int flag = 0;
  int timee = 0;
  ListNode* temp = head_;
  ListNode* temp_next = NULL;
  while(temp!=tail_){
    flag = timee%2;
    if(flag==1){
      temp->prev->next = temp->next;
      temp->next->prev = temp->prev;
      tail_->next = temp;
      temp_next = temp->next;
      temp->next = NULL;
      temp->prev = tail_;
      tail_ = temp;
      //std::cout << "a" << '\n';
      temp = temp_next;
    }else{
      temp = temp->next;
    }

    if(temp==NULL){
      std::cout << "ccc" << '\n';
    }
    timee++;
    std::cout << timee << '\n';
  }
}

/**
 * Splits the given list into two parts by dividing it at the splitPoint.
 *
 * @param splitPoint Point at which the list should be split into two.
 * @return The second list created from the split.
 */
template <class T>
List<T> List<T>::split(int splitPoint) {
    if (splitPoint > length_)
        return List<T>();

    if (splitPoint < 0)
        splitPoint = 0;

    ListNode * secondHead = split(head_, splitPoint);

    int oldLength = length_;
    if (secondHead == head_) {
        // current list is going to be empty
        head_ = NULL;
        tail_ = NULL;
        length_ = 0;
    } else {
        // set up current list
        tail_ = head_;
        while (tail_ -> next != NULL)
            tail_ = tail_->next;
        length_ = splitPoint;
    }

    // set up the returned list
    List<T> ret;
    ret.head_ = secondHead;
    ret.tail_ = secondHead;
    if (ret.tail_ != NULL) {
        while (ret.tail_->next != NULL)
            ret.tail_ = ret.tail_->next;
    }
    ret.length_ = oldLength - splitPoint;
    return ret;
}

/**
 * Helper function to split a sequence of linked memory at the node
 * splitPoint steps **after** start. In other words, it should disconnect
 * the sequence of linked memory after the given number of nodes, and
 * return a pointer to the starting node of the new sequence of linked
 * memory.
 *
 * This function **SHOULD NOT** create **ANY** new List or ListNode objects!
 *
 * @param start The node to start from.
 * @param splitPoint The number of steps to walk before splitting.
 * @return The starting node of the sequence that was split off.
 */
template <class T>
typename List<T>::ListNode * List<T>::split(ListNode * start, int splitPoint) {
  /// @todo Graded in MP3.2
  if(start == NULL){
    return start;
  }
  ListNode* output = start;
  for(int i = 0;i<splitPoint;i++){
    if(output!=NULL){
        output = output->next;
    }else{
      return output;
    }
  }
  output->prev->next = NULL;
  output->prev =NULL;
  return output;

}

/**
 * Merges the given sorted list into the current sorted list.
 *
 * @param otherList List to be merged into the current list.
 */
template <class T>
void List<T>::mergeWith(List<T> & otherList) {
    // set up the current list
    head_ = merge(head_, otherList.head_);
    tail_ = head_;

    // make sure there is a node in the new list
    if (tail_ != NULL) {
        while (tail_->next != NULL)
            tail_ = tail_->next;
    }
    length_ = length_ + otherList.length_;

    // empty out the parameter list
    otherList.head_ = NULL;
    otherList.tail_ = NULL;
    otherList.length_ = 0;
}

/**
 * Helper function to merge two **sorted** and **independent** sequences of
 * linked memory. The result should be a single sequence that is itself
 * sorted.
 *
 * This function **SHOULD NOT** create **ANY** new List objects.
 *
 * @param first The starting node of the first sequence.
 * @param second The starting node of the second sequence.
 * @return The starting node of the resulting, sorted sequence.
 */
template <class T>
typename List<T>::ListNode * List<T>::merge(ListNode * first, ListNode* second) {
  /// @todo Graded in MP3.2
  if(first==NULL){
    return NULL;
  }
  if(second == NULL){

    return NULL;
  }
  if(first==second){
    return first;
  }
  ListNode* tempa =first;
  ListNode* tempb = second;
  ListNode* output = first;
  if(first->data<second->data){
    output = first;
    tempa = tempa->next;
  }else{
    output = second;
    tempb = tempb->next;
  }
  /*ListNode* temp1 = first;
  ListNode* temp2 = second;
  int b = 0;
  int c = 0;
  while(temp1!=NULL){
    temp1 = temp1->next;
    b++;
  }
  std::cout << b << '\n';
  while(temp2!=NULL){
    temp2 = temp2->next;
    c++;
  }
  std::cout << c << '\n';
  std::cout << b << '\n';*/
  //std::cout << size() << '\n';
  int a=0;
  ListNode* outputa = output;
  while(1){
    if(tempa==NULL){
      outputa->next = tempb;
      tempb->prev = outputa;
      std::cout << "damn a" << '\n';
      break;
    }
    if(tempb==NULL){
      outputa->next = tempa;
      tempa->prev = outputa;
      std::cout << "damn b" << '\n';
      break;
    }
    if(tempa->data<tempb->data){
      outputa->next = tempa;
      tempa->prev = outputa;
      outputa = tempa;
      tempa = tempa->next;
      //std::cout << "a" <<a<< '\n';
    }else{
      outputa->next = tempb;
      tempb->prev = outputa;
      outputa = tempb;
      tempb = tempb->next;
      //std::cout << "b" << '\n';
    }

  }
  second = NULL;
  return output;

}

/**
 * Sorts the current list by applying the Mergesort algorithm.
 */
template <class T>
void List<T>::sort() {
    if (empty())
        return;
    head_ = mergesort(head_, length_);
    tail_ = head_;
    while (tail_->next != NULL)
        tail_ = tail_->next;
}

/**
 * Sorts a chain of linked memory given a start node and a size.
 * This is the recursive helper for the Mergesort algorithm (i.e., this is
 * the divide-and-conquer step).
 *
 * @param start Starting point of the chain.
 * @param chainLength Size of the chain to be sorted.
 * @return A pointer to the beginning of the now sorted chain.
 */
template <class T>
typename List<T>::ListNode* List<T>::mergesort(ListNode * start, int chainLength) {
  /// @todo Graded in MP3.2
  ListNode* output=start;
  if(chainLength==1){
    start->next =NULL;
    start->prev = NULL;
    return start;
  }else{
    ListNode* temp = start;
    for(int i = 0;i<chainLength/2;i++){
      temp = temp->next;
    }//get the second start;
    temp->prev->next = NULL;
    temp->prev = NULL;
    start = mergesort(start,chainLength/2);
    temp = mergesort(temp,chainLength-chainLength/2);
    output = merge(start,temp);
  }
  return output;
}
