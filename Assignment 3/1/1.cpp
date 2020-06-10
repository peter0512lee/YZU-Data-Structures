#include <iostream>
#include <iomanip>
#define COUNT 10

using namespace std;

class BST;
class TreeNode {
private:
	TreeNode *leftchild;
	TreeNode *rightchild;
	TreeNode *parent;
	int key;
	
public:	
	TreeNode() :leftchild(0), rightchild(0), parent(0), key(0) {};
	TreeNode(int a) :leftchild(0), rightchild(0), parent(0), key(a) {};
	
	friend class BST;
};

class BST {
private:	
	TreeNode* Leftmost(TreeNode *current);
	TreeNode* rightmost(TreeNode *current);
	TreeNode* Successor(TreeNode *current);

public:
	TreeNode * root;
	BST() :root(0) {};

	TreeNode* Search(int key);
	//[1]
	void InsertBST(int key);
	//[2]
	void DeleteBST(int KEY);
	//[3]
	void Minimum(TreeNode *current);
	//[4]
	void Maximum(TreeNode *current);
	//[5]
	void printBSTUtil(TreeNode * root, int space);
	void printBST(TreeNode * root);
	//[6]	
	void PreorderPrint(TreeNode *current);
	//[7]
	void PostorderPrint(TreeNode *current);	
	//[8]
	void Swap(TreeNode **a, TreeNode **b);
	void swapEveryLevelUtil(TreeNode *root, int level);
	void swapEveryLevel(TreeNode *root);
	
};

TreeNode* BST::Search(int KEY) {

	TreeNode *current = root;               // �Ncurent���Vroot�@��traversal�_�I

	while (current != NULL && KEY != current->key) {  // ��ر��p���X�j��G
													  // 1.�S��� 2.�����
		if (KEY < current->key) {
			current = current->leftchild;   // �V����
		}
		else {
			current = current->rightchild;  // �V�k��
		}
	}
	return current;
}

void BST::InsertBST(int key)
{	

	TreeNode *y = 0;        //insert_node��parent
	TreeNode *x = 0;        //�M��n���J����m������
	TreeNode *insert_node = new TreeNode(key);

	x = root;
	while (x != NULL) {                //�HSearch()���覡�M��A����m       
		y = x;
		if (insert_node->key < x->key) {
			x = x->leftchild;
		}
		else {
			x = x->rightchild;
		}
	}                                  // ���X�j���, x�Y��NULL
									   // y�Y��insert_node��parent
	insert_node->parent = y;           // �Ninsert_node��parent pointer���Vy

	if (y == NULL) {                    // ��insert_node���WBST
		this->root = insert_node;
	}
	else if (insert_node->key < y->key) {
		y->leftchild = insert_node;
	}
	else {
		y->rightchild = insert_node;
	}
}

void BST::DeleteBST(int KEY) {               

	TreeNode *delete_node = Search(KEY);    // ���T�{BST���O�_���㦳KEY��node
	if (delete_node == NULL) {
		std::cout << "data not found.\n";
		return;
	}

	TreeNode *y = 0;      // �u���n�Q�R��������O���骺node
	TreeNode *x = 0;      // �n�Q�R����node��"child"

	if (delete_node->leftchild == NULL || delete_node->rightchild == NULL) {
		y = delete_node;
	}
	else {
		y = Successor(delete_node);        // �Ny�]��delete_node��Successor
	}                                      // �g�L�o��if-else, y�վ㦨�ܦh�u���@��child
										   // �����վ㦨case1��case2�ӳB�z
	if (y->leftchild != NULL) {
		x = y->leftchild;                  // �Nx�]��y��child, �i��O���İO����,
	}                                      // �]���i��ONULL
	else {
		x = y->rightchild;
	}

	if (x != NULL) {                        // �by�Q�R�����e, �o�ӨB�J��x���^BST
		x->parent = y->parent;             // ���Y���ϤG(c)��, ���ñ��^�t�P�H���B�J
	}
	// ���ۦA��n�Q����O���骺node��"parent"���V�s��child
	if (y->parent == NULL) {                // �Y�R�����O�����root, �N��x���s��root 
		this->root = x;
	}
	else if (y == y->parent->leftchild) {    // �Yy�쥻�O��parent��left child
		y->parent->leftchild = x;           // �K��x�Ҧby��parent��left child, ���Ny
	}
	else {                                   // �Yy�쥻�O��parent��right child
		y->parent->rightchild = x;          // �K��x�Ҧby��parent��right child, ���Ny
	}
	// �w��case3
	if (y != delete_node) {                 // �Yy�Odelete_node������, �̫�n�A�Ny�����
		delete_node->key = y->key;          // ��^delete_node���O�����m, �ñNy���O�����m����
		  
	}

	delete y;                               // �Ny���O�����m����
	y = 0;
}

