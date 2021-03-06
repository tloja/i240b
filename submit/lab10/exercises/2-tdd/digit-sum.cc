#include <cctype>
#include "digit-sum.hh"

int
digitSum(const char* str)
{
  int acc = 0;
  bool wantsDigit = true;
  for (const char* p = str; *p != '\0'; ++p) {
    int c = *p;
    if(isdigit(c)){
      if (wantsDigit){
	acc += c - '0';
	wantsDigit = false;
      } else {
	break;
      }
    }
    else if (c == '+'){
      if (wantsDigit){
	break;
      }
      wantsDigit = true;
    } else if (isspace(c)){
      continue;
    } else {
      break;
    }
  }      
  
  return acc;
}
