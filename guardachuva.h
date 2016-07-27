#ifndef GUARDACHUVA_H
#define GUARDACHUVA_H

#include <QGLWidget>

class GuardaChuva
{
public:
    GuardaChuva(bool isWireframe/*, float redFloat, float greenFloat, float blueFloat*/);
    ~GuardaChuva();
    GLuint ReturnList();
    void Draw();

private:
    bool wireframe;
    /*float redComponent, greenComponent, blueComponent;*/
};

#endif // GUARDACHUVA_H
