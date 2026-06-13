class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        
        //edge case if array is empty or just have one element or if k == 0
        if(nums.empty() || nums.size() == 1 || k == 0){
            return false;
        }

        //initialising a hash set for storing k elements
        unordered_set<int> window;

        //looping through the array to find a duplicate within k size
        for(int right = 0; right < nums.size(); right++){

            //when the size of hash set exceeds the window of k
            if(right > k){
                //remove the leftMost element of the hashset to maintain the length
                window.erase(nums[right - k - 1]);
            }

            //if we find a match
            if(window.find(nums[right]) != window.end()){
                return true;
            }

            //else we just add the nums[right] in the set and move to the next element
            window.insert(nums[right]);
        }
        return false;
    }
};

