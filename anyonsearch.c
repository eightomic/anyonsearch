/*
  Copyright © 2026 Eightomic <eightomic@proton.me>

  Permission is hereby granted, free of charge, to any person obtaining a copy
  of this software and associated documentation files (the "Software"), to deal
  in the Software without restriction, including without limitation the rights
  to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
  copies of the Software, and to permit persons to whom the Software is
  furnished to do so, subject to the following conditions:

  The above copyright notice and this permission notice shall be included in all
  copies or substantial portions of the Software.

  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
  IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
  AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
  LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
  OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
  SOFTWARE.
*/

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
