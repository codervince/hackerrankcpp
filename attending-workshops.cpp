#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
//my code
//Define the structs Workshops and Available_Workshops.
//Implement the functions initialize and CalculateMaxWorkshops
struct Workshop 
{
    int start_time; 
    int end_time;
    int duration;
};

struct Available_Workshops
{
  int n=0; //number of enrolled workshops
  Workshop wks[100000];
};

Available_Workshops * initialize( int start_time[], int duration[], int N)
{

Available_Workshops *aw = new Available_Workshops;
(*aw).n = N;
for (int i =0; i < N; i++)
    {
    //init Available_Workshops each one a struct containing a struct
    (aw->wks[i]).start_time = start_time[i];
    (aw->wks[i]).duration = duration[i];
    (aw->wks[i]).end_time = start_time[i] + duration[i];
    }
    return aw;
}

bool compare (const pair<int, int>& a, const pair<int, int>& b){
    return a.second < b.second; //get lower end time
}

int CalculateMaxWorkshops(Available_Workshops * ptr)
{
    vector<pair<int,int>> result;
    int n = (*ptr).n;
    for (int j= 0; j < n; j++){
            result.push_back(make_pair( ptr->wks[j].start_time, ptr->wks[j].end_time ));
    }
    // find minimum remove overlaps
    sort(result.begin(), result.end(), compare);
    //for(vector<pair<int, int> >::iterator it = result.begin(); it != result.end(); it++){
      //  cout << it->first << "-" << it->second << endl;
    //}
    
    // algorithm:
    // 1. choose min end (first) in sorted result this is result[0]
    // 2. "remove" X ie move to next "Remove" ie move to next and count if result[k].first > min.end_time
    // 3. then return to 1
    // IN A LOOP instead of removal move to next since sorted 
    int min;
    int count=0; //or count = 1
    min = result[0].second; //min end time 
    for (int k = 1; k < n; k++){
        if(result[k].first >= min){
            count++;
            //then min becomes this one
            min = result[k].second;
        }
    }
  //the last one always works  or count=1
  return count+1;      
}    




//tester code
int main()
{
    int n;
    cin>>n;
    int start_time[n],duration[n];
    for(int i=0;i<n;i++)
    {
        cin>>start_time[i];
    }
    for(int i=0;i<n;i++)
    {
        cin>>duration[i];
    }
    
    Available_Workshops * ptr;
    ptr=initialize(start_time,duration,n);
    cout<<CalculateMaxWorkshops(ptr)<<endl;
    return 0;
}
