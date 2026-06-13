class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        
        //edge case: if the array size is <= 1 or if k = 0
        if(nums.size() <= 1 || k == 0){
            return false;
        }

        //initialising a set to store the values in the k window in the array
        unordered_set<int> window;

        //initialising variable for the leftMost index of the k window
        int left = 0;

        //looping the array with a right variable to move across the array and scan for duplicates in the k window
        for(int right = 0; right < nums.size(); right++){

            //we check first if the right index is in the window or not
            while(right - left > k){
                window.erase(nums[left]);
                left++;
            }

            //we check for the duplicate
            if(window.find(nums[right]) != window.end()){
                return true;
            }

            //we insert the element
            window.insert(nums[right]);
        }
        return false;
    }
};

