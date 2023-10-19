#include <iostream>
#include <unordered_map>
#include <vector>

std::vector<int>
find_subarray_with_given_sum(const std::vector<int>& arr,
							int sum)
{
	std::unordered_map<int, int> map;
	int curr_sum = 0;
	for (int i = 0; i < arr.size(); i++) {
		curr_sum += arr[i];
		if (map.count(curr_sum - sum)) {
			return std::vector<int>(
				arr.begin() + map[curr_sum - sum] + 1,
				arr.begin() + i + 1);
		}
		map[curr_sum] = i;
	}
	return {};
}

int main()
{
	std::vector<int> arr = { 15, 2, 4, 8, 9, 5, 10, 23 };
	std::vector<int> subarray
		= find_subarray_with_given_sum(arr, 23);
	if (subarray.empty()) {
		std::cout << "No subarray with given sum found"
				<< std::endl;
	}
	else {
		std::cout << "Subarray: [ ";
		for (int i : subarray) {
			std::cout << i << " ";
		}
		std::cout << "]" << std::endl;
	}
	return 0;
}
