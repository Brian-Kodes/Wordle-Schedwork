// For debugging
#include <iostream>
// For std::remove
#include <algorithm>
#include <map>
#include <set>
#include <vector>
#include <string.h> //added this
#include "wordle.h"
#include "dict-eng.h"
using namespace std;
 
 
// Add prototypes of helper functions here
//we want recursive function here
void helperFunction(const std::string& floating, const std::set<std::string>& dict, unsigned int i, std::string possibleWord, vector<char> &floatMethod, std::set<std::string> &results)
{
 //vector <std::string> comboWords;
 int blankCount = 0;
 for (int j = 0; j < possibleWord.size(); j++)
   {
     if (possibleWord[j] == '-')
     {
       blankCount += 1;
     }
     // else
     // {
     //   ;
     // }
   }
  // base case: word is complete
 if (!blankCount) {
   if (dict.find(possibleWord) != dict.end()) {
     results.insert(possibleWord);
   }
   return;
 }
 
 vector<char>setAlphabet ({'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'});
 // word is not complete
 if (possibleWord[i] != '-') {
   helperFunction(floating, dict, i + 1, possibleWord, floatMethod, results);
   return;
 }
 
 // current letter is a dash
 // if there are still floating letters remaining
 if (floatMethod.size()) {
   for (int j = 0; j < floatMethod.size(); j++)
   {
 
     //first, make temp vector equal to floatingMethod
     //possibleWord[i] = floating[i]
     //change temp to not include floating[i] delete
     //recurse with temporary instead of floatingMethod and i+1
     //make the change permanent by making temp = floatingMethod
     vector<char> temp = floatMethod;
     //vector<char>::iterator it = temp.begin();
     possibleWord[i] = temp[j];
     //for (it = temp.begin(); it != temp.end(); it++)
     /*while (it != temp.end())
     {
       if (*it == floating[j])
       {
         temp.erase(it);
         it++;
       }
       else
       {
         it++;
       }
     }*/
     //temp.erase(temp.begin());
     temp.erase(std::find(temp.begin(), temp.end(), floatMethod[j]));
     helperFunction(floating, dict, i + 1, possibleWord, temp, results);
   }
 }
 
 // no floating letters remaining
 if (blankCount > floatMethod.size()) {
   for (int k = 0; k < setAlphabet.size(); k++)
   {
     possibleWord[i] = setAlphabet[k];
     helperFunction(floating, dict, i + 1, possibleWord, floatMethod, results);
   }
   possibleWord[i] = '-';
 }
       //check if there are more blanks than floating character
   // inside if statement iterate through a-z and then set the word at that index to a-z
   //recurse with i+1
 
   //if i go from a-z and nothing works
   //after if statement for blanks and characters
   //reset the word at index[i] to dash
 
 /*for (unsigned int i = 0; i < floating.size(); i++)
 {
   for (unsigned int j = 0; j < in.size(); j++)
   {
     if (in[j] == '-')
     {
       possibleWord += floating[i];
     }
     else
     //add the letter at that location
     {
       possibleWord += in[j];
     }
   }
 }*/
 /*for (it = dict.begin(); it! = dict.end(); it++)
 {
   possibleWord = *it;
   if (possibleWord.size() != sizeof(inString))
   {
     ;
   }
   else
   {
    
   }
 }*/
}
 
// Definition of primary wordle function
std::set<std::string> wordle(
   const std::string& in,
   const std::string& floating,
   const std::set<std::string>& dict)
{
   char inString[in.length()];
   strcpy(inString, in.c_str());
   unsigned int i = 0;
   vector<char> floatMethod;
   std::string letterHelper = floating;
   set<std::string>:: iterator it;
   std::string possibleWord = "";
   std::set<std::string> results;
   for (unsigned int i = 0; i < floating.size(); i++)
   {
     floatMethod.push_back(floating[i]);
   }
   helperFunction(floating, dict, i, in, floatMethod, results);
   // Add your code here
 /*  for (it = dict.begin(); it != dict.end(); it++)
   {
     possibleWord = *it;
       if (possibleWord.size() != sizeof(inString))
       {
         ;
       }
       else
       {//same size
         for (unsigned int i = 0; i < possibleWord.length() - 1; i++) //its same size
         {
           if (inString[i] == possibleWord[i])
           {
             //helperFunction(possibleWord[i], inString[i], )
             for (unsigned int j = 0; j < letterHelper.length(); j++)
             {
               /*for (unsigned int k = 0; k < possibleWord.length(); k++)
               {
                 if (possibleWord[k] ==)
 
               }*/
               /*if (possibleWord.find(letterHelper[j]) != string::npos)
               {
                 probableWords.insert(possibleWord);
               }
               else
               {
                 ;
               }
             }
           }
           else
           {
             ;
           }
          
         }*/
         /*for (unsigned int i = 0; i < letterHelper.length(); i++)
         {
           for (unsigned int j = 0; j < possibleWord.length(); j++)
           {
             if (possibleWord)
           }
         }*/
           return results;
 }
 
 
 
// Define any helper functions here
 



