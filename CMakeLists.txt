cmake_minimum_required(VERSION 3.30)
project(sonarqube_unit_test VERSION 1.0.0 LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

include_directories(${CMAKE_SOURCE_DIR})

# Archivos fuente principales
set(SOURCES
    main.cpp
    videos.cpp
    pelicula.cpp
    serie.cpp
)

# Crear el ejecutable principal
add_executable(main ${SOURCES})

# Opciones
option(ENABLE_TESTING "Enable a Unit Testing build." ON)
option(ENABLE_COVERAGE "Enable coverage reporting" ON)

# Si se habilita la cobertura, establecer flags
if (ENABLE_COVERAGE)
    message(STATUS "Enabling coverage flags for GCC/Clang")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} --coverage -fprofile-arcs -ftest-coverage")
    set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} --coverage")
endif()

# Descarga GoogleTest
include(FetchContent)
FetchContent_Declare(
    googletest
    GIT_REPOSITORY https://github.com/google/googletest.git
    GIT_TAG release-1.11.0
)
FetchContent_MakeAvailable(googletest)

# TESTING - SOLUCION DIRECTA
if(ENABLE_TESTING)
    enable_testing()
    
    # Test ejecutable
    add_executable(test_pelicula1 
        test/test_pelicula1.cpp
        videos.cpp
        pelicula.cpp
        serie.cpp
    )
    
    target_link_libraries(test_pelicula1 gtest gtest_main)
    
    if (ENABLE_COVERAGE)
        target_link_libraries(test_pelicula1 gcov)
        target_compile_options(test_pelicula1 PRIVATE --coverage -fprofile-arcs -ftest-coverage)
        target_link_options(test_pelicula1 PRIVATE --coverage)
    endif()
    
    add_test(NAME test_pelicula1 COMMAND test_pelicula1)
    
    # Generar reportes de cobertura
    if (ENABLE_COVERAGE)
        find_program(LCOV lcov)
        if (LCOV)
            add_custom_target(coverage
                COMMAND lcov --capture --directory . --output-file build/coverage.info
                COMMAND genhtml build/coverage.info --output-directory build/coverage_html
                COMMENT "Generating code coverage report"
                VERBATIM
            )
        else()
            message(WARNING "LCOV not found, coverage reporting will not be available")
        endif()
    endif()
endif()
