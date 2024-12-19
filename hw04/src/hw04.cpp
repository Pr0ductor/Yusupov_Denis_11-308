#include <hw04.h>

size_t hw04(const int* input_array, std::size_t elem_count) {

  int* out_data = new int[1];
  int sum = 0;
  int count = 0;


  for (std::size_t i = 0; i < elem_count; ++i) {
    if (input_array[i] < 0) {
      break;
    }

    if (count > 0) {
      int* new_out_data = new int[count + 1];
      for (std::size_t j = 0; j < count; ++j) {
        new_out_data[j] = out_data[j];
      }
      new_out_data[count] = input_array[i];

      delete[] out_data;
      out_data = new_out_data;
    }

    else {
      out_data[0] = input_array[i];
    }

    sum += input_array[i];
    count++;
  }

  delete[] out_data;

  return sum;
}
