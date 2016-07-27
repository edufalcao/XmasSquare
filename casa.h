#ifndef CASA_H
#define CASA_H

#include <QGLWidget>
#include "paralelepipedo.h"

class Casa
{
public:
    Casa(bool isWireframe, float redFloat, float greenFloat, float blueFloat);
    ~Casa();
    GLuint ReturnList();
    void Draw();

private:
    bool wireframe;
    float redComponent, greenComponent, blueComponent;
};


#endif // CASA_H
