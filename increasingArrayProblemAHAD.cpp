#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
   int minOperations(vector<int>& nums) {
        //int count = 0;
        /*int i = 0;
        int  j = i + 1;*/
        int start = nums[0];
        //int end = nums[j];
        int count = 0;
        //sort(nums.begin(), nums.end());
        
        for(int k=1;k<nums.size();k++){

            if (nums[k] > start) {
                start = nums[k];
                continue;
            }//if
               count += start - nums[k]+1;
               start++;
                  
              } //for
               
            

       
        return count;
    }

};
void main() {

    vector<int>nums = { 1, 5, 2, 4, 1 };
    Solution s;
   cout<< s.minOperations(nums);
    





}