#-------------------------------------------------
#
# Project created by QtCreator 2012-03-17T15:29:08
#
#-------------------------------------------------

QT       -=

TARGET = lckernel
TEMPLATE = lib

DESTDIR = ../../generated/lib

#CONFIG += static warn_on
DEFINES += lckernel_LIBRARY

VERSION=0.0.1

DLL_NAME = lckernel
TARGET = $$DLL_NAME

GENERATED_DIR = ../../generated/lib/lckernel
# Use common project definitions.
include(../../settings.pro)
include(../../common.pro)


SOURCES += lckernel.cpp \
   cad/meta/color.cpp \
   cad/meta/layer.cpp \
   cad/meta/linewidth.cpp \
   cad/meta/pen.cpp \
   cad/primitive/line.cpp \
    cad/base/id.cpp \
    cad/document/document.cpp \
    cad/base/metainfo.cpp \
    cad/interface/variantable.cpp \
    cad/interface/metatype.cpp \
    cad/base/cadentity.cpp \
    cad/primitive/circle.cpp \
    cad/geometry/coordinate.cpp \
    cad/document/documentlayer.cpp \
    cad/document/layermanager.cpp \
    cad/document/documentimpl.cpp \
    cad/document/documentlayerimpl.cpp \
    cad/document/layermanagerimpl.cpp

HEADERS += lckernel.h\
    lckernel_global.h \
    cad/meta/color.h \
    cad/meta/layer.h \
    cad/meta/linewidth.h \
    cad/meta/pen.h \
    cad/primitive/line.h \
    cad/base/id.h \
    cad/document/document.h \
    cad/base/metainfo.h \
    cad/base/cadentity.h \
    cad/primitive/circle.h \
    cad/geometry/coordinate.h \
    cad/document/documentlayer.h \
    cad/document/layermanager.h \
    cad/interface/metatype.h \
    cad/interface/variantable.h \
    cad/document/documentimpl.h \
    cad/document/documentlayerimpl.h \
    cad/document/layermanagerimpl.h


unix:!symbian {
    maemo5 {
        target.path = /opt/usr/lib
    } else {
        target.path = /usr/lib
    }
    INSTALLS += target
}

OTHER_FILES += \
    cad/const.h