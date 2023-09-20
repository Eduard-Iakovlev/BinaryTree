#pragma once
#include<iostream>
#ifndef __BYNARYTREE_H_
#define __BYNARYTREE_H_

//#include "test.h"

class BinaryTree {
public:
    struct Node { // структура узла
        Node(int d, Node* p = nullptr);
        ~Node();
        Node* parent; // родительский узел

        Node* leftChild; // левый узел
        Node* rightChild; // правый узел

        int data; // данные - целое число
    };

    BinaryTree();
    ~BinaryTree();

    void addInt(int newdata);
    void print();

    // поиск, возвращает указатель на найденный элемент
    Node* findNodeByData(int finddata);
    // поиск минимального элемента
    Node* findMinNodata(Node* min);
    // удаление элемента
    void delInt(int deldata);
    //симетричный обход с записью в массив
    void symmetricWalk(int output_array[]);


private:
    //void setNewChild(Node* child, Node* newChild = nullptr);
    //void delNodeWithOneChild(Node* delNode);
    //void delLeaf(Node* leaf);
    // проверка является ли узел листом        
    bool isLeaf(Node* check);
    // проверка, являтся ли узел корневым
    bool isRoot(Node* check);
    Node* root; // корневой узел
};
#endif


// симметричный обход
//void BinaryTree::symmetricWalk(int output_array[]) {
//    if (root != nullptr)
//    {
//        int counter = 0;
//        symmetricWackInner(output_array, counter, root);
//    }
//}
//
//void BinaryTree::symmetricWackInner(int output_array[], int& counter, Node* current) {
//    // обработали левый
//    if (current->leftChild != nullptr) {
//        symmetricWackInner(output_array, counter, current->leftChild);
//    }
//    output_array[counter++] = current->data; // вывели себя
//    //обработали правый
//    if (current->rightChild != nullptr) {
//        symmetricWackInner(current->rightChild);
//    }
//}