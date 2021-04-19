//
// Created by Peter Hoc on 26/03/2018.
//

#ifndef GRAPH_TRAVERSAL_QUEUE_H
#define GRAPH_TRAVERSAL_QUEUE_H


#include "linked_list.h"

namespace petrus {

    template<typename T>
    class queue {
    protected:
        petrus::linked_list<T> list;
    public:

        queue() = default;

        queue(const queue<T> &other);

        void push(const T &t);

        void pop();

        bool is_empty() const;

        size_t size() const;

        T &peek();

        const T &peek() const;

        template<typename _T>
        friend std::ostream &operator<<(std::ostream &os, const queue<_T> &queue1);

        template<typename _T>
        friend bool operator==(const queue<_T> &lhs, const queue<_T> &rhs);

        template<typename _T>
        friend bool operator!=(const queue<_T> &lhs, const queue<_T> &rhs);

        virtual ~queue() = default;

    };

    template<typename T>
    queue<T>::queue(const queue<T> &other):list(other.list) {}

    template<typename T>
    void queue<T>::push(const T &t) {
        list.add_to_tail(t);
    }

    template<typename T>
    void queue<T>::pop() {
        list.remove_head();
    }

    template<typename T>
    bool queue<T>::is_empty() const {
        return list.is_empty();
    }

    template<typename T>
    size_t queue<T>::size() const {
        return list.size();
    }

    template<typename T>
    T &queue<T>::peek() {
        return list[0];
    }

    template<typename T>
    const T &queue<T>::peek() const {
        return list[0];
    }

    template<typename _T>
    std::ostream &operator<<(std::ostream &os, const queue<_T> &queue1) {
        return os << queue1.list;
    }

    template<typename _T>
    bool operator==(const queue<_T> &lhs, const queue<_T> &rhs) {
        return lhs.list == rhs.list;
    }

    template<typename _T>
    bool operator!=(const queue<_T> &lhs, const queue<_T> &rhs) {
        return !(lhs == rhs);
    }
}


#endif //GRAPH_TRAVERSAL_QUEUE_H
