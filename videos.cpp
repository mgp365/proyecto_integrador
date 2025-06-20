
/*
 * Copyright (c) 2024 Mariana Guerrero Pérez
 * Tecnológico de Monterrey
 */

#include "videos.h"
#include "serie.h"
#include "pelicula.h"
using namespace std;

Videos::Videos(int id, const string& nombre, const string& genero, float duracion, double calificacion)
    : id(id), nombre(nombre), genero(genero), duracion(duracion), calificacion(calificacion) {}

Videos::~Videos() = default;

// videos.h
double Videos::ObtenerCalificacion() { return calificacion; }
string Videos::ObtenerTitulo(){return nombre;}

void Videos::GuardarEnArchivo(ostream &archivo){}

void Videos::MostrarInfoFiltrada(double calif, double c){
    if (calif > c) {
        cout << "Nombre: " << nombre << ". Género: " << genero << ". ID: " << id << endl << ". Calificación: " << calif << endl;
    }
}

void Videos::FiltrarPorGenero(string genero){
    if(genero == "Drama"){
        cout << "Nombre: " << nombre << ". Género: " << genero << ". ID: " << id << endl << ". Calificación: " << calificacion << endl;
    }
}

void Videos::AgregarCalificacion(double nuevaCalificacion, ostream& archivo){
    calificacion = (calificacion + nuevaCalificacion) / 2;
}

ostream& operator << (ostream& os, const Videos& vid){
    const Serie* ptrSerie = dynamic_cast<const Serie*>(&vid);

    os << "Nombre: " << vid.nombre << ". Género: " << vid.genero << ". ID: " << vid.id << ". Calificación: " << vid.calificacion;
    
    if (ptrSerie) {
        os << ". Episodio: " << ptrSerie->ObtenerEpisodio();
    }

    return os;
}
