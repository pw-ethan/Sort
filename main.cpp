#include <iostream>
#include <vector>

#include "Sort.h"

using namespace std;

int main()
{
    //{5, 4, 1, 3, 5};
    //{5, 4, 3, 2, 1,};
    //{1, 2, 3, 4, 5};
	vector<int> nums = {13, 14, 94, 33, 82, 25, 59, 94, 65, 23, 45, 27, 73, 25, 39, 10, 35, 54, 90, 58};
	PrintVector(nums);

	QuickSort(nums, 0, nums.size() - 1);

	//bubbleSort(nums);
	//cocktailSort(nums);
	//oddEvenSort(nums);
	//quickSort(nums, 0, nums.size() - 1);
	//combSort(nums);
	//mergeSort(nums, 0, nums.size() - 1);
	//mergePass(nums);
	//selectionSort(nums);
	//heapSort(nums);
	//InsertSort(nums);
//	BinaryInsertSort(nums);
//	ShellSort(nums);
    //pigeonholeSort(nums);

    PrintVector(nums);
	return 0;
}
