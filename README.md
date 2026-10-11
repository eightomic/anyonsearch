# AnyonSearch

[![AnyonSearch](anyonsearch.jpg)](https://github.com/eightomic/anyonsearch)

AnyonSearch (as a proprietary, source-available product of [Eightomic](https://eightomic.com)) is the fast efficient binary search that has low-footprint implementation (efficient memory usage and small code size), no equidistribution requirements (non-interpolated), no division/modulus/multiplication operators and ultra-fast speed (relative to the aforementioned constraints).

Each mention of AnyonSearch refers to both of the following variants individually (`anyonsearch_first` and `anyonsearch_last`) implemented in C.

[anyonsearch.c](anyonsearch.c)

Each of the following speed benchmark results (with `gcc` from an AMD A4-9120C) log the fastest process execution speed (in milliseconds) among several repetitions of searching for 10 million pseudorandom `needle` elements in `haystack_length` pseudorandom `haystack` elements in a blocking loop.

The `anyonsearch_first` function searches in a `haystack` array (of `haystack_length` elements that must be already sorted in ascending integral order) for the first occurrence (left-to-right) of a `needle`. When `needle` is found, `1` is returned and the index position (of `needle`) is assigned as the value pointed to by `position`. When `needle` isn't found, `0` is returned. The integral type of each element in `haystack` must match the integral type of each element in `needle`.

```
haystack_length   Elapsed               Elapsed
                  (anyonsearch_first)   (naive_binary_search_first)

1                 77ms                  117ms
10                201ms                 254ms
50                315ms                 457ms
100               355ms                 595ms
500               497ms                 945ms
1k                630ms                 1033ms
5k                767ms                 1259ms
10k               794ms                 1354ms
100k              937ms                 1633ms
1m                1660ms                2450ms
```

The `anyonsearch_last` function searches in a `haystack` array (of `haystack_length` elements that must be already sorted in ascending integral order) for the last occurrence (right-to-left) of a `needle`. When `needle` is found, `1` is returned and the index position (of `needle`) is assigned as the value pointed to by `position`. When `needle` isn't found, `0` is returned. The integral type of each element in `haystack` must match the integral type of each element in `needle`.

```
haystack_length   Elapsed              Elapsed
                  (anyonsearch_last)   (monobound_binary_search)

1                 78ms                 79ms
10                197ms                309ms
50                299ms                406ms
100               342ms                474ms
500               519ms                612ms
1k                667ms                983ms
5k                754ms                961ms
10k               743ms                1015ms
100k              946ms                1437ms
1m                1666ms               2173ms
```
