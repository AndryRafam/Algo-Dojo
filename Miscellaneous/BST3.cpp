#include <bits/stdc++.h>
using namespace std;

class TreeNode{
	private:
		int val;
		TreeNode *left;
		TreeNode *right;
	public:
        TreeNode(int x): val(x), left(NULL), right(NULL) {}
		static TreeNode *createNode(int key){
			TreeNode *temp = new TreeNode(key);
			temp->val = key;
			temp->left = temp->right = NULL;
			return temp;
		}
		static TreeNode *insert(TreeNode *root, int key){
			 if(root == NULL)
                return createNode(key);
            if(key < root->val)
                root->left = insert(root->left,key);
            else if(key > root->val)
                root->right = insert(root->right,key);
            return root;
		}
		static void dfs_Inorder(TreeNode *root){
			if(root!=NULL){
				dfs_Inorder(root->left);
				cout << root->val << "→";
				dfs_Inorder(root->right);
			}
		}
		static bool is_BST(TreeNode *root, TreeNode* prev){
			if(root==NULL)
				return true;
			bool left = is_BST(root->left,prev);
			if(root->val <= prev->val)
				return false;
			prev = root;
			return left & is_BST(root->right,prev);
		}
		static TreeNode *find(TreeNode *root, int value){
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
	TreeNode *prev = new TreeNode(INT_MIN);
	puts("\n");
	for(auto &x : input)
        TreeNode::insert(root,x);
	TreeNode::dfs_Inorder(root); puts("\n");
	if(TreeNode::is_BST(root,prev))
		puts("BST");
	else
		puts("NOT BST");
	puts("\n");
	cout << "Minimum element of the BST → " << TreeNode::minimum(root); puts("\n");
    cout << "Maximum element of the BST → " << TreeNode::maximum(root); puts("\n");
    if(TreeNode::find(root,42))
    	puts("OK");
    else
    	puts("KO");
}
