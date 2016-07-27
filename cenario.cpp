#include "cenario.h"

#include <QtGui>
#include <QtOpenGL>
#include <math.h>

GLuint Cenario::ReturnList(bool isWireframe)
{
    GLuint list = glGenLists(1);

    glNewList(list,GL_COMPILE);
        if (isWireframe == true)
            glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
        else
            glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);


        //Chao
        glPushMatrix();
        glColor3f(0.8, 0.8, 0.8);
        glBegin(GL_QUADS);
            for (double x = -40; x <= 40; x += 0.5)
            {
                for (double z = -40; z <= 40; z += 0.5)
                {
                    glNormal3f(x + 0.1, 1, z + 0.1);

                    glVertex3f(x, -0.1, z);
                    glVertex3f(x, -0.1, z + 0.5);
                    glVertex3f(x + 0.5, -0.1, z + 0.5);
                    glVertex3f(x + 0.5, -0.1, z);
                }
            }
        glEnd();
        glPopMatrix();


        //Ruas ligando ao pinheiro
        glPushMatrix();
        glColor3f(0.3, 0.3, 0.3);
        glBegin(GL_QUADS);
            for (double x = -5; x <= 5; x += 0.5)
            {
                for (double z = -40; z <= 40; z += 0.5)
                {
                    glNormal3f(x + 0.1, 1, z + 0.1);

                    glVertex3f(x, -0.09, z);
                    glVertex3f(x, -0.09, z + 0.5);
                    glVertex3f(x + 0.5, -0.09, z + 0.5);
                    glVertex3f(x + 0.5, -0.09, z);
                }
            }

            for (double z = -5; z <= 5; z += 0.5)
            {
                for (double x = -40; x <= 40; x += 0.5)
                {
                    glNormal3f(x + 0.1, 1, z + 0.1);

                    glVertex3f(x, -0.09, z);
                    glVertex3f(x, -0.09, z + 0.5);
                    glVertex3f(x + 0.5, -0.09, z + 0.5);
                    glVertex3f(x + 0.5, -0.09, z);
                }
            }
        glEnd();
        glPopMatrix();


        //Faixas amarelas da rua
        glPushMatrix();
        glColor3f(0.8, 0.8, 0.0);
        glBegin(GL_QUADS);
                for (double z = -40; z <= 40; z += 2)
                {
                    glNormal3f(0, 1, 0);

                    glVertex3f(-0.2, -0.08, z);
                    glVertex3f(-0.2, -0.08, z + 1.5);
                    glVertex3f( 0.2, -0.08, z + 1.5);
                    glVertex3f( 0.2, -0.08, z);
                }

                for (double x = -40; x <= 40; x += 2)
                {
                    glNormal3f(0, 1, 0);

                    glVertex3f(x + 1.5, -0.08, -0.2);
                    glVertex3f(x,       -0.08, -0.2);
                    glVertex3f(x,       -0.08,  0.2);
                    glVertex3f(x + 1.5, -0.08,  0.2);                    
                }

        glEnd();
        glPopMatrix();

        
        //Primeira base pinheiro
        glPushMatrix();
        glScalef(16.0, 0.4, 16.0);
        Cilindro* cilindroVermelhoInf = new Cilindro(isWireframe, 1.0, 0.0, 0.0);
        cilindroVermelhoInf->Draw();
        glPopMatrix();


        //Segunda base pinheiro
        glPushMatrix();
        glTranslatef(0.0, 0.4, 0.0);
        glScalef(8.0, 0.4, 8.0);
        Cilindro* cilindroVermelhoSup = new Cilindro(isWireframe, 0.7, 0.0, 0.0);
        cilindroVermelhoSup->Draw();
        glPopMatrix();


        //Pinheiro
        glPushMatrix();
        glTranslatef(0.0, 0.8, 0.0);
        glScalef(4.0, 4.0, 4.0);
        Pinheiro* pinheiro = new Pinheiro(isWireframe);
        pinheiro->Draw();
        glPopMatrix();


        // Banco
        glPushMatrix();
        glTranslatef(0.0, 1, 5.0);
        glScalef(0.3, 0.3, 0.3);
        Banco* banco = new Banco(isWireframe, 0.5, 0.5, 0.5);
        banco->Draw();
        glPopMatrix();

        //Snowman1
        glPushMatrix();
        glTranslatef(-22.5, 2.0, -22.5);
        glRotatef(45, 0.0, 1.0, 0.0);
        glScalef(2.0, 2.0, 2.0);
        Snowman* snowman = new Snowman(isWireframe);
        snowman->Draw();
        glPopMatrix();

        // Casa 1
        glPushMatrix();
        glTranslatef(-12.5, 2.0, -12.5);
        glRotatef(45, 0.0, 1.0, 0.0);
        glScalef(4.0, 4.0, 4.0);
        Casa* casa = new Casa(isWireframe, 0.5, 0.5, 0);
        casa->Draw();
        glPopMatrix();


        //Snowman2
        glPushMatrix();
        glTranslatef(22.5, 2.0, -22.5);
        glRotatef(-45, 0.0, 1.0, 0.0);
        glScalef(2.0, 2.0, 2.0);
        snowman->Draw();
        glPopMatrix();


        //Snowman3
        glPushMatrix();
        glTranslatef(22.5, 2.0, 22.5);
        glRotatef(-135, 0.0, 1.0, 0.0);
        glScalef(2.0, 2.0, 2.0);
        snowman->Draw();
        glPopMatrix();


        //Snowman4
        glPushMatrix();
        glTranslatef(-22.5, 2.0, 22.5);
        glRotatef(135, 0.0, 1.0, 0.0);
        glScalef(2.0, 2.0, 2.0);
        snowman->Draw();
        glPopMatrix();


    glEndList();
    
    return list;
}
