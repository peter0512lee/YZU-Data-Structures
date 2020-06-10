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

	TreeNode *current = root;               // 將curent指向root作為traversal起點

	while (current != NULL && KEY != current->key) {  // 兩種情況跳出迴圈：
													  // 1.沒找到 2.有找到
		if (KEY < current->key) {
			current = current->leftchild;   // 向左走
		}
		else {
			current = current->rightchild;  // 向右走
		}
	}
	return current;
}

void BST::InsertBST(int key)
{	

	TreeNode *y = 0;        //insert_node的parent
	TreeNode *x = 0;        //尋找要插入的位置的指標
	TreeNode *insert_node = new TreeNode(key);

	x = root;
	while (x != NULL) {                //以Search()的方式尋找適當的位置       
		y = x;
		if (insert_node->key < x->key) {
			x = x->leftchild;
		}
		else {
			x = x->rightchild;
		}
	}                                  // 跳出迴圈後, x即為NULL
									   // y即為insert_node的parent
	insert_node->parent = y;           // 將insert_node的parent pointer指向y

	if (y == NULL) {                    // 把insert_node接上BST
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

	TreeNode *delete_node = Search(KEY);    // 先確認BST中是否有具有KEY的node
	if (delete_node == NULL) {
		std::cout << "data not found.\n";
		return;
	}

	TreeNode *y = 0;      // 真正要被刪除並釋放記憶體的node
	TreeNode *x = 0;      // 要被刪除的node的"child"

	if (delete_node->leftchild == NULL || delete_node->rightchild == NULL) {
		y = delete_node;
	}
	else {
		y = Successor(delete_node);        // 將y設成delete_node的Successor
	}                                      // 經過這組if-else, y調整成至多只有一個child
										   // 全部調整成case1或case2來處理
	if (y->leftchild != NULL) {
		x = y->leftchild;                  // 將x設成y的child, 可能是有效記憶體,
	}                                      // 也有可能是NULL
	else {
		x = y->rightchild;
	}

	if (x != NULL) {                        // 在y被刪除之前, 這個步驟把x接回BST
		x->parent = y->parent;             // 此即為圖二(c)中, 把基紐接回龜仙人的步驟
	}
	// 接著再把要被釋放記憶體的node之"parent"指向新的child
	if (y->parent == NULL) {                // 若刪除的是原先的root, 就把x當成新的root 
		this->root = x;
	}
	else if (y == y->parent->leftchild) {    // 若y原本是其parent之left child
		y->parent->leftchild = x;           // 便把x皆在y的parent的left child, 取代y
	}
	else {                                   // 若y原本是其parent之right child
		y->parent->rightchild = x;          // 便把x皆在y的parent的right child, 取代y
	}
	// 針對case3
	if (y != delete_node) {                 // 若y是delete_node的替身, 最後要再將y的資料
		delete_node->key = y->key;          // 放回delete_node的記憶體位置, 並將y的記憶體位置釋放
		  
	}

	delete y;                               // 將y的記憶體位置釋放
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
