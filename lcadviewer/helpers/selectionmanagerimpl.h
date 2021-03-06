#ifndef SELECTIONMANAGERIMPL_H
#define SELECTIONMANAGERIMPL_H

#include <QGraphicsView>

#include "cad/const.h"

#include "cad/document/selectionmanager.h"
#include "cad/document/layermanager.h"
#include "cad/base/cadentity.h"

/**
  * Selection manager can be used to request the selected items on the screen
  * It uses QGraphicsView to get a list of possible items that can be selected because QGraphicsView uses BSP for some function that returns itmes in a area.
  * This will reduce the number of hit test when zoomed in into portions of tgeh drawing
  */
class SelectionManagerImpl : public lc::SelectionManager {
    public:
        SelectionManagerImpl(shared_ptr<lc::LayerManager> layerManager, QGraphicsView* scene);

        /*!
          * \brief return a list of entitires that are near a coordinate
          *
          * \param Coordinate Point to find entities near
          * \param double   Minimum distance for a entity to get added
          */
        virtual QList<lc::EntityDistance> getEntitiesNearCoordinate(const lc::geo::Coordinate& point, double distance) const;
        virtual QList<shared_ptr<const lc::CADEntity> > getEntitiesInArea(const lc::geo::Area& area) const;

    public slots:

    private:
        shared_ptr<lc::LayerManager> _layerManager;
        QGraphicsView* _view;
};
#endif // SELECTIONMANAGERIMPL_H
