#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ConcreteStrategyA.h"
#include "Context.h"
#include "Istrategy.h"

ConcreteStrategyA *ConcreteStrategyA_new()
{
    return(ConcreteStrategyA *)malloc(sizeof(ConcreteStrategyA));
}

void DoAlgorithmA(void * arg)
{
    printf("Context:Sorting data using the strategy (not sure how it'll do it)\n");
    char *res =malloc(sizeof(char[25]));
    strcpy(res,(char*)arg);
    printf("%s", res);
    printf("\n");
    free(res);
}

void ConcreteStrategyA_ctor(ConcreteStrategyA *this)
{
    IStrategy_ctor((IStrategy*)this);
    this->_strategyA.doAlgorithm = DoAlgorithmA;
}