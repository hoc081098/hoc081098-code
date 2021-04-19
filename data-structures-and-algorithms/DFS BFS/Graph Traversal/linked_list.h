//
// Created by Peter Hoc on 26/03/2018.
//

#ifndef GRAPH_TRAVERSAL_LINKED_LIST_H
#define GRAPH_TRAVERSAL_LINKED_LIST_H

#include <cstdio>
#include <stdexcept>
#include <ostream>

namespace petrus {

    template<typename T>
    class linked_list {
    private:
        template<typename E>
        struct node {
            E data;
            node<E> *next;

            explicit node(const E &data, node<E> *next) : data(data), next(next) {}
        };

        template<typename _T>
        inline node<_T> *new_node(const _T &data, node<_T> *next = nullptr);

        typedef node<T> *node_ptr;

        node_ptr get_node_at(int index) const;

        void free_memory();

    protected:
        node_ptr head;
        node_ptr tail;
        size_t _size;

    public:
        linked_list(std::initializer_list<T> l);

        linked_list();

        linked_list(const linked_list<T> &other);

        template<typename _Func_t>
        void for_each(_Func_t f) const;

        void add(int index, const T &t);

        bool is_empty() const;

        void add_to_head(const T &t);

        void add_to_tail(const T &t);

        void remove_head();

        void remove_tail();

        void remove_at(int index);

        const T &get(int index) const;

        T &get(int index);

        const T &operator[](int index) const;

        T &operator[](int index);

        void set(int index, const T &t);

        size_t size() const;

        template<typename _T>
        friend std::ostream &operator<<(std::ostream &os, const linked_list<_T> &list);


        template<typename _T>
        friend bool operator==(const linked_list<_T> &lhs, const linked_list<_T> &rhs);

        template<typename _T>
        friend bool operator!=(const linked_list<_T> &lhs, const linked_list<_T> &rhs);


        virtual ~linked_list();

        void add_all(const linked_list<T> &list);

        linked_list<T> &operator=(const linked_list<T> &rhs);


    };

    template<typename T>
    linked_list<T>::linked_list() : head(NULL), tail(NULL), _size(0) {}

    template<typename T>
    template<typename _Func_t>
    void linked_list<T>::for_each(_Func_t f) const {
        for (node_ptr p = head; p; p = p->next) {
            f(p->data);
        }
    }

    template<typename T>
    void linked_list<T>::add(int index, const T &t) {
        if (index < 0 || index > _size) {
            throw std::out_of_range("Index out of bounds");
        }
        if (index == 0) {
            add_to_head(t);
            return;
        }
        if (index == _size) {
            add_to_tail(t);
            return;
        }
        //index in 1 until _size -> prev is always not null
        node_ptr prev = get_node_at(index - 1);
        prev->next = new_node(t, prev->next);
        ++_size;
    }

    template<typename T>
    linked_list<T>::~linked_list() {
        free_memory();
    }

    template <typename T>
    void linked_list<T>::free_memory() {
        while (head) {
            node_ptr next = head->next;
            delete head;
            head = next;
        }
    }

    template<typename T>
    template<typename _T>
    linked_list<T>::node<_T> *linked_list<T>::new_node(const _T &data, linked_list::node<_T> *next) {
        return new node<_T>(data, next);
    }

    template<typename T>
    linked_list<T>::node<T> *linked_list<T>::get_node_at(int index) const {
        if (index < 0 || index >= _size) {
            return NULL;
        }
        int i = 0;
        for (node_ptr pNode = head; pNode; pNode = pNode->next, ++i) {
            if (i == index) {
                return pNode;
            }
        }
    }

    template<typename T>
    bool linked_list<T>::is_empty() const {
        return head == nullptr;
    }

    template<typename T>
    void linked_list<T>::add_to_head(const T &t) {
        if (is_empty()) {
            head = tail = new_node(t);
        } else {
            head = new_node(t, head);
        }
        ++_size;
    }

    template<typename T>
    void linked_list<T>::add_to_tail(const T &t) {
        if (is_empty()) {
            head = tail = new_node(t);
        } else {
            tail = tail->next = new_node(t);
        }
        ++_size;
    }

