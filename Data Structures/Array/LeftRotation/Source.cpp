//Hashim Abu Sharkh
//20th Of May 2019
//Array Rotation

#include <iostream>
#include <vector>
using std::cin;
using std::cout;
using std::endl;
//There are many methods to left rotate an array by d elements

//GCD is a function which finds the gcd of 2 numbers
int GCD(int , int );


//rotate is a function which rotates an array by d elements to the left
template<class T>
void rotate(T[], int, int);

//reverseArr is a function which reverses an array from a specified starting index to an ending index
template <class T>
void reverseArr(T[], int, int);

//reverseArr is a function which reverses an array from a specified starting index to an ending index recursively
template <class T>
void reverseArrRec(T[], int, int);

//printArr prints an array iteratively
template<class T>
void printArr(T[], int);

//printArrRecursively prints an array recursively
template<class T>
void printArrRecursively(T[], int,int);

//leftRotateByOne rotates array to the left by one
template <class T>
void leftRotateByOne(T[], int);

//leftRotate rotates an array to the left by d elements making use of a temporary array
template <class T>
void leftRotate(T[], int, int);

//leftRotateByJuggling rotates an array to the left by d elements using a juggling algorithm
template <class T>
void leftRotateByJuggling(T[], int,int);

//Makes use of reversal algorithm to rotate array
template<class T> 
void leftRotateByReversal(T[], int, int);

//HACKERRANK SOLUTION
// Complete the rotLeft function below.
std::vector<int> rotLeft(std::vector<int> a, int d) {
	//Using juggling algorithm
	for (int i = 0; i < GCD(a.size(),d) ; i++)
	{
		int tmp = a[i];
		int j = i;

		while (1)
		{
			int cycle = (j + d) % a.size();

			if (cycle == i)
				break;

			a[j] = a[cycle];
			j = cycle;
		}
		a[j] = tmp;
	}
	return a;
}
//Driver program to test functions
int main()
{
	int arr[7] = { 1,2,3,4,5,6,7 };
	int d = 2;
	int size = sizeof(arr)/sizeof(arr[0]);

	printArrRecursively(arr, size-1, 0);
	cout << endl;
	
	//test rotate function by shifting elements to the left by 2
	rotate(arr, size, d);
	cout << "Left Rotate using temp array: ";
	printArr(arr, size);

	//test leftRotate
	leftRotate(arr,size,size-d);
	cout << "Left Rotate using leftRotate method: ";
	printArr(arr, size);

	//test leftRotateByJuggling
	leftRotateByJuggling(arr, size, d);
	cout << "Left Rotate using juggling algorithm: ";
	printArr(arr, size);

	//test leftRotateByReversal
	leftRotateByReversal(arr, size, size - d);
	cout << "Left Rotate using reversal algorithm: ";
	printArr(arr, size);

	//test reversing an array recursively
	reverseArrRec(arr, 0, size - 1);
	cout << "Reverse an aray Recursively: ";
	printArr(arr, size);

	char c;
	cin >> c;

}

//Time Complexity:O(n), Auxilliary Space:O(d) 
template <class T>
void rotate(T arr[], int size, int d)
{
	//create a temporary array
	T *tmp =new T[size];

	//copy first d elements to temp array
	for (int i = 0; i < d; i++)
		tmp[i] = arr[i];

	//shift all elements to the left
	for (int i = 0, j = d; j < size; j++, i++)
		arr[i] = arr[j];

	//Store back the d elements
	for (int i = size - d, j = 0; j < d; i++, j++)
		arr[i] = tmp[j];

	delete[] tmp;
}

//Time Complexity:O(size), Space Complexity:O(1)
template <class T>
void printArr(T arr[], int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << arr[i];
		if (i < size - 1)
			cout << ",";
	}
		cout << endl;
}

//Time Complexity: O(size), Space Complexity:O(size)
template <class T>
void printArrRecursively(T arr[], int size,int count)
{
	if (size != -1)
	{
		printArrRecursively(arr, size - 1, count + 1);
		cout << arr[size];

		if (count > 0)
			cout << ",";
	}

}

template <class T>
void leftRotateByOne(T arr[], int size)
{
	//Temporary variable to store first variable
	T tmp = arr[0];

	for (int i = 0, j = 1; i < size - 1; i++, j++)
		arr[i] = arr[j];

	//Store temp variable in last element
	arr[size - 1] = tmp;
}

//Time Complexity:O(size*d), Auxilliary Space:O(1)
template <class T>
void leftRotate(T arr[], int size, int d)
{
	for (int i = 0; i < d; i++)
		leftRotateByOne(arr, size);
}

//Time Complexity: O(size), Auxilliary Space: O(1)
template <class T>
void leftRotateByJuggling(T arr[], int size, int d)
{
	//find gcd between the size of the array and d
	int gcd = GCD(size, d);
	int j, tmp;
	for (int i = 0; i < gcd; i++)
	{
		tmp = arr[i];
		j = i;

			while (1)
			{
				int cycle = (j + d) % size;

				if (cycle == i)
					break;

				arr[j] = arr[cycle];
				j = cycle;
			}
		arr[j] = tmp;
	}

}

template <class T>
void leftRotateByReversal(T arr[], int size, int d)
{
	reverseArr(arr, 0, d - 1);
	reverseArr(arr, d, size - 1);
	reverseArr(arr, 0, size - 1);
}

int GCD(int a, int b)
{
	if (b == 0)
		return a;

	return GCD(b, a%b);
}

template <class T>
void reverseArr(T arr[], int start, int end)
{
	while (start < end)
	{
		int tmp = arr[start];
		arr[start++] = arr[end];
		arr[end--] = tmp;
	}
}

template <class T>
void reverseArrRec(T arr[], int start, int end)
{
	if (start < end)
	{
		int tmp = arr[start];
		arr[start] = arr[end];
		arr[end] = tmp;
		reverseArrRec(arr, start + 1, end - 1);
	}
	
}