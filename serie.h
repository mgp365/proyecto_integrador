
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
    /**
     * @brief Constructor de clase 
     */
    Serie(int id, const string& nombre, double calificacion, const string& genero, float duracion,int episodio);
    /**
     * @brief Obtener la calificación
     */
    double ObtenerCalificacion() override;
    /**
     * @brief Guardar datos en el archivo
     */
    void GuardarEnArchivo(ostream &archivo) override;
    /**
     * @brief Mostrar información filtrada por calificación
     */
    void MostrarInfoFiltrada(double calif, double c) override;
    /**
     * @brief Obtener serie
     */
    virtual string ObtenerSerie();
    /**
     * @brief Obtener episodio
     */
    virtual int ObtenerEpisodio() const;

    /**
     * @brief Destructor de Pelicula
     */
    ~Serie();
};

#endif
