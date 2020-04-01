#include <ostream>
#include <vector>
#include <algorithm>

using namespace std;

/* medium */
// 非随机选轴
class Solution {
public:
	vector<int> sortArray(vector<int>& nums) {
		QuickSort(nums, 0, nums.size() - 1);
		return nums;
	}
	void QuickSort(vector<int>& nums, int l, int r) {
		if (l < r)
		{
			int mid = partition(nums, l, r);
			QuickSort(nums, l, mid - 1);//注意点，l和r的值自己写错
			QuickSort(nums, mid + 1, r);//注意点,l和r的值自己写错
		}
	}
	int partition(vector<int>& nums, int l, int r)
	{
		int pivot = nums[l];
		int i = l + 1, j = r;
		while (true)
		{
			while (i <= j && nums[i] <= pivot) i++;//寻找比pivot大的元素
			while (i <= j && nums[j] >= pivot) j--;//寻找比pivot小的元素
			if(i>j) break;
			swap(nums[i], nums[j]);
		}
		//把arr[j]和主元交换
		swap(nums[j], nums[l]);
		return j;//为什么返回j而不是i，因为swap是先执行i++的while语句，如果和下面的替换顺序，则返回i
	}
};

// 随机选轴
/*
class Solution {
public:
	vector<int> sortArray(vector<int>& nums) {
		QuickSort(nums, 0, nums.size() - 1);
		return nums;
	}
	void QuickSort(vector<int>& nums, int l, int r) {
		if (l < r)
		{
			int partition = randomPartition(nums, l, r);
			QuickSort(nums, l, partition - 1);
			QuickSort(nums, partition + 1, r);
		}
	}
	int randomPartition(vector<int>& nums, int l, int r)
	{
		int i = (rand() % (r - l + 1)) + l;//产生[a,b]的随机整数
		swap(nums[i], nums[l]);
		return partition(nums, l, r);
	}
	int partition(vector<int>& nums, int l, int r)
	{
		int pivot = nums[l];
		int i = l + 1, j = r;//双指针，分别指向首尾
		while (true)
		{
			while (i <= j && nums[i] <= pivot) i++;
			while (i <= j && nums[j] >= pivot) j--;
			if (i > j) break;
			//交换位置
			swap(nums[i], nums[j]);
		}
		//交换主元
		swap(nums[j], nums[l]);
		return j;
	}
};
*/