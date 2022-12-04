

#include <set>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
// add or remove necessary headers as you please
#include "schedwork.h"

using namespace std;

// a constant that can be used to indicate an INVALID 
// worker ID if that is useful to your implementation.
// Feel free to not use or delete.


// comments from .h 
/**
 * @brief Produces a work schedule given worker availability,
 *        the number of needed workers per day, and the maximum 
 *        shifts any single worker is allowed. Returns true
 *        and the valid schedule if a solution exists, and false
 *        otherwise. 
 * 
 * @param [in]  avail n x k vector of vectors (i.e. matrix) of the availability
 *                    of the k workers for each of the n days
 * @param [in]  dailyNeed Number of workers needed per day (aka d)
 * @param [in]  maxShifts Maximum shifts any worker is allowed over 
 *                        the n day period (aka m)
 * @param [out] sched n x d vector of vectors indicating the d workers
 *                    who are scheduled to work on each of the n days
 * @return true if a solution exists; sched contains the solution
 * @return false if no solution exists; sched is undefined (can be anything)
 */

static const Worker_T INVALID_ID = (unsigned int)-1;


// Add prototypes for any helper functions here
bool helperFunction (const AvailabilityMatrix& avail, const size_t dailyNeed, const size_t maxShifts, DailySchedule& sched, vector<int> numShiftsWorked, int row, int col);
bool isValid (std::vector<int> numDaysWorked, const AvailabilityMatrix& avail, DailySchedule& sched, const size_t dailyNeed, const size_t maxShifts);



// Add your implementation of schedule() and other helper functions here
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
//check if each row of schewdule matrix has a certain number of 1s
//cannot exceed max number of workers
//check if each column is less than a certain number (counting number of 1s inside of row and column)
return true;
}

//iterate through every worker
// check the availability of each worker "true"
//in that for loop check if worker has already worked their maxShifts
//check if they've already worked on that day
//if it works set sched to current worker

bool helperFunction (const AvailabilityMatrix& avail, const size_t dailyNeed, const size_t maxShifts, DailySchedule& sched, vector<int> numShiftsWorked, int row, int col)
{
  if (col > (int)sched[0].size() - 1)
  {
    col = 0;
    helperFunction(avail, dailyNeed, maxShifts, sched, numShiftsWorked, row + 1, col);
  }
  if (row > (int)sched.size() - 1)
  {
    return true; //leave this loop and its fone
  }
  //.size() will return number of rows it has
  /*for (int i = 0; i < (int)avail[0].size(); i++) 
  {
      for (int j = 0; j < (int)avail.size(); j++)
    {
      if (avail[row][j] == true)
      {
          sched[j][row] = true;
          numShiftsWorked[i];
        
        if (!isValid(avail, sched, dailyNeed, maxShifts))
        {
        numShiftsWorked[j]--;
        sched[j][row] = INVALID_ID;
        }
      }
    }
  }*/



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


 /*for (int i = 0; i < sched.size(); i++)
  {
    for (int j = 0; j < sched[i].size(); i++)
    {
      if ()
    }
  }*/
  /*for (int i = 0; i < avail[row].size(); i++)
  {
    
  }*/
  //for (int i = 0; i < sched[row].size(); i++) //iterating through worked one etc;
  //{
    /*if (sched[row][i] != INVALID_ID)
    {
      helperFunction(avail, dailyNeed, maxShifts, sched, numDaysWorked, row, col+1);
    }
    else
    {
      for (int j = 0; j < avail[j].size(); j++)
      {
        if (avail[row][j] == 1)
        {
          numDaysWorked[i] += 1;
          //check if they've already worked on that day
          //call helper function after I set sched = 1
        }
      }
    }*/

  //}

  //create vector of numdaysWorked that we will iterate througha dn change
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
 // final loop set sched value equal to true
 // days worked ++
 // recursive call
 // if it does not meet conidtion after recursive call
 // decrement daysWorked
 // set DaysWorked to "IV"
    if(avail.size() == 0U){
        return false;
    }
    sched.clear();
    // Add your code below
  int row = 0;
  int col = 0;
  std:: vector <int> numShiftsWorked (avail[0].size(), 0);
  for (int i = 0; i < (int)avail[0].size() -1; i++)
  {
    numShiftsWorked.push_back(0);
  }
  for (int i = 0; i < (int)avail.size() - 1; i++)
  {
    std::vector<Worker_T> tempColumns; //(dailyNeed, INVALID_ID);
    tempVector.push_back(tempColumns);
    for (int j = 0; j < dailyNeed ; j++)
    {
      tempVector[i].push_back(INVALID_ID);
    }
  }
    return helperFunction (avail, dailyNeed, maxShifts, tempVector, numShiftsWorked, row, col);
    //pass avail ref, sched ref, and numDays qworked by ref


}




