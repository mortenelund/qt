CXX_MODULE = qml
TARGET  = windowplugin
TARGETPATH = QtQuick/Window.2
IMPORT_VERSION = 2.0

SOURCES += \
    plugin.cpp

QT += quick-private qml-private

load(qml_plugin)
