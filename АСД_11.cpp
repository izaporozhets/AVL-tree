#include "pch.h"
#include "BST.h"
int main()
{
	Node *root = nullptr;
	BST tree;
	bool flag = true;

	std::cout << "1 - Adding an element" << std::endl;
	std::cout << "2 - Show in direct" << std::endl;
	std::cout << "3 - Show in reverse" << std::endl;
	std::cout << "4 - Show first enter in direct" << std::endl;
	std::cout << "5 - Show first enter in  reverse" << std::endl;
	std::cout << "6 - Height from root in direct" << std::endl;
	std::cout << "7 - Height from root in reverse" << std::endl;
	std::cout << "8 - Find an element" << std::endl;
	std::cout << "9 - Delete an element" << std::endl;

	while (flag) {
		int i = 0;
		int counter = 0;
		int value = 0;
		bool success = true;
		char menu[256];
		std::cin.getline(menu, 256);
		while (CheckInt(menu)) {
			std::cin.getline(menu, 256);
		}
		int menu1 = atoi(menu);

		switch (menu1)
		{
		case 1: {
			std::cin >> value;
			tree.Add(root, value);
			break;
		}
		case 2:
		{
			tree.ShowDirect(root);
			std::cout << std::endl;
			break;
		}
		case 3:
		{
			tree.ShowReverse(root);
			std::cout << std::endl;
			break;
		}
		case 4:
		{
			std::cin >> value;
			tree.ShowDirect(root, value, counter);
			break;
		}
		case 5:
		{
			std::cin >> value;
			tree.ShowReverse(root, value, counter);
			break;
		}
		case 6:
		{
			std::cin >> value;
			tree.HeightFromRootDirect(root, value, counter);
			std::cout << std::endl;
			break;
		}
		case 7:
		{
			std::cin >> value;
			tree.HeightFromRootReverse(root, value, counter);
			std::cout << std::endl;
			break;
		}
		case 8:
		{
			std::cin >> value;
			if (!tree.Find(root, value)) {
				std::cout << "There is no such element" << std::endl;
			}
			break;
		}
		case 9:
		{
			std::cin >> value;
			root = tree.Delete(root, value);
			break;
		}
		default:
			std::cout << "Wrong input" << std::endl;
			break;
		}
	}
	system("pause");
}
