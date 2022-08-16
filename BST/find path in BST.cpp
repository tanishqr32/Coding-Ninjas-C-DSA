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

// path in a bianry tree
vector<int> * path (BinaryTreeNode<int>* root,int data){
    if(root == NULL){
        return NULL;
    }
    if(root->data == data){
        vector<int>*ans = new vector<int>();
        ans->push_back(data);
        return ans;
    }
    vector<int>* left = path(root->left,data);
    if(left != NULL){
        left->push_back(root->data);
        return left;
    }
    vector<int>* right = path(root->right,data);
    if(right != NULL){
        right->push_back(root->data);
        return right;
    }   
    else{
        return NULL;
    }
}

// path in BST
vector<int>* getPath(BinaryTreeNode<int> *root , int data){
    if(root == NULL){
        return NULL;
    }
    if(root->data == data){
        vector<int>*ans = new vector<int>();
        ans->push_back(data);
        return ans;
    }
    if(root->data < data){
        vector<int>* right = getPath(root->right,data);
        if(right != NULL){
            right->push_back(root->data);
            return right;
        }   
        else{
            return NULL;
        }
    }
    if(root->data > data){
        vector<int>* left = getPath(root->left,data);
        if(left != NULL){
            left->push_back(root->data);
            return left;
        }
        else{
            return NULL;
        }
    }
    
}