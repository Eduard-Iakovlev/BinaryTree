#pragma once
#include<iostream>
#ifndef __BYNARYTREE_H_
#define __BYNARYTREE_H_

//#include "test.h"

class BinaryTree {
public:
    struct Node { // ��������� ����
        Node(int d, Node* p = nullptr);
        ~Node();
        Node* parent; // ������������ ����

        Node* leftChild; // ����� ����
        Node* rightChild; // ������ ����

        int data; // ������ - ����� �����
    };

    BinaryTree();
    ~BinaryTree();

    void addInt(int newdata);
    void print();

    // �����, ���������� ��������� �� ��������� �������
    Node* findNodeByData(int finddata);
    // ����� ������������ ��������
    Node* findMinNodata(Node* min);
    // �������� ��������
    void delInt(int deldata);
    //����������� ����� � ������� � ������
    void symmetricWalk(int output_array[]);


private:
    //void setNewChild(Node* child, Node* newChild = nullptr);
    //void delNodeWithOneChild(Node* delNode);
    //void delLeaf(Node* leaf);
    // �������� �������� �� ���� ������        
    bool isLeaf(Node* check);
    // ��������, ������� �� ���� ��������
    bool isRoot(Node* check);
    Node* root; // �������� ����
};
#endif


// ������������ �����
//void BinaryTree::symmetricWalk(int output_array[]) {
//    if (root != nullptr)
//    {
//        int counter = 0;
//        symmetricWackInner(output_array, counter, root);
//    }
//}
//
//void BinaryTree::symmetricWackInner(int output_array[], int& counter, Node* current) {
//    // ���������� �����
//    if (current->leftChild != nullptr) {
//        symmetricWackInner(output_array, counter, current->leftChild);
//    }
//    output_array[counter++] = current->data; // ������ ����
//    //���������� ������
//    if (current->rightChild != nullptr) {
//        symmetricWackInner(current->rightChild);
//    }
//}