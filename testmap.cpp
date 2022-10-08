#include <vector>
#include <iterator>
#include <map>
#include <iostream>
#include <set>
#include <iomanip>
#include <algorithm>    // std::lexicographical_compare
#include <cctype>   
#include <string>
#include <fstream>

int main() {
    std::map<char,int> first;

  first['a']=10;
  first['b']=30;
  first['c']=50;
  first['d']=70;

  std::map<char,int> second (first.begin(),first.end());

  std::map<char,int> third (second);
  first.erase('a');
  char highest = first.rbegin()->first;  

  for (std::map<char,int>::iterator it = first.begin(); it != first.end();++it) {
    std::cout << it->first << " => " << it->second << '\n';
  }

//   std::map<char,int,classcomp> fourth;                 // class as Compare

//   bool(*fn_pt)(char,char) = fncomp;
//   std::map<char,int,bool(*)(char,char)> fifth (fn_pt); // function pointer as Compare

  return 0;
}