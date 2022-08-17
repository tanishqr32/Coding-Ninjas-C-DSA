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

TreeNode<int>* maxDataNode(TreeNode<int>* root) {
    int max = root->data;    
    TreeNode<int>* maxP = root;   
    for(int i = 0;i<root->children.size();i++){
        TreeNode<int>* temp = maxDataNode( root->children[i]);
        int tempM = temp->data;
        if(tempM>max){
            maxP = temp;
        }
    }
    
    return maxP;
}