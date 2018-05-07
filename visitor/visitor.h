#include <memory>

namespace visitor
{
template<typename Visitable>
class Visitor
{
public:
    using visitable_type = Visitable;
    using VisitablePtr = visitable_type*;

    virtual ~Visitor() = default;

    // interface
    virtual void visit(VisitablePtr v) = 0;

};

template<typename Visitor>
class Visitable
{
public:
    using visitor_type = Visitor;
    using VisitorPtr = visitor_type*;
    
    virtual ~Visitable() = default;

    // interface
    virtual void accept(VisitorPtr v) = 0;
};
} // namespac visitor