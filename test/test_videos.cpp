#include <gtest/gtest.h>
#include <sstream>
#include "videos.h"
#include "pelicula.h"
#include "serie.h"

TEST(VideosTest, PolimorfismoObtenerCalificacion) {
    Videos* pelicula = new Pelicula(301, "Test Movie", "Acción", 2.0, 4.0);
    Videos* serie = new Serie(302, "Test Series", 3.5, "Thriller", 1.5, 3);
    
    EXPECT_DOUBLE_EQ(pelicula->ObtenerCalificacion(), 4.0);
    EXPECT_DOUBLE_EQ(serie->ObtenerCalificacion(), 3.5);
    
    delete pelicula;
    delete serie;
}

TEST(VideosTest, PolimorfismoObtenerTitulo) {
    Videos* pelicula = new Pelicula(303, "Película Test", "Drama", 2.5, 4.2);
    Videos* serie = new Serie(304, "Serie Test", 4.1, "Comedia", 1.0, 5);
    
    EXPECT_EQ(pelicula->ObtenerTitulo(), "Película Test");
    EXPECT_EQ(serie->ObtenerTitulo(), "Serie Test");
    
    delete pelicula;
    delete serie;
}

TEST(VideosTest, AgregarCalificacion_Pelicula) {
    Videos* pelicula = new Pelicula(305, "Test", "Acción", 2.0, 4.0);
    std::ostringstream archivo;
    
    pelicula->AgregarCalificacion(6.0, archivo);
    EXPECT_DOUBLE_EQ(pelicula->ObtenerCalificacion(), 5.0); // (4.0 + 6.0) / 2
    
    delete pelicula;
}

TEST(VideosTest, DestructorVirtual) {
    Videos* videos[] = {
        new Pelicula(317, "Destructor Test 1", "Comedy", 1.9, 3.5),
        new Serie(318, "Destructor Test 2", 4.1, "Action", 1.4, 5)
    };
    
    for (int i = 0; i < 2; i++) {
        delete videos[i];
    }
    EXPECT_TRUE(true);
}

TEST(VideosTest, MostrarInfoFiltrada_Pelicula) {
    Videos* pelicula = new Pelicula(311, "Filter Test", "Horror", 1.8, 4.3);
    
    testing::internal::CaptureStdout();
    pelicula->MostrarInfoFiltrada(4.3, 4.0);
    std::string output = testing::internal::GetCapturedStdout();
    
    EXPECT_NE(output.find("Nombre: Filter Test"), std::string::npos);
    EXPECT_NE(output.find("Género: Horror"), std::string::npos);
    
    delete pelicula;
}

TEST(VideosTest, FiltrarPorGenero_Drama_Serie) {
    Videos* serie = new Serie(309, "Drama Series", 4.2, "Drama", 1.0, 4);
    
    testing::internal::CaptureStdout();
    serie->FiltrarPorGenero("Drama");
    std::string output = testing::internal::GetCapturedStdout();
    
    EXPECT_NE(output.find("Nombre: Drama Series"), std::string::npos);
    EXPECT_NE(output.find("Género: Drama"), std::string::npos);
    
    delete serie;
}

TEST(VideosTest, FiltrarPorGenero_Drama_Pelicula) {
    Videos* pelicula = new Pelicula(308, "Drama Movie", "Drama", 2.0, 4.5);
    
    testing::internal::CaptureStdout();
    pelicula->FiltrarPorGenero("Drama");
    std::string output = testing::internal::GetCapturedStdout();
    
    EXPECT_NE(output.find("Nombre: Drama Movie"), std::string::npos);
    EXPECT_NE(output.find("Género: Drama"), std::string::npos);
    
    delete pelicula;
}

TEST(VideosTest, AgregarCalificacion_Multiple) {
    Videos* video = new Pelicula(307, "Multi Test", "Sci-Fi", 2.2, 2.0);
    std::ostringstream archivo;
    
    video->AgregarCalificacion(4.0, archivo); // (2.0 + 4.0) / 2 = 3.0
    video->AgregarCalificacion(6.0, archivo); // (3.0 + 6.0) / 2 = 4.5
    
    EXPECT_DOUBLE_EQ(video->ObtenerCalificacion(), 4.5);
    
    delete video;
}

TEST(VideosTest, OperadorSalida_DistincionTipos) {
    Videos* pelicula = new Pelicula(315, "Output Movie", "Western", 2.4, 4.0);
    Videos* serie = new Serie(316, "Output Series", 3.8, "Mystery", 1.1, 7);
    
    std::ostringstream osPeli, osSerie;
    
    osPeli << *pelicula;
    osSerie << *serie;
    
    std::string outputPeli = osPeli.str();
    std::string outputSerie = osSerie.str();
    
    // Película no debe tener información de episodio
    EXPECT_EQ(outputPeli.find("Episodio:"), std::string::npos);
    
    // Serie debe tener información de episodio
    EXPECT_NE(outputSerie.find("Episodio:"), std::string::npos);
    EXPECT_NE(outputSerie.find("7"), std::string::npos);
    
    delete pelicula;
    delete serie;
}