    template<typename T>
    void linked_list<T>::remove_head() {
        if (is_empty()) {
            throw std::runtime_error("No such element");
        }
        node_ptr next = head->next;
        delete head;
        head = next;
        --_size;
    }

    template<typename T>
    void linked_list<T>::remove_tail() {
        if (is_empty()) {
            throw std::runtime_error("No such element");
        }
        nodeptr p = get_node_at(_size - 2);
        delete tail;
        tail = p;
        p->next = nullptr;
        --_size;
    }

    template<typename T>
    void linked_list<T>::remove_at(int index) {
        if (index < 0 || index >= _size) {
            throw std::invalid_argument("Invalid index");
        }

        if (index == 0) {
            remove_head();
            return;
        }

        if (index == _size - 1) {
            remove_tail();
            return;
        }

        //index in 1 until _size -> prev is always not null
        node_ptr prev = get_node_at(index - 1);
        node_ptr cur = prev->next;
        prev->next = cur->next;
        delete cur;
        --_size;
    }

    template<typename T>
    const T &linked_list<T>::get(int index) const {
        if (index < 0 || index >= _size) {
            throw std::invalid_argument("Invalid index");
        }
        return get_node_at(index)->data;
    }

    template<typename T>
    const T &linked_list<T>::operator[](int index) const {
        return get(index);
    }

    template<typename T>
    T &linked_list<T>::get(int index) {
        if (index < 0 || index >= _size) {
            throw std::invalid_argument("Invalid index");
        }
        return get_node_at(index)->data;
    }

    template<typename T>
    T &linked_list<T>::operator[](int index) {
        return get(index);
    }

    template<typename T>
    void linked_list<T>::set(int index, const T &t) {
        if (index < 0 || index >= _size) {
            throw std::invalid_argument("Invalid index");
        }
        get_node_at(index)->data = t;
    }

    template<typename T>
    size_t linked_list<T>::size() const {
        return _size;
    }

    template<typename T>
    linked_list<T>::linked_list(const linked_list<T> &other) {
        if (this == &other) return;

        head = tail = nullptr;
        _size = 0;
        add_all(other);
    }

    template<typename T>
    void linked_list<T>::add_all(const linked_list<T> &list) {
        for (node_ptr p = list.head; p; p = p->next) {
            add_to_tail(p->data);
        }
    }

    template<typename T>
    bool operator==(const linked_list<T> &lhs, const linked_list<T> &rhs) {
        if (lhs.head == rhs.head &&
            lhs.tail == rhs.tail &&
            lhs._size == rhs._size) {
            return true;
        }

        if (lhs._size != rhs._size) {
            return false;
        }

        typename linked_list<T>::node_ptr p1 = lhs.head;
        typename linked_list<T>::node_ptr p2 = rhs.head;

        for (; p1 && p2; p1 = p1->next, p2 = p2->next) {
            if (p1->data != p2->data) {
                return false;
            }
        }
        return true;
    }


    template<typename T>
    bool operator!=(const linked_list<T> &lhs, const linked_list<T> &rhs) {
        return !(rhs == lhs);
    }

    template<typename _T>
    std::ostream &operator<<(std::ostream &os, const linked_list<_T> &list) {
        os << '[';
        for (typename linked_list<_T>::node_ptr p = list.head; p; p = p->next) {
            os << p->data
               << (p->next ? ", " : "");
        }
        return os << ']';
    }

    template<typename T>
    linked_list<T>::linked_list(std::initializer_list<T> l) {
        head = tail = nullptr;
        _size = 0;

        for (auto &e : l) {
            add_to_tail(e);
        }
    }

    template<typename T>
    linked_list<T> &linked_list<T>::operator=(const linked_list<T> &rhs) {
        if (this == &rhs) {
            return *this;
        }
        free_memory();

        head = tail = nullptr;
        _size = 0;
        add_all(rhs);

        return *this;
    }
}


#endif //GRAPH_TRAVERSAL_LINKED_LIST_H
