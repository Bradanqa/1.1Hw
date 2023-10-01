#include <iostream>
#include <fstream>

int main()
{
	int n = 0;
	int temp = 0;

	std::ifstream userData("in.txt");

	if (!userData.is_open())
		return -1;

	userData >> n;
	int firstSize = n;

	int* firstArr = new int[firstSize];
	for (int i = 0; i < firstSize; i++) {
		userData >> temp;
		firstArr[i] = temp;
	}

	userData >> n;
	int secondSize = n;
	int* secondArr = new int[secondSize];

	for (int i = 0; i < secondSize; i++) {
		userData >> temp;
		secondArr[i] = temp;
	}

	userData.close();

	std::ofstream newData("out.txt");
	newData << secondSize << "\n";

	if (newData.is_open()) {

		for (int i = 0; i < secondSize; i++) {
			if (i == 0)
				newData << secondArr[secondSize - 1] << " ";
			else
				newData << secondArr[i - 1] << " ";
		}

		newData << "\n" << firstSize << "\n";

		for (int i = 0; i < firstSize; i++) {
			if (i == firstSize - 1)
				newData << firstArr[0] << " ";
			else
				newData << firstArr[i + 1] << " ";
		}

		newData.close();
	}

	delete[] firstArr;
	delete[] secondArr;
	return 0;
}
