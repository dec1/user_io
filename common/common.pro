# Static lib project.
# Contains code common to several clients (main/test)
# This is the bulk of the code, and clients need only contain code where the differ from each other (esp main() function)
# This setup means that the test project doesnt need to be completely rebuilt, when in main app something (common to both) changes.
# Esentially reduces build times when switching from main-test and vice versa. Enables effective  test driven development.

QT += core gui widgets

TEMPLATE = lib

VERSION = 0.1.0
CONFIG += staticlib


INCLUDEPATH += ./src
VPATH += ./src

include("./common_h.pri")
include("./common_cpp.pri")
include("./common_base.pri")

TRANSLATIONS = .res/translation.de.ts

RESOURCES += ./res/res.qrc


