#include "EU4ReformStackSection.h"
#include "ParserHelpers.h"

EU4::ReformStackSection::ReformStackSection(std::istream& theStream)
{
	registerKeyword(std::regex("reforms"), [this](const std::string& unused, std::istream& theStream)
	{
		commonItems::stringList reformList(theStream);
		for (const auto& reform : reformList.getStrings()) reforms.insert(reform);
	});
	registerKeyword(std::regex("[a-zA-Z0-9_\\.:]+"), commonItems::ignoreItem);

	parseStream(theStream);
}

