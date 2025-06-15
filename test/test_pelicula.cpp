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

TEST(SerieTest, GuardarEnArchivo) {
    Serie serie(205, "The Office", 4.1, "Comedia", 0.5, 9);
    std::ostringstream archivo;
    serie.guardarEnArchivo(archivo);
    std::string contenido = archivo.str();
    
    EXPECT_NE(contenido.find("205"), std::string::npos);
    EXPECT_NE(contenido.find("The Office"), std::string::npos);
    EXPECT_NE(contenido.find("9"), std::string::npos);
    EXPECT_NE(contenido.find("Comedia"), std::string::npos);
    EXPECT_NE(contenido.find("0.5"), std::string::npos);
    EXPECT_NE(contenido.find("4.1"), std::string::npos);
}
