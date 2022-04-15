// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_

template<typename T, int size>
class TPQueue {
 private:
    T arr[100];
    int first;
    int last;
 public:
    TPQueue() :first(0), last(0) { }
    void push(T x) {
        int i = ++last;
        for (i; i >= first; i--) {
            if (arr[i-1].prior >= x.prior && i > first) {
                arr[i] = arr[i-1];
            } else {
                arr[i] = x;
                break;
            }
        }
    }
    T pop() {
        return arr[last--];
    }
};

struct SYM {
  char ch;
  int prior;
};

#endif  // INCLUDE_TPQUEUE_H_
