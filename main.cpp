#include <iostream>
using namespace std;

const int SIZE = 15;

void quickSort(int inputArray[], int start, int end);

int partition(int inputArray[], int start, int end);

void displayArray(int inputArray[]);

int main() {

	int testArray[] = {55, 47, 23, 77, 32, 3, 9, 13, 27, 101, 44, 6, 2, 15, 57};

	displayArray(testArray);
	quickSort(testArray, 0, SIZE - 1);
	displayArray(testArray);

	cout << endl << endl;
	return 0;
}

void quickSort(int inputArray[], int start, int end) {
	if (start > end) return;

	int partitionPoint = partition(inputArray, start, end);
	quickSort(inputArray, start, partitionPoint - 1); //Sort left half of partitionPoint
	quickSort(inputArray, partitionPoint + 1, end); //Sort right half of partitionPoint
}

int partition(int inputArray[], int start, int end) {
	int pivot = inputArray[end];
	int left = start;
	int right = end - 1;

	while (left <= right) {
		while (left <= right && inputArray[left] <= pivot) left++; //Find element whose value is greater than the pivot
		while (left <= right && inputArray[right] >= pivot) right--; //Find element whose value is less than the pivot

		if (left < right) { //Swap element at left with element at right
			int temp = inputArray[left];
			inputArray[left] = inputArray[right];
			inputArray[right] = temp;
		}
	}
	//Place the pivot at the correct index
	int temp = inputArray[left];
	inputArray[left] = inputArray[end];
	inputArray[end] = temp;

	return left; //Return the partition point
}

void displayArray(int inputArray[]) {
	for (int i = 0; i < SIZE; i++) {
		cout << inputArray[i] << " ";
	}
	cout << endl << endl;
}
