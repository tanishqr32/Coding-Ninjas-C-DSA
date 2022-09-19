#include<iostream>
#include<queue>
#define pii pair<int,int>
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


void printBinaryTree(BinaryTreeNode<int> * root){
    if(root == NULL){
        return;
    }
    cout<<root->data<<":";
    if(root->left){
        cout<<"L"<<root->left->data;
    }
    if(root->right){
        cout<<"R"<<root->right->data;
    }
    cout<<endl;
    printBinaryTree(root->left);
    printBinaryTree(root->right); 
}

BinaryTreeNode<int>* takeInputWithoutQueue(){
    int rootData;
    cout<<"enter data"<<endl;
    cin>>rootData;
    if(rootData == -1){
        return NULL;
    }
    BinaryTreeNode<int> * root = new BinaryTreeNode<int>(rootData);
    BinaryTreeNode<int> * leftChild = takeInputWithoutQueue();
    BinaryTreeNode<int> * rightChild = takeInputWithoutQueue();
    root->left = leftChild;
    root->right = rightChild;
    return root; 
}

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

void printLevelATNewLine(BinaryTreeNode<int> *root) {
    queue<BinaryTreeNode<int> *> q;
    q.push(root);
    q.push(NULL);
    while (!q.empty()) {
        BinaryTreeNode<int> *first = q.front();
        q.pop();
        if (first == NULL) {
            if (q.empty()) {
                break;
            }
            cout << endl;
            q.push(NULL);
            continue;
        }
        cout << first->data << " ";
        if (first->left != NULL) {
            q.push(first->left);
        }
        if (first->right != NULL) {
            q.push(first->right);
        }
    }
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

int countNodes(BinaryTreeNode<int>* root){
    if(root == NULL){
        return 0;
    }
    int left = countNodes(root->left);
    int right = countNodes(root->right);    
    return left + right + 1;

}

bool isNodePresent(BinaryTreeNode<int> *root, int x) {
    if(root == NULL){
        return false;
    }
    if(root->data == x){
        return true;
    }
    if(isNodePresent(root->left,x))
        return true;
    else if(isNodePresent(root->right,x))
        return true;
    return false;
}

void mirrorBinaryTree(BinaryTreeNode<int>* root) {
    if(root == NULL){
        return;
    }
    mirrorBinaryTree(root->left);
    mirrorBinaryTree(root->right);
    BinaryTreeNode<int> * temp = root->left;
    root->left = root->right;
    root->right = temp;
}

void InOrder(BinaryTreeNode<int>* root){
    if(root == NULL){
        return;
    }
    InOrder(root->left);
    cout<<root->data <<" ";
    InOrder(root->right);
}

void preOrder(BinaryTreeNode<int> *root) {
    if(root == NULL){
        return;
    }
    cout<<root->data<<" ";
    preOrder(root->left);
    preOrder(root->right); 
}
void postOrder(BinaryTreeNode<int> *root) {
	if(root == NULL){
        return;
    }
    postOrder(root->left);
    postOrder(root->right); 
    cout<<root->data<<" ";
}
/**************************************************/
BinaryTreeNode<int>* helperBT_preAndIn(int *pre,int *in,int PreS, int PreE,int InS,int InE){
    if (InS > InE) {
		return NULL;
	}
    int rootData = pre[PreS];
    
    int rootIndex = -1;
    for(int i = InS;i<=InE;i++){
        if(rootData == in[i]){
            rootIndex = i;
            break;
        }
    }
    int L_InS = InS;
    int L_InE = rootIndex -1;
    int L_PreS = PreS + 1;
    int L_PreE = L_InE + L_PreS - L_InS ;
    int R_InS = rootIndex+ 1;
    int R_InE = InE;
    int R_PreS = L_PreE + 1;
    int R_PreE = PreE;
    BinaryTreeNode<int> * root = new BinaryTreeNode<int>(rootData);
    root->left = helperBT_preAndIn(pre,in,L_PreS,L_PreE,L_InS,L_InE);
    
    root->right = helperBT_preAndIn(pre,in,R_PreS,R_PreE,R_InS,R_InE);
    return root;
}
// using preorder and inorder:
BinaryTreeNode<int>* buildTree_usingPreAndIn(int *preorder, int preLength, int *inorder, int inLength) {
    return helperBT_preAndIn(preorder,inorder,0,preLength-1,0,inLength-1);
}
/**************************************************/
/**************************************************/
BinaryTreeNode<int>* helperBT_postAndIn(int *post,int *in,int PostS, int PostE,int InS,int InE){
    if (InS > InE) {
		return NULL;
	}
    int rootData = post[PostE];
    int rootIndex = 0;
    for(int i = InS;i<=InE;i++){
        if(rootData == in[i]){
            rootIndex = i;
            break;
        }
    }
    int L_InS = InS;
    int L_InE = rootIndex-1;
    int L_PostS = PostS;
    int L_PostE = L_InE - L_InS + L_PostS;
    int R_InS = rootIndex+1;
    int R_InE = InE;
    int R_PostS = L_PostE +1;
    int R_PostE = PostE-1 ;
    BinaryTreeNode<int> * root = new BinaryTreeNode<int>(rootData);
    root->left = helperBT_postAndIn(post,in,L_PostS,L_PostE,L_InS,L_InE);
    
    root->right = helperBT_postAndIn(post,in,R_PostS,R_PostE,R_InS,R_InE);
    return root;

}

BinaryTreeNode<int>* buildTree_postAndIn(int *postorder, int postLength, int *inorder, int inLength) {
    return helperBT_postAndIn(postorder,inorder,0,postLength-1,0,inLength-1);
}
/**************************************************/
int height(BinaryTreeNode<int>* root) {
     if(root == NULL){
        return 0;
    }
    int left = height(root->left);
    int right = height(root->right);    
    if(left>right){
        return left+1;
    }
    return right+1;
}

pair<int,int> height_Diameter(BinaryTreeNode<int>*root){
    if(root == NULL){
       pair<int,int> p;
       p.first = 0;
       p.second = 0;
       return p;
    }
    pair<int,int> L = height_Diameter(root->left);
    pair<int,int> R = height_Diameter(root->right);
    int Lh = L.first;
    int Rh = R.first;
    int Ld = L.second;
    int Rd = R.second;
    pair<int,int> ans;
    ans.first = 1+ max(Lh,Rh);
    ans.second = max(Lh + Rh,max(Ld,Rd));
    return ans;
} 


pair<int, int> getMinAndMax(BinaryTreeNode<int> *root){
    if(root->left == NULL && root->right == NULL){
        pair<int,int> ans;
        ans.second=ans.first=root->data;
        return ans;
    }
    pair<int,int> ans;
    ans.second=ans.first=root->data; 
    if(root->left){
        pii leftanswer = getMinAndMax(root->left);
        ans.second = max(ans.second,leftanswer.second);
        ans.first = min(ans.first,leftanswer.first);
    }
    if(root->right)
  {
     pii ansright= getMinAndMax(root->right);
      ans.second=max(ans.second,ansright.second);
      
      ans.first=min(ans.first,ansright.first);
  }
    return ans;
}



int main(){


cout<<"tanishw"<<endl;
}