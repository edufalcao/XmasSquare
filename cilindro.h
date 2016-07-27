#ifndef CILINDRO_H
#define CILINDRO_H

#include <QGLWidget>

class Cilindro
{
public:
    Cilindro(bool isWireframe, float redFloat, float greenFloat, float blueFloat);
    ~Cilindro();
    GLuint ReturnList();
    void Draw();

private:
    bool wireframe;
    float redComponent, greenComponent, blueComponent;
};

#endif // CILINDRO_H
