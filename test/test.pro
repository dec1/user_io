# Project containing (example) tests (unit/workflow)
# Only the tests themselves are here. As such theyre not included in the shippable production (main) app
# The code being tested is in the "common" project, which is also shared by the main project.

QT  +=  testlib core widgets


TEMPLATE = app


include("../common/common_client.pri")


SOURCES +=  ./src/test.cpp 

HEADERS +=  ./src/test.h

