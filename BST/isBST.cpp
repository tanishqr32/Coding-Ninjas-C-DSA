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

// approach-1    time complexity - O(nh)
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

// approach-2    time complexity - O (n)

class isBSTreturn {
    public:
    int minimum ;
    int maximum;
    bool BST;
};

isBSTreturn helper_isBST(BinaryTreeNode<int>* root){
    if(root == NULL){
        isBSTreturn p;
        p.minimum = INT_MAX;
        p.maximum = INT_MIN;
        p.BST = true;
        return p;
    }
    isBSTreturn leftoutput = helper_isBST(root->left);
    isBSTreturn rightoutput = helper_isBST(root->right);
    int minimum = min(root->data,min(leftoutput.minimum,rightoutput.minimum));
    int maximum = max(root->data,max(leftoutput.maximum,rightoutput.maximum));
    bool isBSTfinal = (leftoutput.maximum < root->data) && (root->data <= rightoutput.minimum)&& leftoutput.BST && rightoutput.BST;
    isBSTreturn p;
    p.maximum = maximum;
    p.minimum = minimum;
    p.BST = isBSTfinal;
    return p;
}
bool isBST2(BinaryTreeNode<int>* root){
    if(root == NULL){
        return true;
    }
    isBSTreturn left = helper_isBST(root->left);
    isBSTreturn right = helper_isBST(root->right);
    bool output = (left.maximum < root->data) && (root->data <= right.minimum)&& left.BST && right.BST;
    return output;
}

// approach-3  time complexity is same as approach 2 but very short code :) 
bool isBST3 (BinaryTreeNode<int>* root,int min = INT_MIN,int max = INT_MAX){
    if(root == NULL)
        return true;
    if(root->data < min || root->data > max)
        return false;
    bool isBSTleft = isBST3(root->left,min,root->data-1);
    bool isBSTright = isBST3(root->right,root->data,max);
    return isBSTleft && isBSTright;
}

