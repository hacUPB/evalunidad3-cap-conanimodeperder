#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Istrategy.h"

IStrategy *IStrategy_new()
{
    return (IStrategy*)malloc(sizeof(IStrategy));
}
void doAlgorithm(void *nombre)
{
    char * result = malloc(sizeof(char[10]));
    printf("%s", result);
    free(result);
}
void IStrategy_ctor(IStrategy* this)
{
    this->doAlgorithm = &doAlgorithm;
}
void IStrategy_dtor(IStrategy* this)
{
    free(this);
}