#ifndef LINKEDLIST_HPP
#define LINKEDLIST_HPP

namespace LinkedList {
  struct Node {
    int val;
    Node *next;
  };

  struct List {
    size_t length;
    Node *root;
  };

  List* init();

  void destroy(List* l);

  void display(List* l);

  void pushFront(List* l, int val);

  void pop(List* l, int val);

  void pushBack(List* l, int val);
}

#endif