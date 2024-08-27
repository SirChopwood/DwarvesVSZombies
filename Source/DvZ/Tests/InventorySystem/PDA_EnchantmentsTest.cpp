#include "Misc/AutomationTest.h"
#include "../../Core/InventorySystem/PDA_Enchantments.h"

IMPLEMENT_SIMPLE_AUTOMATION_TEST(FPDA_EnchantmentsTest, "GetFormattedName.PDA_Enchantments", EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter)

bool FPDA_EnchantmentsTest::RunTest(const FString& Parameters)
{
	UPDA_Enchantments* PDA_Enchantments = NewObject<UPDA_Enchantments>();
	PDA_Enchantments->Name = FText::FromString("PDA_Enchantments");
	PDA_Enchantments->MaxTiers=10;
	FText EnchantmentsText;
	PDA_Enchantments-> GetFormattedName(1,EnchantmentsText);
	FText EnchantmentsText2 = FText::FromString("PDA_Enchantments I");

	if (FString EnchantmentsString = EnchantmentsText.ToString(); EnchantmentsString != "PDA_Enchantments I")
	{
		AddError(TEXT("GetFormattedName does not assign the correct value to EnchantmentsString, it is "+ EnchantmentsString + " but should be PDA_Enchantments I"));
	}

	return true;
}