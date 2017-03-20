#include <iostream>
#include <vector>

using namespace std;

#define min(x, y) (x > y ? y : x)


void printVector(vector<int> &v)
{
	cout << "[ ";
	for(vector<int>::iterator it = v.begin(); it != v.end(); ++it){
		cout << *it << " ";
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

void swap(int &a, int &b)
{
	a = a ^ b;
	b = a ^ b;
	a = a ^ b;
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

void quickSort(vector<int> &nums, int left, int right)
{
	if(nums.empty()){
		return;
	}
	if(left < right){
		int low = left;
		int high = right;
		int key = nums[left];
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
		quickSort(nums, left, low - 1);
		quickSort(nums, low + 1, right);
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

// --插入排序------------------------------------------- 
void insertSort(vector<int> &nums)
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
void binaryInsertSort(vector<int> &nums)
{
	int len = nums.size();
	for(int i = 1; i < len; i++){
		if(nums[i] < nums[i - 1]){
			int low = 0;
			int high = i - 1;
			int tmp = nums[i];
			while(low <= high){
				int mid = (low + high) / 2;
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

void gapInsertSort(vector<int> &nums, int gap)
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
void shellSort(vector<int> &nums)
{
	int len = nums.size();
	for(int i = len / 2; i > 2; i /= 2){
		gapInsertSort(nums, i); 
	}
	gapInsertSort(nums, 1);
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

int main()
{
	//10 13 14 23 25 25 27 33 35 39 45 54 58 59 65 73 82 90 94 94
	int arr[] = {13,14,94,33,82,25,59,94,65,23,45,27,73,25,39,10,35,54,90,58};//{5, 4, 1, 3, 5};//{5, 4, 3, 2, 1,};//{1, 2, 3, 4, 5};
	vector<int> nums;
	for(int i = 0; i < sizeof(arr)/sizeof(int); ++i){
		nums.push_back(arr[i]);
	}
	printVector(nums);
	//bubbleSort(nums);
	//cocktailSort(nums);
	//oddEvenSort(nums);
	//quickSort(nums, 0, nums.size() - 1);
	//combSort(nums);
	//mergeSort(nums, 0, nums.size() - 1);
	//mergePass(nums);
	//selectionSort(nums);
	//heapSort(nums);
	//insertSort(nums);
	//binaryInsertSort(nums);
	//shellSort(nums);
	pigeonholeSort(nums); 
	printVector(nums);
	return 0;
}
