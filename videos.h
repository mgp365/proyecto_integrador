/*
 * Copyright (C) 2025 Tec de Monterrey
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this program; if not, write to the Free Software Foundation,
 * Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
 */

#ifndef VIDEOS_H
#define VIDEOS_H

#include <iostream>
using namespace std;

class Videos{
    protected:
    int id;
    string nombre, genero;
    float duracion;
    double calificacion;
    public:
    Videos(int id, const string& nombre, const string& genero, float duracion,double calificacion);
    virtual ~Videos();
    
    //virtual void leerArchivo();
    virtual double obtenerCalificacion();
    virtual void guardarEnArchivo(ostream &archivo);
    virtual void agregarCalificacion(double nuevaCalificacion, ostream& archivo);
    virtual void mostrarInfoFiltrada(double calif, double c);
    virtual void filtrarPorGenero(string genero);
    virtual string obtenerTitulo();

    friend ostream& operator << (ostream& os, const Videos& vid);
};

#endif
