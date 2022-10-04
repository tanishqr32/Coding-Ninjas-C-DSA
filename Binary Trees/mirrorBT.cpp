#include<iostream>
#include<queue>
using namespace std;
template<typename T>
class BinaryTreeNode{
    public:
    T data;
    BinaryTreeNode *left;
    BinaryTreeNode *right;
    BinaryTreeNode(T data){
        this->data = data;
        left = NULL;
        right = NULL;
    }
    ~BinaryTreeNode(){
        delete left;
        delete right;
    }

};


void mirrorBinaryTree(BinaryTreeNode<int>* root){
    if(root == NULL){
        return;
    }
    mirrorBinaryTree(root->left);
    mirrorBinaryTree(root->right);
    BinaryTreeNode<int>* temp = root->right;
    root->right = root->left;
    root->left = temp;
    return ;
}