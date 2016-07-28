#include <QtGui>
#include <QtOpenGL>
#include <OpenGL/gl.h>
#include <math.h>
#include <iostream>
#include "glwidget.h"
#include <glm/gtc/matrix_transform.hpp>

GLWidget::GLWidget(QWidget *parent)
    : QGLWidget(parent)
{
    setFocusPolicy(Qt::StrongFocus);
    object = 0;
    xRot = 32;
    yRot = 0;
    zRot = 0;
    this->isWireFrame = false;
    this->eyeX = 0.0;
    this->eyeY = 0.0;
    this->eyeZ = 4.0;
    this->atX = 0.0;
    this->atY = 0.0;
    this->atZ = 0.0;
    this->normalX = 0.0;
    this->normalY = 1.0;
    this->normalZ = 0.0;
}


GLWidget::~GLWidget()
{
    makeCurrent();
    glDeleteLists(object, 1);
}


QSize GLWidget::minimumSizeHint() const
{
    return QSize(100, 100);
}


QSize GLWidget::sizeHint() const
{
    return QSize(800, 600);
}

void GLWidget::setXRotation(int angle)
{
    normalizeAngle(&angle);
    if (angle != xRot) {
        xRot = angle;
        updateGL();
    }
}


void GLWidget::setYRotation(int angle)
{
    normalizeAngle(&angle);
    if (angle != yRot) {
        yRot = angle;
        updateGL();
    }
}

void GLWidget::setZRotation(int angle)
{
    normalizeAngle(&angle);
    if (angle != zRot) {
        zRot = angle;
        updateGL();
    }
}


void GLWidget::initializeGL()
{
    glClearColor(0.0, 0.0, 0.0, 1.0);
    glShadeModel(GL_SMOOTH);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_CULL_FACE);
    glEnable(GL_NORMALIZE);
}


void GLWidget::paintGL()
{    
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    float widthHeight = (width()/height())*1.0f;
    glm::perspective(45.0f, widthHeight, 1.0f, 100.0f);
    glm::lookAt(glm::vec3(eyeX, eyeY, eyeZ), // posição observador
              glm::vec3(atX, atY, atZ), // lookAt
              glm::vec3(normalX, normalY, normalZ));
    glMatrixMode(GL_MODELVIEW);


    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();
    glTranslated(0.0, 0.0, -40.0);
    glRotated(xRot / 16.0, 1.0, 0.0, 0.0);
    glRotated(yRot / 16.0, 0.0, 1.0, 0.0);
    glRotated(zRot / 16.0, 0.0, 0.0, 1.0);

    object = Cenario::ReturnList(this->isWireFrame);
    glCallList(object);
}


void GLWidget::resizeGL(int width, int height)
{
    if (width >= height)
        glViewport(0, 0, width, (3*width/4));
    else
        glViewport(0, 0, (4*width/3), height);
}


void GLWidget::mousePressEvent(QMouseEvent *event)
{
    lastPos = event->pos();
}


void GLWidget::mouseMoveEvent(QMouseEvent *event)
{
    int dx = event->x() - lastPos.x();
    int dy = event->y() - lastPos.y();

    if (event->buttons() & Qt::LeftButton) {
        setXRotation(xRot + 8 * dy);
        setYRotation(yRot + 8 * dx);
    } else if (event->buttons() & Qt::RightButton) {
        setXRotation(xRot + 8 * dy);
        setZRotation(zRot + 8 * dx);
    }
    lastPos = event->pos();
}


void GLWidget::keyPressEvent(QKeyEvent *event)
{
    switch(event->key())
    {
        case Qt::Key_I:
            isWireFrame = !isWireFrame;
        break;

        case Qt::Key_W:
            eyeZ = eyeZ - 3;
            atZ = atZ - 3;
        break;

        case Qt::Key_S:
            eyeZ = eyeZ + 0.9;
            atZ = atZ + 0.9;
        break;

        case Qt::Key_A:
            eyeX = eyeX - 0.9;
            atX = atX - 0.9;
        break;

        case Qt::Key_D:
            eyeX = eyeX + 0.9;
            atX = atX + 0.9;
        break;

        case Qt::Key_PageUp:
            eyeY = eyeY + 0.9;
            atY = atY + 0.9;
        break;
        
        case Qt::Key_PageDown:
            eyeY = eyeY - 0.9;
            atY = atY - 0.9;
        break;

        default:
        break;
    }


    updateGL();
}



void GLWidget::normalizeAngle(int *angle)
{
    while (*angle < 0)
    {
        *angle += 360 * 16;
    }
    while (*angle > 360 * 16)
        
    {
        *angle -= 360 * 16;
    }
}
