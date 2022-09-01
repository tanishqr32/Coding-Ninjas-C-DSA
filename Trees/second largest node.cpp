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

// aproach 1

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

TreeNode<int>* getSecondLargestNode1(TreeNode<int>* root){
    if(root == NULL){
        return NULL;
    }
    TreeNode<int>* ans = NULL;
    // TreeNode<int>* max = maxDataNode(root);
    TreeNode<int>* s_max = NULL;
    TreeNode<int>* max = root;

    int s_max = 0;
    for(int i = 0;i<root->children.size();i++){
        TreeNode<int>* temp = maxDataNode( root->children[i]);
        if(temp->data > max->data){
            s_max = max;
            max = temp;
        }
        else{
            if(s_max == NULL){
                s_max = temp;
            }
            else if( s_max->data < temp->data){
                s_max = temp;
            }
        }        
    }
    return s_max;
}

// aproach 2

/*********************************************/
class h_class{
     public :
    TreeNode<int>*  max;
    TreeNode<int>* s_max;
    
    h_class (TreeNode<int>* max, TreeNode<int>* s_max) {
        this->max = max;
        this->s_max = s_max;
    }
};

h_class h_function (TreeNode<int> * root){
    if(root==NULL){
        h_class r(NULL,NULL);
        return r;
    }
    h_class ans(root, NULL);
     for (int i = 0; i < root->children.size(); i++) {
            h_class child = h_function (root -> children[i]);  
            if(child.max->data > ans.max->data){
                if(child.s_max==NULL){
                    ans.s_max=ans.max;
                    ans.max=child.max;
                }
                else{
                    if(child.s_max->data > ans.max->data){
                        ans.s_max=child.s_max;
                        ans.max=child.max;
                    }
                    else{
                       ans.s_max=ans.max;
                        ans.max=child.max; 
                    }
                }
            }
        else {
            if(ans.max->data!=child.max->data && (ans.s_max==NULL || child.max->data > ans.s_max->data)){
                ans.s_max=child.max;
            }
        }
        }
    return ans;
}
TreeNode<int>* getSecondLargestNode2(TreeNode<int>* root){
     
    if (root == NULL) 
        return NULL;
    h_class ans = h_function (root);
    return ans.s_max;
}
/***********************************************/
