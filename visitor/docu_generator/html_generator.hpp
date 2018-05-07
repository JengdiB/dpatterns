#pragma once
#include "i_docu_visitor.h"
#include "docu_parts.hpp"

#include <sstream>
namespace docu
{
class HTMLGenerator: public IVisitor
{
	std::stringstream m_ss;
	friend std::ostream& operator<<(std::ostream& out, const HTMLGenerator& gen);
public:
    virtual void visit(PlainText& p)  override;
    virtual void visit(BoldText& p)   override;
    virtual void visit(HyperLink& p)  override;
};

std::ostream&
operator<<(std::ostream& out, const docu::HTMLGenerator& gen)
{
	out << gen.m_ss.str();
	return out;
}

void
HTMLGenerator::visit(PlainText& doc)
{
	m_ss << "<p>" << doc.getText() << "</p>" << std::endl;
}

void
HTMLGenerator::visit(BoldText& doc)
{
	m_ss << "<b>" << doc.getText() << "</b>" << std::endl;
}

void
HTMLGenerator::visit(HyperLink& doc)
{
	m_ss << "<a href=\"" << doc.getUrl() << "\">" << doc.getText() << "</a>" << std::endl;
}
} // namespace docu