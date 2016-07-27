#ifndef PINHEIRO_H
#define PINHEIRO_H

#include <QGLWidget>
#include "cone.h"
#include "cilindro.h"
#include "esfera.h"
#include "estrela.h"

class Pinheiro
{
public:
    Pinheiro(bool isWireframe);
    ~Pinheiro();
    GLuint ReturnList();
    void Draw();

private:
    bool wireframe;
};

#endif // PINHEIRO_H
