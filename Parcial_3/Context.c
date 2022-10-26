#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Context.h"

Context *Context_new()
{
    return(Context*)malloc(sizeof(Context));
}

void Context_ctor(Context *this, void *_strategy)
{
    this->_strategy = (IStrategy*)_strategy;
    this->arg = malloc(sizeof(char[15]));
    strcpy(this->arg,"a,b,c,d,e");
}
void Context_dtor(Context *this)
{
   free(this->arg);
}
void SetStrategy(Context *this, void *_strategy)
{
    this->_strategy = (IStrategy*)_strategy;
}
void DoSomeBusinessLogic(Context *this)
{
    this->_strategy->doAlgorithm(this->arg);
}