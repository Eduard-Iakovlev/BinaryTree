#include "binarytree.h"

int main() {

	BinaryTree tree;

	tree.addInt(5);
	tree.addInt(4);
	tree.addInt(-17);
	tree.addInt(20);
	tree.addInt(13);
	tree.addInt(43);
	tree.addInt(11);
	tree.addInt(18);
	tree.addInt(15);
	tree.addInt(19);
	
	tree.print();

	std::cout << tree.findNodeByData(5) << "\n";
	tree.delInt(4);
	tree.print();
}