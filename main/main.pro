# The main application
# Most code is in
QT  +=  core widgets

TEMPLATE = app
TARGET = app_input


include("../common/common_client.pri")


SOURCES += \
    ./src/main.cpp


OTHER_FILES += ./res/readme.txt \
               ./res/translation.de.ts






