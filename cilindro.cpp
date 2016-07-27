#include "cilindro.h"

#include <QtGui>
#include <QtOpenGL>
#include <math.h>

Cilindro::Cilindro(bool isWireframe, float redFloat, float greenFloat, float blueFloat)
{
    this->wireframe = isWireframe;
    this->redComponent = redFloat;
    this->greenComponent = greenFloat;
    this->blueComponent = blueFloat;
}

Cilindro::~Cilindro()
{

}

GLuint Cilindro::ReturnList()
{
    GLuint list = glGenLists(1);

    glNewList(list, GL_COMPILE);
        this->Draw();
    glEndList();

    return list;
}

void Cilindro::Draw()
{
    glPushAttrib(GL_ALL_ATTRIB_BITS);

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
                x = sin(theta * c) * 0.5;
                y = 1;
                z = cos(theta * c) * 0.5;
                glVertex3f(x, y, z);
            }
    glEnd();

    glBegin(GL_TRIANGLE_FAN);
        glVertex3f(0.0, 0.0, 0.0);
        for (theta = -180.0; theta <= 180.0; theta +=10.0)
        {
            x = cos(theta * c) * 0.5;
            y = 0;
            z = sin(theta * c) * 0.5;
            glVertex3f(x, y, z);
        }
    glEnd();

    /*
    glBegin(GL_QUADS);
        theta = -180.0;
        while (theta <= 180.0)
        {
            x = sin(theta * c) * 0.5;
            y = 1;
            z = cos(theta * c) * 0.5;
            glVertex3f(x, y, z);

            x = sin(theta * c) * 0.5;
            y = 0;
            z = cos(theta * c) * 0.5;
            glVertex3f(x, y, z);

            theta += 10.0;

            x = sin(theta * c) * 0.5;
            y = 0;
            z = cos(theta * c) * 0.5;
            glVertex3f(x, y, z);

            x = sin(theta * c) * 0.5;
            y = 1;
            z = cos(theta * c) * 0.5;
            glVertex3f(x, y, z);
        }
    glEnd();
    */

    glBegin(GL_QUAD_STRIP);
        for (float height = 0; height <= 1; height += 0.05)
        {
            for (theta = 180.0; theta >= -180.0; theta -=10.0)
            {
                x = sin(c * theta) * 0.5;
                y = height;
                z = cos(c * theta) * 0.5;
    
                glNormal3f(x, y, z);
                glVertex3d(x,y,z);
    
                glNormal3f(x, y+0.05, z);
                glVertex3d(x,y+0.05,z);
            }
        }
    glEnd();

    glPopAttrib();
}

