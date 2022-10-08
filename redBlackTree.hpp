#ifndef REDBLACKTREE_HPP
#define REDBLACKTREE_HPP

#define RED_ "\x1b[1;31m"
#define BLACK_ "\x1b[0m"

#include <iostream>

enum Color {
	BLACK,
	RED
};

template <typename T>
struct Tree
{
	T				data;
	struct Tree		*left;
	struct Tree		*right;
	struct Tree		*parent;
	Color			color;
};

template <typename T>
class redBlackTree {
	private:
	
	size_t count;
	Tree<T> *tree;
	Tree<T> *null_ptr;

	public:

	//typedef typename Tree::data	pointer;

	redBlackTree() {
		tree = NULL;
		null_ptr = NULL;
		this->count = 0;
	}

	void deleteTree(Tree<T> *tree, const int level = 0)
	{
		if (tree->left) {
			deleteTree(tree->left, level + 1);
		}
		delete tree;
		if (tree->right) {
			deleteTree(tree->right, level + 1);
		}
	}

	~redBlackTree() {
		if (tree != NULL) {
			deleteTree(tree, 0);
		}
	}

	Tree<T> *getTree() {
		return tree;
	}

	size_t getSize() {
		return count;
	}

	void rightRotateSmall(Tree<T> *parent, Tree<T> *child) {
		std::cout << "rightRotateSmall: " << parent->data << std::endl;
		Tree<T> *grandParent = parent->parent;
		parent->parent = child;
		child->parent = grandParent;
		child->right = parent;
		parent->left = NULL;
		grandParent->right = child;
	}

	void leftRotateSmall(Tree<T> *parent, Tree<T> *child) {
		std::cout << "leftRotateSmall: " << parent->data << std::endl;
		Tree<T> *grandParent = parent->parent;
		parent->parent = child;
		child->parent = grandParent;
		child->left = parent;
		parent->right = NULL;
		grandParent->left = child;
	}

	void redUncle(Tree<T> *tmp) {
		if (tmp->parent != NULL && ((tmp->parent->right == tmp && tmp->parent->left && tmp->parent->left->color == RED) ||
			(tmp->parent->left == tmp && tmp->parent->right && tmp->parent->right->color == RED))) {
				tmp->parent->right->color = BLACK;
				tmp->parent->left->color = BLACK;
				tmp->parent->color = RED;
				std::cout << "\x1b[1;31m redUncle \x1b[0m" << std::endl;
			if (tmp->parent->parent != NULL) {
				redUncle(tmp->parent->parent);
			}
			else if (tmp->parent->parent == NULL) {
				tmp->parent->color = BLACK;
			}
		}
	}

	void blackUncle(Tree<T> *tmp, Tree<T> *child) {
		if (tmp->parent != NULL && (tmp->parent->right == tmp && (tmp->parent->left == NULL ||
		(tmp->parent->left && tmp->parent->left->color == BLACK)))) {
			std::cout << "LEFT: " << tmp->data << " SUN: " << child->data << std::endl;
			if (tmp->left == child) {
				rightRotateSmall(tmp, child);
				leftRotate(child);
			}
			else {
				leftRotate(tmp);
			}
		}
		else if (tmp->parent != NULL && (tmp->parent->left == tmp && (tmp->parent->right == NULL ||
		(tmp->parent->right && tmp->parent->right->color == BLACK)))) {
			std::cout << "RIGHT: " << tmp->data << " SUN: " << child->data << std::endl;
			if (tmp->right == child) {
				leftRotateSmall(tmp, child);
				rightRotate(child);
			}
			else {
				rightRotate(tmp);
			}
		}
	}

