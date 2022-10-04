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


int height(BinaryTreeNode<int>* root){
    if(root == NULL){
        return 0;
    }
    int left = height(root->left);
    int right = height(root->right);
    int ans = max (left,right);
    return ans + 1;

}