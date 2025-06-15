#ifndef SERIE_H
#define SERIE_H

/*
 * Copyright (C) 2025 Tec de Monterrey
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this program; if not, write to the Free Software Foundation,
 * Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
 */

#include "videos.h"

class Serie : public Videos {
    protected:
    int episodio;
    public:
    Serie(int id, const string& nombre, double calificacion, const string& genero, float duracion,int episodio);
    double obtenerCalificacion() override;
    void guardarEnArchivo(ostream &archivo) override;
    void mostrarInfoFiltrada(double calif, double c) override;
    virtual string obtenerSerie();
    virtual int obtenerEpisodio() const;

    ~Serie();
};

#endif
