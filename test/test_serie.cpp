#include <gtest/gtest.h>
#include "serie.h"

TEST(SerieTest, Constructor) {
    Serie serie(201, "Breaking Bad", 4.9, "Drama", 1.0, 5);
    EXPECT_EQ(serie.obtenerTitulo(), "Breaking Bad");
    EXPECT_DOUBLE_EQ(serie.obtenerCalificacion(), 4.9);
    EXPECT_EQ(serie.obtenerEpisodio(), 5);
}

TEST(SerieTest, ObtenerCalificacion) {
    Serie serie(201, "Breaking Bad", 4.9, "Drama", 1.0, 5);
    EXPECT_DOUBLE_EQ(serie.obtenerCalificacion(), 4.9);
}

TEST(SerieTest, ObtenerEpisodio) {
    Serie serie(202, "Friends", 4.2, "Comedia", 0.5, 10);
    EXPECT_EQ(serie.obtenerEpisodio(), 10);
}

TEST(SerieTest, ObtenerSerie) {
    Serie serie(203, "Game of Thrones", 4.7, "Fantasía", 1.2, 8);
    EXPECT_EQ(serie.obtenerSerie(), "Game of Thrones");
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
