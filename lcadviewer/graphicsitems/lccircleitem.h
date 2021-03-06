#ifndef LCCIRCLEITEM_H
#define LCCIRCLEITEM_H

#include <QGraphicsItem>
#include <QPainter>
#include <QPainterPath>
#include "lcgraphicsitem.h"
#include <cad/primitive/circle.h>
#include <cad/meta/color.h>
#include <cad/interface/metatype.h>

class LCCircleItem : public LCGraphicsItem {
    public:
        LCCircleItem(const shared_ptr<const lc::Circle> circle);

        QRectF boundingRect() const;

        void paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget);
        virtual const shared_ptr<const lc::CADEntity> entity() const;

    private:
        QPainterPath shape() const;

    private:
        const shared_ptr<const lc::Circle> _circle;
};

#endif // LCCIRCLEITEM_H
