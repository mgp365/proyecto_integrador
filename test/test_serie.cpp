#include <gtest/gtest.h>
#include "serie.h"

TEST(SerieTest, Constructor) {
    Serie serie(201, "Breaking Bad", 4.9, "Drama", 1.0, 5);
    EXPECT_EQ(serie.ObtenerTitulo(), "Breaking Bad");
    EXPECT_DOUBLE_EQ(serie.ObtenerCalificacion(), 4.9);
    EXPECT_EQ(serie.ObtenerEpisodio(), 5);
}

TEST(SerieTest, ObtenerCalificacion) {
    Serie serie(201, "Breaking Bad", 4.9, "Drama", 1.0, 5);
    EXPECT_DOUBLE_EQ(serie.ObtenerCalificacion(), 4.9);
}

TEST(SerieTest, ObtenerEpisodio) {
    Serie serie(202, "Friends", 4.2, "Comedia", 0.5, 10);
    EXPECT_EQ(serie.ObtenerEpisodio(), 10);
}

TEST(SerieTest, ObtenerSerie) {
    Serie serie(203, "Game of Thrones", 4.7, "Fantasía", 1.2, 8);
    EXPECT_EQ(serie.ObtenerSerie(), "Game of Thrones");
}

TEST(SerieTest, GuardarEnArchivo) {
    Serie serie(205, "The Office", 4.1, "Comedia", 0.5, 9);
    std::ostringstream archivo;
    serie.GuardarEnArchivo(archivo);
    std::string contenido = archivo.str();
    
    EXPECT_NE(contenido.find("205"), std::string::npos);
    EXPECT_NE(contenido.find("The Office"), std::string::npos);
    EXPECT_NE(contenido.find("9"), std::string::npos);
    EXPECT_NE(contenido.find("Comedia"), std::string::npos);
    EXPECT_NE(contenido.find("0.5"), std::string::npos);
    EXPECT_NE(contenido.find("4.1"), std::string::npos);
}

TEST(SerieTest, MostrarInfoFiltrada_CalificacionMayor) {
    Serie serie(206, "Breaking Bad", 4.9, "Drama", 1.0, 5);
    testing::internal::CaptureStdout();
    serie.MostrarInfoFiltrada(4.9, 4.5);
    std::string output = testing::internal::GetCapturedStdout();
    
    EXPECT_NE(output.find("Nombre: Breaking Bad"), std::string::npos);
    EXPECT_NE(output.find("Número de episodio: 5"), std::string::npos);
    EXPECT_NE(output.find("Género: Drama"), std::string::npos);
    EXPECT_NE(output.find("ID: 206"), std::string::npos);
    EXPECT_NE(output.find("Calificación: 4.9"), std::string::npos);
}

TEST(SerieTest, MostrarInfoFiltrada_CalificacionMenor) {
    Serie serie(207, "Serie Baja", 3.5, "Drama", 1.0, 2);
    testing::internal::CaptureStdout();
    serie.MostrarInfoFiltrada(3.5, 4.0);
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_TRUE(output.empty());
}

TEST(SerieTest, OperadorSalida) {
    Serie serie(209, "House of Cards", 4.3, "Thriller", 1.0, 3);
    std::ostringstream os;
    os << serie;
    std::string output = os.str();
    
    EXPECT_NE(output.find("Nombre: House of Cards"), std::string::npos);
    EXPECT_NE(output.find("Género: Thriller"), std::string::npos);
    EXPECT_NE(output.find("ID: 209"), std::string::npos);
    EXPECT_NE(output.find("Calificación: 4.3"), std::string::npos);
    EXPECT_NE(output.find("Episodio: 3"), std::string::npos);
}

TEST(SerieTest, AgregarCalificacion) {
    Serie serie(210, "Test Serie", 4.0, "Drama", 1.0, 1);
    std::ostringstream archivo;
    serie.AgregarCalificacion(6.0, archivo);
    EXPECT_DOUBLE_EQ(serie.ObtenerCalificacion(), 5.0); // (4.0 + 6.0) / 2
}

TEST(SerieTest, EpisodiosCero) {
    Serie serie(213, "Nueva Serie", 3.8, "Sci-Fi", 1.5, 0);
    EXPECT_EQ(serie.ObtenerEpisodio(), 0);
}

TEST(SerieTest, EpisodiosNegativos) {
    Serie serie(214, "Serie Negativa", 4.0, "Horror", 1.0, -1);
    EXPECT_EQ(serie.ObtenerEpisodio(), -1);
}

TEST(SerieTest, MostrarInfoFiltrada_CalificacionIgual) {
    Serie serie(208, "Serie Igual", 4.0, "Acción", 1.2, 6);
    testing::internal::CaptureStdout();
    serie.MostrarInfoFiltrada(4.0, 4.0);
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_TRUE(output.empty());
}
