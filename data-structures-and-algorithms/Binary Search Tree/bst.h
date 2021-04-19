//
// Created by Peter Hoc on 03/04/2018.
//

#ifndef BINARY_SEARCH_TREE_BST_H
#define BINARY_SEARCH_TREE_BST_H

//using C++14
//gcc - mingw32 - 6.3.0

#include <functional>
#include <experimental/optional>

using namespace std::experimental;

template<typename T, typename Compare = std::less<T>>
class bst {

public:

    explicit bst(const Compare &compare = Compare()) : root(nullptr), compare(compare) {}

    bst(const bst<T, Compare> &o) : compare(o.compare), root(copy(o.root)) {}

    bst(bst<T, Compare> &&o) noexcept
            : root(std::move(o.root)), compare(std::move(o.compare)) { o.root = nullptr; }

    virtual ~bst() { make_empty(root); }


    optional<std::reference_wrapper<T>> find_min() const {
        auto r = find_min(root);
        if (r == nullptr) {
            return nullopt;
        } else {
            return r->value;
        }
    }

    optional<std::reference_wrapper<T>> find_max() const {
        auto r = find_max(root);
        if (r == nullptr) {
            return nullopt;
        } else {
            return r->value;
        }
    }

    bool is_empty() const { return root == nullptr; }

    bool contains(const T &value) const { return contains(root, value); }

    template<typename Func>
    void inorder(Func &&f) const { inorder(root, f); }

    template<typename Func>
    void preorder(Func &&f) const { preorder(root, f); }

    template<typename Func>
    void postorder(Func &&f) const { postorder(root, f); }

    void insert(T &value) { insert(root, value); }

    void insert(T &&value) { insert(root, std::move(value)); }

    void remove(const T &value) { remove(root, value); }

    void clear() { make_empty(root); }

    template<typename T_, typename Compare_>
    friend bool operator==(const bst<T_, Compare_> &lhs, const bst<T_, Compare_> &rhs);

    template<typename T_, typename Compare_>
    friend bool operator!=(const bst<T_, Compare_> &lhs, const bst<T_, Compare_> &rhs);

    bst &operator=(const bst &rhs) {
        if (this != &rhs) {
            make_empty(root);
            root = copy(rhs.root);
            compare = rhs.compare;
        }
        return *this;
    }

    bst &operator=(bst &&rhs) noexcept {
        if (this != &rhs) {
            make_empty(root);
            root = std::move(rhs.root);
            rhs.root = nullptr;
        }
        return *this;
    }

protected:
    virtual void insert_not_success(T &value) {}

private:

    struct bst_node {
        T value;
        bst_node *left;
        bst_node *right;

        explicit bst_node(const T &value, bst_node *left = nullptr, bst_node *right = nullptr)
                : value(value), left(left), right(right) {}

        explicit bst_node(T &&value, bst_node *left = nullptr, bst_node *right = nullptr)
                : value(std::move(value)), left(left), right(right) {}

    };

    bst_node *root;
    Compare compare;


    bst_node *find_min(bst_node *r) const {
        if (r == nullptr || r->left == nullptr)
            return r;
        return find_min(r->left);
    }

    bst_node *find_max(bst_node *r) const {
        if (r == nullptr || r->right == nullptr)
            return r;
        return find_max(r->right);
    }

    bool contains(bst_node *r, const T &value) const {
        if (r == nullptr)
            return false;
        if (compare(r->value, value))
            return contains(r->right, value);
        else if (compare(value, r->value))
            return contains(r->left, value);
        return true;
    }

    template<typename Func>
    void inorder(bst_node *r, Func &&func) const {
        if (r == nullptr) return;
        inorder(r->left, func);
        std::forward<Func>(func)(r->value);
        inorder(r->right, func);
    }

    template<typename Func>
    void preorder(bst_node *r, Func &&func) const {
        if (r == nullptr) return;
        std::forward<Func>(func)(r->value);
        preorder(r->left, func);
        preorder(r->right, func);
    }

    template<typename Func>
    void postorder(bst_node *r, Func &&func) const {
        if (r == nullptr) return;
        postorder(r->left, func);
        postorder(r->right, func);
        std::forward<Func>(func)(r->value);
    }

    void insert(bst_node *&r, T &value) {
        if (r == nullptr)
            r = new bst_node(value);
        else if (compare(r->value, value))
            insert(r->right, value);
        else if (compare(value, r->value))
            insert(r->left, value);
        else
            insert_not_success(r->value);
    }

    void insert(bst_node *&r, T &&value) {
        if (r == nullptr)
            r = new bst_node(std::move(value));
        else if (compare(r->value, value))
            insert(r->right, std::move(value));
        else if (compare(value, r->value))
            insert(r->left, std::move(value));
    }

    void remove(bst_node *&r, const T &value) {
        if (r == nullptr)
            return;
        if (compare(r->value, value))
            remove(r->right, value);
        else if (compare(value, r->value))
            remove(r->left, value);
        else if (r->left != nullptr && r->right != nullptr) {
            r->value = find_min(r->right)->value;
            remove(r->right, r->value);
        } else {
            auto old = r;
            r = r->left != nullptr ? r->left : r->right;
            delete old;
        }
    }

    void make_empty(bst_node *&r) {
        if (r != nullptr) {
            make_empty(r->left);
            make_empty(r->right);
            delete r;
        }
        r = nullptr;
    }

    bst_node *copy(bst_node *r) {
        if (r == nullptr) return nullptr;
        return new bst_node(r->value, copy(r->left), copy(r->right));
    }

    static bool equals(bst_node *r1, bst_node *r2) {
        if (r1 == r2)
            return true;
        if (r1 == nullptr || r2 == nullptr)
            return false;
        return r1->value == r1->value
               && equals(r1->left, r2->left)
               && equals(r1->right, r2->right);
    }
};

template<typename T_, typename Compare_>
bool operator==(const bst<T_, Compare_> &lhs, const bst<T_, Compare_> &rhs) {
    return bst<T_, Compare_>::equals(lhs.root, rhs.root);
}

template<typename T_, typename Compare_>
bool operator!=(const bst<T_, Compare_> &lhs, const bst<T_, Compare_> &rhs) {
    return !(rhs == lhs);
}

#endif //BINARY_SEARCH_TREE_BST_H
