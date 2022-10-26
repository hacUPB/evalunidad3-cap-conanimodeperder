#ifndef CONTEXT_H
#define CONTEXT_H

#include "Istrategy.h"

typedef struct
{
    IStrategy* _strategy;
    char* arg;
} Context;

Context *Context_new();
void Context_ctor(Context*, void*);
void Context_dtor(Context*);
void SetStrategy(Context*, void*);
void DoSomeBusinessLogic(Context*);
#endif