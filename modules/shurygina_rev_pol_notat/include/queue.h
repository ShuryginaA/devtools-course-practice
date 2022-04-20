// Copyright 2022 Shurygina A

#ifndef   MODULES_SHURYGINA_REV_POL_NOTAT_INCLUDE_QUEUE_H_
#define   MODULES_SHURYGINA_REV_POL_NOTAT_INCLUDE_QUEUE_H_
#include<string>
#include"include/structures.h"

template <class T>
class TQueue : public TStruct<T> {
    T* mem;
    int N;
    int first;
    int last;
    int next(int ind) { return (ind + 1) % N; }
 public:
    explicit TQueue(int _N = 100);
    TQueue(const TQueue& v);
    ~TQueue();
    void push(T v);
    T pop();
    bool isFull();
    bool isEmpty();
};

template<class T>
inline TQueue<T>::TQueue(int _N) {
    N = _N;
    mem = new T[N];
    first = 0;
    last = N - 1;
}

#endif  //   MODULES_SHURYGINA_REV_POL_NOTAT_INCLUDE_QUEUE_H_

