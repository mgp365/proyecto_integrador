/*
 * Copyright (C) 2025 Tec de Monterrey
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this program; if not, write to the Free Software Foundation,
 * Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
 */

#ifndef PELICULA_H
#define PELICULA_H

#include "videos.h"

class Pelicula : public Videos {
    public:
    Pelicula(int id, const string& nombre, const string& genero, float duracion, double calificacion);
    double obtenerCalificacion() override;
    void guardarEnArchivo(ostream &archivo) override;
    void mostrarInfoFiltrada(double calif, double c) override;
    ~Pelicula();
};

#endif
