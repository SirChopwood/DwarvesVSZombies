#include "Misc/AutomationTest.h"
#include "../../Core/InventorySystem/ItemObject.h"
#include "DvZ/Core/InventorySystem/ItemObject_Armour.h"
IMPLEMENT_SIMPLE_AUTOMATION_TEST(FItemObject_ArmourTest, "GetTooltipData_Implementation.ItemObject_ArmourTest", EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter)

bool FItemObject_ArmourTest::RunTest(const FString& Parameters)
{
	UPDA_Enchantments* PDA_Enchantments = NewObject<UPDA_Enchantments>();
	PDA_Enchantments->Name = FText::FromString("PDA_Enchantments");
	PDA_Enchantments->MaxTiers=10;
	UItemObject_Armour* ArmourItem = NewObject<UItemObject_Armour>();
	FText TestItem = FText::FromString("TestItem");
	FText TestItemDescription = FText::FromString("Description of a test item");
	TArray<FS_TooltipStat> PreviousStats;
	TArray<FS_TooltipStat> Stats;
	ArmourItem->CurrentDurability = 2;
	ArmourItem->MaxDurability = 10;
	ArmourItem->GetTooltipData(PreviousStats,TestItem,TestItemDescription,Stats);
	

	if (ArmourItem->ItemName.ToString() != TestItem.ToString() or ArmourItem->ItemDescription.ToString() != TestItemDescription.ToString())
	{
		AddError(TEXT("GetTooltipData_Implementation does not assign a ItemName or ItemDescription correctly, it assigned"+TestItem.ToString()+" and "+TestItemDescription.ToString()));
	}
	if(Stats.IsEmpty())
	{
		AddError(TEXT("Stats is empty"+Stats.IsEmpty()));
	}

	return true;
}