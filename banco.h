#ifndef BANCO_H
#define BANCO_H

#include "paralelepipedo.h"
#include <QGLWidget>

class Banco
{
public:
    Banco(bool isWireframe, float redFloat, float greenFloat, float blueFloat);
    ~Banco();
    GLuint ReturnList();
    void Draw();

private:
    bool wireframe;
    float redComponent, greenComponent, blueComponent;
};

#endif // BANCO_H
