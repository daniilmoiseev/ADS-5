// Copyright 2021 NNTU-CS
#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_
#include <cassert>

template<typename T>
class TPQueue {
  struct ITEM {
    T data;
    ITEM *next;
  };

 private:
  ITEM *head;
  ITEM *tail;

 public:
  TPQueue() :head(nullptr), tail(nullptr) {}
  ~TPQueue() {
    while (head)
      pop();
  }

  void push(const T &item) {
    ITEM *t = new ITEM;
    t->data = item;
    t->next = nullptr;

    if (tail && head) {
      ITEM *temp = head;
      if (temp->data.prior < t->data.prior) {
        t->next = temp;
        head = t;
      } else {
        while (temp->next) {
          if (temp->next->data.prior < t->data.prior) {
            t->next = temp->next;
            temp->next = t;
            break;
          } else {
            temp = temp->next;
          }
        }
      }
      if (!temp->next) {
        tail->next = t;
        tail = tail->next;
      }
    } else {
      head = t;
      tail = head;
    }
  }
  T pop() {
    ITEM *temp = head;
    head = head->next;
    return temp->data;
  }
  void print() {
    ITEM *t = head;
    while (t) {
      std::cout << t->data.ch << " ";
      t = t->next;
    }
    std::cout << '\n';
  }
};

struct SYM {
  char ch;
  int prior;
};

#endif // INCLUDE_TPQUEUE_H_
