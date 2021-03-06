#ifndef SNAPMANAGERIMPL_H
#define SNAPMANAGERIMPL_H

#include <QObject>
#include "snapmanager.h"
#include "cad/document/abstractdocument.h"
#include "lcadviewer.h"


/*!
 * \brief Implements the SnapManager interface
 */
class SnapManagerImpl : public SnapManager {
        Q_OBJECT
    public:
        /*!
         * \brief Implementation of the SnapManager
         *
         * \param viewer    Pointer to a LCADViewer object
         * \param selectionmanager    SelectionManager object, this allows SnapManager to locate objects within the document
         * \param grid  Grid that can be snapped into
         * \param distanceToSnap  The minimum distance for a entity to get snapped into. Distance given in real coordinates, not screen pixels
         *
         * \sa lc::SnapManager
         */
        SnapManagerImpl(LCADViewer* viewer, shared_ptr<lc::SelectionManager> _selectionmanager, shared_ptr<const lc::Snapable> grid, double distanceToSnap);


        virtual void setGridSnappable(bool gridSnappable);
        virtual bool isGridSnappable() const;

    public slots:
        void on_mouseMoveEvent(const MouseMoveEvent& event);
        void on_mouseRelease_Event(const MouseReleaseEvent& event);

    private:

        shared_ptr<lc::SelectionManager> _selectionmanager;

        // Grid is snapable
        shared_ptr<const lc::Snapable> _grid;

        // TRE when snapping to grid is evaluated
        bool _gridSnappable;

        // List of entities that are potential for snapping
        QList<shared_ptr<const lc::Snapable> > _snapableEntities;

        // List of additional points a user can pick, to be implemented
        QList<lc::geo::Coordinate> _smartCoordinates;

        // What the minimal distance is when we send a snap event
        double _distanceToSnap;

        // Last Snap Point Event
        SnapPointEvent _lastSnapEvent;

        // List of entities 'under' the cursor
        QList<lc::EntityDistance> _entities;
};

#endif // SNAPMANAGERIMPL_H
