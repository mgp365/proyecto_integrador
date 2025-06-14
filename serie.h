#ifndef SERIE_H
#define SERIE_H

#include "videos.h"

class Serie : public Videos {
    private:
    int episodio;
    public:
    Serie(int id, const string& nombre, double calificacion, const string& genero, float duracion,int episodio);
    double obtenerCalificacion() override;
    void guardarEnArchivo(ostream &archivo) override;
    void mostrarInfoFiltrada(double calif, double c) override;
    virtual string obtenerSerie();
    virtual int obtenerEpisodio() const;
};

#endif
