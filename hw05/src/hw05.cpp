#include <hw05.h>

VecOfStr hw05(const VecOfStr& strings)
{
  VecOfStr polyndroms;

  auto is_Polyndrom = [](const std::string& polyndrom) {
    auto start = polyndrom.begin();
    auto end = polyndrom.rbegin();

    while (start != polyndrom.end() && end != polyndrom.rend()) {
      while (start != polyndrom.end() && !isalnum(*start)) {
        ++start;
      }
      while (end != polyndrom.rend() && !isalnum(*end)) {
        ++end;
      }
      if (start == polyndrom.end() || end == polyndrom.rend()) {
        break;
      }
      if (tolower(*start) != tolower(*end)) {
        return false;
      }
      ++start;
      ++end;
    }
    return true;
  };

  for (const auto& polyndrom : strings) {
    if (is_Polyndrom(polyndrom)) {
      polyndroms.push_back(polyndrom);
    }
  }

  return polyndroms;
}