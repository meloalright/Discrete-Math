#include <stdio.h>
#include <string.h>
struct BTreeNode {
	char e;
	BTreeNode *left;
	BTreeNode *right;
};
typedef BTreeNode* BTree;
BTreeNode *createBTreeNode(char e) {
	BTreeNode *nd = new BTreeNode;
	nd->e = e;
	nd->left = NULL;
	nd->right = NULL;
	return nd;
}
int findChar(const char *str, int s1, int s2, char c) {
	if (!str || s2 < s1 || s1 < 0 || s2 >= strlen(str))
		return -1;
	for (int i = s1; i <= s2; i++) {
		if (str[i] == c)
			return i;
	}
	return -1;
}
BTreeNode *getRoot(char *pre, int p1, int p2, char *in, int i1, int i2) {
	char rootCh = pre[p1];
	if (!pre || p2 < p1 || p1 < 0 || p2 >= strlen(pre) || !in || i2 < i1 || i1
			< 0 || i2 >= strlen(in)) {
		return NULL;
	}
	int tmp = findChar(in, i1, i2, rootCh);
	if (tmp < 0) {
		return NULL;
	}
	BTreeNode *nd = createBTreeNode(rootCh);
	nd->left = getRoot(pre, p1 + 1, p1 + tmp - i1, in, i1, tmp - 1);
	nd->right = getRoot(pre, p1 + tmp - i1 + 1, p2, in, tmp + 1, i2);
	return nd;
}
BTree createBTree(char *pre, char *in) {
	if (!pre || !in)
		return NULL;
	return getRoot(pre, 0, strlen(pre) - 1, in, 0, strlen(in) - 1);
}
void printPostOrder(BTree t) {
	if (!t)
		return;
	printPostOrder(t->left);
	printPostOrder(t->right);
	printf("%c", t->e);
}
void printBTreeNode(BTreeNode *nd, int depth) {
	for (int i = 0; i < depth - 1; i++)
		printf("  ");
	if (depth > 0)
		printf("--");
	if (!nd) {
		printf("*/n");
		return;
	}
	printf("%c/n", nd->e);
	printBTreeNode(nd->left, depth + 1);
	printBTreeNode(nd->right, depth + 1);
}
void printBTree(BTree t) {
	printBTreeNode(t, 0);
}
int countBTree(BTree t) {
	if (!t)
		return 0;
	return countBTree(t->left) + countBTree(t->right) + 1;
}
int main() {
	char pre[] = "ABDGCEFH";
	char in[] = "DGBAECHF";
	BTree t = createBTree(pre, in);
	printf("Preorder: %s/n", pre);
	printf("Inorder: %s/n", in);
	if (countBTree(t) != strlen(pre)) {
		printf("No such a binary tree!/n");
		return 0;
	}
	printf("Postorder: ");
	printPostOrder(t);
	printf("/n");
	printf("The BTree is (* means no such node):/n");
	printBTree(t);
	return 0;
}