#include "pch.h"
#include "BST.h"
#include <iostream>
#include <algorithm>
struct Node {
	int variable;
	Node *leftNode;
	Node *rightNode;
};

void BST::Add(Node *&node, int i) {
	if (node == nullptr) {
		node = new Node;
		node->variable = i;
		node->rightNode = nullptr;
		node->leftNode = nullptr;
		return;
	}
	if (node->variable >= i) {
		Add(node->leftNode, i);
		node = balance(node);
	}
	else {
		Add(node->rightNode, i);
		node = balance(node);
	}
}

bool BST::Find(Node *node, int i) {
	if (node == nullptr) {
		return false;
	}
	if (node->variable == i) {
		std::cout << "Elem - " << node->variable << "  Adress - " << &node << std::endl;
		return true;
	}
	else {
		if (node->variable < i) {
			Find(node->rightNode, i);
		}
		else {
			Find(node->leftNode, i);
		}
	}

}

void BST::ShowDirect(Node *node) {
	if (node == nullptr) {
		return;
	}
	std::cout << " " << node->variable;
	ShowDirect(node->leftNode);
	ShowDirect(node->rightNode);
}

void BST::ShowDirect(Node *node, int find, int &counter) {
	if (node == nullptr) {
		return;
	}
	if (node != nullptr) {
		++counter;
	}
	if (node->variable == find) {
		std::cout << " " << node->variable << " First enter - " << counter << std::endl;
		return;
	}
	ShowDirect(node->leftNode, find, counter);
	ShowDirect(node->rightNode, find, counter);
}

void BST::ShowReverse(Node *node) {
	if (node == nullptr) {
		return;
	}
	ShowReverse(node->leftNode);
	ShowReverse(node->rightNode);
	std::cout << " " << node->variable;
}

void BST::ShowReverse(Node *node, int find, int &counter) {
	if (node == nullptr) {
		return;
	}
	ShowReverse(node->leftNode, find, counter);
	ShowReverse(node->rightNode, find, counter);
	if (node != nullptr) {
		++counter;
	}
	if (node->variable == find) {
		std::cout << " " << node->variable << " First enter - " << counter << std::endl;
		return;
	}
}

void BST::HeightFromRootReverse(Node *node, int elem, int counter) {
	if (node == nullptr) {
		return;
	}
	if (node != nullptr) {
		++counter;
	}
	HeightFromRootReverse(node->leftNode, elem, counter);
	HeightFromRootReverse(node->rightNode, elem, counter);
	if (node->variable == elem) {
		std::cout << "Height = " << counter - 1 << std::endl;
		return;
	}
}

void BST::HeightFromRootDirect(Node *node, int elem, int counter) {
	if (node == nullptr) {
		return;
	}
	if (node != nullptr) {
		++counter;
	}
	if (node->variable == elem) {
		std::cout << "Height = " << counter - 1 << std::endl;
		return;
	}
	HeightFromRootDirect(node->leftNode, elem, counter);
	HeightFromRootDirect(node->rightNode, elem, counter);
}

Node* BST::Delete(Node *&node, int elem) {
	Node *t;
	if (node == nullptr) {
		return nullptr;
	}
	if (elem == node->variable) {
		if (node->leftNode == nullptr) {
			t = node->rightNode;
			delete node;
			return t;
		}
		t = node->leftNode;
		while (t->rightNode) {
			t = t->rightNode;
		}
		t->rightNode = node->rightNode;
		return node->leftNode;
	}
	if (elem < node->variable) {
		node->leftNode = Delete(node->leftNode, elem);
		node = balance(node);
	}
	else {
		node->rightNode = Delete(node->rightNode, elem);
		node = balance(node);
	}
	return node;
}

int BST::height(Node* tree) {
	int h = 0;
	if (tree != nullptr) {
		int l_height = height(tree->leftNode);
		int r_height = height(tree->rightNode);
		int max_height = std::max(l_height, r_height);
		h = max_height + 1;
	}
	return h;
}

int BST::difference(Node *tree) {
	int l_height = height(tree->leftNode);
	int r_height = height(tree->rightNode);
	int b_factor = l_height - r_height;
	return b_factor;
}

Node *BST::rr_rotat(Node *parent) {
	Node *t;
	t = parent->rightNode;
	parent->rightNode = t->leftNode;
	t->leftNode = parent;
	std::cout << "Right-Right Rotation";
	return t;
}
Node *BST::ll_rotat(Node *parent) {
	Node *t;
	t = parent->leftNode;
	parent->leftNode = t->rightNode;
	t->rightNode = parent;
	std::cout << "Left-Left Rotation";
	return t;
}
Node *BST::lr_rotat(Node *parent) {
	Node *t;
	t = parent->leftNode;
	parent->leftNode = rr_rotat(t);
	std::cout << "Left-Right Rotation";
	return ll_rotat(parent);
}
Node *BST::rl_rotat(Node *parent) {
	Node *t;
	t = parent->rightNode;
	parent->rightNode = ll_rotat(t);
	std::cout << "Right-Left Rotation";
	return rr_rotat(parent);
}
Node *BST::balance(Node *t) {
	int bal_factor = difference(t);
	if (bal_factor > 1) {
		if (difference(t->leftNode) > 0)
			t = ll_rotat(t);
		else
			t = lr_rotat(t);
	}
	else if (bal_factor < -1) {
		if (difference(t->rightNode) > 0)
			t = rl_rotat(t);
		else
			t = rr_rotat(t);
	}
	return t;
}


bool CheckInt(char menu[]) {
	bool pass = true;
	for (int i = 0; i < strlen(menu); i++) {
		if (strlen(menu) >= 2) {
			std::cout << "Wrong input" << std::endl;
			pass = true;
			break;
		}
		if (menu[i] < 48 || menu[i] > 57) {
			std::cout << "Wrong input" << std::endl;
			pass = true;
			break;
		}
		else {
			pass = false;
		}
	}
	return pass;
}

