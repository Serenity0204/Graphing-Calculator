cmake_minimum_required(VERSION 3.14 FATAL_ERROR) #FetchContent_MakeAvailable
project(Graphing-Calculator)

#. . . . . . . . . . . . . . . . . . . .
include(GNUInstallDirs)
if(MSVC)
    add_compile_options(/W4)
    add_link_options(/W4)
    set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_DEBUG ${CMAKE_BINARY_DIR}/bin)
    # message("compiler: MSVC")
else()
    # message("compiler: NOT MSVC")
    # add_compile_options(-Wall -Wextra -pedantic -Werror -Wl,--fatal-warnings)
    set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
endif()


# place binaries and libraries according to GNU standards
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/${CMAKE_INSTALL_LIBDIR})
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/${CMAKE_INSTALL_LIBDIR})



if(CMAKE_CXX_COMPILER_ID MATCHES GNU)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fprofile-arcs -ftest-coverage")
endif()


## for testing
option(BUILD_TESTS "Build tests" OFF)
if(BUILD_TESTS)
    #. . . . . . . . . . . . . . . . . . . .

    # ------------------------------------
    # ------------------------------------
    find_package(GTest QUIET)
    if (NOT ${GTest_FOUND}) # GTest not found, FetchContent!
        include(FetchContent)
        FetchContent_Declare(
            googletest
            GIT_REPOSITORY https://github.com/google/googletest.git
            GIT_TAG        v1.13.0)
        FetchContent_MakeAvailable(googletest)
    endif()

    # ------------------------------------
    # ------------------------------------
endif() 

# GoogleTest requires at least C++14
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


set(SFML_VERSION "2.6.0")
# Declare SFML as an external project
include(FetchContent)
FetchContent_Declare(
  sfml
  URL https://www.sfml-dev.org/files/SFML-${SFML_VERSION}-sources.zip
)

# Build SFML as part of the project
FetchContent_MakeAvailable(sfml)

# Set the C++ standard for SFML
target_compile_features(sfml-graphics PUBLIC cxx_std_11)
target_compile_features(sfml-window PUBLIC cxx_std_11)
target_compile_features(sfml-system PUBLIC cxx_std_11)


#- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
#   Grab all cpp files from includes folder
#- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
set(INCLUDES_FOLDER includes)
FILE(GLOB_RECURSE SOURCE_FILES RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} CONFIGURE_DEPENDS "${INCLUDES_FOLDER}/*.cpp")
#- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - 


ADD_EXECUTABLE(main
    main.cpp
    ${SOURCE_FILES}
)




## Not visible for non testing
if(BUILD_TESTS)
    ## testing exe
    ADD_EXECUTABLE(test_shunting_yard_and_rpn
    _tests/_test_files/test_shunting_yard_and_rpn.cpp
    ${SOURCE_FILES}
    )

    ADD_EXECUTABLE(test_tokenizer_shunting_yard
    _tests/_test_files/test_tokenizer_shunting_yard.cpp
    ${SOURCE_FILES}
    )

    ADD_EXECUTABLE(test_input
    _tests/_test_files/test_input.cpp
    ${SOURCE_FILES}
    )

    ADD_EXECUTABLE(test_lru
    _tests/_test_files/test_lru.cpp
    ${SOURCE_FILES}
    )
    ## gtest
    TARGET_LINK_LIBRARIES(test_shunting_yard_and_rpn GTest::gtest_main)
    TARGET_LINK_LIBRARIES(test_input GTest::gtest_main)
    TARGET_LINK_LIBRARIES(test_tokenizer_shunting_yard GTest::gtest_main)
    TARGET_LINK_LIBRARIES(test_lru GTest::gtest_main)
    TARGET_LINK_LIBRARIES(main GTest::gtest_main)
    ## sfml
    TARGET_LINK_LIBRARIES(test_shunting_yard_and_rpn sfml-graphics sfml-window sfml-system)
    TARGET_LINK_LIBRARIES(test_input sfml-graphics sfml-window sfml-system)
    TARGET_LINK_LIBRARIES(test_tokenizer_shunting_yard sfml-graphics sfml-window sfml-system)
    TARGET_LINK_LIBRARIES(test_lru sfml-graphics sfml-window sfml-system)
endif() 

## main
TARGET_LINK_LIBRARIES(main sfml-graphics sfml-window sfml-system)


## copy resources file to build
file(COPY assets DESTINATION ${CMAKE_BINARY_DIR}/bin)



## for other cmake files to install
add_library(Graphing-Calculator ${SOURCE_FILES})
target_include_directories(Graphing-Calculator PUBLIC 
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/includes>
    $<INSTALL_INTERFACE:include>  # <prefix>/include
)

target_link_libraries(Graphing-Calculator PUBLIC sfml-graphics sfml-window sfml-system)

# Install library target
install(TARGETS Graphing-Calculator
    EXPORT Graphing-CalculatorTargets
    LIBRARY DESTINATION lib
    ARCHIVE DESTINATION lib
    RUNTIME DESTINATION bin
    INCLUDES DESTINATION include
)

# This makes project importable from the install directory
# Put config file into the CMake user package registry
install(EXPORT Graphing-CalculatorTargets
    FILE Graphing-CalculatorTargets.cmake
    NAMESPACE Graphing-Calculator::
    DESTINATION lib/cmake/Graphing-Calculator
)

# This makes project importable from the build directory
export(TARGETS Graphing-Calculator
    NAMESPACE Graphing-Calculator::
    FILE ${CMAKE_CURRENT_BINARY_DIR}/Graphing-Calculator.cmake
)
