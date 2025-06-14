#ifndef PELICULA_H
#define PELICULA_H

#include "videos.h"

class Pelicula : public Videos {
    public:
    Pelicula(int id, const string& nombre, const string& genero, float duracion, double calificacion);
    double obtenerCalificacion() override;
    void guardarEnArchivo(ostream &archivo) override;
    void mostrarInfoFiltrada(double calif, double c) override;
};

#endif
