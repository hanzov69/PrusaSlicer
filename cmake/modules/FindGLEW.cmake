set(_q "")
if(GLEW_FIND_QUIETLY)
    set(_q QUIET)
endif()
find_package(GLEW ${GLEW_FIND_VERSION} CONFIG ${_q})

if(NOT GLEW_FIND_QUIETLY)
    if (NOT GLEW_FOUND)
        message(STATUS "Falling back to MODULE search for GLEW...")
    else()
        message(STATUS "GLEW found in ${GLEW_DIR}")
    endif()
endif()

if (NOT GLEW_FOUND)
    set(_modpath ${CMAKE_MODULE_PATH})
    set(CMAKE_MODULE_PATH "")
    include(FindGLEW)
    set(CMAKE_MODULE_PATH ${_modpath})
endif()

# Some GLEW packages (e.g. the glew-cmake fork) export their targets under
# different names. Ensure the canonical GLEW::GLEW imported target exists for
# downstream consumers.
if (GLEW_FOUND AND NOT TARGET GLEW::GLEW)
    foreach(_glew_alt libglew_static libglew_shared glew_s glew
                      glew::glew_s glew::glew
                      libglew::libglew_static libglew::libglew_shared)
        if (TARGET ${_glew_alt})
            add_library(GLEW::GLEW ALIAS ${_glew_alt})
            if(NOT GLEW_FIND_QUIETLY)
                message(STATUS "Aliased GLEW::GLEW -> ${_glew_alt}")
            endif()
            break()
        endif()
    endforeach()
endif()