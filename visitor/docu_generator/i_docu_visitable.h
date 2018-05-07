#pragma once

namespace docu
{
class IVisitor;
class IVisitable
{
public:
    virtual void accept(IVisitor& visitor) = 0;
};
} // namespace docu