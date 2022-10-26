#ifndef IStrategy_H_
#define IStrategy_H_

typedef void (*DoAlgorithm)(void *);

typedef struct
{
    DoAlgorithm doAlgorithm;
} IStrategy ; 

IStrategy *IStrategy_new();
void IStrategy_ctor(IStrategy*);
void IStrategy_dtor(IStrategy*);
char* Fcion(IStrategy*);
#endif