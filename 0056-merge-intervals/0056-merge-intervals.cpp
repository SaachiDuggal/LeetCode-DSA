class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        
        //edge cases
        if(intervals.empty()){
            return {};
        }

        //initialise result
        vector<vector<int>> result;

        //sort the array
        sort(intervals.begin(), intervals.end());

        //add first interval to the result
        result.push_back(intervals[0]);

        //loop through the rest of the array
        for(int current = 1; current < intervals.size(); current++){
            //check of the current interval overlaps the last in the result vector
            //if yes then merge the interval, if not, then push back this current interval
            if(intervals[current][0] <= result.back()[1]){
                result.back()[1] = max(result.back()[1], intervals[current][1]);
            }
            else{
                result.push_back(intervals[current]);
            }
        }
            
        //return result
        return result;
    }
};