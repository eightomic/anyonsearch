# AnyonSearch

[![AnyonSearch](anyonsearch.jpg)](https://github.com/eightomic/anyonsearch)

## Table of Contents

- [Introduction](README.md?tab=readme-ov-file#introduction)
- [Author](README.md?tab=readme-ov-file#author)
- [License](README.md?tab=readme-ov-file#license)
- [Implementation](README.md?tab=readme-ov-file#implementation)

## Introduction

AnyonSearch is the efficient binary search algorithm that has low-footprint implementation (efficient memory usage and small code size), no division/modulus/multiplication operators and ultra-fast speed.

## Author

AnyonSearch was created by William Stafford Parsons as a product of [Eightomic](https://eightomic.com).

## License

AnyonSearch is licensed with [BSD-3-Clause](LICENSE).

## Implementation

Each mention of AnyonSearch refers to both of the following variants individually (`anyonsearch_first` and `anyonsearch_last`) implemented in C.

[anyonsearch.c](anyonsearch.c)

The `anyonsearch_first` function searches in a `haystack` array (of `haystack_length` elements that must be already sorted in ascending integral order) for the first occurrence (left-to-right) of a `needle`.

When `needle` is found, `1` is returned and the index position (of `needle`) is assigned as the value pointed to by `position`. When `needle` isn't found, `0` is returned.

The integral type of each element in `haystack` must match the integral type of each element in `needle`.

`anyonsearch_last` isn't ready to publish yet.
