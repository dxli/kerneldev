#ifndef SCENEMANAGER_H
#define SCENEMANAGER_H

#include <QObject>
#include <QHash>
#include <QGraphicsItem>

#include "cad/events/addentityevent.h"
#include "cad/events/removeentityevent.h"
#include "cad/document/abstractdocument.h"
#include "lcadviewer.h"
#include "cad/base/cadentity.h"

/**
  * Scene manager monitors removal and addition of entities within the document
  * When entities are removed or added, similar entities will be created
  * within the scene
  */
class SceneManager: public QObject {
        Q_OBJECT
    public:
        SceneManager(LCADViewer* viewer, lc::AbstractDocument* _document);

    public slots:
        void on_addEntityEvent(const lc::AddEntityEvent&);
        void on_removeEntityEvent(const lc::RemoveEntityEvent&);

    private:
        lc::AbstractDocument* _document;
        LCADViewer* _viewer;
        QHash <int, QGraphicsItem*> _activeGraphicsItems;
};

#endif // SCENEMANAGER_H
