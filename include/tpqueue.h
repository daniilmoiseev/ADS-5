// Copyright 2021 NNTU-CS
#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_
#include <cassert>

template<typename T>
class TPQueue {
public:
  TPQueue() :head(nullptr), tail(nullptr) {}
  ~TPQueue() {
    while (head)
      pop();
  }

  void push(const T &item) {
    T *t = new T;
    t->ch = item.ch;
    t->prior = item.prior;
    t->next = nullptr;
    if (tail && head) {
      T *temp = head;
      if (temp->prior < t->prior) {
        t->next = temp;
        head = t;
      } else {
        while (temp->next) {
          if (temp->next->prior < t->prior) {
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
    T *temp = head;
    head = head->next;
    return *temp;
  }

private:
  T *head;
  T *tail;
};

struct SYM {
  char ch;
  int prior;
  SYM *next;
};

#endif // INCLUDE_TPQUEUE_H_
