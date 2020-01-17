#pragma once
#include <iostream>

struct Node;

class BST {
public:
	void Add(Node *&node, int i);
	bool Find(Node *node, int i);
	void ShowDirect(Node *node);
	void ShowDirect(Node *node, int find, int &counter);
	void ShowReverse(Node *node);
	void ShowReverse(Node *node, int find, int &counter);
	void HeightFromRootReverse(Node *node, int elem, int counter);
	void HeightFromRootDirect(Node *node, int elem, int counter);
	Node *Delete(Node *&node, int elem);
private:
	int height(Node *tree);
	int difference(Node *tree);
	Node *rr_rotat(Node *parent);
	Node *ll_rotat(Node *parent);
	Node *lr_rotat(Node *parent);
	Node *rl_rotat(Node *parent);
	Node *balance(Node *parent);
};

bool CheckInt(char menu[]);