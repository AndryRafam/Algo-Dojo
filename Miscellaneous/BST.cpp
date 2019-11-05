// Binary Search Tree

#include <bits/stdc++.h>
using namespace std;

class TreeNode{
	private:
		int val;
		TreeNode *left;
		TreeNode *right;
	public:
		TreeNode(int x): val(x), left(NULL), right(NULL) {}
		static TreeNode *createNode(int value){
			TreeNode *temp = new TreeNode(value);
			temp->val = value;
			temp->left = temp->right = NULL;
			return temp;
		}
		static TreeNode *insert(TreeNode *root, int value){
			if(root == NULL)
				return createNode(value);
			if(value < root->val)
				root->left = insert(root->left,value);
			else if(value > root->val)
				root->right = insert(root->right,value);
			return root;
		}
		static void InorderTreeWalk(TreeNode *root){
			if(root==NULL)
				return;
			InorderTreeWalk(root->left);
			printf("%d → ",root->val);
			InorderTreeWalk(root->right);
		}
		static bool find(TreeNode *root, int value){
			while(root!= NULL && value != root->val){
                if(value < root->val)
                    root = root->left;
                else
                    root = root->right;
			}
			return root;
		}
		static int minimum(TreeNode *root){
            while(root->left!=NULL)
                root = root->left;
            return root->val;
		}
		static int maximum(TreeNode *root){
            while(root->right!=NULL)
                root = root->right;
            return root->val;
		}
};
int main(){
	TreeNode *root = NULL;
	root = TreeNode::insert(root,15);
	vector<int> input = {6,7,3,2,4,13,9,18,17,20};
	for(auto &x : input)
        TreeNode::insert(root,x);
    TreeNode::InorderTreeWalk(root); puts("\n");
    cout << "Minimum element of the BST → " << TreeNode::minimum(root); puts("\n");
    cout << "Maximum element of the BST → " << TreeNode::maximum(root); puts("\n");
    if(TreeNode::find(root,42))
    	puts("OK");
    else
    	puts("KO");
}
