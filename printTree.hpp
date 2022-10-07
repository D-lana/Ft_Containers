#ifndef printTree_HPP
#define printTree_HPP

#include <iostream>
#include "redBlackTree.hpp"
#include <stdio.h>
#include <stdlib.h>
#include <fstream>
#include <cmath>
#include <iomanip> //setw


template <typename T>
struct List
{
	T		*data;
	int		deep;
	Color	*color;
	int 	empty;
};

template <typename T>
class printTree {
	
	private:
		
		int count;
		int column;
		Tree<T> &tree;
		int deep;
		std::string *treeString;
		std::string *treeColor;
		List<T> *list;
		int start;
		int between;
		int first;
		T *zero;
		Color *black;
	
	public:

		std::ofstream ofs;
		std::ifstream inf;

	printTree(const printTree &copy) : tree(copy.tree) {
		this->count = copy.count;
		this->deep = copy.deep;
	}

	printTree(Tree<T> &tree_, int count) : tree(tree_) {
		start = 0;
		between = (start * 2) + 1;
		first = 0;
		deep = 0;
		column = 0;
		zero = new T;
		black = new Color;
		*black = BLACK;
		countDeep(&tree, 0, 1);
		this->count = count;
		treeString = new std::string[deep];
		treeColor = new std::string[deep];
		list = new List<T>[40];
		recordList();
	}

	~printTree() {
		
	}

void countDeep(Tree<T> *tree, int i, int deep) {
	if (deep > this->deep) {
		this->deep = deep;
	}
	deep++;
	i = 0;
	if(tree->right) {
		countDeep(tree->right, i, deep);
	}
	if(tree->left) {
		countDeep(tree->left, i, deep);
	}
}

int getDeep() {
	return (this->deep);
}

void recordList() {
	recordListRec(&tree, 0);
}

void recordListRec(Tree<T> *tree, const int level = 0) {

	if (tree->left)
		recordListRec(tree->left, level + 1);
	// else {
	// 	list[column].data = zero;
	// 	list[column].color = black;
	// 	list[column].deep = level + 1;
	// 	list[column].empty = 1;
	// 	std::cout << *list[column].data << " deep " << level << " column " << column << std::endl;
	// 	column++;
	// }
	list[column].data = &tree->data;
	list[column].color = &tree->color;
	list[column].deep = level;
	list[column].empty = 0;
	std::cout << *list[column].data << " deep " << level << " column " << column << std::endl;
	column++;
	if (tree->right)
		recordListRec(tree->right, level + 1);
	// else {
	// 	list[column].data = zero;
	// 	list[column].color = black;
	// 	list[column].deep = level + 1;
	// 	list[column].empty = 1;
	// 	std::cout << *list[column].data << " deep " << level << " column " << column << std::endl;
	// 	column++;
	// }
}

void putColored(int j, int i, int start, int between, int first) {
	if (first == 0) {
			for (int i = 0; i < start; ++i) {
				std::cout << " ";
			}
	}
	else {
		for (int i = 0; i < between; ++i) {
			std::cout << " ";
		}
	}
	if (*list[j].color == RED) {
		std::cout << "\x1b[1;31m " << j << " \x1b[0m";
		std::cout << "\x1b[1;31m " << *list[j].data << " \x1b[0m";
	}
	else {
		std::cout << " " << j << " ";
		std::cout << " " << *list[j].data << " ";
	}
}

void printBrunch(int i) {
	for (int j = 0; j < (start * 2) + between * i + 3; ++j) {
			if (j == start - 1 || (j == start - 1 + between + 3 && i != 0)) {
				std::cout << "/";
			}
			else if (j == start + 3 || (j == start + 3 + 3 + between && i != 0)) {
				std::cout << "\\";
			}
			else {
				std::cout << " ";
			}
		}
		std::cout << std::endl;
}


void printList() {
	std::string branch;
	for (int i = 0; i < deep; i++) {
		//std::cout << start << std::endl;
		start = (start + 1) * 2;
	}
	//std::cout << start << std::endl;
	for (int i = 0; i < deep; ++i) {
		for (int j = 0; j < column; ++j) {
			if (list[j].deep == i) {
				putColored(j, i, start, between, first);
				//std::cout << j;
				first = 1;
			}
			// else {
			// 	std::cout << " ";
			// }
		}
		std::cout << std::endl;
		//printBrunch(i);
		start = start / 2 - 1;
		between = (start * 2) + 1;
		first = 0;
	}
}

};

#endif
