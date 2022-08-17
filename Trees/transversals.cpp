#include<iostream>
#include<vector>
#include<queue>

using namespace std;

template <typename T>
class TreeNode {
   public:
    T data;
    vector<TreeNode<T>*> children;
    /* we dont need to specify the template typename of treeNode, 
       it will assume the 
       typename same as the parent.*/

    TreeNode(T data) { this->data = data; }

    ~TreeNode() {
        for (int i = 0; i < children.size(); i++) {
            delete children[i];
        }
    }
};

// pre order

void preOrder(TreeNode<int>* root){
    cout<<root->data<<" ";
    for(int i = 0;i<root->children.size();i++){
        preOrder(root->children[i]); 
    }
}

// post order

void printPostOrder(TreeNode<int>* root) {
    for(int i = 0;i<root->children.size();i++){
        printPostOrder(root->children[i]); 
    }
    cout<<root->data<<" ";
}
