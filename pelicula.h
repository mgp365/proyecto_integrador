
/*
 * Copyright (c) 2024 Mariana Guerrero Pérez
 * Tecnológico de Monterrey
 */

#ifndef PELICULA_H
#define PELICULA_H

#include "videos.h"

/**
 * @brief Clase que representa una película, hereda de Videos
 * 
 * Esta clase implementa las funcionalidades específicas de una película,
 * extendiendo las características básicas de la clase Videos.
 * 
 * @author Mariana Guerrero Pérez
 * @date 27/05/2025
 */
class Pelicula : public Videos {
    public:
    Pelicula(int id, const string& nombre, const string& genero, float duracion, double calificacion);
    double obtenerCalificacion() override;
    void guardarEnArchivo(ostream &archivo) override;
    void mostrarInfoFiltrada(double calif, double c) override;
    ~Pelicula();
};

#endif
