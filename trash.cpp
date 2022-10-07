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
	T				*data;
	struct List		*next;
	struct List		*parent;
	Color			*color;
};

template <typename T>
class printTree {
	
	private:
		
		int count;
		Tree<T> &tree;
		int deep;
		std::string *treeString;
		std::string *treeColor;
		List<T> **list;
	
	public:

		std::ofstream ofs;
		std::ifstream inf;

	printTree(const printTree &copy) : tree(copy.tree) {
		this->count = copy.count;
		this->deep = copy.deep;
	}

	printTree(Tree<T> &tree_, int count) : tree(tree_) {
		deep = 0;
		countDeep(&tree, 0, 1);
		this->count = count;
		treeString = new std::string[deep];
		treeColor = new std::string[deep];
		list = new List<T>* [deep];
		recordList();
	}

	~printTree() {
		
	}

	void print() {
		ofs.open("test.html", std::ofstream::out | std::ofstream::trunc);
		//ofs("test.txt", std::ofstream::out);
		std::string str;
		std::string buf;
		std::string final;
		str.assign(count, ' ');
		if (tree.color == RED) {
			ofs << "deep" << deep << str << "<b style=\"color:red\">" << tree.data << "</b>";
			this->treeColor[deep].append(std::to_string(tree.color));
			this->treeString[deep].append(std::to_string(tree.data));
			List<T> *newList = new List<T>;
			newList->next = NULL;
			newList->data = &tree.data;
			newList->color = &tree.color;
			list[deep] = newList;
			//node[deep] = &tree.data;
		}
		else {
			ofs  << "deep" << deep << str << "<b style=\"color:black\">" << tree.data << "</b>";
			this->treeColor[deep].append(std::to_string(tree.color));
			this->treeString[deep].append(std::to_string(tree.data));
			List<T> *newList = new List<T>;
			newList->next = NULL;
			newList->data = &tree.data;
			newList->color = &tree.color;
			list[deep] = newList;
			//node[deep] = &tree.data;
		}
		//ofs << str << tree.data << std::endl;
		deep++;
		printChild_1(&tree, 0, deep);
		// for(int i = 0 ; !treeString[i].empty(); ++i) {
		// 	std::cout << treeString[i] << std::endl;
		// }
		//ofs << str << deep << std::endl;
		ofs.close();
		std::cout << std::endl;
		for (int i = 0; 5 > i; ++i) {
			std::cout << str.assign(pow(2, 5 - i) / 2, ' ');
			while(list[i] != NULL) {
				if (*list[i]->color == BLACK) {
					//std::cout << treeString[i] << std::endl;
					std::cout << *list[i]->data;
				}
				else {
					//std::cout << "\x1b[1;31m" << treeString[i] << "\x1b[0m" << std::endl;
					std::cout << "\x1b[1;31m" << *list[i]->data << "\x1b[0m";
				}
				std::cout << str.assign(pow(2, 5 - i), ' ');
				list[i] = list[i]->next;
				//std::cout << treeColor[i][j] << std::endl;
			}

			std::cout << std::endl;
			//std::cout << "i = " << i << std::endl;
			//std::cout << treeString[i] << std::endl;
		}

		//inf.open("test2.html", std::ifstream::in);
		// size_t first;
		// size_t len;
		//int tab = pow(2, deep);
		// for (int i = 0; deep - 1 > i; ++i) {
		// 	ofs << str.assign(tab, ' ') << treeString[deep];
		// }
		//ofs.close();
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
		countDeep(&tree, 0, 1);
		return (this->deep);
	}

