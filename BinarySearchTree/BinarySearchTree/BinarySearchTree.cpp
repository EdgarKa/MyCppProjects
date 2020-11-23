/*
* Title: Binary Search Tree
* Author: Edgar Podvezko
* Date: 2020
* Software: Visual Studio 2019
*/

#include <iostream>

class BinTreeNode {
public:
	BinTreeNode(int value) {
		this->value = value;
		this->left = NULL;
		this->right = NULL;
	}
	int value;
	BinTreeNode* left;
	BinTreeNode* right;

};

/* Insert in tree */
BinTreeNode* tree_insert(BinTreeNode* tree, int item) {
	if (tree == NULL)
		tree = new BinTreeNode(item);
	else
		if (item < tree->value)
			if (tree->left == NULL)
				tree->left = new BinTreeNode(item);
			else
				tree_insert(tree->left, item);
		else
			if (tree->right == NULL)
				tree->right = new BinTreeNode(item);
			else
				tree_insert(tree->right, item);
	return tree;

}
/* Preorder */
void preorder(BinTreeNode* tree) {
	std::cout << tree->value << " ";
	if (tree->left != NULL)
		preorder(tree->left);
	if (tree->right != NULL)
		preorder(tree->right);


}

/* Postorder */
void postorder(BinTreeNode* tree) {
	if (tree->left != NULL)
		postorder(tree->left);
	if (tree->right != NULL)
		postorder(tree->right);
	std::cout << tree->value << " ";

}

/* Inorder */
void in_order(BinTreeNode* tree) {
	if (tree->left != NULL)
		in_order(tree->left);
	std::cout << tree->value << " ";
	if (tree->right != NULL)
		in_order(tree->right);
}

/* Find minimal node */
void minimum(BinTreeNode* tree) {
	if (tree->left != NULL)
		minimum(tree->left);
	else std::cout << "Minimal -> " << tree->value << std::endl;
	//return;
}

int main(int argc, char* argv[])
{
	BinTreeNode* t = tree_insert(0, 6);
	tree_insert(t, 10);
	tree_insert(t, 5);
	tree_insert(t, 2);
	tree_insert(t, 3);
	tree_insert(t, 4);
	tree_insert(t, 11);
	std::cout << "In order: " << std::endl;
	in_order(t);
	std::cout << std::endl << "Preorder: " << std::endl;
	preorder(t);
	std::cout << std::endl << "Postorder: " << std::endl;
	postorder(t);
	std::cout << std::endl;
	minimum(t);
	return 0;
}