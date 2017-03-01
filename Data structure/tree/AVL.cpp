//Root of AVL Tree
#include<iostream>
using namespace std;

#define Max(a,b) ((a)>(b)?(a):(b))
#define Min(a,b) ((a)<(b)?(a):(b))

typedef struct Node* Tree;
struct Node{
	int data;
	Node* left;
	Node* right;
	int height;
};

int GetHeight(Tree T)
{
	if (T == NULL)
		return 0;
	return Max(GetHeight(T->left), GetHeight(T->right)) + 1;
}

//×ó×óÐý×ª
Tree LL(Tree T)
{
	Tree B = T->left;
	T->left = B->right;
	B->right = T;
	T->height = Max(GetHeight(T->left), GetHeight(T->right)) + 1;
	B->height = Max(GetHeight(B->left), GetHeight(B->right))+1;

	return B;
}
//ÓÒÓÒÐý×ª
Tree RR(Tree T)
{
	Tree B = T->right;
	T->right = B->left;
	B->left = T;
	T->height = Max(GetHeight(T->left), GetHeight(T->right)) + 1;
	B->height = Max(GetHeight(B->left), GetHeight(B->right)) + 1;
	return B;
}
//×óÓÒÐý×ª
Tree LR(Tree T)
{
	T->left=RR(T->left);
	return LL(T);
}
//ÓÒ×óÐý×ª
Tree RL(Tree T)
{
	T->right = LL(T->right);
	return RR(T);

}


Tree Insert(Tree T, int X)
{
	if (T == NULL)
	{
		T = (Tree)malloc(sizeof(struct Node));
		T->height = 0;
		T->data = X;
		T->left = T->right = NULL;
	}
	else if (X < T->data)
	{
		T->left = Insert(T->left, X);
		if (GetHeight(T->left) - GetHeight(T->right) == 2)
		{
			if (X < T->left->data)
				T = LL(T);//×ó×ó
			else
				T = LR(T);
		}
	}
	else if (X>T->data)
	{
		T->right = Insert(T->right, X);
		if (GetHeight(T->right) - GetHeight(T->left) == 2)
		{
			if (X > T->right->data)
				T = RR(T);
			else
				T = RL(T);
		}
	}
	T->height = Max(GetHeight(T->left), GetHeight(T->right)) + 1;
	return T;
}


int main(void)
{
	int N;
	cin >> N;
	Tree T=NULL;
	for (size_t i = 0; i < N; i++)
	{
		int X;
		cin >> X;
		/*cout << "insert " << X << " into the tree" << endl;*/
		T = Insert(T, X);
	}
	cout << T->data << endl;
}