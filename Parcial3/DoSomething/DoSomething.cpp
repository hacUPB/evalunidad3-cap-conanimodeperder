// DoSomething.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>

class IStrategy
{
    public:
        virtual char * DoAlgorithm(char arg[], int size) = 0;
};

class ConcreteStrategyA : public IStrategy
{
    public:
        char * DoAlgorithm(char arg[], int size)
        {
            return SortAsc(arg, size);
        }
        char * SortAsc(char data[], int size) {
            char * result = data;
            char temp;
            for (int i = 0; i < size; i++) {
                for (int j = 1; j < size - i; j++) {
                    if (result[j - 1] > result[j]) {
                        temp = result[j - 1];
                        result[j - 1] = result[j];
                        result[j] = temp;
                    }
                }
            }
            return result;
        }
};

class ConcreteStrategyB : public IStrategy
{
    public:
        char * DoAlgorithm(char arg[], int size)
        {
            return SortDesc(arg, size);
        }
        char * SortDesc(char data[], int size) {
            char * result = data;
            char temp;
            for (int i = 0; i < size; i++) {
                for (int j = 1; j < size - i; j++) {
                    if (result[j - 1] < result[j]) {
                        temp = result[j - 1];
                        result[j - 1] = result[j];
                        result[j] = temp;
                    }
                }
            }
            return result;
        }
};

class Context {
    public:
        IStrategy* _strategy;
        Context() { };
        Context(IStrategy* strategy);
        void SetStrategy(IStrategy* strategy)
        {
            _strategy = strategy;
        }

        void DoSomeBusinessLogic()
        {
            std::cout << "Context: Sorting data using the strategy (not sure how it'll do it)\n";
            char arg[] = {'c','b','a','e','d'};
            int size = sizeof(arg) / sizeof(arg[0]);
            char * result = _strategy->DoAlgorithm(arg, size);
                    
            for (int i = 0; i < size; i++) {
                std::cout << result[i];
                if ((i+1) < size ) std::cout << ',';
            }
        }
};

Context::Context(IStrategy* strategy) {
    _strategy = strategy;
}

int main()
{
    Context* context = new Context;

    std::cout << "Client: Strategy is set to normal sorting.\n";
    context->SetStrategy(new ConcreteStrategyA());
    context->DoSomeBusinessLogic();
    std::cout << " \n";
    std::cout << "Client: Strategy is set to reverse sorting.\n";
    context->SetStrategy(new ConcreteStrategyB());
    context->DoSomeBusinessLogic();
}

// Ejecutar programa: Ctrl + F5 o menú Depurar > Iniciar sin depurar
// Depurar programa: F5 o menú Depurar > Iniciar depuración

// Sugerencias para primeros pasos: 1. Use la ventana del Explorador de soluciones para agregar y administrar archivos
//   2. Use la ventana de Team Explorer para conectar con el control de código fuente
//   3. Use la ventana de salida para ver la salida de compilación y otros mensajes
//   4. Use la ventana Lista de errores para ver los errores
//   5. Vaya a Proyecto > Agregar nuevo elemento para crear nuevos archivos de código, o a Proyecto > Agregar elemento existente para agregar archivos de código existentes al proyecto
//   6. En el futuro, para volver a abrir este proyecto, vaya a Archivo > Abrir > Proyecto y seleccione el archivo .sln
