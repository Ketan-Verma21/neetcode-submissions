class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int n=numbers.size();
        int a=0,b=n-1;
        while(a<b){
            if(numbers[a]+numbers[b]<target){
                a++;
            }
            else if(numbers[a]+numbers[b]==target){
                return {a+1,b+1};
            }
            else{
                b--;
            }
        }
        return {};
    }
};
