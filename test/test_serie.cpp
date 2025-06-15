#include <gtest/gtest.h>
#include "serie.h"

TEST(SerieTest, Constructor) {
    Serie serie(201, "Breaking Bad", 4.9, "Drama", 1.0, 5);
    EXPECT_EQ(serie.obtenerTitulo(), "Breaking Bad");
    EXPECT_DOUBLE_EQ(serie.obtenerCalificacion(), 4.9);
    EXPECT_EQ(serie.obtenerEpisodio(), 5);
}
