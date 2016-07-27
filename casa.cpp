#include "casa.h"

#include <QtGui>
#include <QtOpenGL>
#include <math.h>

Casa::Casa(bool isWireframe, float redFloat, float greenFloat, float blueFloat)
{
    this->wireframe = isWireframe;
    this->redComponent = redFloat;
    this->greenComponent = greenFloat;
    this->blueComponent = blueFloat;
}

Casa::~Casa()
{

}

GLuint Casa::ReturnList()
{
    GLuint list = glGenLists(1);

    glNewList(list, GL_COMPILE);
        this->Draw();
    glEndList();

    return list;
}

void Casa::Draw()
{

    if (this->wireframe == true)
        glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
    else
        glPolygonMode(GL_FRONT_AND_BACK, GL_POLYGON);
               // Porta frente
               glColor3f(0.8, 0.55, 0);
               glBegin(GL_POLYGON);
                        glNormal3f(0.0, 0.0, 1.0);
                        glVertex3f(-0.3,  0.4,  1.501);
                        glVertex3f(-0.3, -1,  1.501);
                        glVertex3f( 0.3, -1,  1.501);
                        glVertex3f( 0.3,  0.4,  1.501);
               glEnd();

               // Janela direita
               glBegin(GL_QUADS);
                        glNormal3f(1.0, 0.0, 0.0);
                        glVertex3f( 1.001,  0.4,  0.3);
                        glVertex3f( 1.001,    0,  0.3);
                        glVertex3f( 1.001,    0, -0.3);
                        glVertex3f( 1.001,  0.4, -0.3);
               glEnd();

               // Janela esquerda
               glBegin(GL_QUADS);
                        glNormal3f(-1.0, 0.0, 0.0);
                        glVertex3f( -1.001,  0.4, -0.3);
                        glVertex3f( -1.001,    0, -0.3);
                        glVertex3f( -1.001,    0,  0.3);
                        glVertex3f( -1.001,  0.4,  0.3);
               glEnd();


                glColor3f(this->redComponent, this->greenComponent, this->blueComponent);
               // Face direita
               glBegin(GL_QUADS);
                        glNormal3f(1.0, 0.0, 0.0);
                        glVertex3f( 1,  1,  1.5);
                        glVertex3f( 1, -1,  1.5);
                        glVertex3f( 1, -1, -1.5);
                        glVertex3f( 1,  1, -1.5);
               glEnd();

               // Face esquerda
               glBegin(GL_QUADS);
                        glNormal3f(-1.0, 0.0, 0.0);
                        glVertex3f(-1,  1, -1.5);
                        glVertex3f(-1, -1, -1.5);
                        glVertex3f(-1, -1,  1.5);
                        glVertex3f(-1,  1,  1.5);
               glEnd();


               // Face frente
               glBegin(GL_POLYGON);
                        glNormal3f(0.0, 0.0, 1.0);
                        glVertex3f(-1,  1,  1.5);
                        glVertex3f(-1, -1,  1.5);
                        glVertex3f( 1, -1,  1.5);
                        glVertex3f( 1,  1,  1.5);
                        glVertex3f( 0,  1.5,  1.5);
               glEnd();




               // Face traseira
               glBegin(GL_POLYGON);
                        glNormal3f(0.0, 0.0, -1.0);
                        glVertex3f(-1,  1,  -1.5);
                        glVertex3f(-1, -1,  -1.5);
                        glVertex3f( 1, -1,  -1.5);
                        glVertex3f( 1,  1,  -1.5);
                        glVertex3f( 0,  1.5,  -1.5);
               glEnd();




               // Muda a cor do teto
               glColor3f(0.8, 0.33, 0);
               Paralelepipedo* teto = new Paralelepipedo(wireframe, 0.8, 0.3, 0);

               glPushMatrix();
                    glTranslatef(-0.72, 1.1, 0);
                    glRotatef(30, 0, 0, 1);
                    glScalef(0.8,0.1,1.8);
                    teto->Draw();
               glPopMatrix();

               glPushMatrix();
                    glTranslatef(0.72, 1.1, 0);
                    glRotatef(-30, 0, 0, 1);
                    glScalef(0.8,0.1,1.8);
                    teto->Draw();
               glPopMatrix();

               // Teto esquerdo



}
