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

int getLeafNodeCount(TreeNode<int>* root) {
    if(root->children.size() == 0){
        return 1;
    }
    int ans = 0;
    for(int i = 0;i<root->children.size();i++){
        ans += getLeafNodeCount(root->children[i]);
    }
    return ans;
}