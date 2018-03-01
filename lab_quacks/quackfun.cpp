/**
 * @file quackfun.cpp
 * This is where you will implement the required functions for the
 *  stacks and queues portion of the lab.
 */
#include <iostream>
using namespace std;

namespace QuackFun {

/**
 * Sums items in a stack.
 * @param s A stack holding values to sum.
 * @return The sum of all the elements in the stack, leaving the original
 *  stack in the same state (unchanged).
 *
 * @note You may modify the stack as long as you restore it to its original
 *  values.
 * @note You may use only two local variables of type T in your function.
 *  Note that this function is templatized on the stack's type, so stacks of
 *  objects overloading the + operator can be summed.
 * @note We are using the Standard Template Library (STL) stack in this
 *  problem. Its pop function works a bit differently from the stack we
 *  built. Try searching for "stl stack" to learn how to use it.
 * @hint Think recursively!
 */
template <typename T>
T sum(stack<T>& s)
{
    T new_ = s.top();
    if(s.size()==1){
      return new_;
    }
    s.pop();
    T output = sum(s)+new_;
    s.push(new_);
    // Your code here
    return output; // stub return value (0 for primitive types). Change this!
                // Note: T() is the default value for objects, and 0 for
                // primitive types
}

/**
 * Checks whether the given string (stored in a queue) has balanced brackets.
 * A string will consist of
 * square bracket characters, [, ], and other characters. This function will return
 * true if and only if the square bracket characters in the given
 * string are balanced. For this to be true,
 * all brackets must be matched up correctly, with no extra, hanging, or unmatched
 * brackets. For example, the string "[hello][]" is balanced, "[[][[]a]]" is balanced,
 * "[]]" is unbalanced, "][" is unbalanced, and "))))[cs225]" is balanced.
 *
 * You are allowed only the use of one stack in this function, and no other local variables.
 *
 * @param input The queue representation of a string to check for balanced brackets in
 * @return Whether the input string had balanced brackets
 */
bool isBalanced(queue<char> input)
{
  stack<char> sta;
  while(!input.empty()){
    if(input.front()!='['||input.front()!=']'){
      input.pop();
    }else if(input.front()==']'){
      char temp=input.front();
      sta.push(temp);
      input.pop();
    }else if(input.front()=='['){
      char temp = input.front();
      if(sta.top()==']'){
        sta.pop();
        input.pop();
      }else{
        sta.push(temp);
      }
    }
  }
  if(sta.empty()){
    return true;
  }else{return false;}
}

/**
 * Reverses even sized blocks of items in the queue. Blocks start at size
 * one and increase for each subsequent block.
 * @param q A queue of items to be scrambled
 *
 * @note Any "leftover" numbers should be handled as if their block was
 *  complete.
 * @note We are using the Standard Template Library (STL) queue in this
 *  problem. Its pop function works a bit differently from the stack we
 *  built. Try searching for "stl stack" to learn how to use it.
 * @hint You'll want to make a local stack variable.
 */
template <typename T>
void scramble(queue<T>& q){
    static unsigned num = 1;
    stack<T> s;
    queue<T> q2;
    while(!q.empty()){
      unsigned flag = (num+1)%2;
      if(q.size()<num){
        unsigned a=q.size();
        for(unsigned i = 0;i<a;i++){
          unsigned temp = q.front();
          s.push(temp);
          q.pop();
        }
        for(unsigned j = 0;j<a;j++){
          unsigned temp2 = s.top();
          q2.push(temp2);
          s.pop();
        }
      }else if(flag==0){
        for(unsigned i = 0;i<num;i++){
          q2.push(q.front());
          q.pop();
        }
        num++;
      }else if(flag==1){
        for(unsigned i = 0;i<num;i++){
          unsigned temp = q.front();
          q.pop();
          s.push(temp);
        }
        for(unsigned j = 0;j<num;j++){
          unsigned temp2 = s.top();
          s.pop();
          q2.push(temp2);
        }
        num++;
      }
    }
    while(!q2.empty()){
      q.push(q2.front());
      q2.pop();
    }
}

/**
 * @return true if the parameter stack and queue contain only elements of
 *  exactly the same values in exactly the same order; false, otherwise.
 *
 * @note You may assume the stack and queue contain the same number of items!
 * @note The back of the queue corresponds to the top of the stack!
 * @note There are restrictions for writing this function.
 * - Your function may not use any loops
 * - In your function you may only declare ONE local boolean variable to use in
 *   your return statement, and you may only declare TWO local variables of
 *   parametrized type T to use however you wish.
 * - No other local variables can be used.
 * - After execution of verifySame, the stack and queue must be unchanged. Be
 *   sure to comment your code VERY well.
 */
template <typename T>
bool verifySame(stack<T>& s, queue<T>& q)
{
    static bool retval = true; // optional
    T temp1;// rename me
    T temp2; // rename :)

    // Your code here
    /*if(s.empty()){
      return retval;
    }
    for(unsigned i = 0;i<q.size()-1;i++){
      temp1 = q.front();
      q.pop();
      q.push(temp1);
    }
    temp2 = s.top
    if(q.front()!=stack.top()){
      retval = false;
    }else{}*/

    /*if(s.top()==q.back()){
      s.pop();
      q.pop();
      q.push(temp1);
    }*/

    if(s.size()==1){//base case: the stack only remain one element
      if(s.top()==q.front()){//compare the bottom item on stack with front of queue;
        temp2 = q.front();
        q.pop();
        q.push(temp2);//connect the front of the queue to the end of the queue.
      }else{//the bottom of the stack != front of the queue;
        retval = false;//set return val to be false;
        temp2 = q.front();
        q.pop();
        q.push(temp2);}//connect the front of the queue to the end of the queue;
    }else{//not yet base case, pop out the top of stack
      temp1 = s.top();
      s.pop();//pop the top
      verifySame(s,q);
      s.push(temp1);//push it back to the stack
      temp2 = q.front();
      q.pop();
      q.push(temp2);//connect the front of the queue to the end of the queue;

      //if all compared, the queue will be connected q.size() times and remain the same.
    }

    return retval;
}

}
