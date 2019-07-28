cmake_minimum_required(VERSION 3.15)
project(packme)

set(CMAKE_CXX_STANDARD 14)
find_package(SDL2 REQUIRED)

add_executable(packme main.cpp)

target_link_libraries(packme PRIVATE SDL2::SDL2)

install(TARGETS packme
        BUNDLE
            DESTINATION .
        RESOURCE
            DESTINATION $<TARGET_BUNDLE_CONTENT_DIR:packme>/Resources
        )

if(CMAKE_MACOSX_BUNDLE)
    target_sources(packme PRIVATE packme.icns)

    set_target_properties(packme PROPERTIES
            MACOSX_BUNDLE_ICON_FILE packme.icns
            RESOURCE packme.icns
        )

    set_source_files_properties(packme.icns PROPERTIES
            MACOSX_PACKAGE_LOCATION Resources
        )

    install(CODE [[
            include(BundleUtilities)
            copy_and_fixup_bundle($<TARGET_BUNDLE_DIR:packme> ${CMAKE_INSTALL_PREFIX}/packme.app "" "")
        ]])

endif()

include(cmake/CMakeCPack.cmake)
