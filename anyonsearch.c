#include <stddef.h>

char anyonsearch_first(int *haystack, size_t haystack_length, int needle,
                       size_t *position) {
  size_t step;
  size_t i = 0;

  if (
    haystack_length &&
    haystack[haystack_length - 1] >= needle
  ) {
    if (haystack[0] < needle) {
      if (haystack_length > 7) {
        step = haystack_length >> 2;

        if (haystack[step] < needle) {
          i = step;

          if (haystack[step + i] < needle) {
            i += step;

            if (haystack[step + i] < needle) {
              i += step;
            }
          }
        }

        while (step > 3) {
          step >>= 1;

          if (haystack[step + (step & 1) + i] < needle) {
            i += step + (step & 1);
          }
        }
      }

      while (haystack[i] < needle) {
        i++;
      }

      if (haystack[i] == needle) {
        *position = i;
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

char anyonsearch_last(int *haystack, size_t haystack_length, int needle,
                      size_t *position) {
  size_t i = 1;

  if (
    haystack_length &&
    haystack[haystack_length - 1] >= needle
  ) {
    if (haystack[haystack_length - 1] == needle) {
      *position = haystack_length - 1;
      return 1;
    }

    if (haystack[0] < needle) {
      if (haystack_length > 7) {
        haystack_length >>= 2;

        if (haystack[haystack_length] <= needle) {
          i = haystack_length;

          if (haystack[haystack_length + i] <= needle) {
            i += haystack_length;

            if (haystack[haystack_length + i] <= needle) {
              i += haystack_length;
            }
          }
        }

        while (haystack_length > 3) {
          haystack_length >>= 1;

          if (haystack[haystack_length + (haystack_length & 1) + i] <= needle) {
            i += haystack_length + (haystack_length & 1);
          }
        }
      }

      while (haystack[i] <= needle) {
        i++;
      }
    }

    if (haystack[i - 1] == needle) {
      *position = i - 1;
      return 1;
    }
  }

  return 0;
}
