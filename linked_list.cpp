#include <iostream>
#include <stdexcept>

#include "linked_list.hpp"

namespace LinkedList {

  List* init() {
    List* l = (List*) malloc(sizeof(List));
    l->length = 0;
    l->root = nullptr;
    return l;
  }

  void destroy(List* l) {
    Node* p = l->root;
    while (p != nullptr) {
      Node* tmp = p->next;
      free(p);
      p = tmp;
    }
    free(l);
  }

  void display(List* l) {
    std::cout << "[";
    Node* p = l->root;
    for (size_t i = 0; i < l->length; i++) {
      if (i != 0) {
        p = p->next;
      }
      std::cout << p->val;
      if (i != l->length-1) {
        std::cout << ", ";
      }
    }
    std::cout << "]";
  }

  void pushFront(List* l, int val) {
    Node* p = (Node*) malloc(sizeof(Node));
    p->val = val;
    p->next = l->root;
    l->root = p;
    l->length++;
  }

  void pop(List* l, int val) {
    if (l->length == 0) return;

    Node* p = l->root;
    if (p->val == val) {
      l->root = p->next;
      l->length -= 1;
      free(p);
      return;
    }
    while (p->next != nullptr) {
      if (p->next->val == val) {
        Node* tmp = p->next;
        p->next = tmp->next;
        l->length--;
        free(tmp);
        return;
      }
      p = p->next;
    }    
  }

  void pushBack(List* l, int val) { 
    Node* p = l->root;    
    while (p->next != nullptr) {
      p = p->next;
    }
    
    Node* v = (Node*) malloc(sizeof(Node));
    v->val = val;
    v->next = nullptr;
    p->next = v;
    l->length += 1;
  }

}