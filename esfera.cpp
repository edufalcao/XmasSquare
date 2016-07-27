#include "esfera.h"

#include <QtGui>
#include <QtOpenGL>
#include <math.h>

Esfera::Esfera(bool isWireframe, float redFloat, float greenFloat, float blueFloat)
{
    this->wireframe = isWireframe;
    this->redComponent = redFloat;
    this->greenComponent = greenFloat;
    this->blueComponent = blueFloat;
}

Esfera::~Esfera()
{

}

GLuint Esfera::ReturnList()
{
    GLuint list = glGenLists(1);
    glNewList(list,GL_COMPILE);
        this->Draw();
    glEndList();

    return list;
}


void Esfera::Draw()
{
    GLfloat c, phi, theta, x, y, z;

    // Conversion constant from degrees to radians
    c = 3.1415/180.0;

    // Current color
    glColor3f(this->redComponent, this->greenComponent, this->blueComponent);

    if (this->wireframe == true)
        glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
    else
        glPolygonMode(GL_FRONT_AND_BACK, GL_POLYGON);


    for (phi = -80.0; phi < 80.0; phi +=10.0)
    {
            glBegin(GL_QUAD_STRIP);
                    for (theta = -180.0; theta <= 180.0; theta +=10.0)
                    {
                            x = sin(c*theta)*cos(c*phi);
                            y = cos(c*theta)*cos(c*phi);
                            z = sin(c*phi);
                            glNormal3f(x, y, z);
                            glVertex3d(x, y, z);

                            x = sin(c*theta)*cos(c*(phi+20.0));
                            y = cos(c*theta)*cos(c*(phi+20.0));
                            z = sin(c*(phi+20.0));
                            glNormal3f(x, y, z);
                            glVertex3d(x, y, z);
                    }
            glEnd();
    }

    // Draw North Pole Cap with a triangle fan centered at the pole and connected to parallel 80 degrees
    x = y = 0.0;
    z = 1.0;
    glBegin(GL_TRIANGLE_FAN);
            glVertex3d(x, y, z);
            // z coordinate of points on the parallel 80 degrees
            z = sin(c*80.0);

            for (theta = 180.0; theta >= -180.0; theta -=20.0)
            {
                    x = sin(c*theta)*cos(c*80.0);
                    y = cos(c*theta)*cos(c*80.0);
                    glNormal3f(x, y, z);
                    glVertex3d(x, y, z);
            }

    glEnd();

    // Draw South Pole Cap with a triangle fan centered at the pole and connected to parallel -80 degrees
    x = y = 0.0;
    z = -1.0;
    glBegin(GL_TRIANGLE_FAN);
            glVertex3d(x, y, z);
            z = -sin(c*80.0);

            for (theta = -180.0; theta <= 180.0; theta +=20.0)
            {
                    x = sin(c*theta)*cos(c*80.0);
                    y = cos(c*theta)*cos(c*80.0);
                    glNormal3f(x, y, z);
                    glVertex3d(x, y, z);
            }
    glEnd();
}
