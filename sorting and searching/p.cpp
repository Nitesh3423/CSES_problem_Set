
#include <iostream>
#include <sstream>
#include <unordered_map>
#include <vector>
#include <queue>
#include <map>
#include <stack>

using namespace std;

// TreeNode structure
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

TreeNode *prev = NULL;

// for preorder
void flatten(TreeNode *root)
{
    
    if (root == NULL)
    {
        return;
    }
    
    stack<TreeNode *> st;
    st.push(root);

   
    while (!st.empty())
    {
        // Get the top node from the stack.
        TreeNode *cur = st.top();
        // Pop the top node.
        st.pop();

        if (cur->right != NULL)
        {
            // Push the right child
            // onto the stack.
            st.push(cur->right);
        }

        if (cur->left != NULL)
        {
            // Push the left child
            // onto the stack.
            st.push(cur->left);
        }

        if (!st.empty())
        {
            // Connect the right child to
            // the next node in the stack.
            cur->right = st.top();
        }

        // Set the left child to NULL to
        // form a right-oriented linked list.
        cur->left = NULL;
    }
}
//inorder faltten
void flattenInorder(TreeNode* root){
    stack<TreeNode*> st;
    st.push(root);
    TreeNode* prev=NULL;
    TreeNode* curr=root;
    while(curr!=NULL and !st.empty()){
        while(curr!=NULL){
            st.push(curr->left);
            curr=curr->left;
        }
        curr=st.top();
        st.pop();
        if(prev!=NULL){
            prev->right=curr;
            prev->left=NULL;
        }
        prev=curr;
        curr=curr->right;
    }
}
void printInorder(TreeNode *root)
{
    if (!root)
    {
        return;
    }
    printInorder(root->left);
    cout << root->val << " ";
    printInorder(root->right);
}



void printPreorder(TreeNode *root)
{
    if (!root)
    {
        return;
    }
    cout << root->val << " ";
    printPreorder(root->left);
    printPreorder(root->right);
}

void printFlattenTree(TreeNode *root)
{
    if (!root)
    {
        return;
    }
    cout << root->val << " ";
    printFlattenTree(root->right);
}

int main()
{

    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->left->right->right = new TreeNode(6);
    root->right->right = new TreeNode(7);
    root->right->left = new TreeNode(8);

    // cout << "Binary Tree Preorder: ";
    // printPreorder(root);
    // cout << endl;
    // flatten(root);
    // cout << "Binary Tree After Flatten: ";
    // printFlattenTree(root);
    // cout << endl;
    cout << "Binary Tree Inorder: ";
    printInorder(root);
    cout << endl;
    flattenInorder(root);
    cout << "Binary Tree After Flatten Inorder: ";
    printFlattenTree(root);
    cout << endl;

    return 0;
}
