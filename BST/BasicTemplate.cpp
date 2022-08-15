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

BinaryTreeNode<int> *takeInput() {
    int rootData;
    cin >> rootData;
    if (rootData == -1) {
        return NULL;
    }
    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(rootData);
    queue<BinaryTreeNode<int> *> q;
    q.push(root);
    while (!q.empty()) {
        BinaryTreeNode<int> *currentNode = q.front();
        q.pop();
        int leftChild, rightChild;
        cin >> leftChild;
        if (leftChild != -1) {
            BinaryTreeNode<int> *leftNode = new BinaryTreeNode<int>(leftChild);
            currentNode->left = leftNode;
            q.push(leftNode);
        }
        cin >> rightChild;
        if (rightChild != -1) {
            BinaryTreeNode<int> *rightNode =
                new BinaryTreeNode<int>(rightChild);
            currentNode->right = rightNode;
            q.push(rightNode);
        }
    }
    return root;
}
void printLevelWise(BinaryTreeNode<int> *root) {
	queue<BinaryTreeNode<int>*> pendingNode;
    pendingNode.push(root);
    while(!pendingNode.empty()){
        BinaryTreeNode<int>* front = pendingNode.front();
        pendingNode.pop();
        cout<<front->data<<":";
        if(front->left != NULL){
            cout<<"L"<<":"<<front->left->data;
            pendingNode.push(front->left);
        }
        else{
            cout<<"L"<<":"<<-1;
        }
        if(front->right != NULL){
            cout<<","<<"R"<<":"<<front->right->data;
            pendingNode.push(front->right);
        }
        else{
            cout<<","<<"R"<<":"<<-1;
        }
        cout<<endl;
    }
}

int main(){
    BinaryTreeNode<int>* root = takeInput();
    printLevelWise(root);
}