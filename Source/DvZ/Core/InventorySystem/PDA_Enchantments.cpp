#include "PDA_Enchantments.h"

//From the wikipedia page Roman numerals/Encode by Rosetta Code contributors. Link is https://rosettacode.org/wiki/Roman_numerals/Encode#C++_11
std::string To_Roman(int x) {
	if (x <= 0)
		return "Negative or zero!";
	auto roman_digit = [](char one, char five, char ten, int x) {
		if (x <= 3)
			return std::string().assign(x, one);
		if (x <= 5)
			return std::string().assign(5 - x, one) + five;
		if (x <= 8)
			return five + std::string().assign(x - 5, one);
		return std::string().assign(10 - x, one) + ten;
	};
	if (x >= 1000)
		return x - 1000 > 0 ? "M" + To_Roman(x - 1000) : "M";
	if (x >= 100) {
		auto s = roman_digit('C', 'D', 'M', x / 100);
		return x % 100 > 0 ? s + To_Roman(x % 100) : s;
	}
	if (x >= 10) {
		auto s = roman_digit('X', 'L', 'C', x / 10);
		return x % 10 > 0 ? s + To_Roman(x % 10) : s;
	}
	return roman_digit('I', 'V', 'X', x);
}

void UPDA_Enchantments::GetFormattedName(int32 Tier, FText& FormattedName)
{
	uint8 ClampTier = std::clamp(Tier, 1, MaxTiers);
	FString RomanNumeral = To_Roman(ClampTier).c_str();
	FormattedName = FText::FromString("{name} {To_Roman(ClampTier)}");
}
