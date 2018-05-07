#include "html_generator.hpp"

#include <iostream>
#include <fstream>

int main(int argc, char** arv)
{
	docu::HTMLGenerator htmlGenerator;
	docu::Document docu;
	{

		auto bold = new docu::BoldText("Hello World");
		auto link = new docu::HyperLink("click me", "http://www.google.com");
		auto line = new docu::PlainText("-------------------");

		docu.addPart(bold);
		docu.addPart(link);
		docu.addPart(line);
	}

	docu.accept(htmlGenerator);

	std::cout << htmlGenerator << std::endl;
    return 0;
}