#include "estrela.h"

#include <QtGui>
#include <QtOpenGL>
#include <math.h>

Estrela::Estrela(bool isWireframe, float redFloat, float greenFloat, float blueFloat)
{
    this->wireframe = isWireframe;
    this->redComponent = redFloat;
    this->greenComponent = greenFloat;
    this->blueComponent = blueFloat;
}

Estrela::~Estrela()
{

}

GLuint Estrela::ReturnList()
{
    GLuint list = glGenLists(1);
    glNewList(list,GL_COMPILE);
        this->Draw();
    glEndList();

    return list;
}


void Estrela::Draw()
{
    if (this->wireframe == true)
        glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
    else
        glPolygonMode(GL_FRONT_AND_BACK, GL_POLYGON);

    Cone* coneAmarelo = new Cone(this->wireframe, redComponent, greenComponent, blueComponent);

    glPushMatrix();
    glTranslatef(0.0, 0.5, 0.0);
    glScalef(1.5, 1.5, 1.5);
    coneAmarelo->Draw();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.0, 0.5, 0.0);
    glScalef(1.5, 1.5, 1.5);
    glRotatef(72, 0.0, 0.0, 1.0);
    coneAmarelo->Draw();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.0, 0.5, 0.0);
    glScalef(1.5, 1.5, 1.5);
    glRotatef(144, 0.0, 0.0, 1.0);
    coneAmarelo->Draw();
    glPopMatrix();
    
    glPushMatrix();
    glTranslatef(0.0, 0.5, 0.0);
    glScalef(1.5, 1.5, 1.5);
    glRotatef(216.0, 0.0, 0.0, 1.0);
    coneAmarelo->Draw();
    glPopMatrix();


    glPushMatrix();
    glTranslatef(0.0, 0.5, 0.0);
    glScalef(1.5, 1.5, 1.5);
    glRotatef(288.0, 0.0, 0.0, 1.0);
    coneAmarelo->Draw();
    glPopMatrix();
}
