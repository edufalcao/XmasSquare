#include "snowman.h"

#include <QtGui>
#include <QtOpenGL>
#include <math.h>

Snowman::Snowman(bool isWireframe)
{
    this->wireframe = isWireframe;
}

Snowman::~Snowman()
{

}

GLuint Snowman::ReturnList()
{
    GLuint list = glGenLists(1);

    glNewList(list,GL_COMPILE);
        this->Draw();
    glEndList();

    return list;
}

void Snowman::Draw()
{
    Esfera* esferaBranca = new Esfera(this->wireframe, 1.0, 1.0, 1.0);
    Cone* coneVermelho = new Cone(this->wireframe, 1.0, 0.0, 0.0);
    Cone* narizLaranja = new Cone(this->wireframe, 1.0, 0.6, 0.2);
    Esfera* esferaAzul = new Esfera(this->wireframe, 0.0, 0.0, 0.8);
    Esfera* esferaPreta = new Esfera(this->wireframe, 0.0, 0.0, 0.0);
    Cilindro* cilindroVermelho = new Cilindro(this->wireframe, 1.0, 0.0, 0.0);


    //Corpo
    esferaBranca->Draw();


    //Cabeca
    glPushMatrix();
    glTranslatef(0.0, 1.0, 0.0);
    glScalef(0.7, 0.7, 0.7);
    esferaBranca->Draw();
    glPopMatrix();


    //Gravata
    glPushMatrix();
    glTranslatef(0.23, 0.65, 0.78);
    glRotatef(90.0, 0.0, 0.0, 1.0);
    glScalef(0.3, 0.3, 0.1);
    coneVermelho->Draw();
    glRotatef(-180.0, 1.0, 0.0, 0.0);
    glRotatef(-180.0, 0.0, 1.0, 0.0);
    glTranslatef(0.0, -1.5, 0.0);
    coneVermelho->Draw();
    glTranslatef(0.0, 0.74, 0.0);
    glScalef(0.3, 0.3, 0.5);
    esferaPreta->Draw();
    glPopMatrix();


    //Nariz
    glPushMatrix();
    glTranslatef(0.0, 1.0, 0.6);
    glRotatef(90.0, 1.0, 0.0, 0.0);
    glRotatef(180.0, 0.0, 1.0, 0.0);
    glScalef(0.3, 0.5, 0.3);
    narizLaranja->Draw();
    glPopMatrix();


    //Olho direito
    glPushMatrix();
    glTranslatef(-0.25, 1.3, 0.6);
    glScalef(0.1, 0.1, 0.1);
    esferaAzul->Draw();
    glPopMatrix();


    //Olho esquerdo
    glPushMatrix();
    glTranslatef(0.25, 1.3, 0.6);
    glScalef(0.1, 0.1, 0.1);
    esferaAzul->Draw();
    glPopMatrix();


    //Botoes
    glPushMatrix();
    glTranslatef(0.0, -0.3, 0.95);
    glScalef(0.06, 0.06, 0.06);
    esferaPreta->Draw();
    glTranslatef(0.0, 6.0, 1.0);
    esferaPreta->Draw();
    glPopMatrix();


    //Chapeu
    glPushMatrix();
    glTranslatef(0.0, 1.45, 0.0);
    glScalef(2.0, 0.08, 2.0);
    cilindroVermelho->Draw();
    glScalef(0.5, 12.5, 0.5);
    cilindroVermelho->Draw();
    glPopMatrix();
}
