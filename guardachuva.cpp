#include "guardachuva.h"

#include <QtGui>
#include <QtOpenGL>
#include <math.h>

GuardaChuva::GuardaChuva(bool isWireframe/*, float redFloat, float greenFloat, float blueFloat*/)
{
    this->wireframe = isWireframe;
    /*this->redComponent = redFloat;
    this->greenComponent = greenFloat;
    this->blueComponent = blueFloat;*/
}

GuardaChuva::~GuardaChuva()
{

}

GLuint GuardaChuva::ReturnList()
{
    GLuint list = glGenLists(1);

    glNewList(list, GL_COMPILE);
        this->Draw();
    glEndList();

    return list;
}

void GuardaChuva::Draw()
{
    glPushAttrib(GL_ALL_ATTRIB_BITS);

    GLfloat c, theta, x, y, z;

    // Conversion constant from degrees to radians
    c = 3.1415/180.0;

    // Current color
    //glColor3f(this->redComponent, this->greenComponent, this->blueComponent);

    if (this->wireframe == true)
        glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
    else
        glPolygonMode(GL_FRONT_AND_BACK, GL_POLYGON);

    glBegin(GL_TRIANGLE_FAN);
        glVertex3d(0.0, 2.0, 0.0);

        for (theta = -180.0; theta <= 180.0; theta +=45.0)
        {
                z = cos(c * theta);
                y = 1;
                x = sin(c * theta);

                glColor3f(cos(c * theta) + 0.2,
                          sin(c * theta) + 0.2,
                          (cos(c * theta) * cos(c * theta)) + 0.2);

                glNormal3f(x, y, z);
                glVertex3d(x,y,z);
        }

        for (theta = -180.0; theta <= 180.0; theta +=45.0)
        {
                x = cos(c * theta);
                y = 1;
                z = sin(c * theta);

                glColor3f(cos(c * theta) + 0.2,
                          sin(c * theta) + 0.2,
                          (cos(c * theta) * cos(c * theta)) + 0.2);

                glNormal3f(-x, -y, -z);
                glVertex3d(x,y,z);
        }
    glEnd();

    glColor3f(1.0, 1.0, 0.0);

    glBegin(GL_LINES);
        glVertex3d(0,2,0);
        glVertex3d(0,0,0);
    glEnd();

    glBegin(GL_LINE_STRIP);
        for (theta = 180.0; theta <= 360.0; theta +=10.0)
        {
                x = 0.15 + (cos(c * theta) * 0.15);
                y = sin(c * theta) * 0.15;
                z = 0;
                glVertex3d(x,y,z);
        }
    glEnd();

    glPopAttrib();
}
