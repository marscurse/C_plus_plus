/**
 * @file binarytree.cpp
 * Definitions of the binary tree functions you'll be writing for this lab.
 * You'll need to modify this file.
 */
#include "TreeTraversals/InorderTraversal.h"
#include <iostream>
#include "binarytree.h"
/**
 * @return The height of the binary tree. Recall that the height of a binary
 *  tree is just the length of the longest path from the root to a leaf, and
 *  that the height of an empty tree is -1.
 */
template <typename T>
int BinaryTree<T>::height() const
{

    // Call recursive helper function on root
    return height(root);
}

/**
 * Private helper function for the public height function.
 * @param subRoot
 * @return The height of the subtree
 */
template <typename T>
int BinaryTree<T>::height(const Node* subRoot) const
{
    // Base case
    if (subRoot == NULL)
        return -1;

    // Recursive definition
    return 1 + max(height(subRoot->left), height(subRoot->right));
}

/**
 * Prints out the values of the nodes of a binary tree in order.
 * That is, everything to the left of a node will be printed out before that
 * node itself, and everything to the right of a node will be printed out after
 * that node.
 */
template <typename T>
void BinaryTree<T>::printLeftToRight() const
{
    // Call recursive helper function on the root
    printLeftToRight(root);

    // Finish the line
    cout << endl;
}

/**
 * Private helper function for the public printLeftToRight function.
 * @param subRoot
 */
template <typename T>
void BinaryTree<T>::printLeftToRight(const Node* subRoot) const
{
    // Base case - null node
    if (subRoot == NULL)
        return;

    // Print left subtree
    printLeftToRight(subRoot->left);

    // Print this node
    cout << subRoot->elem << ' ';

    // Print right subtree
    printLeftToRight(subRoot->right);
}

/**
 * Flips the tree over a vertical axis, modifying the tree itself
 *  (not creating a flipped copy).
 */
template <typename T>
void BinaryTree<T>::mirror()
{
    //your code here
    mirror(root);

}

template <typename T>
void BinaryTree<T>::mirror(Node* &subRoot)
{
	if(subRoot == NULL)
		return;


	Node* temp = subRoot->left;
	subRoot->left = subRoot->right;
	subRoot->right = temp;
  mirror(subRoot->left);
  mirror(subRoot->right);
}



/**
 * isOrdered() function iterative version
 * @return True if an in-order traversal of the tree would produce a
 *  nondecreasing list output values, and false otherwise. This is also the
 *  criterion for a binary tree to be a binary search tree.
 */
template <typename T>
bool BinaryTree<T>::isOrderedIterative() const
{
    // your code here
    bool output = true;
    stack<Node*> sta;
    Node* temp = root;
    T tempa = -1;
    while(!sta.empty()||temp!=NULL){
      if(temp!=NULL){
        sta.push(temp);
        temp = temp->left;
      }else{
        temp = sta.top();
        sta.pop();
        if(temp->elem<tempa){
          output = false;
          break;
        }else{
          tempa = temp->elem;
        }
        temp = temp->right;
      }
    }
    return output;
}

/**
 * isOrdered() function recursive version
 * @return True if an in-order traversal of the tree would produce a
 *  nondecreasing list output values, and false otherwise. This is also the
 *  criterion for a binary tree to be a binary search tree.
 */

template <typename T>
bool BinaryTree<T>::isOrderedRecursive() const
{
    stack<T> sta;
    bool output = true;
    isOrderedRecursive(root,sta);
    T temp = sta.top();
    while(!sta.empty()){
      if(sta.top()>temp){
        output = false;
        break;
      }else{
        temp = sta.top();
        sta.pop();
      }
    }

    return output;
}
template <typename T>
void BinaryTree<T>::isOrderedRecursive(const Node* subRoot,stack<T> &sta)const{
  if(subRoot==NULL){
    return;
  }
  isOrderedRecursive(subRoot->left,sta);
  sta.push(subRoot->elem);
  isOrderedRecursive(subRoot->right,sta);

}

/**
 * creates vectors of all the possible paths from the root of the tree to any leaf
 * node and adds it to another vector.
 * Path is, all sequences starting at the root node and continuing
 * downwards, ending at a leaf node. Paths ending in a left node should be
 * added before paths ending in a node further to the right.
 * @param paths vector of vectors that contains path of nodes
 */
template <typename T>
void BinaryTree<T>::printPaths(vector<vector<T> > &paths) const
{
    // your code here
    T path[1000];
    for(int i = 0;i<1000;i++){
      path[i] = 0;
    }
    findpath(root,0,path,paths);

}
template <typename T>
void BinaryTree<T>::findpath(Node* head,int pathlen,T path[],vector<vector<T>> &b) const  {
  if(head==NULL){
    return ;
  }
  path[pathlen]=head->elem;
  pathlen++;
  if(head->left ==NULL&&head->right==NULL){
    vector<T> a;
    for(int i = 0;i<pathlen;i++){
        a.push_back(path[i]);

    }
    b.push_back(a);

  }else{
    findpath(head->left,pathlen,path,b);
    findpath(head->right,pathlen,path,b);
  }
}
/**
 * Each node in a tree has a distance from the root node - the depth of that
 * node, or the number of edges along the path from that node to the root. This
 * function returns the sum of the distances of all nodes to the root node (the
 * sum of the depths of all the nodes). Your solution should take O(n) time,
 * where n is the number of nodes in the tree.
 * @return The sum of the distances of all nodes to the root
 */
template <typename T>
int BinaryTree<T>::sumDistances() const
{
    // your code here
    int *output = new int(0);
    sumDistances(root,output,0);
    return *output;
}

template <typename T>
void BinaryTree<T>::sumDistances(Node* subRoot,int* output,int pathlen) const{
  if(subRoot==NULL){
    return ;
  }else{
    *output = *output + pathlen;
    sumDistances(subRoot->left,output,pathlen+1);
    sumDistances(subRoot->right,output,pathlen+1);

  }
}
