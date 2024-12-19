#include <hw03.h>
#include <cstring>
#include <cstddef>

void hw03(char* str, const char* pattern)
{
  if (str == nullptr || pattern == nullptr || *str == '\0' || *pattern == '\0')
    return;

  size_t pattern_len = std::strlen(pattern);
  char* pos = std::strstr(str, pattern);


  if (pos != nullptr) {
    std::memmove(pos, pos + pattern_len, std::strlen(pos + pattern_len) + 1);
  }
}