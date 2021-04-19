//
// Created by Peter Hoc on 03/04/2018.
//

#include <iostream>
#include "bst.h"


using std::cout;

struct functor {
    template<typename T>
    bool operator()(T &&l, T &&r) {
        return l * l < r * r;
    }
};

int main() {
    cout << std::boolalpha;

    auto cmp = [](auto &&a, auto &&b) {
        return (a ^ 1) > (b ^ 1);
    };
    auto print = [](auto &&e) {
        cout << e << '\n';
    };

    bst<int, decltype(cmp)> tree1(cmp);
    {
        bst<int, decltype(cmp)> tree(cmp);
        tree.insert(1);
        tree.insert(-1);
        tree.insert(123);
        tree.insert(2213);
        tree.insert(-23);
        tree.insert(1124);

        //try explicit move
        tree1 = std::move(tree);
        cout << "After move: \n";
        cout << "tree.is_empty() == " << tree.is_empty() << '\n';
    }
    tree1.insert(2);
    tree1.insert(3);
    tree1.insert(12);
    tree1.insert(2);

    cout << "Inorder: \n";
    tree1.preorder(print);

    cout << "Preorder: \n";
    tree1.preorder(print);

    cout << "Postorder: \n";
    tree1.postorder(print);

    cout << "Is empty? " << tree1.is_empty() << '\n';
    cout << "Contains 2? " << tree1.contains(2) << '\n';
    cout << "Contains 100? " << tree1.contains(100) << '\n';
    auto max = tree1.find_max();
    if (max) {
        cout << "Max is " << max.value().get() << '\n';
    } else {
        cout << "Tree is empty\n";
    }
    auto min = tree1.find_min();
    if (min) {
        cout << "Min is " << min.value().get() << '\n';
    } else {
        cout << "Tree is empty\n";
    }

    tree1.remove(2);
    tree1.remove(12);
    tree1.remove(999);
    cout << "After remove 2, 12, 999: \n";

    cout << "Inorder: \n";
    tree1.preorder(print);

    tree1.clear();
    cout << "After clear: \n";

    cout << "Is empty? " << tree1.is_empty() << '\n';
    cout << "Contains 2? " << tree1.contains(2) << '\n';
    cout << "Contains 100? " << tree1.contains(100) << '\n';
    auto max1 = tree1.find_max();
    if (max1) {
        cout << "Max is " << max1.value().get();
    } else {
        cout << "Tree is empty\n";
    }
    auto min1 = tree1.find_min();
    if (min1) {
        cout << "Min is " << min1.value().get();
    } else {
        cout << "Tree is empty\n";
    }


    tree1.insert(1);
    tree1.insert(2);
    tree1.insert(3);

    auto tree3 = tree1;

    cout << "tree1 == tree3? " << (tree1 == tree3) << '\n';

    tree3.clear();

    cout << "tree1 == tree3? " << (tree1 == tree3) << '\n';

    auto tree4(std::move(tree1));

    cout << "After Tree1 move, Tree1 is empty? " << tree1.is_empty() << '\n';
    cout << "Tree4 inorder\n";
    tree4.inorder(print);
    return 0;

    bst<int, functor> tree5;
    tree5.insert(1);
    tree5.insert(2);

    auto tree6 = std::move(tree5);
    bst<int, functor> tree7;
    tree7 = std::move(tree6);

    auto tree8(tree7);
}