	void findPlaceRecursive(const T &data, Tree<T> *tmp, Tree<T> *newTree) {
		if (data > tmp->data) {
			if (tmp->right != NULL) {
				findPlaceRecursive(data, tmp->right, newTree);
			}
			else {
				tmp->right = newTree;
				newTree->parent = tmp;
				redUncle(tmp);
				if (tmp->parent != NULL && tmp->color == RED) {
					blackUncle(tmp, newTree);
				}
				return ;
			}
		}
		else if (data < tmp->data) {
			if (tmp->left != NULL) {
				findPlaceRecursive(data, tmp->left, newTree);
			}
			else {
				tmp->left = newTree;
				newTree->parent = tmp;
				redUncle(tmp);
				if (tmp->parent != NULL && tmp->color == RED) {
					blackUncle(tmp, newTree);
				}
				return ;
			}
		}
		else {
			//std::cout << "delete: " << data << std::endl;
			delete newTree;
			return ;
		}
	}

	Tree<T> *newNode(const T &data) {
		Tree<T> *newTree = new Tree<T>;
		newTree->data = data;
		newTree->color = RED;
		newTree->left = NULL;
		newTree->right = NULL;
		newTree->parent = NULL;
		this->count++;
		return newTree;
	}

	void leftRotate(Tree<T> *rotate) {
		std::cout << "leftRotate: " << rotate->data << std::endl;
		Tree<T> *tmp = rotate->parent;
		if (rotate->parent->parent != NULL) {
			rotate->parent = rotate->parent->parent; //1
			tmp->parent->right = rotate; //2
			tmp->parent = rotate; //3
			if (rotate->left) {
				tmp->right = rotate->left; // 4
				rotate->left->parent = tmp->right;
				rotate->left = tmp;
			}
			else {
				tmp->right = NULL;
				rotate->left = tmp;
			}
		}
		else {
			tmp->parent = rotate;
			rotate->parent = NULL;
			if (rotate->left) {
				tmp->right = rotate->left;
				rotate->left->parent = tmp->right;
				rotate->left = tmp->right;
			}
			else {
				tmp->right = NULL;
				rotate->left = tmp;
			}
			this->tree = rotate;
			this->tree->color = BLACK;
		}
		tmp->color = RED;
		rotate->color = BLACK;
	}

	void rightRotate(Tree<T> *rotate) {
		std::cout << "rightRotate: " << rotate->data << std::endl;
		Tree<T> *tmp = rotate->parent;
		if (rotate->parent->parent != NULL) {
			rotate->parent = rotate->parent->parent;
			tmp->parent = rotate;
			rotate->parent->left = rotate;
			if (rotate->right) {
				tmp->left = rotate->right;
				rotate->right->parent = tmp->left;
				rotate->right = tmp->left;
			}
			else {
				tmp->left = NULL;
				rotate->right = tmp;
			}
		}
		else {
			tmp->parent = rotate;
			rotate->parent = NULL;
			if (rotate->right) {
				tmp->left = rotate->right;
				rotate->right->parent = tmp->left;
				rotate->right = tmp->left;
			}
			else {
				tmp->left = NULL;
				rotate->right = tmp;
			}
			this->tree = rotate;
			this->tree->color = BLACK;
		}
		tmp->color = RED;
		rotate->color = BLACK;
	}


	void insert(const T &data) {
		if (tree == NULL) {
			tree = newNode(data);
			tree->color = BLACK;
		}
		else {
			Tree<T> *newTree = newNode(data);
			Tree<T> *tmp = tree;
			findPlaceRecursive(data, tmp, newTree);
			//findPlace(data, tmp, newTree);
		}
	}

	void simpleDelete(Tree<T> *tmp) {
		if (tmp->parent->left == tmp) {
				tmp->parent->left = NULL;
		}
		else if (tmp->parent->right == tmp) {
			tmp->parent->right = NULL;
		}
		else {
			std::cout << "ERROR!" << std::endl;
			exit(1);
		}
		std::cout << "delete: " << tmp->data << std::endl;
		delete tmp;
	}

