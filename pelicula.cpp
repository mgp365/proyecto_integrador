
/*
 * Copyright (c) 2024 Mariana Guerrero Pérez
 * Tecnológico de Monterrey
 */

#include <iostream>
#include "videos.h"
#include "pelicula.h"
using namespace std;

Pelicula::Pelicula(int id, const string& nombre, const string& genero, float duracion, double calificacion)
    : Videos(id, nombre, genero, duracion, calificacion){}

Pelicula::~Pelicula() = default;

void Pelicula::GuardarEnArchivo(ostream &archivo){
    archivo << id << "," << nombre << "," << genero << "," << duracion << "," << calificacion << endl;
}

double Pelicula::ObtenerCalificacion(){
    return calificacion;
}

void Pelicula::MostrarInfoFiltrada(double calif, double c){
    if (calif > c) {
        cout << "Nombre: " << nombre << ". Género: " << genero << ". ID: " << id << endl << ". Calificación: " << calif << endl;
    }
}

ostream& operator<<(ostream& os, const Pelicula& pelicula) {
    os << static_cast<const Videos&>(pelicula) << endl;
    return os;
}
