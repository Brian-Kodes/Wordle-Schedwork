

#include <set>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include "schedwork.h"

using namespace std;

static const Worker_T INVALID_ID = (unsigned int)-1;


bool helperFunction (const AvailabilityMatrix& avail, const size_t dailyNeed, const size_t maxShifts, DailySchedule& sched, vector<int> numShiftsWorked, int row, int col);
bool isValid (std::vector<int> numDaysWorked, const AvailabilityMatrix& avail, DailySchedule& sched, const size_t dailyNeed, const size_t maxShifts);



bool isValid (const AvailabilityMatrix& avail, DailySchedule& sched, const size_t dailyNeed, const size_t maxShifts)
{
  for (int i = 0; i < (int)sched[0].size() - 1; i++)
  {
    int rowCounter = 0;
    for (int j = 0; j < (int)sched.size() - 1; j++)
    {
      if (sched[i][j] == 1)
      {
        rowCounter++;
      }
    }
    if (rowCounter > (int)dailyNeed)
    {
    return false;
    }
  }
  for (int i = 0; i < (int)sched[0].size() - 1; i++)
  {
    int oneCounter = 0;
    for (int j = 0; j < (int)sched.size() - 1; j++)
    {
      if (sched[j][i] == 1)
      {
        oneCounter++;
      }
    }
    if (oneCounter < (int)maxShifts)
    {
      return false;
    }
  }
return true;
}

bool helperFunction (const AvailabilityMatrix& avail, const size_t dailyNeed, const size_t maxShifts, DailySchedule& sched, vector<int> numShiftsWorked, int row, int col)
{
  if (col > (int)sched[0].size() - 1)
  {
    col = 0;
    helperFunction(avail, dailyNeed, maxShifts, sched, numShiftsWorked, row + 1, col);
  }
  if (row > (int)sched.size() - 1)
  {
    return true; 
  }


for (int j = 0; j < (int)avail[0].size(); j++)
{
  if (avail[row][col] == true)
  {
    sched[col][row] = true;
    if (isValid(avail, sched, dailyNeed, maxShifts))
    {
      numShiftsWorked[j]++;
    }
    else
    {
      sched[col][row] = INVALID_ID;
    }

  }
  numShiftsWorked[j]--;
}
  return false;
}



bool schedule(
    const AvailabilityMatrix& avail,
    const size_t dailyNeed,
    const size_t maxShifts,
    DailySchedule& sched
)
{
  std::vector<std::vector<Worker_T>> tempVector;
    if(avail.size() == 0U){
        return false;
    }
    sched.clear();
  int row = 0;
  int col = 0;
  std:: vector <int> numShiftsWorked (avail[0].size(), 0);
  for (int i = 0; i < (int)avail[0].size() -1; i++)
  {
    numShiftsWorked.push_back(0);
  }
  for (int i = 0; i < (int)avail.size() - 1; i++)
  {
    std::vector<Worker_T> tempColumns; 
    tempVector.push_back(tempColumns);
    for (int j = 0; j < dailyNeed ; j++)
    {
      tempVector[i].push_back(INVALID_ID);
    }
  }
    return helperFunction (avail, dailyNeed, maxShifts, tempVector, numShiftsWorked, row, col);
    //pass avail ref, sched ref, and numDays qworked by ref


}




