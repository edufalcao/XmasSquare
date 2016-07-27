#ifndef ESTRELA_H
#define ESTRELA_H

#include <QGLWidget>
#include "esfera.h"
#include "cone.h"

class Estrela
{
public:
    Estrela(bool isWireframe, float redFloat, float greenFloat, float blueFloat);
    ~Estrela();
    GLuint ReturnList();
    void Draw();

private:
    bool wireframe;
    float redComponent, greenComponent, blueComponent;
};


#endif // ESTRELA_H
