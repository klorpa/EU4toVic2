#include "Mod.h"
#include "ParserHelpers.h"

EU4::Mod::Mod(std::istream& theStream)
{
	registerKeyword(std::regex("name"), [this](const std::string& unused, std::istream& theStream) {
		commonItems::singleString nameString(theStream);
		name = nameString.getString();
	});
	registerKeyword(std::regex("path"), [this](const std::string& unused, std::istream& theStream) {
		commonItems::singleString pathString(theStream);
		path = pathString.getString();
	});
	registerKeyword(std::regex("archive"), [this](const std::string& unused, std::istream& theStream) {
		commonItems::singleString pathString(theStream);
		path = pathString.getString();
	});
	registerKeyword(std::regex("[a-zA-Z0-9_\\.:]+"), commonItems::ignoreItem);

	parseStream(theStream);

	if (path != "")
	{
		int lastDot = path.find_last_of('.');
		if (lastDot != std::string::npos)
		{
			std::string ending = path.substr(lastDot + 1, path.size());
			compressed = (ending == "zip") || (ending == "bin");
		}
	}
}