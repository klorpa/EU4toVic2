#include "StartingInventionLimit.h"
#include "ParserHelpers.h"
#include "StartingInventionDetails.h"


mappers::StartingInventionLimit::StartingInventionLimit(std::istream& theStream)
{
	registerKeyword("limit", [this](const std::string& unused, std::istream& theStream) {
		const StartingInventionDetails limitBlock(theStream);
		techName = limitBlock.getTechName();
	});
	registerRegex("[a-zA-Z0-9\\_.:]+", commonItems::ignoreItem);

	parseStream(theStream);
	clearRegisteredKeywords();
}
