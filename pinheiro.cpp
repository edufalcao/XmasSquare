#include "pinheiro.h"

#include <QtGui>
#include <QtOpenGL>
#include <math.h>

Pinheiro::Pinheiro(bool isWireframe)
{
    this->wireframe = isWireframe;
}

Pinheiro::~Pinheiro()
{

}

GLuint Pinheiro::ReturnList()
{
    GLuint list = glGenLists(1);

    glNewList(list, GL_COMPILE);
        this->Draw();
    glEndList();

    return list;
}

void Pinheiro::Draw()
{
    glPushAttrib(GL_ALL_ATTRIB_BITS);

     if (this->wireframe == true)
        glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
    else
        glPolygonMode(GL_FRONT_AND_BACK, GL_POLYGON);

    Cilindro* tronco = new Cilindro(wireframe, 0.47, 0.17, 0.03);
    Cone* copa = new Cone(wireframe, 0.0, 0.5, 0.0);
    Estrela* estrela = new Estrela(wireframe, 1.0, 1.0, 0.0);


    //tronco
    glPushMatrix();
    glScalef(0.3, 2.0, 0.3);
    tronco->Draw();
    glPopMatrix();


    glTranslatef(0.0, 2.0, 0.0);


    //primeira copa (inferior)
    glPushMatrix();
    glScalef(3.5, 1.5, 3.5);
    copa->Draw();
    glPopMatrix();
    //------------


    glTranslatef(0.0, 0.7, 0.0);


    //segunda copa
    glPushMatrix();
    glScalef(2.8, 1.3, 2.8);
    copa->Draw();
    glPopMatrix();
    //------------


    glTranslatef(0.0, 0.6, 0.0);


    //terceira copa (superior)
    glPushMatrix();
    glScalef(2.2, 1.0, 2.2);
    copa->Draw();
    glPopMatrix();
    //------------

    glTranslatef(0.0, 0.9, 0.0);

    //estrela
    glPushMatrix();
    glScalef(0.4, 0.4, 0.4);
    estrela->Draw();
    glPopMatrix();
    //------------

    glPopAttrib();
}


