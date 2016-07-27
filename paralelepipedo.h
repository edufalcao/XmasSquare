#ifndef PARALELEPIPEDO_H
#define PARALELEPIPEDO_H

#include <QGLWidget>

class Paralelepipedo
{
public:
    Paralelepipedo(bool isWireframe, float redFloat, float greenFloat, float blueFloat);
    ~Paralelepipedo();
    GLuint ReturnList();
    void Draw();

private:
    bool wireframe;
    float redComponent, greenComponent, blueComponent;
};


#endif // PARALELEPIPEDO_H
