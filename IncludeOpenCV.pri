OPENCV_DIR = C:/Prog/OpenCV/OpenCV_3.0_MinGW
OPENCV_INCLUDE = $${OPENCV_DIR}/include
OPENCV_BIN_DIR = $${OPENCV_DIR}/x86/mingw/bin
OPENCV_LIB_DIR = $${OPENCV_DIR}/x86/mingw/lib

INCLUDEPATH += $${OPENCV_INCLUDE}
LIBS += -L$${OPENCV_LIB_DIR}
win32{
    OPENCV_LIBS = opencv_core300 opencv_imgproc300 opencv_imgcodecs300 opencv_highgui300
    CONFIG(debug, debug|release){
        DEBUGSIFFIX = d
    }
    for(library, OPENCV_LIBS):{
        libraryName = $${library}$${DEBUGSIFFIX}
        LIBS += -l$${libraryName}
    }
}