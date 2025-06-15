#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
#include "videos.h"
#include "pelicula.h"
#include "serie.h"
//#include "arch.cpp"
using namespace std;

void cargarDesdeArchivo(const string& nombreArchivo, vector<Pelicula*>& listaPeliculas, vector<Serie*>& listaSeries, vector<Videos*>& listaVideos) {
    ifstream archivo(nombreArchivo);
    string linea;

    while (getline(archivo, linea)) {
        int id, episodio;
        string nombre, genero;
        float duracion;
        double calificacion;

        size_t pos = 0;
        string originalLinea = linea;

        try {
            pos = linea.find(",");
            id = stoi(linea.substr(0, pos));
            linea.erase(0, pos + 1);

            pos = linea.find(",");
            nombre = linea.substr(0, pos);
            linea.erase(0, pos + 1);

            pos = linea.find(",");
            episodio = stoi(linea.substr(0, pos));
            linea.erase(0, pos + 1);

            pos = linea.find(",");
            genero = linea.substr(0, pos);
            linea.erase(0, pos + 1);

            pos = linea.find(",");
            duracion = stof(linea.substr(0, pos));
            linea.erase(0, pos + 1);

            calificacion = stod(linea); //YA LO QUE QUEDA

            if (episodio == -1) {
                Pelicula* pelicula = new Pelicula(id, nombre, genero, duracion, calificacion);
                listaVideos.push_back(pelicula);
                listaPeliculas.push_back(pelicula);
            } else {
                Serie* serie = new Serie(id, nombre, calificacion, genero, duracion, episodio);
                listaVideos.push_back(serie);
                listaSeries.push_back(serie);
            }

        } catch (...) {
            cerr << "Error al procesar línea: " << originalLinea << endl;
        }
    }

    cout << "Se cargaron " << listaVideos.size() << " videos correctamente" << endl;
    archivo.close();
}

int main() {
    vector<Videos*> listaVideos;
    vector<Pelicula*> listaPeliculas;
    vector<Serie*> listaSeries;

    ofstream archivo("lista_videos.txt",ios::app); //LEER Y NO SOBREESCRIBIR DESDE CERO

    int opcion, añadir, seleccionar;
    do {
        cout << "1. Cargar archivos de datos\n";
        cout << "2. Mostrar videos por calificación o género\n";
        cout << "3. Mostrar episodios de una serie con calificación\n";
        cout << "4. Mostrar películas con cierta calificación\n";
        cout << "5. Calificar un video\n";
        cout << "0. Salir\n";
        cout << "Opción: ";
        cin >> opcion;

        switch (opcion) {
            case 1: //CARGAR ARCHIVO COMO VECTOR
                cout << "Cargando archivo de videos..." << endl;
                cargarDesdeArchivo("lista_videos.txt", listaPeliculas, listaSeries, listaVideos);
                break;
            case 2: //mostrar videos filtrados por calificación o género
                cout << "1. Filtrar por calificación" << endl;
                cout << "2. Filtrar por género" << endl;
                cin >> seleccionar;
                if(seleccionar == 1){
                    double filtroVideos;
                    cout << "Mostrar videos con calificación mayor a: ";
                    cin >> filtroVideos;
                    for (Videos* vid : listaVideos) {
                        vid->MostrarInfoFiltrada(vid->ObtenerCalificacion(), filtroVideos);
                    } break;
                } else if(seleccionar == 2){
                    string filtroGenero;
                    cout << "Mostrar videos con género: ";
                    cin >> filtroGenero;
                    for (Videos* vid : listaVideos) {
                        vid->FiltrarPorGenero(filtroGenero);
                    } break;
                } else{cout << "Seleccione una opción válida" << endl; break;}
            case 3: {
                string filtroSerie;
                double filtroEpisodio;

                cin.ignore();
                cout << "Serie a visualizar: ";
                getline(cin, filtroSerie);

                cout << "Mostrar episodios con calificación mayor a: ";
                cin >> filtroEpisodio;

                for (Serie* ser : listaSeries) {
                    if (ser->ObtenerSerie() == filtroSerie) {
                        ser->MostrarInfoFiltrada(ser -> ObtenerCalificacion(),filtroEpisodio);
                    }
                }
                break;
            }     
            case 4:
                //mostrar películas con cierta calificación
                double filtroPelicula;
                cout << "Mostrar películas con calificación mayor a: ";
                cin >> filtroPelicula;
                for (Pelicula* pel : listaPeliculas) {
                    pel->MostrarInfoFiltrada(pel->ObtenerCalificacion(), filtroPelicula);
                }
                break;
                //calificar un video (pedir título a calificar y valor otorgado)
            case 5: {
                string titulo;
                int op;
                double puntuacion;

                cout << "1. Calificar película" << endl;
                cout << "2. Calificar episodio" << endl;
                cin >> op;

                cin.ignore();
                cout << "Ingrese título a calificar: ";
                getline(cin, titulo);

                if (op == 1) {
                    for (Videos* vid : listaPeliculas) {
                        if (vid->ObtenerTitulo() == titulo) {
                            cout << "¿Cómo califica esta película del 1 al 5?: ";
                            cin >> puntuacion;
                            vid->AgregarCalificacion(puntuacion, archivo);
                            cout << *vid << endl;
                            cout << "La calificación promedio se ha actualizado." << endl;
                            break;
                        }
                    }
                } else if (op == 2) {
                    int numEpisodio;
                    cout << "Ingrese el número de episodio: ";
                    cin >> numEpisodio;

                    for (Serie* ser : listaSeries) {
                        if (ser->ObtenerTitulo() == titulo && ser->ObtenerEpisodio() == numEpisodio) {
                            cout << "¿Cómo califica este episodio del 1 al 5?: ";
                            cin >> puntuacion;
                            ser->AgregarCalificacion(puntuacion, archivo);
                            cout << *ser << endl;
                            cout << "La calificación promedio del episodio se ha actualizado." << endl;
                            break;
                        }
                    }
                } else {
                    cout << "Opción inválida." << endl;
                }
                break;
}

        }
    } while (opcion != 0);

    for(Videos* vid : listaVideos){delete vid;}
    for(Pelicula* pel : listaPeliculas){delete pel;}
    for(Serie* ser : listaSeries){delete ser;}
    archivo.close();
    return 0;
}
