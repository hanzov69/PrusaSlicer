
set(_context_abi_line "")
set(_context_arch_line "")
if (APPLE AND CMAKE_OSX_ARCHITECTURES)
    if (CMAKE_OSX_ARCHITECTURES MATCHES "x86")
        set(_context_abi_line "-DBOOST_CONTEXT_ABI:STRING=sysv")
    elseif (CMAKE_OSX_ARCHITECTURES MATCHES "arm")
        set (_context_abi_line "-DBOOST_CONTEXT_ABI:STRING=aapcs")
    endif ()
    set(_context_arch_line "-DBOOST_CONTEXT_ARCHITECTURE:STRING=${CMAKE_OSX_ARCHITECTURES}")
endif ()

# Boost 1.83's CMake mis-selects the 32-bit `armasm` assembler when targeting
# Windows ARM64 (should be `armasm64`). PrusaSlicer does not use boost::context,
# so exclude context (and the libs that pull it in) on Windows ARM64.
set(_extra_excludes "")
if (MSVC AND CMAKE_GENERATOR_PLATFORM STREQUAL "ARM64")
    set(_extra_excludes "|context|coroutine|coroutine2")
endif ()

add_cmake_project(Boost
    URL "https://github.com/boostorg/boost/releases/download/boost-1.83.0/boost-1.83.0.zip"
    URL_HASH SHA256=9effa3d7f9d92b8e33e2b41d82f4358f97ff7c588d5918720339f2b254d914c6
    LIST_SEPARATOR |
    CMAKE_ARGS
        "-DBOOST_EXCLUDE_LIBRARIES:STRING=contract|fiber|numpy|stacktrace|wave|test${_extra_excludes}"
        -DBOOST_LOCALE_ENABLE_ICU:BOOL=OFF # do not link to libicu, breaks compatibility between distros
        -DBUILD_TESTING:BOOL=OFF
        -DBOOST_IOSTREAMS_ENABLE_ZSTD:BOOL=OFF
        "${_context_abi_line}"
        "${_context_arch_line}"
)

set(DEP_Boost_DEPENDS ZLIB)
