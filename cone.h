#ifndef CONE_H
#define CONE_H

#include <QGLWidget>

class Cone
{
public:
    Cone(bool isWireframe, float redFloat, float greenFloat, float blueFloat);
    ~Cone();
    GLuint ReturnList();
    void Draw();

private:
    bool wireframe;
    float redComponent, greenComponent, blueComponent;
};

#endif // CONE_H
