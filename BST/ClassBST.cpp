#include<iostream>
using namespace std;
#include<queue>
#include<climits>
template <typename T>
class BinaryTreeNode {
	public : 
	T data;
	BinaryTreeNode<T> *left;
	BinaryTreeNode<T> *right;

    BinaryTreeNode(T data) {
    	this -> data = data;
    	left = NULL;
     	right = NULL;
	}
};

class BST{

    BinaryTreeNode<int> * root;
    public:
    BST(){
        root = NULL;
    }
    ~BST(){
        delete root;
    }
    private:
    bool helper_hasData(BinaryTreeNode<int>*root,int data){
        if(root == NULL){
            return false;
        }
        if(root->data == data){
            return true;
        }
        else if (data < root->data){
            return helper_hasData(root->left,data);
        }
        else if (data > root->data){
            return helper_hasData(root->right,data);
        }
    }
    public:
    bool search(int Data){
        return helper_hasData(root,Data);
    }
    private:   
    BinaryTreeNode<int>* helper_insert(BinaryTreeNode<int>* root,int data){
        if(root == NULL){
            BinaryTreeNode<int> * ans = new BinaryTreeNode<int>(data);
            return ans;
        }
        if(data <= root->data){
            root->left = helper_insert(root->left,data);
        }
        else {
            root->right = helper_insert(root->right,data);
        }
        return root;
   }
    public:
    void insert (int data){
        this->root = helper_insert(this->root,data);
    }
    private:
    BinaryTreeNode<int>* helper_remove(BinaryTreeNode<int>* root,int data){
        if(root == NULL){
            return NULL;
        }
        if(data < root->data){
            root->left = helper_remove(root->left,data);
            return root;
        }
        else if(data > root->data){
            root->right = helper_remove(root->right,data);
            return root;
        }
        if(root->data == data){
            if(root->left == NULL && root->right == NULL){
                delete root;
                return NULL;
            }
            else if(root->left == NULL){
                BinaryTreeNode<int> * temp = root->right;
                root->right = NULL;
                delete root;
                return temp;
            }
            else if(root->right == NULL){
                BinaryTreeNode<int> * temp = root->left;
                root->left = NULL;
                delete root;
                return temp;
            }
            else{
                BinaryTreeNode<int>* min = root->right;
                while(min->left != NULL){
                    min = min->left;
                }
                root->data = min->data;
                root->right = helper_remove(root->right,min->data);
                return root;
            }
        }
        return root;
    }
    public:
    void remove(int data){
        this->root = helper_remove(root,data);
    }
    private:
    void printTree(BinaryTreeNode<int> * root){
        if(root == NULL){
            return;
        }
        cout<<root->data<<":";
        if(root->left != NULL){
            cout<<"L"<<":"<<root->left->data<<",";
        }
        if(root->right != NULL){
            cout<<"R"<<":"<<root->right->data;
        }
        cout<<endl;
        printTree(root->left);
        printTree(root->right);
    }
    public:
    void print (){
        printTree(root);
    }

};