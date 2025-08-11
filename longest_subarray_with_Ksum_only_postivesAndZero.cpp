//this solution wil only work when we have positives and zeros, it fails for negative numbers

#include <bits/stdc++.h> 
int getLongestSubarray(vector<int>& nums, int k){
//follows the two pointer apporach, where we will increment the right pointer only till sum==k, as it becomes sum>k we will increament left pointer while decreasign the value of sum
    int left=0;int right=0; int sum=nums[0]; int maxLen=0;
    int n=nums.size();
    while(right<n){

        while(left<=right&&sum>k){
            sum-=nums[left];
            left++;
        }
        if(sum==k){
            maxLen=max(maxLen, right-left+1);
        }
        //we will increment right first then only add as sum is already a[0] here
        right++;
        if(right<n) sum+=nums[right];
    }
    return maxLen;
}

//time complexity is O(2N) as first while loop runs for n times, second runs for n times overall- i.e. it does not runs n times every time otherwise it will be n^2, 
// it runs for 1 times, then sometimes 2 times, sometimes zero times, so overall n times. hence it will be n+n and not n*n.
//space complexity will be O(1) as we are not using any space.
