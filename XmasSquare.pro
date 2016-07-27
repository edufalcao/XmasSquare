CONFIG += qt
HEADERS = glwidget.h \
    window.h \
    guardachuva.h \
    esfera.h \
    cilindro.h \
    cone.h \
    cenario.h \
    snowman.h \
    pinheiro.h \
    estrela.h \
    paralelepipedo.h \
    banco.h \
    casa.h
SOURCES = glwidget.cpp \
    main.cpp \
    window.cpp \
    guardachuva.cpp \
    esfera.cpp \
    cilindro.cpp \
    cone.cpp \
    cenario.cpp \
    snowman.cpp \
    pinheiro.cpp \
    estrela.cpp \
    paralelepipedo.cpp \
    banco.cpp \
    casa.cpp
QT += opengl

# install
target.path = XmasSquare
sources.files = $$SOURCES \
    $$HEADERS \
    $$RESOURCES \
    $$FORMS \
    XmasSquare.pro
sources.path = XmasSquare
INSTALLS += target \
    sources
OTHER_FILES += Makefile
