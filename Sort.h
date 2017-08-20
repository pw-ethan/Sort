#ifndef SORT_H_INCLUDED
#define SORT_H_INCLUDED

#include <vector>

using std::vector;


void PrintVector(const vector<int> &vec);


int SelectPivot(vector<int> &nums, int left, int right);
int SelectPivotRandom(vector<int> &nums, int left, int right);
int SelectPivotMiddleOfThree(vector<int> &nums, int left, int right);
void QuickSort(vector<int> &nums, int left, int right);

// ≤Â»Î≈≈–Ú°¢’€∞Î≤Â»Î≈≈–Ú°¢œ£∂˚≈≈–Ú
void InsertSort(vector<int> &nums);
void BinaryInsertSort(vector<int> &nums);
void GapInsertSort(vector<int> &nums, int gap);
void ShellSort(vector<int> &nums);

#endif // SORT_H_INCLUDED
