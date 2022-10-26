#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ConcreteStrategyB.h"
#include "Context.h"
#include "Istrategy.h"

ConcreteStrategyB *ConcreteStrategyB_new()
{
    return (ConcreteStrategyB*)malloc(sizeof(ConcreteStrategyB));
}
void DoAlgorithmB(void * arg)
{
    char* data = malloc(sizeof(char[25]));
    strcpy(data,(char*)arg);
    invert(data);
    free(data);
}

void invert (char * data)
{
    char *puntero_1, *puntero_2;
    puntero_1 = data;
    puntero_2 = data + strlen(data) - 1;
    char noInvert = *puntero_2;
    do
    {
        if (noInvert != '\0')
        {
            puntero_2--;
            noInvert = *puntero_2;
        }
        else
        {
            puntero_2--;
        }
    } while (puntero_2 >= puntero_1);
}
void ConcreteStrategyB_ctor(ConcreteStrategyB *this)
{
    IStrategy_ctor((IStrategy*)this);
    this->_strategyB.doAlgorithm = DoAlgorithmB;
}