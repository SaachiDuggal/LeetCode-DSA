class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        
        //no edge case here as numRows start from greater than or equal to 1

        //initialise a 2D vector to store our result
        vector<vector<int>>triangle;

        //outerLoop for tracking number of rows
        for(int row = 0; row < numRows; row++){

            //Instantiate the current row with r+1 size and all values as 1.
            vector<int>currentRow(row + 1, 1);

            //InnerLoop to fill in only the middle rooms skipping boundaries as they are one only
            for(int column = 1; column < row; column++){
                //calculating the column value
                currentRow[column] = triangle[row-1][column-1] + triangle[row-1][column];
            }
            triangle.push_back(currentRow);
        }
        return triangle;
    }
};


