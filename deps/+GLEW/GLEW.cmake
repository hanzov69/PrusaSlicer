add_cmake_project(
  GLEW
  URL https://github.com/Perlmint/glew-cmake/archive/refs/tags/glew-cmake-2.2.0.tar.gz
  URL_HASH SHA256=cdd82afba80f7cf34548cf5c902240d6721ec5a27ec9e075851b4a3a79ec6907
  CMAKE_ARGS
    -DBUILD_UTILS=OFF
    -Dglew-cmake_BUILD_SHARED=OFF
    -Dglew-cmake_BUILD_STATIC=ON
    -DONLY_LIBS=ON
)
