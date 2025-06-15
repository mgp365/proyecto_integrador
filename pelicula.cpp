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

#include <iostream>
#include "videos.h"
#include "pelicula.h"
using namespace std;

Pelicula::Pelicula(int id, const string& nombre, const string& genero, float duracion, double calificacion)
    : Videos(id, nombre, genero, duracion, calificacion){}

Pelicula::~Pelicula() = default;

void Pelicula::guardarEnArchivo(ostream &archivo){
    archivo << id << "," << nombre << "," << genero << "," << duracion << "," << calificacion << endl;
}

double Pelicula::obtenerCalificacion(){
    return calificacion;
}

void Pelicula::mostrarInfoFiltrada(double calif, double c){
    if (calif > c) {
        cout << "Nombre: " << nombre << ". Género: " << genero << ". ID: " << id << endl << ". Calificación: " << calif << endl;
    }
}

ostream& operator<<(ostream& os, const Pelicula& pelicula) {
    os << static_cast<const Videos&>(pelicula) << endl;
    return os;
}
