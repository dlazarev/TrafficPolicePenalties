//
//  BTree.cpp
//  TrafficPolicePenalties
// Goodbye win32

#include "BTree.h"
#include "service.h"

Node* BTree::_add(Node *r, T *d)
{
    if (r == NULL)
        r = new Node(d);
    else if (d->number < r->number)
        r->left = _add(r->left, d); // Вставка в левое поддерево
    else
        r->right = _add(r->right, d); // Вставка в правое поддерево
    return r;
}

Node* BTree::_add(Node *r, Node *new_node)
{
    if (r == NULL)
        r = new_node;
    else if (new_node->number < r->number)
        r->left = _add(r->left,new_node);
    else
        r->right = _add(r->right, new_node);
    return r;
};

void BTree::Add(T *d)
{
    root = _add(root, d);
}

void BTree::Add(Node *n)
{
    root = _add(root, n);
}

void BTree::_inOrderWalk(Node *r, void DoIt(Node*))
{
    if(r == NULL) return;
    DoIt(r);
    _inOrderWalk(r->left, DoIt);
    _inOrderWalk(r->right, DoIt);
}

void BTree::_inOrderWalk(ostream &stream, Node *r, void DoIt(ostream&, Node*))
{
    if(r == NULL) return;
    DoIt(stream, r);
    _inOrderWalk(stream, r->left, DoIt);
    _inOrderWalk(stream, r->right, DoIt);
}

void BTree::InOrderWalk(void DoIt(Node*))
{
    _inOrderWalk(root, DoIt);
}

void BTree::InOrderWalk(ostream &stream, void DoIt(ostream &stream, Node*))
{
    _inOrderWalk(stream, root, DoIt);
}

void BTree::print()
{
    _inOrderWalk(root, printNode);
}

ostream &operator<<(ostream &stream, BTree r)
{
    r.InOrderWalk(stream, outNode);
    return stream;
}