TEST(VideosTest, GuardarEnArchivo_Polimorfismo) {
    Videos* pelicula = new Pelicula(313, "Save Test", "Romance", 2.1, 3.9);
    Videos* serie = new Serie(314, "Save Serie", 4.4, "Fantasy", 1.3, 8);
    
    std::ostringstream archivoPeli, archivoSerie;
    
    pelicula->GuardarEnArchivo(archivoPeli);
    serie->GuardarEnArchivo(archivoSerie);
    
    std::string contenidoPeli = archivoPeli.str();
    std::string contenidoSerie = archivoSerie.str();
    
    // Verificar contenido de película
    EXPECT_NE(contenidoPeli.find("313"), std::string::npos);
    EXPECT_NE(contenidoPeli.find("Save Test"), std::string::npos);
    
    // Verificar contenido de serie (incluye episodio)
    EXPECT_NE(contenidoSerie.find("314"), std::string::npos);
    EXPECT_NE(contenidoSerie.find("Save Serie"), std::string::npos);
    EXPECT_NE(contenidoSerie.find("8"), std::string::npos);
    
    delete pelicula;
    delete serie;
}

TEST(VideosTest, MostrarInfoFiltrada_Serie) {
    Videos* serie = new Serie(312, "Serie Filter", 4.6, "Thriller", 1.2, 6);
    
    testing::internal::CaptureStdout();
    serie->MostrarInfoFiltrada(4.6, 4.0);
    std::string output = testing::internal::GetCapturedStdout();
    
    EXPECT_NE(output.find("Nombre: Serie Filter"), std::string::npos);
    EXPECT_NE(output.find("Número de episodio: 6"), std::string::npos);
    
    delete serie;
}

TEST(VideosTest, Constructor) {
    Videos video(101, "Avatar", "Acción", 2.5, 4.8);
    EXPECT_EQ(video.ObtenerTitulo(), "Avatar");
    EXPECT_DOUBLE_EQ(video.ObtenerCalificacion(), 4.8);
}

TEST(VideosTest, AgregarCalificacion) {
    std::ostringstream archivo;
    Videos video(1, "Titanic", "Romance", 3.2, 4.0);
    
    video.AgregarCalificacion(5.0, archivo);
    EXPECT_DOUBLE_EQ(video.ObtenerCalificacion(), 4.5); // (4.0 + 5.0) / 2
}

TEST(VideosTest, MostrarInfoFiltrada_Mayor) {
    std::ostringstream buffer;
    std::streambuf* old = std::cout.rdbuf(buffer.rdbuf());
    
    Videos video(123, "Avengers", "Acción", 2.5, 4.8);
    video.MostrarInfoFiltrada(4.8, 4.5); // calif > c
    
    std::cout.rdbuf(old);
    
    std::string output = buffer.str();
    EXPECT_TRUE(output.find("Avengers") != std::string::npos);
    EXPECT_TRUE(output.find("Acción") != std::string::npos);
    EXPECT_TRUE(output.find("123") != std::string::npos);
    EXPECT_TRUE(output.find("4.8") != std::string::npos);
}

TEST(VideosTest, MostrarInfoFiltrada_Menor) {
    std::ostringstream buffer;
    std::streambuf* old = std::cout.rdbuf(buffer.rdbuf());
    
    Videos video(456, "Batman", "Acción", 2.2, 3.5);
    video.MostrarInfoFiltrada(3.5, 4.0);
    
    std::cout.rdbuf(old);
    
    std::string output = buffer.str();
    EXPECT_TRUE(output.empty());
}

TEST(VideosTest, FiltrarPorGenero_Drama) {
    std::ostringstream buffer;
    std::streambuf* old = std::cout.rdbuf(buffer.rdbuf());
    
    Videos video(789, "Forrest Gump", "Drama", 2.3, 4.9);
    video.FiltrarPorGenero("Drama");
    
    std::cout.rdbuf(old);
    
    std::string output = buffer.str();
    EXPECT_TRUE(output.find("Forrest Gump") != std::string::npos);
    EXPECT_TRUE(output.find("Drama") != std::string::npos);
    EXPECT_TRUE(output.find("789") != std::string::npos);
    EXPECT_TRUE(output.find("4.9") != std::string::npos);
}

TEST(VideosTest, OperadorInsercion) {
    std::ostringstream os;
    Videos video(555, "Pulp Fiction", "Drama", 2.6, 4.7);
    
    os << video;
    
    std::string output = os.str();
    EXPECT_TRUE(output.find("Pulp Fiction") != std::string::npos);
    EXPECT_TRUE(output.find("Drama") != std::string::npos);
    EXPECT_TRUE(output.find("555") != std::string::npos);
    EXPECT_TRUE(output.find("4.7") != std::string::npos);
}
