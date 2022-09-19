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

BinaryTreeNode<int>* takeInput(){
    int rootData;
    cout<<"enter data"<<endl;
    cin>> rootData;
    if(rootData == -1){
        return NULL;
    }

    BinaryTreeNode<int> * root = new BinaryTreeNode<int>(rootData);
    queue<BinaryTreeNode<int>*> pendingNode;
    pendingNode.push(root);
    while(!pendingNode.empty()){
        BinaryTreeNode<int>* front = pendingNode.front();
        pendingNode.pop();

        int leftChildData;
        cout<<"enter left child data of"<<front->data<<endl;
        cin>>leftChildData;
        if(leftChildData != -1){
            BinaryTreeNode<int>* leftChild = new BinaryTreeNode<int>(leftChildData);
            front->left = leftChild;
            pendingNode.push(leftChild);
        }
        int rightChildData;
        cout<<"enter right child data of "<<front->data<<endl;
        cin>>rightChildData;
        if(rightChildData != -1){
            BinaryTreeNode<int>* rightChild = new BinaryTreeNode<int>(rightChildData);
            front->right = rightChild;
            pendingNode.push(rightChild);
        }
    }
    return root;
}

void printLevelWise(BinaryTreeNode<int> *root) {
    if(root == NULL){
        return;
    }
    queue<BinaryTreeNode<int>*> pendingNodes;
    pendingNodes.push(root);

    while(!pendingNodes.empty()){
        BinaryTreeNode<int>* front = pendingNodes.front();
        pendingNodes.pop();
        cout<<front->data<<":";
        if(front->left != NULL){
            cout<<"L"<<":"<<front->left->data;
            pendingNodes.push(front->left);
        }
        else{
            cout<<"L"<<":"<<-1;
        }
        if(front->right != NULL){
            cout<<","<<"R"<<":"<<front->right->data;
            pendingNodes.push(front->right);
        }
        else{
            cout<<","<<"R"<<":"<<-1;
        }
    cout<<endl;
    }
}