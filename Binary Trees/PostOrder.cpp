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

void postOrder(BinaryTreeNode<int> *root){
    if(root == NULL){
        return;
    }
    postOrder(root->left);
    postOrder(root->right);
    cout<<root->data << " ";
    return;

}