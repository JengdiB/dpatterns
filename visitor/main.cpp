#include "visitor.h"
#include <string>
#include <iostream>

namespace logging
{
class LogRecord;
class LogRecordVisitor;

using LogRecordPtr = LogRecord*;
using LogRecordVisitorPtr = LogRecordVisitor*;

class LogRecordVisitor: public visitor::Visitor<LogRecord>
{
public:
    using base = visitor::Visitor<LogRecord>;

    LogRecordVisitor(): base() {}
    virtual ~LogRecordVisitor() = default;

    virtual void visit(LogRecordPtr rec) = 0;
};

class LogRecord: public visitor::Visitable<LogRecordVisitor>
{
private:
    std::string m_msg;
public:
    using base = visitor::Visitable<LogRecordVisitor>;
    LogRecord(std::string msg): base(), m_msg(std::move(msg)) { }

    const std::string& getMsg() const { return m_msg; }
    void setMsg(std::string msg) { m_msg = std::move(msg); }

    // visitor::Visitable
    virtual void accept(LogRecordVisitorPtr v) override
    {
        v->visit(this);
    }
};


class ConsolePrinter: public LogRecordVisitor
{
public:
    using base = LogRecordVisitor;
    ConsolePrinter(): LogRecordVisitor() {}
    // visitor::IVisitor
    virtual void visit(LogRecordPtr rec) override 
    {
        std::cout << rec->getMsg() << std::endl;
    }
};

class DoubleLogMsg : public LogRecordVisitor
{
public:
	using base = LogRecordVisitor;
	DoubleLogMsg() : LogRecordVisitor() {}
	// visitor::IVisitor
	virtual void visit(LogRecordPtr rec) override
	{
		auto msg = rec->getMsg();
		rec->setMsg(msg + " " + msg);
	}
};
}

int main(int argc, char** argv)
{
    using namespace logging;

    LogRecord log_record("Hello World");
	DoubleLogMsg   doulble_log_msg;
    ConsolePrinter console_printer;

	LogRecordVisitorPtr visitor = &console_printer;
	LogRecordPtr rec = &log_record;
	
	visitor->visit(rec);

	rec->accept(&doulble_log_msg);
	rec->accept(&console_printer);

    return 0;
}