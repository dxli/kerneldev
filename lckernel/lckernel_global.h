#ifndef LCKERNEL_GLOBAL_H
#define LCKERNEL_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(LCKERNEL_LIBRARY)
#  define LCKERNELSHARED_EXPORT Q_DECL_EXPORT
#else
#  define LCKERNELSHARED_EXPORT Q_DECL_IMPORT
#endif

#endif // LCKERNEL_GLOBAL_H
