#pragma once
#include <iostream>
#include <iomanip>

using namespace std;

template <typename T>
struct knot
{
	T date;
	knot<T>* left;
	knot<T>* right;
	knot()
	{
		left = right = nullptr;
	}
};

template <typename T>
struct BST_lis
{
private:
	int count;
	knot<T>* root;
	knot<T>* add_knot(T val);
	knot<T>* Insert_hide(knot<T>*& root, T val);
	knot<T>* find_Max_hide(knot<T>* temp);
	knot<T>* find_Max_ineractive_hide(knot<T>* temp);
	knot<T>* find_Low_hide(knot<T>* temp);
	knot<T>* find_Low_ineractive_hide(knot<T>* temp);
	knot<T>* succBST_hide(T val);
	knot<T>* predBST_hide(knot<T>* root, knot<T>* prec, T val);
	bool isEmpty(knot<T>* root);
	bool search_hide(knot<T>* root, T val);
	bool search_hide_itr(knot<T>* root, T val);
	knot<T>* search_hide_itr_value(knot<T>* root, T val);
	void print_tree(knot<T>* root);
	void tree_show_hide(knot<T>* root, int ind);
	void preorder_hide(knot<T>* root);
	void postorder_hide(knot<T>* root);
	void inorder_hide(knot<T>* root);
	//void delete_knot_hide(T val);
	knot<T>* clear_hide(knot<T>* root);
	knot<T>* delete_knot_hide(knot<T>*& root, T val);


public:
	BST_lis();
	~BST_lis();

	void Insert(T val);
	T find_Max();
	T find_Max_itr();

	T find_Low();
	T find_Low_itr();

	T succBST(T val);
	T predBST(T val);

	void show();
	void tree_show();
	void search(T val);
	void preorder();
	void postorder();
	void inorder();
	void clear();
	void delete_knot(T val);


};

template<typename T>
inline BST_lis<T>::BST_lis()
{
	count = 0;
	root = nullptr;
}

template<typename T>
inline BST_lis<T>::~BST_lis()
{
	clear_hide(root);
}

template<typename T>
inline knot<T>* BST_lis<T>::add_knot(T val)
{
	knot<T>* knotting = new knot<T>;
	knotting->date = val;
	knotting->right = knotting->left = nullptr;
	count++;
	return knotting;
}

template<typename T>
inline knot<T>* BST_lis<T>::Insert_hide(knot<T>*& root, T val)
{
	if (root == NULL)
		root = add_knot(val);
	else if (root->date > val)
		root->left = Insert_hide(root->left, val);
	else if (root->date <= val)
		root->right = Insert_hide(root->right, val);
	return root;
}

template<typename T>
inline knot<T>* BST_lis<T>::find_Max_hide(knot<T>* temp)
{
	if (temp == NULL) return temp;
	if (temp->right == NULL) return temp;
	else return find_Max_hide(temp->right);
}

template<typename T>
inline knot<T>* BST_lis<T>::find_Max_ineractive_hide(knot<T>* temp)
{
	while (temp->right)
		temp = temp->right;
	return temp;
}

template<typename T>
inline knot<T>* BST_lis<T>::find_Low_hide(knot<T>* temp)
{
	if (temp == NULL) return temp;
	if (temp->left == nullptr) return temp;
	else return find_Low_hide(temp->left);
}

template<typename T>
inline knot<T>* BST_lis<T>::find_Low_ineractive_hide(knot<T>* temp)
{
	while (temp->left != 0)
		temp = temp->left;
	return temp;

}

template<typename T>
inline knot<T>* BST_lis<T>::succBST_hide(T val)
{
	knot<T>* knotting = search_hide_itr_value(root, val);
	if (knotting->left != NULL) return knotting->left;
	else if (knotting->right != NULL) return knotting->right;
	else return knotting;

}

template<typename T>
inline knot<T>* BST_lis<T>::predBST_hide(knot<T>* root, knot<T>* prec, T val)
{
	//if (isEmpty(root)) return prec;
	//if (root->date == val)
	//{
	//	return root;
	//	/*if (root->left != nullptr)
	//	{
	//		return find_Max_ineractive_hide(root->left);
	//	}*/
	//}
	//else if (root->date > val)
	//{
	//	return predBST_hide(root->left, prec, val);
	//}
	//else
	//{
	//	prec = root;
	//	return predBST_hide(root->right, prec, val);
	//}
	//return prec;

	////knot<T>* knotting = search_hide_itr_value(root, val);

	// base case
	if (root == nullptr) {
		return prec;
	}

	// if a node with the desired value is found, the predecessor is the maximum
	// value node in its left subtree (if any)
	if (root->date == val)
	{
		if (root->left != nullptr) {
			return find_Max_ineractive_hide(root->left);
		}
	}

	// if the given key is less than the root node, recur for the left subtree
	else if (val < root->date) {
		return predBST_hide(root->left, prec, val);
	}

	// if the given key is more than the root node, recur for the right subtree
	else {
		// update predecessor to the current node before recursing
		// in the right subtree
		prec = root;
		return predBST_hide(root->right, prec, val);
	}
	return prec;

}

template<typename T>
inline void BST_lis<T>::print_tree(knot<T>* root)
{
	if (root != NULL)
	{
		print_tree(root->left);
		cout << root->date << "->";
		print_tree(root->right);
	}
}

