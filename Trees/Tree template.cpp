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
TreeNode<int>* takeInputLevelWise() {
    int rootData;
    cin >> rootData;
    TreeNode<int>* root = new TreeNode<int>(rootData);

    queue<TreeNode<int>*> pendingNodes;

    pendingNodes.push(root);
    while (pendingNodes.size() != 0) {
        TreeNode<int>* front = pendingNodes.front();
        pendingNodes.pop();
        int numChild;
        cin >> numChild;
        for (int i = 0; i < numChild; i++) {
            int childData;
            cin >> childData;
            TreeNode<int>* child = new TreeNode<int>(childData);
            front->children.push_back(child);
            pendingNodes.push(child);
        }
    }

    return root;
}

TreeNode<int>* takeInputRecursion(){

    int rootDATA;
    cout<<"enter data :"<<endl;
    cin>>rootDATA;

    TreeNode<int>* root = new TreeNode<int>(rootDATA);
    int n;
    cout<<"enter number of children of  "<< rootDATA<<endl;
    cin>>n;

    for(int i = 0;i<n;i++){
        TreeNode<int>* child = takeInputRecursion();
        root->children.push_back(child);
    }
    return root;
}

void printAtreeRecursion(TreeNode<int> * root){
    if(root == NULL){
        return;
    }
    cout<<root->data<<" "<<":"<<" ";
    for(int i = 0;i<root->children.size();i++){
       cout<<root->children[i]->data<<",";
    }
    cout<<endl;
    for(int i = 0;i<root->children.size();i++){
        printAtreeRecursion(root->children[i]);
    }
}

void printLevelWise(TreeNode<int>* root){
    queue<TreeNode<int>*> pendingNodes;
    pendingNodes.push(root);

    while(!pendingNodes.empty()){
        TreeNode<int>* front = pendingNodes.front();
        pendingNodes.pop();
        for(int i = 0;i<front->children.size();i++){
            pendingNodes.push(front->children[i]);
        }
        cout<<front->data<<":";
        for(int i = 0;i<front->children.size();i++){
            cout<<front->children[i]->data;
            if(i<front->children.size()-1){
                cout<<",";
            }
        }
        cout<<endl;
    }
}
