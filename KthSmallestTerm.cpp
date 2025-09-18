#include<iostream>
#include<bits/stdc++.h>
#include<vector>
using namespace std;
/*
We binary search between the smallest and largest matrix values.
For each mid, we count how many elements are ≤ mid using binary search per row.
If the count is less than k, we go right; else we go left and return the smallest valid number
*/
class Solution{
    int getCount(vector<vector<int>>& matrix, int m, int n, int target){
        int count = 0;
        for(int i = 0; i<m; i++){
            count += binarySearch(matrix[i], target);
        }
        return count;
    }

    int binarySearch(vector<int>& row, int target){
        int low = 0, high = row.size()-1;
        while(low <= high){
            int mid = low + (high - low)/2;
            if(row[mid] < target) low = mid +1;
            else high = mid - 1;
        }
        return low;
    }
public:
    int kthSmallest(vector<vector<int>>& matrix, int k){
        int m = matrix.size();
        int n = matrix[0].size();

        int low = matrix[0][0];
        int high = matrix[m-1][n-1];

        while(low <= high){
            int mid = low + (high - low)/2;
            int count = getCount(matrix, m, n, mid);
            if(count < k) low = mid + 1;
            else high = mid - 1;
        }
        return low;
    }
};
