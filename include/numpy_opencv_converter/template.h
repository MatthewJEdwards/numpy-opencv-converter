// Author: Sudeep Pillai (spillai@csail.mit.edu)
// Note: Stripped from pyxx project

#ifndef PYXX_TEMPLATE_H
#define PYXX_TEMPLATE_H

#include <boost/python.hpp>

namespace py = boost::python;

/*
 * Provides template support
 */

template<typename TemplateType>
struct expose_template_type
{
   // do nothing! 
};

template<typename TemplateType>
struct expose_template_type_base
{
    bool wrapped()
    {
        py::converter::registration const * p = py::converter::registry::query( py::type_id<TemplateType>() );
        return p && (p->m_class_object || p->m_to_python);
    }

};

#endif
