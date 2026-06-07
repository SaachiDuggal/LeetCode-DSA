class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        
        //edge case
        if(nums.empty() || nums.size() == 1){
            return {};
        }

        //we make an unordered map to keep track of the elements and there indices
        unordered_map<int, int>seen;

        //loop through the array to fill up the hash map and look for the target
        for(int pointer = 0; pointer < nums.size(); pointer++){

            //calculate the complement
            int complement = target - nums[pointer];

            //look for the complement in the map
            if(seen.find(complement) != seen.end()){
                return {seen[complement], pointer};
            }
            else{
                //we add the current element with its index to the map
                seen[nums[pointer]] = pointer;
            }
        }
        return{};
    }
};