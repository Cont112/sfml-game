#pragma once

class Ente {
protected:
    int id;

public:
    Ente();
    ~Ente();

    virtual void executar();
    void imprimir_se();
};