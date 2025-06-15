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
