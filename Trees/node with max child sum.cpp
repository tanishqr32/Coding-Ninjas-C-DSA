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

TreeNode<int>* maxSumNode(TreeNode<int>* root){
    if(root == NULL){
        return NULL;
    }
    int max = root->data;
    TreeNode<int>* ans = root;
    for(int i = 0;i<root->children.size();i++){
        max += root->children[i]->data;
        TreeNode<int>* temp = maxSumNode(root->children[i]);
        int t = temp->data;
        for(int i = 0;i<temp->children.size();i++){
            t += temp->children[i]->data;
        }
        if(t > max){
            ans = temp;
        }
    }
    return ans;
}
