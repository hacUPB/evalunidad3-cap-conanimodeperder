#ifndef CONCRETESTRATEGYA_H
#define CONCRETESTRATEGYA_H

#include "Istrategy.h"

typedef struct 
{
    IStrategy _strategyA;

} ConcreteStrategyA; 

ConcreteStrategyA *ConcreteStrategyA_new(); 
void ConcreteStrategyA_ctor(ConcreteStrategyA*);
void ConcreteStrategyA_dtor(ConcreteStrategyA*);

#endif