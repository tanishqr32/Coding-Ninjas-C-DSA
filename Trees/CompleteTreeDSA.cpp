// all the major DSA problems are here

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

int sumOfNodes(TreeNode<int>* root){
    int ans = root->data;
    for(int i = 0;i<root->children.size();i++){
        ans += sumOfNodes(root->children[i]);

    }
    return ans;
}


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

int getHeight(TreeNode<int>* root) {
    int ans = 0;
    for(int i = 0;i<root->children.size();i++){
        int smallans = getHeight(root->children[i]);
        if(smallans>ans){
            ans = smallans;
        } 
    }
    return ans+1;
}

void printAtLevelK(TreeNode<int> * root,int k){
    if(root == NULL){
        return;
    }
    if(k == 0){
        cout<< root->data<<endl;
    }
    for(int i = 0;i<root->children.size();i++){
        printAtLevelK(root->children[i],k-1); 
    }
    
}

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

void preOrder(TreeNode<int>* root){
    cout<<root->data<<" ";
    for(int i = 0;i<root->children.size();i++){
        preOrder(root->children[i]); 
    }
}

void printPostOrder(TreeNode<int>* root) {
    for(int i = 0;i<root->children.size();i++){
        printPostOrder(root->children[i]); 
    }
    cout<<root->data<<" ";
}

bool isPresent(TreeNode<int>* root, int x) {
    
    if(root->data == x){
       return true;
    }
    bool ans = false;
    for(int i = 0;i<root->children.size();i++){
        ans = isPresent(root->children[i], x);
        if(ans == true){
            return true;
        }
    }
    return ans;
    
}

int getLargeNodeCount(TreeNode<int>* root, int x) {
    int count = 0;
    if(root->data > x){
        count++;
    }
    for(int i = 0;i<root->children.size();i++){
        count += getLargeNodeCount(root->children[i],x);
    }
    return count;
}

TreeNode<int>* maxSumNode(TreeNode<int>* root) {
    int sum = root->data;
    TreeNode<int>* ans = root;
    for(int i = 0;i<root->children.size();i++){
        sum += root->children[i]->data;
        TreeNode<int>* temp = maxSumNode(root->children[i]);
        int tempS = temp->data;
        for(int j = 0;j<temp->children.size();j++){
            tempS += temp->children[j]->data;
        }
        if(sum<tempS){
            ans = temp;
        }
    }
    return ans;
}

bool areIdentical(TreeNode<int> *root1, TreeNode<int> * root2) {
    if(root1->data != root2->data){
        return false;
    }
    if(root2->children.size() != root1->children.size()){
        return false;
    }
    bool are = true;
    for(int i = 0;i<root1->children.size();i++){
        bool temp;
        temp = areIdentical(root1->children[i],root2->children[i]);
        if(temp == false){
            return false;
        }
        are = temp;
    }
    return are;
}

TreeNode<int>* getNextLargerElement(TreeNode<int>* root, int x) {
     if(root==NULL)
        return NULL;
    TreeNode<int>* ans = NULL;
    if(root->data > x){
        ans = root;
    }
    for(int i = 0;i<root->children.size();i++){
        TreeNode<int>* temp = getNextLargerElement(root->children[i],x);
        if(temp == NULL){
            continue;
        }
        else {
            if(ans == NULL){
                ans = temp;
            }
            else if(temp->data > x && temp->data<ans->data){
            	ans = temp;      
            }
        }
        
    }
    return ans;
}

/*********************************************/
class HelperS_L_N{
     public :
    TreeNode<int>*  max;
    TreeNode<int>* s_max;
    
    HelperS_L_N (TreeNode<int>* max, TreeNode<int>* s_max) {
        this->max = max;
        this->s_max = s_max;
    }
};

HelperS_L_N help (TreeNode<int> * root){
    if(root==NULL){
        HelperS_L_N r(NULL,NULL);
        return r;
    }
    HelperS_L_N ans(root, NULL);
     for (int i = 0; i < root->children.size(); i++) {
            HelperS_L_N child = help (root -> children[i]);  
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
TreeNode<int>* getSecondLargestNode(TreeNode<int>* root){
     
    if (root == NULL) 
        return NULL;
    HelperS_L_N ans = help (root);
    return ans.s_max;
}
/***********************************************/

void helper (TreeNode<int>* root,int k){
    root->data = k;
    for(int i = 0;i<root->children.size();i++){
        helper(root->children[i],k+1);
    }
}


void replaceWithDepthValue(TreeNode<int>* root) {
    int k = 0;
    helper(root,k);
}

/*************************************************/

void printLevelATNewLine(TreeNode<int>* root) {
    queue<TreeNode<int>*> q;
    q.push(root);
    q.push(NULL);
    while (!q.empty()) {
        TreeNode<int>* first = q.front();
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
        for (int i = 0; i < first->children.size(); i++) {
            q.push(first->children[i]);
        }
    }
}

int main() {
    TreeNode<int>* root = takeInputLevelWise();
   
}