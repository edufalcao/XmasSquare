#include "banco.h"

#include <QtGui>
#include <QtOpenGL>
#include <math.h>

Banco::Banco(bool isWireframe, float redFloat, float greenFloat, float blueFloat)
{
    this->wireframe = isWireframe;
    this->redComponent = redFloat;
    this->greenComponent = greenFloat;
    this->blueComponent = blueFloat;
}

Banco::~Banco()
{

}

GLuint Banco::ReturnList()
{
    GLuint list = glGenLists(1);

    glNewList(list, GL_COMPILE);
        this->Draw();
    glEndList();

    return list;
}

void Banco::Draw()
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

    Paralelepipedo* cubo = new Paralelepipedo(wireframe, this->redComponent, this->greenComponent, this->blueComponent);
    // Desenha o assento do banco
    for (float i=-4; i <= 4; i++) {
        for (float j=-1; j<= 2; j++) {
            glPushMatrix();
            glTranslatef(i, 1, j);
            glScalef(1, 0.5, 1);
            cubo->Draw();
            glPopMatrix();
        }
    }

    // Desenha o encosto do banco
    for (float i=-4; i <= 4; i++) {
        for (float j= 1; j<= 5; j++) {
            glPushMatrix();
            glTranslatef(i, j, -2);
            glScalef(1, 1, 0.5);
            cubo->Draw();
            glPopMatrix();
        }
    }

    // Lateral esquerda
    for (float i=0; i <= 3; i++) {
        for (float j=-1; j<= 1; j++) {
            glPushMatrix();
            glTranslatef(-5, i, j);
            glScalef(0.5, 1, 1);
            cubo->Draw();
            glPopMatrix();
        }
    }

    // Lateral direita
    for (float i=0; i <= 3; i++) {
        for (float j=-1; j<= 1; j++) {
            glPushMatrix();
            glTranslatef(5, i, j);
            glScalef(0.5, 1, 1);
            cubo->Draw();
            glPopMatrix();
        }
    }


}
