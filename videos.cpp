/*
 * Copyright (c) 2024 [Mariana Guerrero Pérez - Tecnológico de Monterrey]
 * 
 * Descripción: Implementación de la clase Pelicula que hereda de Videos
 * Autor: [Mariana Guerrero Pérez]
 * Fecha de creación: [27/05/2025]
 * Última modificación: [16/06/2025]
 * 
 * Licencia: [Tipo de licencia, ej: MIT, GPL, etc.]
 */

#include "videos.h"
#include "serie.h"
#include "pelicula.h"
using namespace std;

Videos::Videos(int id, const string& nombre, const string& genero, float duracion, double calificacion)
    : id(id), nombre(nombre), genero(genero), duracion(duracion), calificacion(calificacion) {}

Videos::~Videos() = default;

// videos.h
double Videos::obtenerCalificacion() { return calificacion; }
string Videos::obtenerTitulo(){return nombre;}

void Videos::guardarEnArchivo(ostream &archivo){}

void Videos::mostrarInfoFiltrada(double calif, double c){
    if (calif > c) {
        cout << "Nombre: " << nombre << ". Género: " << genero << ". ID: " << id << endl << ". Calificación: " << calif << endl;
    }
}

void Videos::filtrarPorGenero(string genero){
    if(genero == "Drama"){
        cout << "Nombre: " << nombre << ". Género: " << genero << ". ID: " << id << endl << ". Calificación: " << calificacion << endl;
    }
}

void Videos::agregarCalificacion(double nuevaCalificacion, ostream& archivo){
    calificacion = (calificacion + nuevaCalificacion) / 2;
}

ostream& operator << (ostream& os, const Videos& vid){
    const Serie* ptrSerie = dynamic_cast<const Serie*>(&vid);

    os << "Nombre: " << vid.nombre << ". Género: " << vid.genero << ". ID: " << vid.id << ". Calificación: " << vid.calificacion;
    
    if (ptrSerie) {
        os << ". Episodio: " << ptrSerie->obtenerEpisodio();
    }

    return os;
}
