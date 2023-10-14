#include <vector>

class Solution {
public:
    // Function to find the starting and ending position of a target value in a sorted array
    std::vector<int> searchRange(std::vector<int>& nums, int target) {
        int n = nums.size();
        
        // Find the leftmost occurrence (starting position) of the target
        int left = findFirstOccurrence(nums, target);
        
        // If the target is not found, return [-1, -1]
        if (left == -1) {
            return {-1, -1};
        }
        
        // Find the rightmost occurrence (ending position) of the target
        int right = findLastOccurrence(nums, target);
        
        // Return the result as a vector [starting position, ending position]
        return {left, right};
    }

private:
    // Binary search to find the leftmost occurrence of the target
    int findFirstOccurrence(const std::vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;
        int result = -1;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (nums[mid] == target) {
                result = mid;
                right = mid - 1; // Continue searching on the left side
            } else if (nums[mid] < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        return result;
    }

    // Binary search to find the rightmost occurrence of the target
    int findLastOccurrence(const std::vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;
        int result = -1;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (nums[mid] == target) {
                result = mid;
                left = mid + 1; // Continue searching on the right side
            } else if (nums[mid] < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        return result;
    }
};
