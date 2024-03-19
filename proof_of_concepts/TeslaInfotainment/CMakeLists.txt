cmake_minimum_required(VERSION 3.16)

project(TeslaInfotainment VERSION 0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 6.4 REQUIRED COMPONENTS Quick positioning location)

qt_standard_project_setup()

qt_add_executable(appTeslaInfotainment
    main.cpp
)

qt_add_qml_module(appTeslaInfotainment
    URI TeslaInfotainment
    VERSION 1.0
    QML_FILES Main.qml
    QML_FILES ui/BottomBar/BottomBar.qml
    QML_FILES ui/RightScreen/RightScreen.qml
    QML_FILES ui/LeftScreen/LeftScreen.qml

    QML_FILES ui/assets/carRender.png
    QML_FILES ui/assets/carIcon.png
    QML_FILES ui/assets/locked.png
    QML_FILES ui/assets/unlocked.png
    QML_FILES ui/assets/search.png
    QML_FILES ui/assets/volume1.png
    QML_FILES ui/assets/volume2.png
    QML_FILES ui/assets/volume3.png
    QML_FILES ui/assets/mute.png

    SOURCES controllers/system.h controllers/system.cpp
    QML_FILES ui/RightScreen/NavigationSearchBox.qml
    SOURCES controllers/hvachandler.h controllers/hvachandler.cpp
    QML_FILES ui/BottomBar/HVACComponent.qml
    SOURCES controllers/audiocontroller.h controllers/audiocontroller.cpp
    QML_FILES ui/BottomBar/VolumeControlComponent.qml
)

# Qt for iOS sets MACOSX_BUNDLE_GUI_IDENTIFIER automatically since Qt 6.1.
# If you are developing for iOS or macOS you should consider setting an
# explicit, fixed bundle identifier manually though.
set_target_properties(appTeslaInfotainment PROPERTIES
#    MACOSX_BUNDLE_GUI_IDENTIFIER com.example.appTeslaInfotainment
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

target_link_libraries(appTeslaInfotainment
    PRIVATE Qt6::Quick
)

include(GNUInstallDirs)
install(TARGETS appTeslaInfotainment
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
