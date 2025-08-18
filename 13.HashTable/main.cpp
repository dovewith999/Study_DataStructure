#include "HashTable.h"

int main()
{
	HashTable table;

	table.Add("Ronnie", "010-12345678");
	table.Add("Ronnie", "010-37610942");
	table.Add("Kevin", "010-32979287");
	table.Add("Baker", "010-29871982");
	table.Add("Taejun", "010-39487298");

	table.Print();

	TPair<std::string, std::string> find;

	if (table.Find("Ronnie", find))
	{
		std::cout << "검색 결과: " << find.key << ", " << find.value << '\n';
	}

	table.Delete("Ronnie");
	table.Delete("Baker");
	table.Delete("Test");

	table.Print();

	std::cin.get();

	return 0;
}