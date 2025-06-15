
/*
 * Copyright (c) 2024 Mariana Guerrero Pérez
 * Tecnológico de Monterrey
 */

#ifndef VIDEOS_H
#define VIDEOS_H

#include <iostream>
using namespace std;

/**
 * @brief Clase base que representa un video genérico
 * 
 * Esta clase abstracta define la estructura básica para videos,
 * incluyendo propiedades comunes como id, nombre, género, duración y calificación.
 * Sirve como clase padre para tipos específicos de videos como películas y series.
 * 
 * @author Mariana Guerrero Pérez
 * @date 2024
 */

class Videos{
    protected:
    /**
     * ID del video
     */
    int id;
    
    /**
     * Nombre del título
     */
    string nombre;
    
    /**
     * Género del título
     */
    string genero;
    
    /**
     * Duración en minutos
     */
    float duracion;
    
    /**
     * Calificación promedio
     */
    double calificacion;
    public:
    /**
     * @brief Constructor de la clase Videos
     * 
     * @param id Identificador único del video
     * @param nombre Título del video
     * @param genero Género del video
     * @param duracion Duración en minutos
     * @param calificacion Calificación del video
     */
    Videos(int id, const string& nombre, const string& genero, float duracion,double calificacion);
    /**
     * @brief Destructor virtual de la clase Videos
     * Permite destruir objetos derivados
     */
    virtual ~Videos();

    /**
     * @brief Obtiene la calificación del video
     * @return double Calificación
     */
    virtual double obtenerCalificacion();
    /**
     * @brief Guarda info de video en archivo
     * 
     * @return salida a guardar
     */
    virtual void guardarEnArchivo(ostream &archivo);
    /**
     * @brief Agrega una nueva calificación y su cálculo
     */
    virtual void agregarCalificacion(double nuevaCalificacion, ostream& archivo);
    /**
     * @brief Muestra información filtrada por filtro propuesto
     */
    virtual void mostrarInfoFiltrada(double calif, double c);
    /**
     * @brief Muestra información filtrada por filtro de género
     */
    virtual void filtrarPorGenero(string genero);
    /**
     * @brief Obtiene título del video
     */
    virtual string obtenerTitulo();
    /**
     * @brief Operador de inserción << para mostrar información del video
     * 
     * @param os Stream de salida
     * @param vid Objeto Videos a mostrar
     * @return Referencia al stream de salida
     */
    friend ostream& operator << (ostream& os, const Videos& vid);
};

#endif
