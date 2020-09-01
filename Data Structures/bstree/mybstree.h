// Obadiah Boda LEC a

#ifndef MYBSTREE_H
#define MYBSTREE_H

#include "abstractbstree.h"


template<typename T>
class Node
{
public:
    T m_data;
    Node* m_right;
    Node* m_left;

    Node()
    {
        m_left = NULL;
        m_right = NULL;
    }

    Node(Node* left, Node* right, T data)
    {
        m_data = data;
        m_left = left;
        m_right = right;
    }
};

template<typename T>
class MyBSTree: public AbstractBSTree<T>
{
private:

    Node<T>* m_root;

    int size(Node<T>* t) const;

    int height(const Node<T>* t) const;

    const T& getMax(const Node<T>* t) const throw (Oops);

    const T& getMin(const Node<T>* t) const throw (Oops);

    int find(const T& x, const Node<T>* t) const;

    int findT(const T& x, const Node<T>* t) const;

    void clear(Node<T>*& t);

    void insert(Node<T>*& t, const T& x);

    void remove(const T& x, Node<T>*& t);

    void printPreOrder(const Node<T>* t) const;

    void printPostOrder(const Node<T>* t) const;

    void prettyPrint(const Node<T>* t, int pad) const;

    Node<T>* cpy(const Node<T>* t) const;

public:

    MyBSTree();

    ~MyBSTree();

    MyBSTree(const MyBSTree & rhs);

    int size() const;

    bool isEmpty() const;

    int height() const;

    const T& getMax() const throw (Oops);

    const T& getMin() const throw (Oops);

    int find(const T& x) const;

    void clear();

    void insert(const T& x);

    void remove(const T& x);

    void printPreOrder() const;

    void printPostOrder() const;

    void print() const;

    const MyBSTree<T>& operator =(const MyBSTree &rhs);
};

#include "mybstree.hpp"

#endif



