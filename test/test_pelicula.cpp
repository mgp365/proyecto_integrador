#include <gtest/gtest.h>
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

TEST(PeliculaTest, MostrarInfoFiltrada_CalificacionIgual) {
    Pelicula peli(105, "Thriller", "Thriller", 2.2, 4.0);
    testing::internal::CaptureStdout();
    peli.mostrarInfoFiltrada(4.0, 4.0);
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_TRUE(output.empty());
}

TEST(PeliculaTest, OperadorSalida) {
    Pelicula peli(106, "Titanic", "Romance", 3.5, 4.4);
    std::ostringstream os;
    os << peli;
    std::string output = os.str();
    
    EXPECT_NE(output.find("Nombre: Titanic"), std::string::npos);
    EXPECT_NE(output.find("Género: Romance"), std::string::npos);
    EXPECT_NE(output.find("ID: 106"), std::string::npos);
    EXPECT_NE(output.find("Calificación: 4.4"), std::string::npos);
}

TEST(PeliculaTest, AgregarCalificacion) {
    Pelicula peli(107, "Test", "Acción", 2.0, 4.0);
    std::ostringstream archivo;
    peli.agregarCalificacion(6.0, archivo);
    EXPECT_DOUBLE_EQ(peli.obtenerCalificacion(), 5.0); // (4.0 + 6.0) / 2
}

TEST(PeliculaTest, FiltrarPorGenero_Drama) {
    Pelicula peli(108, "Película Drama", "Drama", 2.5, 4.3);
    testing::internal::CaptureStdout();
    peli.filtrarPorGenero("Drama");
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_NE(output.find("Nombre: Película Drama"), std::string::npos);
}

TEST(PeliculaTest, FiltrarPorGenero_NoCoincide) {
    Pelicula peli(109, "Acción", "Acción", 2.0, 4.1);
    testing::internal::CaptureStdout();
    peli.filtrarPorGenero("Drama");
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_TRUE(output.empty());
}
