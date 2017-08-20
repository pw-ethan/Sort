#include "Sort.h"
#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

#define min(x, y) (x > y ? y : x)


void PrintVector(const vector<int> &vec)
{
	cout << "[ ";
	for(auto item : vec){
		cout << item << " ";
	}
	cout << "]" << endl;
}


// --交换排序-------------------------------------------
void bubbleSort(vector<int> &nums) // 需要把参数声明为引用，否则只是对形参进行排序
{
    if(nums.empty()){
        return;
    }
    int top= nums.size() - 1;
    while(top!= 0){
        for(int i = 0; i < top; ++i){
            if(nums[i] > nums[i + 1]){
                int tmp = nums[i];
                nums[i] = nums[i + 1];
                nums[i + 1] = tmp;
               /* 另一种交换方法 */
                //nums[i] = nums[i + 1] + nums[i];
                //nums[i + 1] = nums[i] - nums[i + 1];
                //nums[i] = nums[i] - nums[i + 1];
               /* 另一种交换方法 */
                //nums[i] = nums[i + 1] ^ nums[i];
                //nums[i + 1] = nums[i] ^ nums[i + 1];
                //nums[i] = nums[i] ^ nums[i + 1];
            }
        }
        --top;
    }
}

void bubbleSort1(vector<int> &nums) // 需要把参数声明为引用，否则只是对形参进行排序
{
	if(nums.empty()){
		return;
	}
	int top = nums.size() - 1;
	int bound = top;
	while(top != 0){
		for(int i = 0; i < bound; ++i){
			if(nums[i] > nums[i + 1]){
				nums[i] = nums[i + 1] ^ nums[i];
				nums[i + 1] = nums[i] ^ nums[i + 1];
				nums[i] = nums[i] ^ nums[i + 1];
				bound = i;
			}
		}
		--top;
	}
}

void bubbleSort2(vector<int> &nums) // 需要把参数声明为引用，否则只是对形参进行排序
{
	if(nums.empty()){
		return;
	}
	int top = nums.size() - 1;
	bool flag = true;
	while(flag && top != 0){
		flag = false;
		for(int i = 0; i < top; ++i){
			if(nums[i] > nums[i + 1]){
				swap(nums[i], nums[i + 1]);
				flag = true;
			}
		}
		--top;
	}
}

void cocktailSort(vector<int> &nums)
{
	if(nums.empty()){
		return;
	}
	int top	= nums.size() - 1;
	int bottom = 0;
	int bound = 0;
	bool flag = true;
	while(flag){
		flag = false;
		for(int i = bottom; i < top; i++){
			if(nums[i] > nums[i + 1]){
				swap(nums[i], nums[i + 1]);
				flag = true;
				bound = i;
			}
		}
		top = bound;
		for(int i = top; i > bottom; i--){
			if(nums[i] < nums[i - 1]){
				swap(nums[i], nums[i - 1]);
				flag = true;
				bound = i;
			}
		}
		bottom = bound;
	}
}

void oddEvenSort(vector<int> &nums)
{
	if(nums.empty()){
		return;
	}
	int top = nums.size() - 1;
	bool oddFlag = true;
	bool evenFlag = true;
	while(oddFlag || evenFlag){
		oddFlag = false;
		evenFlag = false;
		for(int i = 0; i < top; i += 2){
			if(nums[i] > nums[i + 1]){
				swap(nums[i], nums[i + 1]);
				oddFlag = true;
			}
		}
		for(int i = 1; i < top; i += 2){
			if(nums[i] > nums[i + 1]){
				swap(nums[i], nums[i + 1]);
				evenFlag = true;
			}
		}
	}
}

// 选固定值基准
int SelectPivot(vector<int> &nums, int left, int right) {
    return nums[left];
}
// 随机选基准
int SelectPivotRandom(vector<int> &nums, int left, int right) {
    srand(unsigned(time(nullptr)));
    int index = rand() % (right - left) + left;
    swap(nums[left], nums[index]);
    return nums[left];
}
// 三数取中选基准
int SelectPivotMiddleOfThree(vector<int> &nums, int left, int right) {
    int mid = (left + right) >> 1;
    if (nums[mid] > nums[right]) {
        swap(nums[mid], nums[right]);
    }
    if (nums[left] > nums[right]) {
        swap(nums[left], nums[right]);
    }
    if (nums[mid] > nums[left]) {
        swap(nums[mid], nums[left]);
    }
    return nums[left];
}
// 快速排序
void QuickSort(vector<int> &nums, int left, int right)
{
	if (nums.empty()) return;

	if(left < right){
		int low = left;
		int high = right;
		int key = SelectPivotMiddleOfThree(nums, left, right);
		while(low < high)
		{
			while(low < high && nums[high] > key){
				high--;
			}
			if(low < high){
				nums[low++] = nums[high];
			}
			while(low < high && nums[low] < key){
				low++;
			}
			if(low < high){
				nums[high--] = nums[low];
			}
		}
		nums[low] = key;
		QuickSort(nums, left, low - 1);
		QuickSort(nums, low + 1, right);
	}
}

