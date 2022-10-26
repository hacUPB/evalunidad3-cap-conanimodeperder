#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Istrategy.h"
#include "ConcreteStrategyA.h"
#include "ConcreteStrategyB.h"
#include "Context.h"

int main(void)
{
    ConcreteStrategyA *concreteStrategyA = ConcreteStrategyA_new();
    ConcreteStrategyA_ctor(concreteStrategyA);

    Context *context = Context_new();
    Context_ctor(context, concreteStrategyA);

    printf("Client: Strategy is set to normal sorting.");
    DoSomeBusinessLogic(context);
    printf("\n");

    printf("Client: Strategy is set to reverse sorting.");

    ConcreteStrategyB *concreteStrategyB = ConcreteStrategyB_new();
    ConcreteStrategyB_ctor(concreteStrategyB);

    SetStrategy(context,concreteStrategyB);
    DoSomeBusinessLogic(context);

    Context_dtor(context);
    free(context);

    free(concreteStrategyA);
    free(concreteStrategyB);

    return 0;
}