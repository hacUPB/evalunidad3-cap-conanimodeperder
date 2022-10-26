#ifndef CONCRETESTRATEGYB_H
#define CONCRETESTRATEGYB_H

#include "Istrategy.h"

typedef struct 
{
    IStrategy _strategyB;

} ConcreteStrategyB; 

ConcreteStrategyB *ConcreteStrategyB_new(); 
void ConcreteStrategyB_ctor(ConcreteStrategyB*);
void ConcreteStrategyB_dtor(ConcreteStrategyB*);
void invert (char*);

#endif