#include "BST_list.h"

int main()
{
	BST_lis<int> tree;

	tree.Insert(55);
	tree.Insert(44);
	tree.Insert(11);
	tree.Insert(15);
	tree.Insert(45);
	tree.Insert(99);
	tree.Insert(43);
	tree.Insert(97);
	tree.Insert(98);
	cout << "found min:" << tree.find_Low() << " found min itr:" << tree.find_Low_itr() << "\n";
	cout << "found max:" << tree.find_Max() << " found max itr:" << tree.find_Max_itr() << "\n";
	tree.show();
	cout << "\nsearch:";
	tree.search(13);
	cout << "\npreorder\n";
	tree.preorder();
	cout << "\npostorder\n";
	tree.postorder();
	cout << "\ninorder\n";
	tree.inorder();
	cout << "\ndelete el: 11\n"; tree.delete_knot(11);
	cout << "succ::" << tree.succBST(44);
	cout << "\npred::" << tree.predBST(45);
	//tree.show();
	cout << "\n";
	tree.tree_show();

	return 0;
}