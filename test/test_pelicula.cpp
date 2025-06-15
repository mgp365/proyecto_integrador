#include <gtest/gtest.h>
#include <sstream>
#include "pelicula.h"

TEST(PeliculaTest, Constructor) {
    Pelicula peli(101, "Interestelar", "Sci-Fi", 2.5, 4.5);
    EXPECT_EQ(peli.obtenerTitulo(), "Interestelar");
    EXPECT_DOUBLE_EQ(peli.obtenerCalificacion(), 4.5);
}

TEST(PeliculaTest, ObtenerCalificacion) {
    Pelicula peli(101, "Interestelar", "Sci-Fi", 2.5, 4.5);
    EXPECT_DOUBLE_EQ(peli.obtenerCalificacion(), 4.5);
}

TEST(PeliculaTest, ObtenerTitulo) {
    Pelicula peli(102, "El Padrino", "Drama", 3.0, 4.8);
    EXPECT_EQ(peli.obtenerTitulo(), "El Padrino");
}

TEST(PeliculaTest, MostrarInfoFiltrada_CalificacionMayor) {
    Pelicula peli(102, "Drama", "Drama", 2.0, 4.2);
    testing::internal::CaptureStdout();
    peli.mostrarInfoFiltrada(4.2, 4.0);
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_NE(output.find("Nombre: Drama"), std::string::npos);
    EXPECT_NE(output.find("Género: Drama"), std::string::npos);
    EXPECT_NE(output.find("ID: 102"), std::string::npos);
}

TEST(PeliculaTest, MostrarInfoFiltrada_CalificacionMenor) {
    Pelicula peli(104, "Comedia", "Comedia", 1.5, 3.0);
    testing::internal::CaptureStdout();
    peli.mostrarInfoFiltrada(3.0, 4.0);
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_TRUE(output.empty());
}

TEST(PeliculaTest, GuardarEnArchivo) {
    Pelicula peli(103, "Avatar", "Sci-Fi", 3.2, 4.6);
    std::ostringstream archivo;
    peli.guardarEnArchivo(archivo);
    std::string contenido = archivo.str();
    
    EXPECT_NE(contenido.find("103"), std::string::npos);
    EXPECT_NE(contenido.find("Avatar"), std::string::npos);
    EXPECT_NE(contenido.find("Sci-Fi"), std::string::npos);
    EXPECT_NE(contenido.find("3.2"), std::string::npos);
    EXPECT_NE(contenido.find("4.6"), std::string::npos);
}

TEST(PeliculaTest, FiltrarPorGenero_Drama) {
    Pelicula peli(108, "Película Drama", "Drama", 2.5, 4.3);
    testing::internal::CaptureStdout();
    peli.filtrarPorGenero("Drama");
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_NE(output.find("Nombre: Película Drama"), std::string::npos);
}

TEST(PeliculaTest, OperadorInsercion) {
    std::ostringstream os;
    Pelicula peli(777, "Gladiator", "Acción", 2.5, 4.6);
    
    os << peli;
    
    std::string output = os.str();
    EXPECT_TRUE(output.find("Gladiator") != std::string::npos);
    EXPECT_TRUE(output.find("Acción") != std::string::npos);
    EXPECT_TRUE(output.find("777") != std::string::npos);
    EXPECT_TRUE(output.find("4.6") != std::string::npos);
}
