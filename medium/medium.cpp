// Question: Given a binary search tree (BST), find the lowest common ancestor (LCA) node of two given nodes in the BST.

#include <iostream>
using namespace std;

struct Node
{
	int data;
	Node *left;
	Node *right;

	Node(int value) : data(value), left(nullptr), right(nullptr) {}
};

Node *LCA(Node *root, int n1, int n2)
{
	if (root == nullptr)
	{
		return nullptr;
	}

	if (root->data < n1 && root->data < n2)
	{
		return LCA(root->right, n1, n2);
	}

	if (root->data > n1 && root->data > n2)
	{
		return LCA(root->left, n1, n2);
	}

	return root;
}

Node *createNode(int value)
{
	return new Node(value);
}

int main()
{
	int rootValue;
	cin >> rootValue;
	Node *root = createNode(rootValue);

	int value;
	while (cin >> value)
	{
		Node *currentNode = root;
		Node *parent = nullptr;

		while (currentNode != nullptr)
		{
			parent = currentNode;
			if (value < currentNode->data)
			{
				currentNode = currentNode->left;
			}
			else
			{
				currentNode = currentNode->right;
			}
		}

		if (value < parent->data)
		{
			parent->left = createNode(value);
		}
		else
		{
			parent->right = createNode(value);
		}
	}

	int n1, n2;
	cout << "Enter two node values for finding their Lowest Common Ancestor: ";
	cin >> n1 >> n2;

	Node *lcaNode = LCA(root, n1, n2);

	// Output the result
	if (lcaNode != nullptr)
	{
		cout << "Lowest Common Ancestor of " << n1 << " and " << n2 << " is: " << lcaNode->data << endl;
	}
	else
	{
		cout << "One or both nodes not found in the tree." << endl;
	}

	return 0;
}
