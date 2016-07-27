#include "cone.h"

#include <QtGui>
#include <QtOpenGL>
#include <math.h>

Cone::Cone(bool isWireframe, float redFloat, float greenFloat, float blueFloat)
{
    this->wireframe = isWireframe;
    this->redComponent = redFloat;
    this->greenComponent = greenFloat;
    this->blueComponent = blueFloat;
}

Cone::~Cone()
{

}

GLuint Cone::ReturnList()
{
    GLuint list = glGenLists(1);

    glNewList(list, GL_COMPILE);
        this->Draw();
    glEndList();

    return list;
}

void Cone::Draw()
{
    GLfloat c, theta, x, y, z;

    // Conversion constant from degrees to radians
    c = 3.1415/180.0;

    // Current color
    glColor3f(this->redComponent, this->greenComponent, this->blueComponent);

    if (this->wireframe == true)
        glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
    else
        glPolygonMode(GL_FRONT_AND_BACK, GL_POLYGON);

    glBegin(GL_TRIANGLE_FAN);
        glVertex3f(0.0, 1.0, 0.0);
        for (theta = -180.0; theta <= 180.0; theta +=10.0)
        {
            z = cos(theta * c) * 0.4;
            y = 0;
            x = sin(theta * c) * 0.4;
            glNormal3f(x, y, z);
            glVertex3f(x, y, z);
        }
    glEnd();

    glBegin(GL_TRIANGLE_FAN);
        glVertex3f(0.0, 0.0, 0.0);
        for (theta = -180.0; theta <= 180.0; theta +=10.0)
        {
            x = cos(theta * c) * 0.4;
            y = 0;
            z = sin(theta * c) * 0.4;
            glNormal3f(0, -1, 0);
            glVertex3f(x, y, z);
        }
    glEnd();
}
