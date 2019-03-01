#ifndef POINTS_SEGMENTS_H
#define POINTS_SEGMENTS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void print_array(int *arr, int size);
void print_array_2D(int **arr, int rows, int cols);
int *fast(int **segs, int s, int*pts, int p);
int *naive(int **segs, int s, int*pts, int p);
int comparison(const void *a, const void *b);
int are_same(int *ans1, int *ans2, int size);
int sort_points(const void *a, const void *b);
void input_test();
#endif