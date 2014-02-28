#ifndef ARC_H
#define ARC_H

#include "cad/const.h"
#include "cad/interface/entityvisitor.h"
#include "cad/interface/entitydispatch.h"

#include "lckernel_global.h"
#include "cad/geometry/geocoordinate.h"
#include "cad/geometry/geoarc.h"
#include "cad/base/cadentity.h"
#include "cad/vo/entitycoordinate.h"

#include <boost/enable_shared_from_this.hpp>

namespace lc {
    class Arc : public boost::enable_shared_from_this<Arc>, public CADEntity, public geo::Arc {
        public:
            Arc(const geo::Coordinate& center, double radius, double startAngle, double endAngle);
            Arc(const geo::Coordinate& center, double radius, double startAngle, double endAngle, const QList<boost::shared_ptr<const lc::MetaType> >& metaTypes);

        public:
            virtual void accept(boost::shared_ptr<const lc::Line> o, EntityVisitor& ei) const {
                ei.visit(shared_from_this(), o);
            }
            virtual void accept(boost::shared_ptr<const lc::Circle> o, EntityVisitor& ei) const {
                ei.visit(shared_from_this(), o);
            }
            virtual void accept(boost::shared_ptr<const lc::Arc> o, EntityVisitor& ei) const {
                ei.visit(shared_from_this(), o);
            }
            virtual void accept(boost::shared_ptr<const lc::Ellipse> o, EntityVisitor& ei) const {
                ei.visit(shared_from_this(), o);
            }
            virtual void accept(boost::shared_ptr<const lc::CADEntity> o, EntityVisitor& ei) const {
                o->accept(shared_from_this(), ei);
            }
            virtual void dispatch(EntityDispatch& ed) const {
                ed.visit(shared_from_this());
            }

    };
}

#endif // ARC_H
