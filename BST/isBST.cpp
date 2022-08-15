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

int help_isBST_min(BinaryTreeNode<int>* root){
    if(root == NULL){
        return INT_MAX;
    }
    int left_min = help_isBST_min(root->left);
    int right_min = help_isBST_min(root->right);
    return min(min(left_min,right_min),root->data);
}
int help_isBST_max(BinaryTreeNode<int>* root){
    if(root == NULL){
        return INT_MIN;
    }
    int left_max = help_isBST_max(root->left);
    int right_max = help_isBST_max(root->right);
    return max(max(left_max,right_max),root->data);
}

bool isBST(BinaryTreeNode<int> *root){
    if(root == NULL){
        return true;
    }
    int left_max = help_isBST_max(root->left);
    int right_min = help_isBST_min(root->right);
    bool ans = (root -> data > left_max) && (root -> data <= right_min) && isBST(root -> left) && isBST(root -> right);
    return ans;
}