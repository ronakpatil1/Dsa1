#include<iostream>
using namespace std;
//Q.5)Merge overlapping subintervals

//naive approach using stack
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) 
    {
       vector<vector<int>> v;
        int size=intervals.size();
        sort(intervals.begin(),intervals.end());
         stack<pair<int,int>> s;
        s.push({intervals[0][0],intervals[0][1]});
        for(int i=1;i<size;i++)
        {
            int start1=s.top().first;
            int end1=s.top().second;
            int start2=intervals[i][0];
            int end2=intervals[i][1];
            if(end1<start2)
                s.push({start2,end2});
            else
            {
                s.pop();
                end1=max(end1,end2);
                s.push({start1,end1});
            }
        }
        while(!s.empty())
        {
            v.push_back({s.top().first,s.top().second});
            s.pop();
        }
        
         return v;
    }
};
