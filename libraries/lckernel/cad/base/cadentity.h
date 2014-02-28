#ifndef CADENTITY_H
#define CADENTITY_H
#include <QList>

#include "cad/const.h"
#include "id.h"
#include "metainfo.h"
#include "cad/interface/metatype.h"
#include "cad/geometry/geoarea.h"

namespace lc {

    class Circle;
    class Line;
    class Arc;
    class Ellipse;
    class CADEntity;

    class EntityVisitor;
    class EntityDispatch;

    /**
     *Class that all CAD entities must inherit
     *
     */
    class CADEntity : public ID, public MetaInfo {
        public:
            CADEntity();
            CADEntity(QList<boost::shared_ptr<const lc::MetaType> > metaTypes);
            virtual void accept(boost::shared_ptr<const lc::Line>, EntityVisitor&) const = 0;
            virtual void accept(boost::shared_ptr<const lc::Circle>, EntityVisitor&) const = 0;
            virtual void accept(boost::shared_ptr<const lc::Arc>, EntityVisitor&) const = 0;
            virtual void accept(boost::shared_ptr<const lc::Ellipse>, EntityVisitor&) const = 0;
            virtual void accept(boost::shared_ptr<const lc::CADEntity>, EntityVisitor&) const = 0;
            virtual void dispatch(EntityDispatch&) const = 0;
    };
}

#endif // CADENTITY_H
