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

# TESTING - TRES ARCHIVOS DE PRUEBA
if(ENABLE_TESTING)
    enable_testing()
    
    # Test ejecutable para Pelicula
    add_executable(test_pelicula 
        test/test_pelicula.cpp
        videos.cpp
        pelicula.cpp
        serie.cpp
    )
    
    target_link_libraries(test_pelicula gtest gtest_main)
    
    if (ENABLE_COVERAGE)
        target_link_libraries(test_pelicula gcov)
        target_compile_options(test_pelicula PRIVATE --coverage -fprofile-arcs -ftest-coverage)
        target_link_options(test_pelicula PRIVATE --coverage)
    endif()
    
    add_test(NAME PeliculaTests COMMAND test_pelicula)
    
    # Test ejecutable para Serie
    add_executable(test_serie 
        test/test_serie.cpp
        videos.cpp
        pelicula.cpp
        serie.cpp
    )
    
    target_link_libraries(test_serie gtest gtest_main)
    
    if (ENABLE_COVERAGE)
        target_link_libraries(test_serie gcov)
        target_compile_options(test_serie PRIVATE --coverage -fprofile-arcs -ftest-coverage)
        target_link_options(test_serie PRIVATE --coverage)
    endif()
    
    add_test(NAME SerieTests COMMAND test_serie)
    
    # Test ejecutable para Videos (clase base)
    add_executable(test_videos 
        test/test_videos.cpp
        videos.cpp
        pelicula.cpp
        serie.cpp
    )
    
    target_link_libraries(test_videos gtest gtest_main)
    
    if (ENABLE_COVERAGE)
        target_link_libraries(test_videos gcov)
        target_compile_options(test_videos PRIVATE --coverage -fprofile-arcs -ftest-coverage)
        target_link_options(test_videos PRIVATE --coverage)
    endif()
    
    add_test(NAME VideosTests COMMAND test_videos)
    
    # Test ejecutable combinado (opcional - ejecuta todas las pruebas juntas)
    add_executable(test_all 
        test/test_pelicula.cpp
        test/test_serie.cpp
        test/test_videos.cpp
        videos.cpp
        pelicula.cpp
        serie.cpp
    )
    
    target_link_libraries(test_all gtest gtest_main)
    
    if (ENABLE_COVERAGE)
        target_link_libraries(test_all gcov)
        target_compile_options(test_all PRIVATE --coverage -fprofile-arcs -ftest-coverage)
        target_link_options(test_all PRIVATE --coverage)
    endif()
    
    add_test(NAME AllTests COMMAND test_all)
    
    # Generar reportes de cobertura
    if (ENABLE_COVERAGE)
        find_program(LCOV lcov)
        if (LCOV)
            add_custom_target(coverage
                COMMAND lcov --capture --directory . --output-file coverage.info
                COMMAND genhtml coverage.info --output-directory coverage_html
                COMMAND echo "Coverage report generated in coverage_html/index.html"
                COMMENT "Generating code coverage report"
                VERBATIM
                DEPENDS test_pelicula test_serie test_videos
            )
            
            # Target para limpiar archivos de cobertura
            add_custom_target(coverage_clean
                COMMAND find . -name "*.gcda" -delete
                COMMAND find . -name "*.gcno" -delete
                COMMAND rm -rf coverage.info coverage_html
                COMMENT "Cleaning coverage files"
            )
            
            # Target para ejecutar todas las pruebas y generar cobertura
            add_custom_target(test_coverage
                COMMAND ${CMAKE_CTEST_COMMAND} --verbose
                COMMAND ${CMAKE_COMMAND} --build . --target coverage
                COMMENT "Running all tests and generating coverage report"
                DEPENDS test_pelicula test_serie test_videos
            )
        else()
            message(WARNING "LCOV not found, coverage reporting will not be available")
        endif()
    endif()
    
    # Información útil
    message(STATUS "Testing enabled with the following targets:")
    message(STATUS "  - test_pelicula: Tests for Pelicula class")
    message(STATUS "  - test_serie: Tests for Serie class") 
    message(STATUS "  - test_videos: Tests for Videos base class")
    message(STATUS "  - test_all: All tests combined")
    if (ENABLE_COVERAGE)
        message(STATUS "Coverage targets:")
        message(STATUS "  - coverage: Generate coverage report")
        message(STATUS "  - coverage_clean: Clean coverage files")
        message(STATUS "  - test_coverage: Run tests + generate coverage")
    endif()
endif()
