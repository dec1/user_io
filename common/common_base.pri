
# output debug/release dirs
#---------------------------

MY_OUT_DIR =  ../../out

CONFIG(debug, debug|release) {
    DESTDIR = $${MY_OUT_DIR}/debug

}else {
    DESTDIR = $${MY_OUT_DIR}/release
}
