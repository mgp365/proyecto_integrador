/*
 * Copyright (C) 2025 Tec de Monterrey
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this program; if not, write to the Free Software Foundation,
 * Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
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
