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

void preOrder(BinaryTreeNode<int> *root) {
    if(root == NULL){
        return;
    }

    cout<<root->data<<" ";
    preOrder(root->left);
    preOrder(root->right);
    return;
}