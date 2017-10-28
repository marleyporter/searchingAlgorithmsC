//============================================================================
//SEARCHING ALGORITHMS - search for a target number, outputs location and number of comparisons it took to find it
//============================================================================

#include <iostream>
#include <sstream>
#include <string>
#include <math.h>

using namespace std;

//declaration of functions
void output(int target, int numCom, int ind);
int sqrt(int size);
void linearSearch(int arg[], int target, int size);
void binarySearch(int arg[], int target, int size);
void jumpSearch(int arg[], int target, int size);
void ternarySearch(int arg[], int target, int size);



int main() {

	//declaration of variables
	int size = 2046;
	string input;
	int target;
	int array [size];

	//fill array with numbers
	for (int i = 0; i<size; i++) {
		array[i] = i;
	}


	cout << "Enter your target number: " << endl;
	getline(cin, input);
	stringstream(input) >> target;

	linearSearch(array, target, size);
	binarySearch(array, target, size);
	jumpSearch(array, target, size);
	ternarySearch(array, target, size);

	return 0;
}

void output(int target, int numCom, int ind) {

	//check if target has been found and outputs results
	if (ind == target) {
		cout << "Number of comparisons: " << numCom << endl;
		cout << "Target is found at the index: " << ind << endl;

	} else {
		cout << "Number of comparisons: " << numCom << endl;
		cout << "Target not found." << endl;
	}
}

int sqrt(int size) {

	int temp = 0;

	for (int i = 0; i<=size; i++) {

		if ((i * i) > size) {
			temp = i - 1;
			break;
		} else if ((i * i) == size) {
			temp = i;
			break;
		}

	}


	return temp;

}

//Linear Search Function
void linearSearch(int arg[], int target, int size) {

	cout << "LINEAR SEARCH" << endl;

	int numCom = 0;
	int ind = -1;

	//cycle through the elements of the array
	for(int i = 0; i< size ; i++) {

		numCom +=1;	//add 1 to comparisons

		//if target is found break from the loop
		if (arg[i] == target) {
			ind = i;
			break;
		}
	}

	output(target, numCom, ind);

}

//Binary Search Function
void binarySearch(int arg[], int target, int size) {

	cout << "BINARY SEARCH" << endl;

	//declaration of variables
	int numCom = 0;
	int ind = -1;
	int low = 0;
	int high = size;

	//while there are still available elements in the array cycle through the array
	for (int i = low; i <= high; i) {

		int mid = (high + low) / 2;

		//if there is one element left and it is not the target, break
		if (mid == low && arg[mid] != target) {
			numCom += 1;
			break;
		}

		//if there is one element left and it is not the target, break
		if (mid == high && arg[mid] != target) {
			numCom += 1;
			break;
		}

		//if target is found break from the loop
		if (arg[mid] == target) {
			numCom += 1;
			ind = mid;
			break;

		} else if (target < arg[mid]) {
			numCom += 1;
			high = mid;

		} else if (target > arg[mid]) {
			numCom += 1;
			low = mid;
		}

	}

	output(target, numCom, ind);

}

//Jump Search Function
void jumpSearch(int arg[], int target, int size) {

	cout << "JUMP SEARCH" << endl;

	//declaration of variables
	int numCom = 0;
	int ind = -1;
	int prev = 0;
	int jump = sqrt(size-1);

	//cycle through the array in jumps
	for (int i = jump; i<=size; i +=jump) {

		//avoid infinite loop caused by changing loop variable (last 'if' statement)
		if(target > arg[size-1]) {
			numCom +=1;
			break;
		}

		//break from loop if target is found
		if (arg[i] == target) {
			numCom +=1;
			ind = i;
			break;
		}

		//if loop jumps past target
		if (arg[i] > target) {
			numCom +=1;

			//linear search from previous jump to current jump
			for(int j = prev; j < i; j++) {

				//break from loop if the target is found
				if (arg[j] == target) {
					numCom +=1;
					ind = j;
					break;
				}

				numCom +=1;

			}

			break;
		}

		numCom +=1;
		prev = i;

		//avoid jumping over the size of the array by preparing for loop variable 'i'
		if ((i + jump) > size) {
			i = size - jump;
		}

	}

	output(target, numCom, ind);

}

//Ternary Search Function
void ternarySearch (int arg[], int target, int size) {
	cout << "TERNARY SEARCH" << endl;

	//declaration of variables
	int numCom = 0;
	int ind = -1;
	int low = 0;
	int high = size;

	for (int i = low; i<=high; i) {

		//cut remaining array into thirds for variables
		int mid1 = low + (high - low) / 3;
		int mid2 = low + 2 * (high - low) / 3;

		//if one element is left in the array and not the target, break from loop
		if ((mid1 == mid2) && (high == low) && (mid1 == high) && (arg[mid1] != target)) {
			numCom +=1;
			break;
		}

		//break from loop if 1st third is target
		if (arg[mid1] == target) {
			ind = mid1;
			numCom +=1;
			break;
		}

		//break from loop if 2nd third is target
		if (arg[mid2] == target) {
			ind = mid2;
			numCom +=1;
			break;
		}

		//compare target with thirds cutting the array into thirds and eliminating 2 thirds each loop
		if (target < arg[mid1]) {
			numCom +=1;
			high = mid1;
		} else if (target > arg[mid2]) {
			numCom +=1;
			low = mid2;
		} else {
			numCom +=1;
			low = mid1;
			high = mid2;
		}

	}

	output(target,numCom, ind);

}


