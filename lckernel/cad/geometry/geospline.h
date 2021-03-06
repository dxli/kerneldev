#ifndef GEOSPLINE_H
#define GEOSPLINE_H

#include "cad/const.h"
#include "geocoordinate.h"

namespace lc {
    namespace geo {
        // TODO: Should Spline be a arc with a start angle of 0 and a stop angle of 2PI ?
        class Spline {
            public:
                Spline(const QList<Coordinate>& control_points, int degree, bool closed);

                const QList<Coordinate>& control_points() const;

                int degree() const;

                bool closed() const;

                /*!
                 * \brief returns the nearest Point On Path
                 * \param lc::geo::Coordinate coord
                 * \return lc::geo::Coordinate
                 */
                Coordinate nearestPointOnPath(const Coordinate& coord) const;

                /*!
                 * \brief checks if Coordinate is on path
                 * \param lc::geo::Coordinate coord
                 * \return bool
                 */
                bool isCoordinateOnPath(const Coordinate& coord) const;

            private:
                const QList<Coordinate> _control_points; /*!< center of cirlce */
                int _degree; /*!< Radius of Spline. */
                bool _closed;
        };
    }
}

#endif // GEOSPLINE_H