template<typename T>
inline void BST_lis<T>::tree_show_hide(knot<T>* root, int ind)
{
	if (root)
	{
		if (root->right)
		{
			tree_show_hide(root->right, ind + 3);
		}
		if (ind)
			cout << setw(ind) << ' ';
		if (root->right)
			cout << " /\n" << setw(ind) << ' ';
		cout << root->date << "\n";
		if (root->left)
		{
			cout << setw(ind) << ' ' << " \\\n";
			tree_show_hide(root->left, ind + 4);
		}
	}
}

template<typename T>
inline void BST_lis<T>::preorder_hide(knot<T>* root)
{
	if (root == NULL) return;
	cout << root->date << " ";
	preorder_hide(root->left);
	preorder_hide(root->right);
}

template<typename T>
inline void BST_lis<T>::postorder_hide(knot<T>* root)
{
	if (root == NULL) return;
	postorder_hide(root->left);
	postorder_hide(root->right);
	cout << root->date << " ";
}

template<typename T>
inline void BST_lis<T>::inorder_hide(knot<T>* root)
{
	if (root == NULL) return;
	inorder_hide(root->left);
	cout << root->date << " ";
	inorder_hide(root->right);
}

//template<typename T>
//inline void BST_lis<T>::delete_knot_hide(T val)
//{
//	knot<T>* del_knot = search_hide(root, val);
//	if (del_knot->date != val)
//		return;
//}

template<typename T>
inline knot<T>* BST_lis<T>::clear_hide(knot<T>* root)
{
	if (root)
		return nullptr;
	{
		clear_hide(root->left);
		clear_hide(root->right);
		return nullptr;
	}
}

template<typename T>
inline knot<T>* BST_lis<T>::delete_knot_hide(knot<T>*& root, T val)
{
	knot<T>* knotting = new knot<T>;
	if (knotting == NULL) return NULL;
	else if (root->date > val)
		root->left = delete_knot_hide(root->left, val);
	else if (root->date < val)
		root->right = delete_knot_hide(root->right, val);
	else if (root->left && root->right)
	{
		knotting = find_Low_hide(root->right);
		root->date = knotting->date;
		root->right = delete_knot_hide(root->right, root->date);
	}
	else
	{
		knotting = root;
		if (root->left)
			root = root->right;
		else if (root->right)
			root = root->left;
		delete knotting;
	}
	return root;

}


template<typename T>
inline bool BST_lis<T>::isEmpty(knot<T>* root)
{
	return root == NULL;
}

template<typename T>
inline bool BST_lis<T>::search_hide(knot<T>* root, T val)
{
	if (isEmpty(root))
		return false;
	if (val == root->date)
		return true;
	else if (val < root->date)
		search_hide(root->left, val);
	else if (val > root->date)
		search_hide(root->right, val);
	else return false;
}

template<typename T>
inline bool BST_lis<T>::search_hide_itr(knot<T>* root, T val)
{
	if (isEmpty(root))
		return false;
	while (root != 0 && val != root->date)
		if (root->date > val) root = root->left;
		else root = root->right;
	if (root == nullptr) return false;
	else return true;
}

template<typename T>
inline knot<T>* BST_lis<T>::search_hide_itr_value(knot<T>* root, T val)
{
	while (root != 0 && val != root->date)
		if (root->date > val) root = root->left;
		else root = root->right;
	return root;
}





template<typename T>
inline T BST_lis<T>::find_Max()
{
	return find_Max_hide(root)->date;
}

template<typename T>
inline T BST_lis<T>::find_Max_itr()
{
	return find_Max_ineractive_hide(root)->date;
}

template<typename T>
inline T BST_lis<T>::find_Low()
{
	return find_Low_hide(root)->date;
}

template<typename T>
inline T BST_lis<T>::find_Low_itr()
{
	return find_Low_ineractive_hide(root)->date;
}

template<typename T>
inline T BST_lis<T>::succBST(T val)
{
	return succBST_hide(val)->date;
}

template<typename T>
inline T BST_lis<T>::predBST(T val)
{
	knot<T>* prec = predBST_hide(root, nullptr, val);
	return prec->date;
}

template<typename T>
inline void BST_lis<T>::Insert(T val)
{
	Insert_hide(root, val);
}

template<typename T>
inline void BST_lis<T>::show()
{
	print_tree(root);
	cout << "\n";
}

template<typename T>
inline void BST_lis<T>::tree_show()
{
	int ind = 2;
	tree_show_hide(root, ind);
}

template<typename T>
inline void BST_lis<T>::search(T val)
{
	//if (search_hide(root, val)) cout << "yes\n";
	//else cout << "no\n";

	if (search_hide_itr(root, val)) cout << "yes\n";
	else cout << "no\n";
}

template<typename T>
inline void BST_lis<T>::preorder()
{
	preorder_hide(root);
}

template<typename T>
inline void BST_lis<T>::postorder()
{
	postorder_hide(root);
}

template<typename T>
inline void BST_lis<T>::inorder()
{
	inorder_hide(root);
}

template<typename T>
inline void BST_lis<T>::clear()
{
	clear_hide(root);
}

template<typename T>
inline void BST_lis<T>::delete_knot(T val)
{
	delete_knot_hide(root, val);
	//delete_knot_hide(val);
}
