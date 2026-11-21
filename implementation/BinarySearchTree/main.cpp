#include "BinarySearchTree.h"
#include <cassert>
#include <iostream>
#include <climits>
using namespace std;

// 1. Тест конструктора
void test_constructor() {
    BinarySearchTree<int> bst;
    assert(bst.is_empty());
    assert(bst.size() == 0);
    assert(bst.height() == 0);
    cout << "test_constructor passed" << endl;
}

// 2. Тест деструктора
void test_destructor() {
    {
        BinarySearchTree<int> bst;
        bst.insert(10);
        bst.insert(20);
        bst.insert(5);
        assert(bst.size() == 3);
    }
    cout << "test_destructor passed" << endl;
}

// 3. Тест конструктора копирования
void test_copy_constructor() {
    BinarySearchTree<int> bst;
    bst.insert(50);
    bst.insert(30);
    bst.insert(70);
    BinarySearchTree<int> copy(bst);
    assert(copy.size() == 3);
    assert(copy.find(50));
    assert(copy.find(30));
    assert(copy.find(70));
    copy.insert(100);
    assert(copy.size() == 4);
    assert(bst.size() == 3);
    assert(!bst.find(100));
    BinarySearchTree<int> empty;
    BinarySearchTree<int> emptyCopy(empty);
    assert(emptyCopy.is_empty());
    cout << "test_copy_constructor passed" << endl;
}

// 4. Тест оператора присваивания
void test_assignment_operator() {
    BinarySearchTree<int> bst;
    bst.insert(10);
    bst.insert(20);
    bst.insert(5);
    BinarySearchTree<int> copy;
    copy.insert(100);
    copy = bst;
    assert(copy.size() == 3);
    assert(copy.find(10));
    assert(copy.find(20));
    assert(copy.find(5));
    copy = copy;
    assert(copy.size() == 3);
    BinarySearchTree<int> empty;
    copy = empty;
    assert(copy.is_empty());
    cout << "test_assignment_operator passed" << endl;
}

// 5. Тест вставки
void test_insert() {
    BinarySearchTree<int> bst;
    assert(bst.size() == 0);
    bst.insert(50);
    assert(bst.size() == 1);
    assert(bst.find(50));
    bst.insert(30);
    bst.insert(70);
    bst.insert(20);
    bst.insert(40);
    assert(bst.size() == 5);
    assert(bst.find(30));
    assert(bst.find(70));
    bst.insert(50);
    assert(bst.size() == 5);
    bst.insert(INT_MIN);
    bst.insert(INT_MAX);
    assert(bst.size() == 7);
    assert(bst.find(INT_MIN));
    assert(bst.find(INT_MAX));
    cout << "test_insert passed" << endl;
}

// 6. Тест удаления
void test_remove() {
    BinarySearchTree<int> bst;
    bst.remove(10);
    assert(bst.size() == 0);
    bst.insert(50);
    bst.insert(30);
    bst.insert(70);
    bst.insert(20);
    bst.insert(40);
    bst.insert(60);
    bst.insert(80);
    bst.remove(20);
    assert(!bst.find(20));
    assert(bst.size() == 6);
    bst.remove(30);
    assert(!bst.find(30));
    assert(bst.size() == 5);
    bst.remove(70);
    assert(!bst.find(70));
    assert(bst.size() == 4);
    bst.remove(50);
    assert(!bst.find(50));
    assert(bst.size() == 3);
    bst.remove(999);
    assert(bst.size() == 3);
    cout << "test_remove passed" << endl;
}

// 7. Тест поиска
void test_find() {
    BinarySearchTree<int> bst;
    assert(!bst.find(10));
    bst.insert(50);
    bst.insert(30);
    bst.insert(70);
    assert(bst.find(50));
    assert(bst.find(30));
    assert(bst.find(70));
    assert(!bst.find(100));
    assert(!bst.find(-10));
    cout << "test_find passed" << endl;
}

// 8. Тест inorder
void test_inorder() {
    BinarySearchTree<int> bst;
    bst.inorder();
    bst.insert(50);
    bst.insert(30);
    bst.insert(70);
    bst.insert(20);
    bst.insert(40);
    cout << "Inorder: ";
    bst.inorder();
    cout << "test_inorder passed" << endl;
}

// 9. Тест preorder
void test_preorder() {
    BinarySearchTree<int> bst;
    bst.preorder();
    bst.insert(50);
    bst.insert(30);
    bst.insert(70);
    bst.insert(20);
    bst.insert(40);
    cout << "Preorder: ";
    bst.preorder();
    cout << "test_preorder passed" << endl;
}

// 10. Тест postorder
void test_postorder() {
    BinarySearchTree<int> bst;
    bst.postorder();
    bst.insert(50);
    bst.insert(30);
    bst.insert(70);
    bst.insert(20);
    bst.insert(40);
    cout << "Postorder: ";
    bst.postorder();
    cout << "test_postorder passed" << endl;
}

// 11. Тест size
void test_size() {
    BinarySearchTree<int> bst;
    assert(bst.size() == 0);
    bst.insert(10);
    assert(bst.size() == 1);
    bst.insert(20);
    bst.insert(30);
    assert(bst.size() == 3);
    bst.insert(20);
    assert(bst.size() == 3);
    bst.remove(10);
    assert(bst.size() == 2);
    cout << "test_size passed" << endl;
}

// 12. Тест height
void test_height() {
    BinarySearchTree<int> bst;
    assert(bst.height() == 0);
    bst.insert(10);
    assert(bst.height() == 1);
    bst.insert(5);
    assert(bst.height() == 2);
    bst.insert(15);
    assert(bst.height() == 2);
    bst.insert(3);
    assert(bst.height() == 3);
    bst.insert(1);
    assert(bst.height() == 4);
    cout << "test_height passed" << endl;
}

// 13. Тест clear
void test_clear() {
    BinarySearchTree<int> bst;
    bst.clear();
    assert(bst.is_empty());
    assert(bst.size() == 0);
    bst.insert(10);
    bst.insert(20);
    bst.insert(5);
    bst.clear();
    assert(bst.is_empty());
    assert(bst.size() == 0);
    assert(bst.height() == 0);
    assert(!bst.find(10));
    bst.insert(100);
    assert(bst.size() == 1);
    assert(bst.find(100));
    cout << "test_clear passed" << endl;
}

// 14. Тест is_empty
void test_is_empty() {
    BinarySearchTree<int> bst;
    assert(bst.is_empty());
    bst.insert(10);
    assert(!bst.is_empty());
    bst.remove(10);
    assert(bst.is_empty());
    bst.insert(20);
    bst.clear();
    assert(bst.is_empty());
    cout << "test_is_empty passed" << endl;
}

int main() {
    cout << "BinarySearchTree tests" << endl;

    test_constructor();
    test_destructor();
    test_copy_constructor();
    test_assignment_operator();
    test_insert();
    test_remove();
    test_find();
    test_inorder();
    test_preorder();
    test_postorder();
    test_size();
    test_height();
    test_clear();
    test_is_empty();

    cout << "\nAll tests passed!" << endl;

    return 0;
}
