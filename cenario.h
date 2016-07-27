#ifndef CENARIO_H
#define CENARIO_H

#include <QGLWidget>
#include "cilindro.h"
#include "cone.h"
#include "esfera.h"
#include "banco.h"
#include "casa.h"
#include "guardachuva.h"
#include "pinheiro.h"
#include "snowman.h"

class Cenario
{
public:
    static GLuint ReturnList(bool isWireframe);
};

#endif // CENARIO_H
