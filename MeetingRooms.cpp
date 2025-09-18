#include<iostream>
#include<bits/stdc++.h>
#include<vector>
using namespace std;
/*
We separate and sort all start and end times of the meetings.
We move through both arrays, increasing room count when a meeting starts before another ends.
We track the maximum number of concurrent meetings to find the room count
*/
class Solution{
public:
    int minMeetingRooms(vector<vector<int>>& intervals){
        vector<int> startTime(intervals.size());
        vector<int> endTime(intervals.size());

        for(int i=0; i<intervals.size(); i++){
            startTime.push_back(intervals[i][0]);
            endTime.push_back(intervals[i][1]);
        }

        sort(startTime.begin(), startTime.end());
        sort(endTime.begin(), endTime.end());

        int currRooms = 0;
        int result = 0;
        int i=0, j=0;
        while(i < startTime.size()){
            if(startTime[i] < endTime[j]){
                currRooms++;
                result = max(result, currRooms);
                i++;
            }else{
                currRooms--;
                j++;
            }
        }
        return result;
    }
};
