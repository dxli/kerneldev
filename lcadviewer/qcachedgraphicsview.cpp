
#include <QGraphicsSceneDragDropEvent>

#include "qcachedgraphicsview.h"
#include "events/mousemoveevent.h"

QCachedGraphicsView::QCachedGraphicsView(QWidget* parent) : QGraphicsView(parent) {
}

QCachedGraphicsView::QCachedGraphicsView(QGraphicsScene* scene, QWidget* parent) : QGraphicsView(scene, parent) {
}

void QCachedGraphicsView::drawItems(QPainter* painter, int numItems,
                                    QGraphicsItem* items[],
                                    const QStyleOptionGraphicsItem options[]) {
    QGraphicsView::drawItems(painter, numItems, items, options);

}


void QCachedGraphicsView::paintEvent(QPaintEvent* event) {
    QGraphicsView::paintEvent(event);



    // HEre we properly stop calling the paint event and call render to render the scene on a pixmap
    // then we just do normal bitblk.
    // rubber band needs to be worked out!
}

QPixmap* QCachedGraphicsView::getPixmapForView(QPixmap* pm) {
    if (pm == NULL) {
        return new QPixmap(width(), height());
    } else if (pm->width() != width() || pm->height() != height()) {
        delete pm;
        return new QPixmap(width(), height());
    } else {
        return pm;
    }
}




/**
  * Zoom the view in and out.
  */
void QCachedGraphicsView::wheelEvent(QWheelEvent* event) {

    // FIXME: Need to have configurable KeyModifier
    if (event->modifiers().testFlag(Qt::AltModifier)) {
        // FIXME: see if we can create scalefactors so that the grid will always be perfectly alligned with the view
        qreal scaleFactor = pow((double)2, -event->delta() / 240.0);
        qreal factor = transform().scale(scaleFactor, scaleFactor).mapRect(QRectF(0, 0, 1, 1)).width();

        // TODO: See if these scale factors are good for us. We have to set a limit else there is a chance
        // that people zoom in way to much, or zoomout way to much
        if (factor < 0.001 || factor > 10000) {
            return;
        }

        setTransformationAnchor(QGraphicsView::AnchorUnderMouse);
        QMatrix mat = matrix();
        mat.scale(scaleFactor, scaleFactor);
        setMatrix(mat);
        event->accept();

    } else {
        QGraphicsView::wheelEvent(event);
    }
}


/**
  * Need to update the center so there is no jolt in the
  * interaction after resizing the widget.
  */
void QCachedGraphicsView::resizeEvent(QResizeEvent* event) {
    setResizeAnchor(QGraphicsView::AnchorViewCenter);
    QGraphicsView::resizeEvent(event);
    return;
}


QPointF QCachedGraphicsView::lastMousePosition() const {
    return _lastMousePosition;
}

void QCachedGraphicsView::mousePressEvent(QMouseEvent * event) {
    QGraphicsView::mousePressEvent(event);

}

/**
*Handles the mouse move event
*/
void QCachedGraphicsView::mouseMoveEvent(QMouseEvent* event) {
    QGraphicsView::mouseMoveEvent(event);

    _lastMousePosition = this->mapToScene(event->pos());

    QPolygonF p = mapToScene(this->rect());

    // Invalidate screen so we can draw the mouse
    // FIXME: See QCachedGraphicsView performance is quite bad because we need to update all layers
    invalidateScene(QRectF(_lastMousePosition.x() - 2, _lastMousePosition.y() - 2, 4, 4), QGraphicsScene::AllLayers);

    // Emit a mouse move event
    MouseMoveEvent e(this, QRectF(p.at(0), p.at(2)), _lastMousePosition);
    emit mouseMoveEvent(e);

    update();
}

void QCachedGraphicsView::mouseReleaseEvent(QMouseEvent* event) {
    QList<lc::EntityDistance> emptyList;
    MouseReleaseEvent e(this, _lastMousePosition, event, emptyList);
    emit mouseReleaseEvent(e);
}



void QCachedGraphicsView::dragEnterEvent ( QDragEnterEvent * event ) {
    QCachedGraphicsView::dragEnterEvent(event);
     qDebug() << "dragEnterEvent";
}

void QCachedGraphicsView::dragLeaveEvent ( QDragLeaveEvent * event ) {
    QCachedGraphicsView::dragLeaveEvent(event);
    qDebug() << "dragLeaveEvent";
}

void QCachedGraphicsView::dragMoveEvent ( QDragMoveEvent * event ) {
    QCachedGraphicsView::dragMoveEvent(event);
    qDebug() << "dragMoveEvent";
}




