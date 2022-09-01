#include<iostream>
#include<vector>
#include<queue>

using namespace std;

template <typename T>
class TreeNode {
   public:
    T data;
    vector<TreeNode<T>*> children;
    TreeNode(T data) { this->data = data; }
    ~TreeNode() {
        for (int i = 0; i < children.size(); i++) {
            delete children[i];
        }
    }
};

TreeNode<int>* getNextLargerElement(TreeNode<int>* root, int x) {
    if(root == NULL){
        return NULL;
    }
    TreeNode<int> * ans = NULL;
    if(root->data > x){
        ans = root;
    }
    for(int i = 0;i<root->children.size();i++){
        TreeNode<int> * temp = getNextLargerElement(root->children[i],x);
        if(temp == NULL){
            continue;
        }
        else{
            if(ans == NULL){
                ans = temp;
            }
            else if( x < temp->data && temp->data < ans->data){
                ans = temp;
            }
        }
    }
    return ans;
}