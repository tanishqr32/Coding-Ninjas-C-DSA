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


int getLargeNodeCount(TreeNode<int>* root, int x){
    if(root == NULL){
        return 0;
    }
    int count = 0;
    if(root->data > x){
        count++;
    }
    for(int i = 0;i<root->children.size();i++){
        count += getLargeNodeCount(root->children[i],x);
    }
    return count;
}
