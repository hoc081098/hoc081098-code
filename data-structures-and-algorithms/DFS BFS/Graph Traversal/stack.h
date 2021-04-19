//
// Created by Peter Hoc on 23/03/2018.
//

#ifndef GRAPH_TRAVERSAL_STACK_T_H
#define GRAPH_TRAVERSAL_STACK_T_H


#include "linked_list.h"

namespace petrus {
    template<typename T>
    class stack {
    protected:

        linked_list <T> list;

    public:
        stack() = default;

        stack(const stack<T> &other);

        void push(const T &t);

        void pop();

        bool is_empty() const;

        size_t size() const;

        T &peek();

        const T &peek() const;

        template<typename _T>
        friend std::ostream &operator<<(std::ostream &os, const stack<_T> &stack);

        template<typename _T>
        friend bool operator==(const stack <_T> &lhs, const stack <_T> &rhs);

        template<typename _T>
        friend bool operator!=(const stack <_T> &lhs, const stack <_T> &rhs);

        virtual ~stack() = default;
    };

    template<typename T>
    stack<T>::stack(const stack<T> &other):list(other.list) {}

    template<typename T>
    void stack<T>::push(const T &t) {
        list.add_to_head(t);
    }

    template<typename T>
    void stack<T>::pop() {
        list.remove_head();
    }

    template<typename T>
    bool stack<T>::is_empty() const {
        return list.is_empty();
    }

    template<typename T>
    size_t stack<T>::size() const {
        return list.size();
    }

    template<typename T>
    T &stack<T>::peek() {
        return list[0];
    }

    template<typename T>
    const T &stack<T>::peek() const {
        return list[0];
    }

    template<typename T>
    bool operator==(const stack<T> &lhs, const stack<T> &rhs) {
        return lhs.list == rhs.list;
    }

    template<typename T>
    bool operator!=(const stack<T> &lhs, const stack<T> &rhs) {
        return !(rhs == lhs);
    }

    template<typename _T>
    std::ostream &operator<<(std::ostream &os, const stack<_T> &stack) {
        return os << stack.list;
    }

}

#endif //GRAPH_TRAVERSAL_STACK_T_H
