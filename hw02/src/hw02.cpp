#include <hw02.h>

std::string hw02(std::string input_str)
{

  std::string result;
  for (char c : input_str) {
    if (result.find(c) == std::string::npos) {
      result += c;
    }
  }

  return result; 
}