	void red2(Tree<T> *swap) { //К2 — красный узел с двумя детьми
		Tree<T> *tmp = nextNode(del);
		std::cout << "del k2: " << swap->data << std::endl;
		std::cout << "nextNode: " << tmp->data << std::endl;
		swap->data = tmp->data;
		else if (tmp->left != NULL && tmp->right == NULL) {
			std::cout << "tmp->left != NULL" << std::endl;
		}
		else if (tmp->left == NULL && tmp->right != NULL) {
			std::cout << "tmp->right != NULL" << std::endl;
		}
	}

	void leftMoveAndDelete(Tree<T> *tmp) { //tmp->left != NULL

	}

	void allMoveAndDelete(Tree<T> *tmp) {

	}

	void findToDeleteRecursive(Tree<T> *tmp, const T &del) {
		if (del < tmp->data) {
			if (tmp->left) {
				tmp = tmp->left;
				findToDeleteRecursive(tmp, del);
			}
		}
		else if (del > tmp->data) {
			if (tmp->right) {
				tmp = tmp->right;
				findToDeleteRecursive(tmp, del);
			}
		}
		else {
			if (tmp->left == NULL && tmp->right == NULL) {
				simpleDelete(tmp);
			}
			else if (tmp->color == RED && tmp->right != NULL && tmp->left != NULL) { //К2 — красный узел с двумя детьми
				red2(tmp);
			}
			else if (tmp->color == BLACK && tmp->right != NULL && tmp->left != NULL) { //Ч2 — чёрный узел с двумя детьми
				bkack2(tmp);
			}
			else if (tmp->left != NULL && tmp->right != NULL) {
				allMoveAndDelete(tmp);
			}
			//delete tree;
		}
	}




	void remove(const T &del) {
		Tree<T> *tmp = tree;
		if (tmp == NULL) {
			return ;
		}
		findToDeleteRecursive(tmp, del);
	}

	Tree<T> &beginTree() {
		Tree<T> *tmp = tree;
		if (tree == NULL) {
			return (*null_ptr);
		}
		else {
			while (tmp->left != NULL) {
				tmp = tmp->left;
			}
		}
		return (*tmp);
	}

	Tree<T> &endTree() {
		Tree<T> *tmp = tree;
		if (tree == NULL) {
			return (*null_ptr);
		}
		else {
			while (tmp->right != NULL) {
				tmp = tmp->right;
			}
		}
		return (*tmp);
	}

	Tree<T> &nextNode(Tree<T> &current) {
		Tree<T> *tmp = &current;
		if (tmp == NULL || (tmp->right == NULL && tmp->parent == NULL)) {
			return (*tmp);//return (*null_ptr); //!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
		}
		else if (tmp->right == NULL) {
			while (tmp->parent != NULL && tmp->parent->right == tmp) {
				tmp = tmp->parent;
			}
			if (tmp->parent == NULL) {
				return (*tmp);//return (*null_ptr); //!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
			}
			else if (tmp->parent->left == tmp) {
				tmp = tmp->parent;
			}
		}
		else {
			tmp = tmp->right;
			while (tmp->left != NULL) {
				tmp = tmp->left;
			}
		}
		return (*tmp);
	}

		Tree<T> &prevNode(Tree<T> &current) {
		Tree<T> *tmp = &current;
		if (tmp == NULL || (tmp->left == NULL && tmp->parent == NULL)) {
			return (*tmp);//return (*null_ptr); //!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
		}
		else if (tmp->left == NULL) {
			while (tmp->parent != NULL && tmp->parent->left == tmp) {
				tmp = tmp->parent;
			}
			if (tmp->parent == NULL) {
				return (*tmp);//return (*null_ptr); //!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
			}
			else if (tmp->parent->right == tmp) {
				tmp = tmp->parent;
			}
		}
		else {
			tmp = tmp->left;
			while (tmp->right != NULL) {
				tmp = tmp->right;
			}
		}
		return (*tmp);
	}



};

#endif
