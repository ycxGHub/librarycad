cmake_minimum_required(VERSION 3.4.1)
set(DIR src/main/jni)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
add_library(
        drw-jni
        SHARED
        ${DIR}/libdxfrw.cpp
        ${DIR}/libdwgr.cpp
        ${DIR}/drw_header.cpp
        ${DIR}/drw_classes.cpp
        ${DIR}/drw_entities.cpp
        ${DIR}/drw_objects.cpp
        ${DIR}/intern/drw_textcodec.cpp
        ${DIR}/intern/dxfreader.cpp
        ${DIR}/intern/dxfwriter.cpp
        ${DIR}/intern/dwgreader.cpp
        ${DIR}/intern/dwgbuffer.cpp
        ${DIR}/intern/drw_dbg.cpp
        ${DIR}/intern/dwgreader21.cpp
        ${DIR}/intern/dwgreader18.cpp
        ${DIR}/intern/dwgreader15.cpp
        ${DIR}/intern/dwgutil.cpp
        ${DIR}/intern/rscodec.cpp
        ${DIR}/intern/dwgreader27.cpp
        ${DIR}/intern/dwgreader24.cpp
        ${DIR}/drw_imp.cpp
        ${DIR}/drw_imp.h
        ${DIR}/dx_data.h
        ${DIR}/libdxfrw.h
        ${DIR}/libdwgr.h
        ${DIR}/drw_interface.h
        ${DIR}/drw_base.h
        ${DIR}/drw_header.h
        ${DIR}/drw_classes.h
        ${DIR}/drw_entities.h
        ${DIR}/drw_objects.h
        ${DIR}/intern/drw_textcodec.h
        ${DIR}/intern/dxfreader.h
        ${DIR}/intern/dxfwriter.h
        ${DIR}/intern/dwgreader.h
        ${DIR}/intern/dwgbuffer.h
        ${DIR}/intern/drw_cptables.h
        ${DIR}/intern/drw_cptable950.h
        ${DIR}/intern/drw_cptable949.h
        ${DIR}/intern/drw_cptable936.h
        ${DIR}/intern/drw_cptable932.h
        ${DIR}/intern/drw_dbg.h
        ${DIR}/intern/dwgreader21.h
        ${DIR}/intern/dwgreader18.h
        ${DIR}/intern/dwgreader15.h
        ${DIR}/intern/dwgutil.h
        ${DIR}/intern/rscodec.h
        ${DIR}/intern/dwgreader27.h
        ${DIR}/intern/dwgreader24.h
        ${DIR}/drw-jni.cpp
        ${DIR}/drw-jni.h
        )

# Include libraries needed for hello-jni lib
target_link_libraries(
        drw-jni
        android
        log)