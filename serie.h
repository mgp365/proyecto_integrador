/**
 * @file videos.h
 * @brief Header file for video processing functions.
 * 
 * This file contains declarations for functions used to load, play, and stop videos.
 * 
 * @author Mariana Guerrero Pérez
 * @date 2024
 * @copyright (c) 2024 Mariana Guerrero Pérez, Tecnológico de Monterrey
 */

#ifndef SERIE_H
#define SERIE_H

#include "videos.h"

class Serie : public Videos {
    protected:
    int episodio;
    public:
    Serie(int id, const string& nombre, double calificacion, const string& genero, float duracion,int episodio);
    double obtenerCalificacion() override;
    void guardarEnArchivo(ostream &archivo) override;
    void mostrarInfoFiltrada(double calif, double c) override;
    virtual string obtenerSerie();
    virtual int obtenerEpisodio() const;

    ~Serie();
};

#endif
