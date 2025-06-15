/**
 * @file pelicula.h
 * @brief Header file for video processing functions.
 * 
 * This file contains declarations for functions used to load, play, and stop videos.
 * 
 * @author Mariana Guerrero Pérez
 * @date 2024
 * @copyright (c) 2024 Mariana Guerrero Pérez, Tecnológico de Monterrey
 */

#ifndef PELICULA_H
#define PELICULA_H

#include "videos.h"

class Pelicula : public Videos {
    public:
    Pelicula(int id, const string& nombre, const string& genero, float duracion, double calificacion);
    double obtenerCalificacion() override;
    void guardarEnArchivo(ostream &archivo) override;
    void mostrarInfoFiltrada(double calif, double c) override;
    ~Pelicula();
};

#endif
