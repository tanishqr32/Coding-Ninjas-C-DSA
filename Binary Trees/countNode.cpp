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


int countNodes (BinaryTreeNode<int>* root){
    if(root == NULL){
        return 0;
    }
    int left = countNodes(root->left);
    int right = countNodes(root->right);
    return left + right + 1;
}
