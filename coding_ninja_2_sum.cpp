/*Problem statement-
Given an integer array Arr of size N and an integer target, your task is to find the indices of two elements of the array such that their sum is equal to target. Return <-1,-1> if no such pair exists.
Note:
If more than one such pair of indices exist, return the lexicographically smallest pair
You may not use the same element twice.
Link- https://www.naukri.com/code360/problems/2-sum_893025?interviewProblemRedirection=true&search=2%20sum&leftPanelTabValue=PROBLEM
*/

#include<bits/stdc++.h>
pair<int,int> twoSum(vector<int>& arr, int n, int target) {

    map<int, int> mpp; // this map will store the results which are equal to my target
    map<int, int> m1; // i made this map to push all the result pairs in lexographical order as there may be more than two solutions, this is only required in case of lexographical order being asked
    for(int i=0;i<n;i++){
        int remaining=target-arr[i]; 
        if(mpp.find(remaining)!=mpp.end())//this line checks if the remaining is in the map or not
        {
            m1.insert({mpp[remaining], i}); //this line pushes the solution pair into second map where I will compare
        }
        if(mpp.find(arr[i])==mpp.end()) mpp[arr[i]]=i; // this condition is important because if the element already exists then we do not need to push it again, as element were repeating in the problem statetement 
    }
    if(m1.empty()) return {-1, -1}; //returnign {-1,-1} if no pair exists in the map
    else {
        auto i=m1.begin(); //making an iterator 
        return {i->first, i->second}; // returning the first element of map key, value as it is ordered map so everything is stored in the sorted way
    }
}
