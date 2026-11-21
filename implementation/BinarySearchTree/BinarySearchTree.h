#ifndef BINARYSEARCHTREE_H
#define BINARYSEARCHTREE_H

#include <iostream>

template <typename T>
class BinarySearchTree {
private:
    struct Node {
        T data;
        Node* left;
        Node* right;
        Node(const T& d) : data(d), left(nullptr), right(nullptr) {}
    };
    Node* _root;
    int _size;
    Node* insert_recursive(Node* node, const T& value) {
        if (node == nullptr) {
            _size++;
            return new Node(value);
        }
        if (value < node->data) {
            node->left = insert_recursive(node->left, value);
        }
        else if (value > node->data) {
            node->right = insert_recursive(node->right, value);
        }
        return node;
    }

    Node* remove_recursive(Node* node, const T& value) {
        if (node == nullptr)
            return nullptr;
        if (value < node->data) {
            node->left = remove_recursive(node->left, value);
        }
        else if (value > node->data) {
            node->right = remove_recursive(node->right, value);
        }
        else {
            _size--;
            if (node->left == nullptr) {
                Node* temp = node->right;
                delete node;
                return temp;
            }
            if (node->right == nullptr) {
                Node* temp = node->left;
                delete node;
                return temp;
            }
            Node* successor = node->right;
            while (successor->left != nullptr)
                successor = successor->left;
            node->data = successor->data;
            _size++;
            node->right = remove_recursive(node->right, successor->data);
        }
        return node;
    }
    Node* find_recursive(Node* node, const T& value) const {
        if (node == nullptr || node->data == value)
            return node;
        if (value < node->data)
            return find_recursive(node->left, value);
        return find_recursive(node->right, value);
    }
    void clear_recursive(Node* node) {
        if (node == nullptr)
            return;
        clear_recursive(node->left);
        clear_recursive(node->right);
        delete node;
    }
    int height_recursive(Node* node) const {
        if (node == nullptr)
            return 0;

        int leftHeight = height_recursive(node->left);
        int rightHeight = height_recursive(node->right);

        return 1 + (leftHeight > rightHeight ?
                    leftHeight : rightHeight);
    }
    Node* copy_recursive(Node* node) {
        if (node == nullptr)
            return nullptr;
        Node* newNode = new Node(node->data);
        try {
            newNode->left = copy_recursive(node->left);
            newNode->right = copy_recursive(node->right);
        }
        catch (...) {
            clear_recursive(newNode);
            throw;
        }

        return newNode;
    }

    void inorder_recursive(Node* node) const {
        if (node == nullptr)
            return;
        inorder_recursive(node->left);
        std::cout << node->data << " ";
        inorder_recursive(node->right);
    }

    void preorder_recursive(Node* node) const {
        if (node == nullptr)
            return;
        std::cout << node->data << " ";
        preorder_recursive(node->left);
        preorder_recursive(node->right);
    }

    void postorder_recursive(Node* node) const {
        if (node == nullptr)
            return;
        postorder_recursive(node->left);
        postorder_recursive(node->right);
        std::cout << node->data << " ";
    }

public:
    // 1. Конструктор
    BinarySearchTree() : _root(nullptr), _size(0) {}

    // 2. Деструктор
    ~BinarySearchTree() {
        clear();
    }

    // 3. Конструктор копирования
    BinarySearchTree(const BinarySearchTree& other)
        : _root(nullptr), _size(0) {
        _root = copy_recursive(other._root);
        _size = other._size;
    }

    // 4. Оператор присваивания
    BinarySearchTree& operator=(const BinarySearchTree& other) {
        if (this == &other)
            return *this;

        BinarySearchTree temp(other);
        Node* oldRoot = _root;
        _root = temp._root;
        _size = temp._size;
        temp._root = oldRoot;
        temp._size = 0;
        return *this;
    }

    // 5. Вставка
    void insert(const T& value) {
        _root = insert_recursive(_root, value);
    }

    // 6. Удаление
    void remove(const T& value) {
        _root = remove_recursive(_root, value);
    }

    // 7. Поиск
    bool find(const T& value) const {
        return find_recursive(_root, value) != nullptr;
    }

    // 8. Inorder
    void inorder() const {
        inorder_recursive(_root);
        std::cout << std::endl;
    }

    // 9. Preorder
    void preorder() const {
        preorder_recursive(_root);
        std::cout << std::endl;
    }

    // 10. Postorder
    void postorder() const {
        postorder_recursive(_root);
        std::cout << std::endl;
    }

    // 11. Размер
    int size() const {
        return _size;
    }

    // 12. Высота
    int height() const {
        return height_recursive(_root);
    }

    // 13. Очистка
    void clear() {
        clear_recursive(_root);
        _root = nullptr;
        _size = 0;
    }

    // 14. Проверка на пустоту
    bool is_empty() const {
        return _root == nullptr;
    }
};

#endif // BINARYSEARCHTREE_H
