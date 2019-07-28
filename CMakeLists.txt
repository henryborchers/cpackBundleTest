cmake_minimum_required(VERSION 3.15)
project(packme)

set(CMAKE_CXX_STANDARD 14)
find_package(SDL2 REQUIRED)
add_executable(packme main.cpp)
target_link_libraries(packme PRIVATE SDL2::SDL2)

install(TARGETS packme
        BUNDLE
            DESTINATION bin
        )

if(CMAKE_MACOSX_BUNDLE)
    install(CODE "
        include(BundleUtilities)
        fixup_bundle($<TARGET_BUNDLE_DIR:packme> \"\" \"\")
    ")
endif()
