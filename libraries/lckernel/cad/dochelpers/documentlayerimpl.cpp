#include "documentlayerimpl.h"

#include <QDebug>
#include <QVectorIterator>

using namespace lc;

DocumentLayerImpl::DocumentLayerImpl() {
}
DocumentLayerImpl::DocumentLayerImpl(boost::shared_ptr<const lc::Layer> layer) : _layer(layer) {
}

DocumentLayerImpl::~DocumentLayerImpl() {
}

boost::shared_ptr<const lc::Layer> DocumentLayerImpl::layer() const {
    return this->_layer;
}

void DocumentLayerImpl::addEntity(boost::shared_ptr<const lc::CADEntity> entity) {
    _cadentities.insert(entity->id(), entity);
}

void DocumentLayerImpl::removeEntity(ID_DATATYPE id) {
    if (_cadentities.contains(id)) {
        _cadentities.remove(id);
        return;
    }

    throw "Entity not found";
}

QHash<int, boost::shared_ptr<const lc::CADEntity> > DocumentLayerImpl::allEntities() const {
    return _cadentities;
}

boost::shared_ptr<const lc::CADEntity> DocumentLayerImpl::findByID(ID_DATATYPE id) const {
    if (_cadentities.contains(id)) {
        return _cadentities.value(id);
    }

    throw "Entity not found";
}
