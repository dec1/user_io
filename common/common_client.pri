# Centralized include for any client that uses this lib
#-------------------------------------------------------


# include headers
include("../common/common_h.pri")

# include setting such as output dir
include("./common_base.pri")


# update include path (relative to client)
# INCLUDEPATH += ../common/src


# Link the debug/release version of the lib
#-------------------------------------------
CONFIG(debug, debug|release) {
    LIBS += -L$${MY_OUT_DIR}/debug -lcommon

}else {
    LIBS += -L$${MY_OUT_DIR}/release -lcommon
}
