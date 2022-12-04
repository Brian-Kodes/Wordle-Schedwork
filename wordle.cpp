// For debugging
#include <iostream>
#include <map>
#include <set>
#include <vector>
#include <string.h>
#include "wordle.h"
#include "dict-eng.h"
using namespace std;
 
 
void helperFunction(const std::string& floating, const std::set<std::string>& dict, unsigned int i, std::string possibleWord, set<char> &floatMethod, std::set<std::string> &results)
{
 int blankCount = 0;
 for (int j = 0; j < possibleWord.size(); j++)
   {
     if (possibleWord[j] == '-')
     {
       blankCount += 1;
     }
   }
 if (!blankCount) {
   if (dict.find(possibleWord) != dict.end()) {
     results.insert(possibleWord);
   }
   return;
 }
 
 vector<char>setAlphabet ({'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'});
 if (possibleWord[i] != '-') {
   helperFunction(floating, dict, i + 1, possibleWord, floatMethod, results);
   return;
 }
 std::set<char>::iterator it;
 if (floatMethod.size()) {
   for (it = floatMethod.begin(); it != floatMethod.end(); it++)
   {
     set<char> temp = floatMethod;
     possibleWord[i] = *it;
     temp.erase(*it);
     helperFunction(floating, dict, i + 1, possibleWord, temp, results);
   }
 }
 if (blankCount > floatMethod.size()) {
   for (int k = 0; k < setAlphabet.size(); k++)
   {
     possibleWord[i] = setAlphabet[k];
     helperFunction(floating, dict, i + 1, possibleWord, floatMethod, results);
   }
 }
 possibleWord[i] = '-';
}
 
std::set<std::string> wordle(
   const std::string& in,
   const std::string& floating,
   const std::set<std::string>& dict)
{
   char inString[in.length()];
   strcpy(inString, in.c_str());
   unsigned int i = 0;
   set<char> floatMethod;
   std::string letterHelper = floating;
   set<std::string>:: iterator it;
   std::string possibleWord = "";
   std::set<std::string> results;
   for (unsigned int i = 0; i < floating.size(); i++)
   {
     floatMethod.insert(floating[i]);
   }
   helperFunction(floating, dict, i, in, floatMethod, results);
   return results;
} 



