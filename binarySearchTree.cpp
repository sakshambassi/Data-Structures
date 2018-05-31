#include <bits/stdc++.h>

using namespace std;

struct node
{
	int data;
	struct node *left, *right;	
};

struct node * create_node(int data)
{
	struct node * temp;
	temp = new(struct node);
	temp -> data = data;
	temp -> left = temp	-> right = NULL;
	return temp;
}

struct node * insert(struct node * root, int data)
{
	if(root == NULL)
		return create_node(data);
	if(data < root->data)
		root->left=insert(root->left, data);
	else if(data > root->data)
		root->right=insert(root->right, data);
	return root;
}

void inorder(struct node *root)
{
	if(root!=NULL)
	{
		inorder(root->left);
		cout<<root->data<<" \n";
		inorder(root->right);
	}
}

void postorder(struct node *root)
{
	if(root != NULL)
	{
		postorder(root->left);
		postorder(root->right);
		cout<<root->data<<" \n";
	}
}

void preOrder(struct node *root)
{
	if(root != NULL)
	{
		cout<<root->data<<" \n";
		preOrder(root->left);
		preOrder(root->right);
	}
	else
		return;
}

struct node *search(struct node *root, int data)
{
	if(root==NULL || root->data == data)
		return root;
	if(root->data > data)
		return search(root->left, data);
	return search(root->right, data);
}

//for deletion function
struct node *minValue(struct node *root)
{
	struct node *curr = root;
	while(curr->left!=NULL)
		curr=curr->left;
	return curr;
}

struct node *deleteNode(struct node* root, int data)
{
	if(root==NULL)
		return root;
	
	if (data < root->data)
		root->left = deleteNode(root->left, data);

	else if (data > root->data)
		root->right = deleteNode(root->right, data);

	else
	{
		//one child or zero child
		if(root->left==NULL)
		{
			struct node * temp = root->right;
			free(root);
			return temp;
		}
		else if(root->right==NULL)
		{
			struct node * temp = root->left;
			free(root);
			return temp;
		}
		//two children
		struct node *temp = minValue(root->right);
		root->data = temp->data;
		root->right = deleteNode(root->right, temp->data);
	}
	return root;
}
int main()
{
	int value;
	struct node *root = NULL,*searched;
	root = insert(root, 50);
	insert(root, 30);
	insert(root, 20);
	insert(root, 40);
	insert(root, 70);
	insert(root, 60);
	insert(root, 80);
	inorder(root);
	cout<<"post Order:\n ";
	postorder(root);
	cout<<"pre Order: \n";
	preOrder(root);
	cout<<"Enter element to be searched: ";
	cin>>value;
	searched = search(root, value);
	if(searched!=NULL)
		cout<<"Searched element found at "<<searched->data<<"\n";
	cout<<"Enter element to be deleted: ";
	cin>>value;
	root = deleteNode(root, value);
	cout<<"\n Inorder traversal of the modified tree: ";
	inorder(root);
	return 0;
}