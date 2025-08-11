#include <bits/stdc++.h> 
int getLongestSubarray(vector<int>& nums, int k){
    // Write your code here
    unordered_map<int, int> mpp; //used unordered map because in average case TC is O(n) instead of O(nlogn) for ordered map.
    int sum=0;
    int maxLen=0;
    for(int i=0;i<nums.size();i++){
        sum+=nums[i];
        if(sum==k)// used this  condition so that if sum appears during iteration we do not miss it like k=3, and first element is 3 so we need to keep that in mind
        {
            maxLen=max(maxLen, i+1);

        }
        int remaining=sum-k; // what is remaining, like we need 3 {1,1, 2} so remaining will be one in this case and we need to return the position of 1, as 1+2 =3 so it will be two elements
        if(mpp.find(remaining)!=mpp.end())//this condition says if key "value" is found, as mpp.find() returns mpp.end() if the value searching is not found.
        {
            int len=i-mpp[remaining];
            maxLen=max(maxLen, len);
        }
        if(mpp.find(sum)==mpp.end())//this condition is made to find if sum exists already or not, if it exists then no need to change the key "value" again, specially needed when array contains zeroes as well
          // like {1,0,0,0,3}, so longeset subarray with k=3 will be 4 and not 1
        {
            mpp[sum]=i;
        }


    }

    return maxLen;
}
