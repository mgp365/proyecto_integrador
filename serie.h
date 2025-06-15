
/*
 * Copyright (c) 2024 Mariana Guerrero Pérez
 * Tecnológico de Monterrey
 */

#ifndef SERIE_H
#define SERIE_H

#include "videos.h"

/**
 * @brief Clase que representa una serie
 */
class Serie : public Videos {
    protected:
    /**
     * @brief variable episodio
     */
    int episodio;
    public:
    Serie(int id, const string& nombre, double calificacion, const string& genero, float duracion,int episodio);
    double obtenerCalificacion() override;
    void guardarEnArchivo(ostream &archivo) override;
    void mostrarInfoFiltrada(double calif, double c) override;
    virtual string obtenerSerie();
    virtual int obtenerEpisodio() const;

    /**
     * @brief Destructor de Pelicula
     */
    ~Serie();
};

#endif
