#include <stddef.h>

char anyonsearch_first(int *haystack, size_t haystack_length, int needle,
                       size_t *position) {
  size_t step;
  size_t i;

  if (
    haystack_length &&
    haystack[haystack_length - 1] >= needle
  ) {
    if (haystack[0] < needle) {
      step = haystack_length | (haystack_length >> 1);
      step |= step >> 2;
      step |= step >> 4;
      i = 8;

      while (
        i < (sizeof(size_t) << 3) &&
        step < (step | (step >> i))
      ) {
        step |= step >> i;
        i <<= 1;
      }

      step = (step >> 1) + 1;
      i = (haystack[haystack_length - step] < needle) ? (haystack_length - step) : 0;

      while (step > 1) {
        step >>= 1;

        if (haystack[i + step] < needle) {
          i += step;
        }
      }

      if (haystack[i + 1] == needle) {
        *position = i + 1;
        return 1;
      }

      return 0;
    }

    if (haystack[0] == needle) {
      *position = 0;
      return 1;
    }
  }

  return 0;
}
