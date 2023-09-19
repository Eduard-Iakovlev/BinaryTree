#include "binarytree.h"
//
BinaryTree::Node::Node(int d, Node* p) :
    data(d), parent(p) {
    leftChild = nullptr;
    rightChild = nullptr;
}
//
BinaryTree::Node::~Node() {
    // ������ �� ����� ������
    if (rightChild != nullptr)
        delete rightChild;
    if (leftChild != nullptr)
        delete leftChild;
}
//
BinaryTree::BinaryTree() {
    root = nullptr;
}
//
BinaryTree::~BinaryTree() {
    if (root != nullptr)
    {
        delete root;
    }
}
void BinaryTree::addInt(int newdata) {
    if (root == nullptr) {
        // ���� ������ ������, �� ����� ������� ������ ������
        root = new Node(newdata);
    }
    else {
        Node* current = root; // �������� � �����
        Node* newNode = nullptr;
        while (newNode == nullptr) {
            if (current->data >= newdata) {
                // ���� ������� ������ ��������, ���� �����
                if (current->leftChild != nullptr) {
                    current = current->leftChild;
                    continue;
                }
                // ���� ������ ���� ���, �� ����� ����� ��� ������ ��������
                newNode = new Node(newdata, current);
                current->leftChild = newNode;
            }
            else {
                // ���� ������� ������ ��������, ���� ������
                if (current->rightChild != nullptr) {
                    current = current->rightChild;
                    continue;
                }
                // ���� ������� ���� ���, �� ����� ����� ��� ������ ��������
                newNode = new Node(newdata, current);
                current->rightChild = newNode;
            }
        }
    }
}
void BinaryTree::print()
{
    Node* queue[100];
    int counter{ 0 };
    queue[counter++] = root;

    while (counter != 0) {
        Node* current = queue[0];
            // �������
        counter--;
        for (int i = 0; i < counter; i++) {
            queue[i] = queue[i + 1];
        }

        if (current->parent)
            std::cout << current->parent->data;
        std::cout << " " << current->data << "\n";
        if (current->leftChild)
            queue[counter++] = current->leftChild;
        if (current->rightChild)
            queue[counter++] = current->rightChild;
    }
}
// �����, ���������� ��������� �� ��������� �������
BinaryTree::Node* BinaryTree::findNodeByData(int finddata)
{
    if (root->data == finddata) return root;
    else {
        Node* current = root;
        while (current != nullptr) {
            if (finddata <= current->data) {
                current = current->leftChild;
                if (current == NULL) break;
                if (current->data == finddata) {
                    break;
                    }
            }
            if (finddata >= current->data) {
                current = current->rightChild;
                if (current == NULL) break;
                if (current->data == finddata) {
                    break;
                }
            }

        }
        if (current == nullptr) {
             //std::cout << " value not found" << "\n";
            return current;
        }

        //std::cout << current->data << "\n";
        return current;
    }
}
// ����� ������������ ��������
BinaryTree::Node* BinaryTree::findMinNodata(Node* min)
{
    while (min->rightChild != nullptr) min = min->rightChild;
    return min; 
}

// �������� ��������
void BinaryTree::delInt(int deldata)
{
    Node* temp = nullptr;  // ��������� ��� �������� �������� �������� ����
    Node* current = findNodeByData(deldata); // ������� �������
    if (current == nullptr) return;
    temp = current->parent;
    // 1 - �������� ���� ������� ������
    if (isLeaf(current)) { 
        if (temp->leftChild == current) temp->leftChild = nullptr;
        else temp->rightChild = nullptr;
    }
    // 2 - ���� ������� ����� 2 �������
    else if (current->leftChild && current->rightChild) {
        Node* successor = findMinNodata(current->leftChild); // ����� �����-���������
        int val = successor->data;  // ��������� ����������� ��������

     // ������� ���������. 
        //delInt(successor->data);// ����������� �������� �����
        delInt(successor->data);
        current->data = val;
    }
    // 3 - ���� ����� 1-�� �������
    else {
        // �������� �������� ����
        Node* childe = (current->leftChild) ? current->leftChild : current->rightChild;
        // ���� ��������� ���� �� �������� �������� �����, ������������� ��� �������� ������ �������
        if (current != root) {
            if (current == temp->leftChild) temp->leftChild = childe;
            else temp->rightChild = childe;
        }
        // ���� ��������� ���� �������� �������� �����, �� ���������� ������ ���������
        else root = childe;
        childe->parent = current->parent;

    }
 }
// �������� �������� �� ���� ������        
bool BinaryTree::isLeaf(Node* check) {
    return check->leftChild == nullptr
        && check->rightChild == nullptr;
}

// ��������, ������� �� ���� ��������
bool BinaryTree::isRoot(Node* check) {
    return check == root;
}
//---------