	void printChild(Tree<T> *tree, int i, int deep) {
		std::string str;
		std::string buffer;
		str.assign(i, ' ');
		if (deep > this->deep) {
			this->deep = deep;
		}
		//std::cout << "Deep: " << deep << std::endl;
		if(tree->left) {
			if (tree->left->color == RED) {
				ofs << "deep" << deep << str << "<b style=\"color:red\">" << tree->left->data << "</b>";
				this->treeColor[deep].append(std::to_string(tree->left->color));
				this->treeString[deep].append(std::to_string(tree->left->data));
				List<T> *newList = new List<T>;
				newList->data = &tree->left->data;
				newList->color = &tree->left->color;
				if (list[deep] != NULL) {
					List<T> *tmp = list[deep]->next;
					list[deep]->next = newList;
					newList->next = tmp;
				}
				else {
					list[deep] = newList;
					list[deep]->next = NULL;
				}
				//node[deep].[i] = &tree->left->data;
				//this->treeString[deep].append("<b style=\"color:red\">" + str.assign(pow(2, deep), ' ') + std::to_string(tree->left->data) + "</b>");
			}
			else {
				ofs  << "deep" << deep << str << "<b style=\"color:black\">" << tree->left->data << "</b>";
				this->treeColor[deep].append(std::to_string(tree->left->color));
				this->treeString[deep].append(std::to_string(tree->left->data));
				List<T> *newList = new List<T>;
				newList->next = NULL;
				newList->data = &tree->left->data;
				newList->color = &tree->left->color;
				if (list[deep] != NULL) {
					List<T> *tmp = list[deep]->next;
					list[deep]->next = newList;
					newList->next = tmp;
				}
				else {
					list[deep] = newList;
					list[deep]->next = NULL;
				}
				//node[deep] = &tree->left->data;
				//this->treeString[deep].append("<b style=\"color:black\">" + str.assign(pow(2, deep), ' ') + std::to_string(tree->left->data) + "</b>");
			}
		}
		if (tree->right) {
			if (tree->right->color == RED) {
				ofs  << "deep" << deep << str << "<b style=\"color:red\">" << tree->right->data << "</b>";
				this->treeColor[deep].append(std::to_string(tree->right->color));
				this->treeString[deep].append(std::to_string(tree->right->data));
				List<T> *newList = new List<T>;
				newList->next = NULL;
				newList->data = &tree->right->data;
				newList->color = &tree->right->color;
				if (list[deep] != NULL) {
					List<T> *tmp = list[deep]->next;
					list[deep]->next = newList;
					newList->next = tmp;
				}
				else {
					list[deep] = newList;
					list[deep]->next = NULL;
				}
				//node[deep] = &tree->right->data;
				//this->treeString[deep].append("<b style=\"color:red\">" + str.assign(pow(2, deep), ' ') + std::to_string(tree->right->data) + "</b>");
			}
			else {
				ofs  << "deep" << deep << str << "<b style=\"color:black\">" << tree->right->data << "</b>";
				this->treeColor[deep].append(std::to_string(tree->right->color));
				this->treeString[deep].append(std::to_string(tree->right->data));
				List<T> *newList = new List<T>;
				newList->next = NULL;
				newList->data = &tree->right->data;
				newList->color = &tree->right->color;
				if (list[deep] != NULL) {
					List<T> *tmp = list[deep]->next;
					list[deep]->next = newList;
					newList->next = tmp;
				}
				else {
					list[deep] = newList;
					list[deep]->next = NULL;
				}
				//node[deep] = &tree->right->data;
				//this->treeString[deep].append("<b style=\"color:black\">" + str.assign(pow(2, deep), ' ') + std::to_string(tree->right->data) + "</b>");

			}
		}
		// if(tree->parent) {
		// 	if (tree->parent->right == tree) {
		// 		std::cout << std::endl;
		// 	}
		// }
		deep++;
		i = 0;
		if(tree->right) {
			printChild(tree->right, i, deep);
		}
		if(tree->left) {
			printChild(tree->left, i, deep);
	}
	}

	void printChild_1(Tree<T> *tree, int i, int deep) {
		if(tree->left) {
			printChild_1(tree->left, i, deep + 1);
		}
		List<T> *newList = new List<T>;
		newList->data = &tree->right->data;
		newList->color = &tree->right->color;
		if (list[deep] != NULL) {
			List<T> *tmp = list[deep]->next;
			list[deep]->next = newList;
			newList->next = tmp;
		}
		else {
			list[deep] = newList;
			list[deep]->next = NULL;
			newList->next = NULL;
		}
		if(tree->right) {
			printChild_1(tree->right, i, deep + 1);
		}
	}


void recordList() {
	recordListRec(&tree, 0);
}

void recordListRec(Tree<T> *tree, const int level = 0) {
	if (tree->left)
		recordListRec(tree->left, level + 1);
	List<T> *newList = new List<T>;
	newList->data = &tree->data;
	newList->color = &tree->color;
	if (list[level] != NULL) {
		List<T> *tmp = list[level]->next;
		list[level]->next = newList;
		newList->next = tmp;
		//tree->parent;
		//std::cout << level << "  " << *list[level]->next->data << std::endl;
	}
	else {
		list[level] = newList;
		list[level]->next = NULL;
		newList->next = NULL;
		//std::cout  << level  << "  n  " << *list[level]->data << std::endl;
	}
	if (tree->right)
		recordListRec(tree->right, level + 1);
}

void printList() {
	List<T> **listTmp = this->list;
	for (int i = 0; i < deep; ++i) {
		//std::cout << std::setw(deep - i * 6) << std::setfill(' ');
		for (int j = 0; list[i] != NULL; ++j) {
			//std::cout << "IN" << i << std::endl;
			if (*list[i]->color == RED) {
				std::cout << std::setw((deep - i) * 3) << std::setfill(' ') << "\x1b[1;31m" << *list[i]->data << " \x1b[0m";
			}
			else {
				std::cout << std::setw((deep - i) * 3) << std::setfill(' ') << *list[i]->data << " ";
			}
			list[i] = list[i]->next;
		}
		std::cout << std::endl;
	}
}

};

#endif
