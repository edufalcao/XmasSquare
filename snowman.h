#ifndef SNOWMAN_H
#define SNOWMAN_H

#include <QGLWidget>
#include "cilindro.h"
#include "cone.h"
#include "esfera.h"
#include "guardachuva.h"

class Snowman
{
public:
    Snowman(bool isWireframe);
    ~Snowman();
    GLuint ReturnList();
    void Draw();

private:
    bool wireframe;
};

#endif // SNOWMAN_H
