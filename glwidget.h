#ifndef GLWIDGET_H
#define GLWIDGET_H

#include <QGLWidget>
#include <iostream>
#include "cenario.h"

class GLWidget : public QGLWidget
{
    Q_OBJECT;

public:
    GLWidget(QWidget *parent = 0);
    ~GLWidget();

    QSize minimumSizeHint() const;
    QSize sizeHint() const;


public slots:
    void setXRotation(int angle);
    void setYRotation(int angle);
    void setZRotation(int angle);

signals:
    void xRotationChanged(int angle);
    void yRotationChanged(int angle);
    void zRotationChanged(int angle);


protected:
    void initializeGL();
    void paintGL();
    void resizeGL(int width, int height);
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void keyPressEvent(QKeyEvent *event);


private:
    void normalizeAngle(int *angle);
    GLuint object;
    int xRot;
    int yRot;
    int zRot;
    bool isWireFrame;
    float eyeX, eyeY, eyeZ, atX, atY, atZ, normalX, normalY, normalZ;
    QPoint lastPos;
};


#endif
