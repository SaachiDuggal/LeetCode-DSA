/*
class Solution {
public:
    int search(vector<int>& nums, int target) {
        //edge cases
        //initialising pointer left and right
        int left = 0;
        int right = nums.size() - 1;

        //loop till left <= right
        while(left <= right){

            //calculating mid
            int mid = left + (right - left) / 2;

            //if target found return mid
            if(target == nums[mid]){
                return mid;
            }

            //check if left side is sorted
            else if(nums[left] <= nums[mid]){
                //check if target exists in the range
                if(target >= nums[left] && target < nums[mid]){
                    right = mid - 1;
                }
                else{
                    left = mid + 1;
                }
            }
            //check if right side is sorted
            else{
                //check if it exists in the range
                if(target > nums[mid] && target <= nums[right]){
                    left = mid + 1;
                }
                else{
                    right = mid - 1;
                }
            }

        }
        return -1;
    }
};
*/


class Solution {
public:

    int binarySearch(vector<int>& nums, int target, int left, int right){

        //base case
        if(left > right){
            return -1;
        }

        //calculate mid
        int mid = left + (right - left) / 2;

        //found
        if(nums[mid] == target){
            return mid;
        }

        //if Left side is sorted
        if(nums[left] <= nums [mid]){

            //if target lies in the sorted range
            if(target < nums[mid] && target >= nums[left]){
                return binarySearch(nums, target, left, mid - 1);
            }
            else{
                return binarySearch(nums, target, mid + 1, right);
            }
        }

        //if right side is sorted
        else{

            //if target lies in the sorted range
            if(target > nums[mid] && target <= nums[right]){
                return binarySearch(nums, target, mid + 1, right);
            }
            else{
                return binarySearch(nums, target, left, mid - 1);
            }
        }
    }

    int search(vector<int>& nums, int target) {
        return binarySearch(nums, target, 0, nums.size() - 1);
    }

};