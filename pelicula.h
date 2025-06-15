
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
    /**
     * @brief Constructor de clase 
     */
    Pelicula(int id, const string& nombre, const string& genero, float duracion, double calificacion);
    double ObtenerCalificacion() override;
    void guardarEnArchivo(ostream &archivo) override;
    void mostrarInfoFiltrada(double calif, double c) override;

    /**
     * @brief Destructor de la clase Pelicula
     * 
     * Libera los recursos utilizados por la instancia de Pelicula
     */
    ~Pelicula();
};

#endif
