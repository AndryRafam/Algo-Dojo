/* Andry Rafam Andrianjafy - September 2018.
Little program which demonstrate how binary search tree (BST) works.*/

#include <bits/stdc++.h>
using namespace std;

struct node
{
	int data;
	struct node* left;
	struct node* right;
};

// Create a Node
struct node* createNode (int value) 
{ 
	struct node* newNode = (struct node*)malloc(sizeof(struct node));
	newNode->data = value;
	newNode->left = NULL;
	newNode->right = NULL;
}

// Insert a Node
struct node* insert (struct node* root, int data)
{
	if (root == NULL) return createNode(data);
	if (data < root->data)
		root->left = insert(root->left,data);
	else if (data > root->data)
		root->right = insert(root->right, data);
		
	return root;
}

// Print the elements of the tree
void inorder (struct node* root) {
	if (root == NULL) return;
	inorder (root->left);
	cout << root->data << " --> ";
	inorder (root->right);
}

// Search if an element is in the tree
struct node* search (struct node* root, int number)
{
	if (root == NULL || root->data == number)
		return root;
	else if (number < root->data)
		return search (root->left,number);
	else if (number > root->data)
		return search (root->right,number);
}

int main () {
	struct node *root = NULL;
	srand(time(NULL));
	cout << endl;
	root = insert (root,rand() % 50 + 1);
	cout <<"The root of the tree is initialized with the value >>  " << root->data << endl;  // Initialize randomly the root of the tree
	
	for (int i = 0; i < 10; i++) { // Initialize randomly the element of the tree
		int key = rand () % 50 + 1;
		insert (root,key);
	}
	int element;
	cout << endl;
	cout <<"Enter a number >>  ";
	cin >> element;
	cout << endl;

	// Check if the element is in tree	
	if (search(root,element))
		cout <<"Element found" << endl;
	else
		cout <<"Element not found. Inserting element " << element << endl; // If an element is not in the tree; insert the element

	insert (root,element); // Insert the element
	cout << endl;
	cout <<"The elements of the tree are >>  ";
	inorder(root); // Print the element
	cout << endl << endl;
	return 0;
}
		


