#include <bits/stdc++.h>

using namespace std;

struct node
{
    int data;
    node *left;
    node *right;

    node(int d)
    {
        data = d;
        left = NULL;
        right = NULL;
    }
};
int search(int curr,int inorder[],int start,int end){
    for(int i=start;i<=end;i++){
        if(inorder[i]==curr){
            return i;
        }
    }
    return -1;
}

node *buildTreeinpre(int preorder[], int inorder[], int start, int end)
{
    static int i = 0;
    if (start > end)
    {
        return NULL;
    }
    int curr = preorder[i];
    i++;
    node *root = new node(curr);
    if (start == end)
    {
        return root;
    }
    int pos = search(curr, inorder, start, end);
    root->left = buildTreeinpre(preorder, inorder, start, pos - 1);
    root->right = buildTreeinpre(preorder, inorder, pos + 1, end);

    return root;
}

void printInorder(node* root){
        if(root==NULL){
            return;
        }
    printInorder(root->left);
    cout<<root->data<<" ";
    printInorder(root->right);
}
int main()
{
    int n;
    cout<<"Enter the no. of nodes in tree\n";
    cin>>n;
    int preorder[n];
    int inorder[n];
    cout<<"Enter the preorder sequence\n";
    for(int i=0;i<n;i++){
        cin>>preorder[i];
    }
    cout<<"Enter the inorder sequence\n";
    for(int i=0;i<n;i++){
        cin>>inorder[i];
    }
    node* root=buildTreeinpre(preorder,inorder,0,n-1);
    // cout<<"Inorder : ";
    // printInorder(root);
    cout<<endl;

    return 0;
}