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

