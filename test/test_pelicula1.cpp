#include <gtest/gtest.h>
#include "pelicula.h"

TEST(PeliculaTest, ObtenerCalificacion) {
    Pelicula peli(101, "Interestelar", "Sci-Fi", 2.5, 4.5);
    EXPECT_DOUBLE_EQ(peli.obtenerCalificacion(), 4.5);
}

//TEST(PeliculaTest, MostrarInfoFiltrada) {
//    Pelicula peli(102, "Drama", "Drama", 2.0, 4.2);
//    testing::internal::CaptureStdout();
//    peli.mostrarInfoFiltrada(4.2, 4.0);
//    std::string output = testing::internal::GetCapturedStdout();
//    EXPECT_NE(output.find("Nombre: Drama"), std::string::npos);
//}
