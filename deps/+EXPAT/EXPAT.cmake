add_cmake_project(EXPAT
  URL https://github.com/libexpat/libexpat/archive/refs/tags/R_2_4_3.zip
  URL_HASH SHA256=8851e199d763dc785277d6d414ed3e70ff683915158b51b8d8781df0e3af950a
  PATCH_COMMAND COMMAND ${PATCH_CMD} ${CMAKE_CURRENT_LIST_DIR}/EXPAT.patch
  SOURCE_SUBDIR expat
  CMAKE_ARGS
    -DEXPAT_BUILD_TOOLS:BOOL=OFF
    -DEXPAT_BUILD_EXAMPLES:BOOL=OFF
    -DEXPAT_BUILD_TESTS:BOOL=OFF
    -DEXPAT_BUILD_DOCS=OFF
    -DEXPAT_BUILD_PKGCONFIG=OFF
    # Build expat as a DLL so wxWidgets' xml.obj `__imp_XML_*` import-table
    # references resolve at link-time without requiring XML_STATIC propagation.
    -DEXPAT_SHARED_LIBS:BOOL=ON
)