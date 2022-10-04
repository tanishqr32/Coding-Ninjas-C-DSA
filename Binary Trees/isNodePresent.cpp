
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
bool isNodePresent(BinaryTreeNode<int> *root, int x){
    if(root == NULL){
        return false;
    }
    if(root->data == x){
        return true;
    }
    bool left = isNodePresent(root->left,x);
    if(left == true){
        return left;
    }
    bool right = isNodePresent(root->right,x);
    if(right == true){
        return right;
    }
    return false;
}