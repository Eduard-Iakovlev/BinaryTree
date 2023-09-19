#include "binarytree.h"
//
BinaryTree::Node::Node(int d, Node* p) :
    data(d), parent(p) {
    leftChild = nullptr;
    rightChild = nullptr;
}
//
BinaryTree::Node::~Node() {
    // чистим за собой память
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
        // если дерево пустое, то новый элемент станет корнем
        root = new Node(newdata);
    }
    else {
        Node* current = root; // начинаем с корня
        Node* newNode = nullptr;
        while (newNode == nullptr) {
            if (current->data >= newdata) {
                // если элемент меньше текущего, идем влево
                if (current->leftChild != nullptr) {
                    current = current->leftChild;
                    continue;
                }
                // если левого узла нет, то нашли место для нового элемента
                newNode = new Node(newdata, current);
                current->leftChild = newNode;
            }
            else {
                // если элемент меньше текущего, идем вправо
                if (current->rightChild != nullptr) {
                    current = current->rightChild;
                    continue;
                }
                // если правого узла нет, то нашли место для нового элемента
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
            // удалить
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
// поиск, возвращает указатель на найденный элемент
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
// поиск минимального значения
BinaryTree::Node* BinaryTree::findMinNodata(Node* min)
{
    while (min->rightChild != nullptr) min = min->rightChild;
    return min; 
}

// удаление элемента
void BinaryTree::delInt(int deldata)
{
    Node* temp = nullptr;  // указатель для хранения родителя текущего узла
    Node* current = findNodeByData(deldata); // находим элемент
    if (current == nullptr) return;
    temp = current->parent;
    // 1 - удаление если элемент листок
    if (isLeaf(current)) { 
        if (temp->leftChild == current) temp->leftChild = nullptr;
        else temp->rightChild = nullptr;
    }
    // 2 - если элемент имеет 2 потомка
    else if (current->leftChild && current->rightChild) {
        Node* successor = findMinNodata(current->leftChild); // поиск узела-преемника
        int val = successor->data;  // сохраняем последующее значение

     // удаляем преемника. 
        //delInt(successor->data);// рекурсивное удаление листа
        delInt(successor->data);
        current->data = val;
    }
    // 3 - если имеет 1-го потомка
    else {
        // выбираем дочерний узел
        Node* childe = (current->leftChild) ? current->leftChild : current->rightChild;
        // если удаляемый узел не является корневым узлом, устанавливаем его родителя своему потомку
        if (current != root) {
            if (current == temp->leftChild) temp->leftChild = childe;
            else temp->rightChild = childe;
        }
        // если удаляемый узел является корневым узлом, то установить корень дочернему
        else root = childe;
        childe->parent = current->parent;

    }
 }
// проверка является ли узел листом        
bool BinaryTree::isLeaf(Node* check) {
    return check->leftChild == nullptr
        && check->rightChild == nullptr;
}

// проверка, являтся ли узел корневым
bool BinaryTree::isRoot(Node* check) {
    return check == root;
}
//---------