TreeNode* BST::Leftmost(TreeNode *current) {

	while (current->leftchild != NULL) {
		current = current->leftchild;
	}
	return current;
}

TreeNode* BST::rightmost(TreeNode *current) {
	while (current->rightchild != NULL) {
		current = current->rightchild;
	}
	return current;
}

TreeNode* BST::Successor(TreeNode *current) {

	if (current->rightchild != NULL) {
		return Leftmost(current->rightchild);
	}

	TreeNode *new_node = current->parent;

	while (new_node != NULL && current == new_node->rightchild) {
		current = new_node;
		new_node = new_node->parent;
	}

	return new_node;
}

void BST::PreorderPrint(TreeNode *current) {	
	if (current) {										// if current != NULL
		std::cout << "(" << current->key << ")" << " ";	// V
		PreorderPrint(current->leftchild);				// L
		PreorderPrint(current->rightchild);				// R
	}
}

void BST::PostorderPrint(TreeNode *current) {
	if (current) {										 // if current != NULL
		PostorderPrint(current->leftchild);				 // L
		PostorderPrint(current->rightchild);			 // R
		std::cout << "(" << current->key << ")" << " ";  // V
	}
}

void BST::Minimum(TreeNode *current)
{
	while (current->leftchild != NULL) {
		current = current->leftchild;
	}
	cout << "(" << current->key << ")";
}

void BST::Maximum(TreeNode *current)
{
	while (current->rightchild != NULL) {
		current = current->rightchild;
	}
	cout << "(" << current->key << ")";
}

void BST::Swap(TreeNode **a, TreeNode **b)
{	
	TreeNode *temp = *a;
	*a = *b;
	*b = temp;
	
}

void BST::swapEveryLevelUtil(TreeNode *root, int level)
{
	// base case 
	if (root == NULL || (root->leftchild == NULL && root->rightchild == NULL))
		return;
	
	Swap(&root->leftchild, &root->rightchild);

	// Recur for left and right subtrees 
	swapEveryLevelUtil(root->leftchild, level + 1);
	swapEveryLevelUtil(root->rightchild, level + 1);
}

void BST::swapEveryLevel(TreeNode *root)
{
	// call swapEveryKLevelUtil function with 
	// initial level as 1. 
	swapEveryLevelUtil(root, 1);
}

void BST::printBSTUtil(TreeNode *root, int space)
{
	// Base case 
	if (root == NULL)
		return;

	// Increase distance between levels 
	space += COUNT;

	// Process right child first 
	printBSTUtil(root->rightchild, space);

	// Print current node after space 
	// count 
	printf("\n");
	for (int i = COUNT; i < space; i++)
		cout << " ";
	cout << root->key << endl;

	// Process left child 
	printBSTUtil(root->leftchild, space);
}

void BST::printBST(TreeNode *root)
{
	// Pass initial space count as 0 
	printBSTUtil(root, 0);
}

int main() 
{	
	BST T;

	while (true)
	{
		cout << "[1].Insert a key\n";
		cout << "[2].Delete a key\n";
		cout << "[3].Find the minimum key in current binary tree\n";
		cout << "[4].Find the maximum key in current binary tree\n";
		cout << "[5].Print out current binary tree\n";
		cout << "[6].Perform a pre - order traversal of the tree\n";
		cout << "[7].Perform a post - order traversal of the tree\n";
		cout << "[8].Swap the left child and right child of every node of the binary search tree.\n";
		cout << "[9].Exit\n\n";

		int choice;
		cout << "choice:";
		cin >> choice;
		switch (choice)
		{
		case 1:
			int number;
			cout << "Insert key number:";
			cin >> number;
			T.InsertBST(number);
			cout << endl;
			break;
		case 2:
			int number1;
			cout << "Delete key number:";
			cin >> number;
			T.DeleteBST(number);
			cout << endl;
			break;
		case 3:
			T.Minimum(T.root);
			cout << endl;
			break;
		case 4:
			T.Maximum(T.root);
			cout << endl;
			break;
		case 5:
			T.printBST(T.root);
			cout << endl;
			break;
		case 6:
			T.PreorderPrint(T.root);
			cout << endl;
			break;
		case 7:
			T.PostorderPrint(T.root);
			cout << endl;
			break;
		case 8:
			T.swapEveryLevel(T.root);
			cout << endl;
			break;
		case 9:
			system("pause");
			return 0;
		default:
			break;
		}
	}

	return 0;
}
