cmake_minimum_required(VERSION 3.15)
project(colors)

set(CMAKE_CXX_STANDARD 14)
find_package(SDL2 REQUIRED)

add_executable(colors main.cpp)

target_link_libraries(colors PRIVATE SDL2::SDL2)

install(TARGETS colors
        BUNDLE
            DESTINATION .
        RESOURCE
            DESTINATION $<TARGET_BUNDLE_CONTENT_DIR:colors>/Resources
        )

if(CMAKE_MACOSX_BUNDLE)
    target_sources(colors PRIVATE colors.icns)

    set_target_properties(colors PROPERTIES
            MACOSX_BUNDLE_ICON_FILE colors.icns
            MACOSX_BUNDLE_BUNDLE_NAME Colors
            RESOURCE colors.icns
        )

    set_source_files_properties(colors.icns PROPERTIES
            MACOSX_PACKAGE_LOCATION Resources
        )

    install(CODE [[
            include(BundleUtilities)
            copy_and_fixup_bundle($<TARGET_BUNDLE_DIR:colors> ${CMAKE_INSTALL_PREFIX}/colors.app "" "")
        ]])

endif()

include(cmake/CMakeCPack.cmake)
