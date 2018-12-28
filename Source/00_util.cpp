#include "00_util.h"

//vector:
#if 0
template<typename T>
void VectorPrint(vector<T> &vec)
{
	for (auto i : vec)
		cout << i << " , ";
	cout << endl;
}

template<typename T>
void Vector2DPrint(vector<vector<T> > &vec)
{
	printf("[\n");
	for (size_t i = 0; i < vec.size(); i++)
	{
		printf("[ ");
		for (size_t j = 0; j < vec[i].size(); j++)
			cout << vec[i][j] << ", ";
		printf(" ]\n");
	}
	printf("]\n");
}
#endif

//List
ListNode *ListCreate(int count, ...)
{
	va_list argptr;
	va_start(argptr, count);

	ListNode *head, *curr;
	int num = va_arg(argptr, int);
	head = new ListNode(num);
	curr = head;
	for (int i = 1; i < count; i++)
	{
		num = va_arg(argptr, int);
		ListNode *temp = new ListNode(num);
		curr->next = temp;
		curr = temp;
	}
	va_end(argptr);
	return head;
}

void ListPrint(ListNode *head)
{
	ListNode *node = head;
	while (node)
	{
		cout << node->val;// << " -> ";
		node = node->next;
		if (node)
			cout << " -> ";
	}
	cout << endl;
}


//Tree:
TreeNode *TreeCreate(int count, ...)
{
	va_list argptr;
	va_start(argptr, count);

	TreeNode **treeArr = new TreeNode*[count];
	for (int i = 0; i < count; i++)
	{
		int num = va_arg(argptr, int);
		if (INT_MAX == num)
			treeArr[i] = NULL;
		else
			treeArr[i] = new TreeNode(num);
	}

	int curr = 1;
	for (int i = 0; i < count; i++)
	{
		if (!treeArr[i])
			continue;

		if (curr < count)
			treeArr[i]->left = treeArr[curr++];
		if (curr < count)
			treeArr[i]->right = treeArr[curr++];
	}

	va_end(argptr);
	return treeArr[0];
}


void SubTreePrint(TreeNode *node, int level)
{
	if (!node)
		return;

	SubTreePrint(node->right, level + 1);
	for (int i = 0; i < level; i++)
		printf("    ");
	printf("%4d\n", node->val);
	SubTreePrint(node->left, level + 1);
}

void TreePrint(TreeNode *root)
{
	cout << "------------------------------------" << endl;
	SubTreePrint(root, 0);
	cout << "------------------------------------" << endl;
}