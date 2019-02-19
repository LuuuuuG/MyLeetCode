#include <iostream>
#include <00_util.h>
using namespace std;

/*
Given a root node reference of a BST and a key, delete the node with the given key in the BST. Return the root node reference (possibly updated) of the BST.

Basically, the deletion can be divided into two stages:

Search for a node to remove.
If the node is found, delete the node.
Note: Time complexity should be O(height of tree).

Example:

root = [5,3,6,2,4,null,7]
key = 3

    5
   / \
  3   6
 / \   \
2   4   7

Given key to delete is 3. So we find the node with value 3 and delete it.

One valid answer is [5,4,6,2,null,null,7], shown in the following BST.

    5
   / \
  4   6
 /     \
2       7

Another valid answer is [5,2,6,null,4,null,7].

    5
   / \
  2   6
   \   \
    4   7

450. Delete Node in a BST: https://leetcode.com/problems/delete-node-in-a-bst/description/
*/

class Solution {
public:
	TreeNode* deleteNode(TreeNode* root, int key) {
		if (!root) return root;

		if (root->val > key)
			root->left = deleteNode(root->left, key);
		else if (root->val < key)
			root->right = deleteNode(root->right, key);
		else {
			if (!root->right) {
				TreeNode* left = root->left;
				delete root;
				return left;
			}
			
			//TreeNode* minNode = findMinNode(root->right); 
			//root->val = minNode->val;
			//equals to:
			TreeNode* minNode = root->right;
			while (minNode->left) minNode = minNode->left;
			swap(root->val, minNode->val);

			root->right = deleteNode(root->right, minNode->val);

		}
		return root;
	}
private:
	TreeNode* findMinNode(TreeNode* root) {
		if (root->left) return findMinNode(root->left);
		return root;
	}
};

int main_450()
{
	TreeNode *tree = TreeCreate(7, 5, 3, 6, 2, 4, INT_MAX, 7);
	TreePrint(tree);

	Solution s1;
	s1.deleteNode(tree, 5);
	TreePrint(tree);

	system("pause");
	return 0;
}