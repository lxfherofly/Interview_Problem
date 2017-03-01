#include<iostream>
using namespace std;

class node{
public:
	node(){};
	~node(){};
	node* left;
	node * right;
	int data;
};
//preorder the tree
void PrintTree(node* root)
{
	if (root == NULL)
		return;
	cout << root->data << endl;
	PrintTree(root->left);
	PrintTree(root->right);
}
//
node* InsertTree(node* bst, int data)
{
	if (!bst)
	{
		bst = new node();
		bst->data = data;
		bst->left = NULL;
		bst->right = NULL;
	}
	else
	{
		if (bst->data > data)
		{
			bst->left = InsertTree(bst->left, data);
		}
			
		else if (bst->data < data)
		{
			bst->right = InsertTree(bst->right, data);
		}
			
	}
	return bst;
}
//
void BuildTree(node*& root,const int & N)
{
	int data;
	for (size_t i = 0; i < N; i++)
	{
		cin >> data;
		/*cout << "insert the data=" << data << endl;*/
		root = InsertTree(root, data);
	}
}

void CompareTree(node* &root1, node* &root2, bool& result)
{
	if ((root1 == NULL) && (root2 == NULL))
	{
		return;
	}
	if (((root1 != NULL) && (root2 == NULL)) || ((root1 == NULL) && (root2 != NULL)))
	{
		result = false;
		return;
	}
	if (root1->data != root2->data)
	{
		result = false;
		return;
	}
	else{
		CompareTree(root1->left, root2->left, result);
		CompareTree(root1->right, root2->right, result);
	}
}

int main()
{
	int N, L;
	node* Origin=NULL;
	
	while (1)
	{
		cin >> N;
		if (N == 0){ break; }
		cin >> L;
		for (int i = 0; i < L + 1; i++)
		{
			if (i == 0)
			{
				BuildTree(Origin, N);
			}
			else{
				node* T1 = NULL;
				BuildTree(T1, N);
				bool result = true;
				CompareTree(Origin, T1, result);
				if (result)
					cout << "Yes" << endl;
				else
					cout << "No" << endl;
				delete T1;
			}
			
		}

	}
	
}