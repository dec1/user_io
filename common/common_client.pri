# Centralized include for any client that uses this lib
#-------------------------------------------------------

# Paths are relative to client (not dir where this file is located)

# include headers
include("../common/common_h.pri")

# include setting such as output dir
include("../common/common_base.pri")


# get warnings that common header files cant be found wihout this
VPATH += ../common/src


# Link the debug/release version of the lib
#-------------------------------------------
CONFIG(debug, debug|release) {
    LIBS += -L$${MY_OUT_DIR}/debug -lcommon

}else {
    LIBS += -L$${MY_OUT_DIR}/release -lcommon
}
