#include<bits/stdc++.h>

using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};
//Traversal
vector<vector<int>> preInPostTraversal(Node* root){
    vector<vector<int>> ans;
    if(root==NULL) return ans;
    vector<int> pre,post,in;

    stack<pair<Node*,int>> st;
    st.push({root , 1});
    while(!st.empty()){
        auto p= st.top();
        st.pop();
        if(p.second==1){
            pre.push_back(p.first->data);
            p.second=2;
            st.push(p);

            if(p.first->left){
                st.push({p.first->left, 1});
            }
        }else if(p.second==2){
            in.push_back(p.first->data);
            p.second=3;
            st.push(p);

            if(p.first->right){
                st.push({p.first->right,2});
            }
        }else{
            post.push_back(p.first->data);
        }
    }
    ans.push_back(pre);
    ans.push_back(in);
    ans.push_back(post);
    return ans;
}

void printVector(const vector<int>& vec) {
    for (int num : vec) {
        cout << num << " ";
    }
    cout << endl;
}

//height of BT
int height(Node* root){
    if(root==NULL) return 0;

    int lh= height(root->left);
    int rh=height(root->right);

    return 1+max(lh,rh);
}
// check Height Balanced
int dfsHeight(Node* root){
    if(root==NULL) return -1;

    int lh=dfsHeight(root->left);
    int rh=dfsHeight(root->right);

    if(lh==-1) return -1;
    if(rh==-1) return -1;

    if(abs(lh-rh)>1) return -1;

    return 1+max(lh,rh);
}

bool isBalanced(Node* root){
     return dfsHeight(root)!=-1;
}

//maximum Path sum

int pathSumHelper(Node* root, int &maxi){
    if(root==NULL){
        return 0;
    }
    int leftmax=max(0, pathSumHelper(root->left,maxi));
    int rightmax=max(0, pathSumHelper(root->right,maxi));

    maxi=max(maxi,leftmax+rightmax+root->data);

    return max(leftmax,rightmax)+root->data;

}

int pathSum(Node* root){

    int maxi=INT_MIN;
    pathSumHelper(root,maxi);
    
    return maxi;
}

int main()
{
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

/*    vector<int> pre, in, post;
    vector<vector<int>> traversals = preInPostTraversal(root);

    pre = traversals[0];
    in = traversals[1];
    post = traversals[2];

    
    cout << "Preorder traversal: ";
    for (int val : pre) {
        cout << val << " ";
    }
    cout << endl;

    cout << "Inorder traversal: ";
    for (int val : in) {
        cout << val << " ";
    }
    cout << endl;

    cout << "Postorder traversal: ";
    for (int val : post) {
        cout << val << " ";
    }
    cout << endl;                                               */

    int Height=height(root);
    cout<<Height<<endl;
    cout<<isBalanced(root)<<endl;
    return 0;
}
                            
                        