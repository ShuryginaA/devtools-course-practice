// Copyright 2022 Shurygina A


#ifndef  MODULES_SHURYGINA_REV_POL_NOTAT_INCLUDE_STRUCTURES_H_
#define  MODULES_SHURYGINA_REV_POL_NOTAT_INCLUDE_STRUCTURES_H_

#include<string>

enum class ExceptionType {stackisFull,
                          queueisFull,
                          stackisEmpty,
                          queueisEmpty,
                          unidentified_symbol,
                          negative_length };
struct Exception {
    ExceptionType error;
    explicit Exception(ExceptionType _error) { error = _error; }
};

template <class T>
class TStruct {
 public:
    virtual void push(T v) = 0;
    virtual T pop() = 0;
    virtual bool isEmpty() = 0;
    virtual bool isFull() = 0;
};

#endif   // MODULES_SHURYGINA_REV_POL_NOTAT_INCLUDE_STRUCTURES_H_

