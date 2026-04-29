if (MSVC AND CMAKE_GENERATOR_PLATFORM STREQUAL "ARM64")
    # GMP/MPFR ship as x86-64 prebuilts in deps/+GMP and deps/+MPFR, so we
    # cannot link CGAL against them on ARM64. CGAL 5.4+ exposes
    # CGAL_DISABLE_GMP which makes CGAL header-only via Boost.Multiprecision
    # (slower numerics but functionally equivalent — adequate for PoC).
    set(_cgal_extra_args -DCGAL_DISABLE_GMP:BOOL=ON -DWITH_CGAL_Qt5:BOOL=OFF)
    set(_cgal_depends Boost)
else ()
    set(_cgal_extra_args "")
    set(_cgal_depends Boost GMP MPFR)
endif ()

add_cmake_project(
    CGAL
    URL      https://github.com/CGAL/cgal/archive/refs/tags/v5.6.2.zip
    URL_HASH SHA256=29acaeee5a76a95029fac23131bb1c3a4a75df9a0e7e43b465a1f32d0628f45d
    CMAKE_ARGS
        ${_cgal_extra_args}
)

include(GNUInstallDirs)

set(DEP_CGAL_DEPENDS ${_cgal_depends})
