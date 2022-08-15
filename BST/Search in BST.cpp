#include<iostream>
using namespace std;
#include<queue>
#include<climits>
template <typename T>
class BinaryTreeNode {
	public : 
	T data;
	BinaryTreeNode<T> *left;
	BinaryTreeNode<T> *right;

    BinaryTreeNode(T data) {
    	this -> data = data;
    	left = NULL;
     	right = NULL;
	}
};

bool searchInBST(BinaryTreeNode<int> *root , int k){
    if(root == NULL){
        return false;
    }
    bool ans ;
    if(root->data == k){
        return true;
    }
    else if( root->data > k){
        return searchInBST(root->left,k);
    }
    else{
        return searchInBST(root->right,k);
    }
}