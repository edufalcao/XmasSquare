#include "paralelepipedo.h"

#include <QtGui>
#include <QtOpenGL>
#include <math.h>

Paralelepipedo::Paralelepipedo(bool isWireframe, float redFloat, float greenFloat, float blueFloat)
{
    this->wireframe = isWireframe;
    this->redComponent = redFloat;
    this->greenComponent = greenFloat;
    this->blueComponent = blueFloat;
}

Paralelepipedo::~Paralelepipedo()
{

}

GLuint Paralelepipedo::ReturnList()
{
    GLuint list = glGenLists(1);

    glNewList(list, GL_COMPILE);
        this->Draw();
    glEndList();

    return list;
}

void Paralelepipedo::Draw()
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


               glBegin(GL_QUADS);

                        // Face direita
                        glNormal3f(1.0, 0.0, 0.0);
                        glVertex3f( 1,  1,  1);
                        glVertex3f( 1, -1,  1);
                        glVertex3f( 1, -1, -1);
                        glVertex3f( 1,  1, -1);

                        // Face traseira
                        glNormal3f(0.0, 0.0, -1.0);
                        glVertex3f( 1,  1, -1);
                        glVertex3f( 1, -1, -1);
                        glVertex3f(-1, -1, -1);
                        glVertex3f(-1,  1, -1);

                        // Face esquerda
                        glNormal3f(-1.0, 0.0, 0.0);
                        glVertex3f(-1,  1, -1);
                        glVertex3f(-1, -1, -1);
                        glVertex3f(-1, -1,  1);
                        glVertex3f(-1,  1,  1);

                        // Face dianteira
                        glNormal3f(0.0, 0.0, 1.0);
                        glVertex3f(-1,  1,  1);
                        glVertex3f(-1, -1,  1);
                        glVertex3f( 1, -1,  1);
                        glVertex3f( 1,  1,  1);

                        // Face superior
                        glNormal3f( 0, 1.0, 0.0);
                        glVertex3f(-1,  1, -1);
                        glVertex3f(-1,  1,  1);
                        glVertex3f( 1,  1,  1);
                        glVertex3f( 1,  1, -1);

                        // Face inferior
                        glNormal3f(0.0, -1.0, 0.0);
                        glVertex3f(-1, -1,  1);
                        glVertex3f(-1, -1, -1);
                        glVertex3f( 1, -1, -1);
                        glVertex3f( 1, -1,  1);

                glEnd();



}
