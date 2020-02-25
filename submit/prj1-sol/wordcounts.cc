#include <iostream>
#include <vector>
#include <algorithm>
#include <cerrno>
#include <cstdlib>
#include <string>
#include <fstream>
#include <map>
#include <set>
#include <assert.h>
typedef std::pair<std::string, int> WordCount;
bool wordCountCompare(WordCount a, WordCount b)
{
  return a.second > b.second;
}
std::map<std::string, int>
CountNums(std::vector<std::string> fileNames, int min, int max)
{
  std::map<std::string, int>map;
    for(auto fileName : fileNames)
      {
	std::ifstream in(fileName);
	if(!in){
	  std::cerr << "cannot read\"" << fileName << "\"" << std::endl;
	  std::exit(1);
	}
	std::string str;
	while(in >> str)
	  {
	    for(unsigned int i = 0; i < str.length(); i++)
	      {
		if((str[i] < 'A' || str[i] > 'Z')&&(str[i] < 'a' || str[i] > 'z'))
		  {
	    str.erase(i, 1);
	    i = i - 1;
	  }
      }
  transform(str.begin(), str.end(), str.begin(), ::tolower);
  if(str.length() < (long unsigned int) min || str.length() > (long unsigned int)max)
    {
      continue;
    }
  if(map.find(str) == map.end())
    {
      map[str] = 1;
    }
  else {
    map[str]++;
  }
}
if(!in.eof()) {
  std::cerr << "i/p error on file \"" << fileName << "\"" << std::endl;
  std::exit(0);
 }
return map;
}
}
//  #ifndef NDEBUG
//#   define M_Assert(Expr, Msg)				\
  //     __M_Assert(#Expr, Expr, __FILE__, __LINE__, Msg)
//#else
//#   define M_Assert(Expr, Msg) ;
//#endif

//void __M_Assert(const char* expr_str, bool expr, const char* file, int line, const char* msg)
//{
  //    if (!expr)
      //    {
      //       std::cerr << msg;
	//       abort();
	//    }
    //}





int main(int argc, char *argv[])
{
  if (argc < 5) {
    std::cerr << "usage: " << argv[0] << " MAX_N_OUT " << "MIN_WORD_LEN " << "MAX_WORD_LEN " << "FILE..." << std::endl;
    std::exit(1);
  }
  auto args = std::vector<std::string>(&argv[0], &argv[argc]);
  std::size_t endIndex;
  int max_out = std::stoi(args[1], &endIndex);
  assert(endIndex == args[1].length());

  int min_len = std::stoi(args[2], &endIndex);
  assert(endIndex == args[2].length());

  int max_len = std::stoi(args[3], &endIndex);
    assert(("Bad Integer Value" && endIndex == args[3].length()));
      
    //  M_Assert(endIndex == args[3].length(), "Bad integer value" + args[3].toString());




  


  assert(("MIN_WORD_LEN is greater than MAX_WORD_LEN",max_len >= min_len));
  std::map<std::string, int> mapped = CountNums(std::vector<std::string>(&argv[4], &argv[argc]), min_len, max_len);
  auto wordCounts =
    std:: vector<WordCount>(mapped.begin(), mapped.end());
  sort(wordCounts.begin(), wordCounts.end(),
       wordCountCompare);
  for(int i = 0; i < max_out; i++)
    {
      if(i >= wordCounts.size())
	{
	  break;
	}
      std::cout << wordCounts[i].first << ": " << wordCounts[i].second << std::endl;
    }
}
     
    
