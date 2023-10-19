#include <iostream>
#include <vector>
using namespace std;

int search(vector<int>& nums, int target, bool findStartIndex)
{
	int answer = -1;
	int start = 0;
	int end = nums.size() - 1;
	while (start <= end) {
		int mid = start + (end - start) / 2;
		if (target < nums[mid]) {
			end = mid - 1;
		}
		else if (target > nums[mid]) {
			start = mid + 1;
		}
		else {
			answer = mid;
			if (findStartIndex) {
				end = mid - 1;
			}
			else {
				start = mid + 1;
			}
		}
	}
	return answer;
}

int countOccurrences(vector<int>& nums, int x)
{
	int firstIndex = search(nums, x, true);
	int lastIndex = search(nums, x, false);
	if (firstIndex != -1 && lastIndex != -1)
		return lastIndex - firstIndex + 1;
	else
		return 0;
}

int main()
{
	vector<int> arr{ 1, 2, 2, 2, 2, 3, 4, 7, 8, 8 };
	int x = 2;
	int c = countOccurrences(arr, x);
	cout << x << " occurs " << c << " times" << endl;
	return 0;
}
