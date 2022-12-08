/**
 * @file challenge1.c
 * @author luka luig (luka@4luig.de)
 * @brief merge sort and quicksort implementation
 * @date 2022-12-08
 *
 * @copyright Copyright (c) 2022
 *
 */

#include <stdio.h>

void quicksort(int array[], int p, int r);
int partition(int array[], int p, int r);

void merge(int array[], int p, int q, int r);
void merge_sort(int array[], int p, int r);

void swap(int *x, int *y);
void print_array(int array[], int size);


int main(void) {
	int array[10] = {3, 10, 5, 1, 8, 4, 7, 9, 2, 6};
	int size_array = sizeof(array) / sizeof(int);
	print_array(array, size_array);

	// merge_sort(array, 0, size_array - 1);
	quicksort(array, 0, size_array - 1);
	print_array(array, size_array);
}

void quicksort(int array[], int p, int r) {
	if (p < r) {
		int q = partition(array, p, r);
		quicksort(array, p, q - 1);
		quicksort(array, q + 1, r);
	}
}

int partition(int array[], int p, int r) {
	int pivot = array[r];
	int i = p - 1;
	for (int j = p; j < r; j++) {
		if (array[j] <= pivot) {
			i++;
			swap(&array[i], &array[j]);
		}
	}
	swap(&array[i + 1], &array[r]);
	return i + 1;
}

void merge(int array[], int p, int q, int r) {
	// lengths of subbarrays
	int n1 = q - p + 1;
	int n2 = r - q;

	// filling L with first subarray
	int L[n1];
	for (int i = 0; i < n1; i++)
		L[i] = array[p + i];

	// filling R with second subarray
	int R[n2];
	for (int i = 0; i < n2; i++)
		R[i] = array[q + 1 + i];

	// from L and R: compare and copy into array
	int i = 0;
	int j = 0;
	int k = p;

	while (i < n1 && j < n2) {
		if (L[i] <= R[j]) {
			array[k] = L[i];
			i++;
			k++;
		} else {
			array[k] = R[j];
			j++;
			k++;
		}
	}
	// remainder
	while (i < n1) {
		array[k] = L[i];
		i++;
		k++;
	}
	while (j < n2) {
		array[k] = R[j];
		j++;
		k++;
	}
}

void merge_sort(int array[], int p, int r) {
	if (p < r) {
		int q = (p + r) / 2;
		merge_sort(array, p, q);
		merge_sort(array, q + 1, r);
		merge(array, p, q, r);
	}
}

void swap(int *x, int *y) {
	int tmp = *x;
	*x = *y;
	*y = tmp;
}

void print_array(int array[], int size) {
	for (int i = 0; i < size; i++)
		printf("%d ", array[i]);
	printf("\n");
}
