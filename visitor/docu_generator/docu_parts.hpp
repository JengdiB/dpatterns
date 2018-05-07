#pragma once
#include "i_docu_visitable.h"
#include "i_docu_visitor.h"

#include <string>
#include <vector>

namespace docu
{

class Part : public IVisitable
{
    std::string m_text;
public:
	Part(std::string str) : m_text(std::move(str)) {}
	virtual ~Part() = default;

    virtual const std::string& getText() const
    {
        return m_text;
    }

	// IVisitable interface
	virtual void accept(IVisitor& visitor) = 0;
};

class PlainText: public Part 
{
public:
	using base = Part;
	PlainText(std::string str) : base(std::move(str)) {}

	virtual void accept(IVisitor& visitor) override
	{
		visitor.visit(*this);
	}
};

class BoldText: public Part 
{
public:
	using base = Part;
	BoldText(std::string str) : base(std::move(str)) {}

	virtual void accept(IVisitor& visitor) override
	{
		visitor.visit(*this);
	}
};

class HyperLink: public Part {
    std::string m_url;
public:
	using base = Part;
	HyperLink(std::string str, std::string url) : base(std::move(str)), m_url(std::move(url)) {}

	virtual void accept(IVisitor& visitor) override
	{
		visitor.visit(*this);
	}

    virtual const std::string& getUrl() const
    {
        return m_url;
    }
};
 
class Document: public IVisitable
{
    std::vector<Part*> m_parts;
public:
	Document() = default;
	virtual ~Document() 
	{
		free();
	}

	void addPart(Part* part)
	{
		m_parts.emplace_back(part);
	}

	virtual void accept(IVisitor& visitor) override
	{
		for (auto part : m_parts)
			part->accept(visitor);
	}

private:
	void free()
	{
		for (auto part : m_parts)
			delete part;
		m_parts.clear();
	}
};
} // namespace doc
