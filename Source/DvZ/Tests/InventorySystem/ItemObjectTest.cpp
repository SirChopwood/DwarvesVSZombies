#include "Misc/AutomationTest.h"
#include "../../Core/InventorySystem/ItemObject.h"

/*IMPLEMENT_SIMPLE_AUTOMATION_TEST(FPlaceholderTest, "TestGroup.TestSubgroup.Placeholder Test", EAutomationTestFlags::EditorContext | EAutomationTestFlags::EngineFilter)
	 
		bool FPlaceholderTest::RunTest(const FString& Parameters)
{
	// Make the test pass by returning true, or fail by returning false.
	return true;
}
*/

IMPLEMENT_SIMPLE_AUTOMATION_TEST(FItemObjectTest, "GetTooltipData_Implementation.ItemObject", EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter)

bool FItemObjectTest::RunTest(const FString& Parameters)
{
	UPDA_Enchantments* PDA_Enchantments = NewObject<UPDA_Enchantments>();
	PDA_Enchantments->Name = FText::FromString("PDA_Enchantments");
	PDA_Enchantments->MaxTiers=10;
	UItemObject* Item = NewObject<UItemObject>();
	FText TestItem = FText::FromString("TestItem");
	FText TestItemDescription = FText::FromString("Description of a test item");
	TArray<FS_TooltipStat> PreviousStats;
	TArray<FS_TooltipStat> Stats;
	
	Item->GetTooltipData_Implementation(PreviousStats,TestItem,TestItemDescription,Stats);
	

	if (Item->ItemName.ToString() != TestItem.ToString() or Item->ItemDescription.ToString() != TestItemDescription.ToString())
	{
		AddError(TEXT("GetTooltipData_Implementation does not assign a ItemName or ItemDescription correctly, it assigned"+TestItem.ToString()+" and "+TestItemDescription.ToString()));
	}
	if(Stats.IsEmpty())
	{
		AddError(TEXT("Stats is empty"+Stats.IsEmpty()));
	}

	return true;
}


