#ifndef ESFERA_H
#define ESFERA_H

#include <QGLWidget>

class Esfera
{
public:
    Esfera(bool isWireframe, float redFloat, float greenFloat, float blueFloat);
    ~Esfera();
    GLuint ReturnList();
    void Draw();

private:
    bool wireframe;
    float redComponent, greenComponent, blueComponent;
};

#endif // ESFERA_H
