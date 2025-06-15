/*
 * Copyright (C) 2025 Tec de Monterrey
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this program; if not, write to the Free Software Foundation,
 * Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
 */

#include <iostream>
#include "serie.h"
using namespace std;

Serie::Serie(int id, const string& nombre, double calificacion, const string& genero, float duracion,int episodio)
    : Videos(id, nombre, genero, duracion, calificacion), episodio(episodio) {}

Serie::~Serie() = default;

void Serie::guardarEnArchivo(ostream &archivo){
    archivo << id << "," << nombre << "," << episodio << "," << genero << "," << duracion << "," << calificacion << endl;
}

double Serie::obtenerCalificacion(){
    return calificacion;
}

void Serie::mostrarInfoFiltrada(double calif, double c){
    if (calif > c) {
        cout << "Nombre: " << nombre << ". Número de episodio: " << episodio << ". Género: " << genero << ". ID: " << id << ". Calificación: " << calif << endl;
    }
}

string Serie::obtenerSerie(){
    return nombre;
}

int Serie::obtenerEpisodio() const{
    return episodio;
}

ostream& operator<<(ostream& os, const Serie& serie) {
    os << static_cast<const Videos&>(serie) << ". Episodio: " << serie.obtenerEpisodio() << endl;
    return os;
}