void combSort(vector<int> &nums)
{
	float shrink_factor = 1.3f;
	int gap = nums.size();
	bool flag = true;
	while(gap > 1 || flag){
		if(gap > 1){
			gap /= shrink_factor;
		}
		flag = false;
		for(int i = 0; i + gap < nums.size(); i++){
			if(nums[i] > nums[i + gap]){
				swap(nums[i], nums[i + gap]);
				flag = true;
			}
		}
	}
}
// --交换排序-------------------------------------------

// --归并排序-------------------------------------------
void merge(vector<int> &nums, int start, int middle, int end)
{
	vector<int> tmp(end - start + 1);
	int s = start, m = middle + 1, k = 0;
	while(s != middle + 1 && m != end + 1){
		if(nums[s] > nums[m]){
			tmp[k++] = nums[m++];
		}
		else{
			tmp[k++] = nums[s++];
		}
	}
	while(s != middle + 1){
		tmp[k++] = nums[s++];
	}
	while(m != end + 1){
		tmp[k++] = nums[m++];
	}
	for(k = start; k < end + 1; k++){
		nums[k] = tmp[k - start];
	}
}
void mergeSort(vector<int> &nums, int start, int end)
{
	if(start < end){
		int middle = (start + end) / 2;
		mergeSort(nums, start, middle);
		mergeSort(nums, middle + 1, end);
		merge(nums, start, middle, end);
	}
}
void mergePass(vector<int> &nums)
{
	int len = nums.size();
	int gap = 1;
	while(gap <= len){
		for(int i = 0; i < len; i += gap * 2){
			merge(nums, i, min(i + gap - 1, len - 1), min(i + gap * 2 - 1, len - 1));
		}
		gap *= 2;
	}
}


// --选择排序-------------------------------------------
void selectionSort(vector<int> &nums)
{
	int top = nums.size() - 1;
	for(int i = 0; i < top; i++){
		int min = i;
		for(int j = i + 1; j <= top; j++){
			if(nums[j] < nums[min]){
				min = j;
			}
		}
		if(min != i){
			swap(nums[min], nums[i]);
		}
	}
}

void max_heapify(vector<int> &nums, int index, int size)
{
	int left = index * 2 + 1;
	int right = index * 2 + 2;
	int max = index;
	if(left < size && nums[left] > nums[max]){
		max = left;
	}
	if(right < size && nums[right] > nums[max]){
		max = right;
	}
	if(max != index){
		swap(nums[max], nums[index]);
		max_heapify(nums, max, size);
	}
}
void build_heap(vector<int> &nums)
{
	for(int i = nums.size() / 2 - 1 ; i >= 0; i--){
		max_heapify(nums, i, nums.size());
	}
}
void heapSort(vector<int> &nums)
{
	build_heap(nums);
	for(int i = nums.size() - 1; i > 0; i--){
		swap(nums[i], nums[0]);
		max_heapify(nums, 0, i);
	}
}

// 插入排序
void InsertSort(vector<int> &nums)
{
	int len = nums.size();
	for(int i = 1; i < len; i++){
		int tmp = nums[i];
		int j = i - 1;
		while(j >= 0 && nums[j] > tmp){
			nums[j + 1] = nums[j];
			j--;
		}
		nums[j + 1] = tmp;
	}
}
// 折半插入排序
void BinaryInsertSort(vector<int> &nums)
{
	int len = nums.size();
	for(int i = 1; i < len; i++){
		if(nums[i] < nums[i - 1]){
			int low = 0;
			int high = i - 1;
			int tmp = nums[i];
			while(low <= high){
				int mid = (low + high) >> 1;
				if(tmp < nums[mid]){
					high = mid - 1;
				}
				else{
					low = mid + 1;
				}
			}
			for(int j = i; j > high + 1; j--){
				nums[j] = nums[j - 1];
			}
			nums[high + 1] = tmp;
		}
	}
}

void GapInsertSort(vector<int> &nums, int gap)
{
	int len = nums.size();
	for(int i = gap; i < len; i += gap){
		int tmp = nums[i];
		int j = i - gap;
		while(j >= 0 && nums[j] > tmp){
			nums[j + gap] = nums[j];
			j -= gap;
		}
		nums[j + gap] = tmp;
	}
}
void ShellSort(vector<int> &nums)
{
	int len = nums.size();
	for(int i = len / 2; i > 2; i /= 2){
		GapInsertSort(nums, i);
	}
	GapInsertSort(nums, 1);
}


// --分布排序-------------------------------------------
void pigeonholeSort(vector<int> &nums)
{
	vector<int> tmp(100);
	int len = nums.size();
	for(int i = 0; i < len; i++){
		tmp[nums[i]]++;
	}
	int k = 0;
	for(int i = 0; i < 100; i++){
		for(int j = 0; j < tmp[i]; j++){
			nums[k++] = i;
		}
	}
}
