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


template <typename T>
class Node {
   public:
    T data;
    Node<T>* next;
    Node(T data) {
        this->data = data;
        this->next = NULL;
    }
};

class BSTtoLL{
    public:
    Node<int>* head;
    Node<int>* tail;

};

BSTtoLL helperBST_LL(BinaryTreeNode<int>* root){
    if(root == NULL){
        BSTtoLL p;
        p.head = NULL;
        p.tail = NULL;
        return p;
    }
    Node<int> * current = new Node<int>(root->data);
    BSTtoLL left_tree = helperBST_LL(root->left);
    BSTtoLL right_tree = helperBST_LL(root->right);
    BSTtoLL out;
    if(left_tree.head == NULL && right_tree.head == NULL){
        out.head = current;
        out.tail = current;
    }
    else if(!left_tree.head && right_tree.head){
        out.head = current;
        current->next = right_tree.head;
        out.tail = right_tree.tail;
    }
    else if(left_tree.head && right_tree.head == NULL){
        out.head = left_tree.head;
        left_tree.tail->next = current;
        out.tail = current;
    }
    else{
        out.head = left_tree.head;
        left_tree.tail->next = current;
        current->next = right_tree.head;
        out.tail = right_tree.tail;
    }
    
    return out;
}

Node<int>* constructLinkedList(BinaryTreeNode<int>* root) {
    return helperBST_LL(root).head;
}
