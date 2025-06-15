#include <gtest/gtest.h>
#include <sstream>
#include "videos.h"
#include "pelicula.h"
#include "serie.h"

// Usamos las clases derivadas para probar la funcionalidad de la clase base Videos
// ya que Videos es una clase base con métodos virtuales

TEST(VideosTest, PolimorfismoObtenerCalificacion) {
    Videos* pelicula = new Pelicula(301, "Test Movie", "Acción", 2.0, 4.0);
    Videos* serie = new Serie(302, "Test Series", 3.5, "Thriller", 1.5, 3);
    
    EXPECT_DOUBLE_EQ(pelicula->obtenerCalificacion(), 4.0);
    EXPECT_DOUBLE_EQ(serie->obtenerCalificacion(), 3.5);
    
    delete pelicula;
    delete serie;
}

TEST(VideosTest, PolimorfismoObtenerTitulo) {
    Videos* pelicula = new Pelicula(303, "Película Test", "Drama", 2.5, 4.2);
    Videos* serie = new Serie(304, "Serie Test", 4.1, "Comedia", 1.0, 5);
    
    EXPECT_EQ(pelicula->obtenerTitulo(), "Película Test");
    EXPECT_EQ(serie->obtenerTitulo(), "Serie Test");
    
    delete pelicula;
    delete serie;
}

TEST(VideosTest, AgregarCalificacion_Pelicula) {
    Videos* pelicula = new Pelicula(305, "Test", "Acción", 2.0, 4.0);
    std::ostringstream archivo;
    
    pelicula->agregarCalificacion(6.0, archivo);
    EXPECT_DOUBLE_EQ(pelicula->obtenerCalificacion(), 5.0); // (4.0 + 6.0) / 2
    
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
    pelicula->mostrarInfoFiltrada(4.3, 4.0);
    std::string output = testing::internal::GetCapturedStdout();
    
    EXPECT_NE(output.find("Nombre: Filter Test"), std::string::npos);
    EXPECT_NE(output.find("Género: Horror"), std::string::npos);
    
    delete pelicula;
}

TEST(VideosTest, FiltrarPorGenero_Drama_Serie) {
    Videos* serie = new Serie(309, "Drama Series", 4.2, "Drama", 1.0, 4);
    
    testing::internal::CaptureStdout();
    serie->filtrarPorGenero("Drama");
    std::string output = testing::internal::GetCapturedStdout();
    
    EXPECT_NE(output.find("Nombre: Drama Series"), std::string::npos);
    EXPECT_NE(output.find("Género: Drama"), std::string::npos);
    
    delete serie;
}
