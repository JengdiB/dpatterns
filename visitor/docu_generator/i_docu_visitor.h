#pragma once

namespace docu
{
class Document;
class PlainText;
class BoldText;
class HyperLink;

class IVisitor
{
public:
    virtual void visit(PlainText& p)  = 0;
    virtual void visit(BoldText& p)  = 0;
    virtual void visit(HyperLink& p)  = 0;
};
} // namespace docu
