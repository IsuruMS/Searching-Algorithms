//header files
#include<iostream>
#include<vector>
#include<fstream>
#include<algorithm>
#include<string>

//including namespace std;
using namespace std;

//class for searching
class MySearch
{
	//public members
public:
	//public variables
	int count1 = 0, count2 = 0, count3 = 0, count4 = 0, count5 = 0;
	
	//function for lenier search
	int LeniarSearch(vector<int> arr, int count, int value)
	{
		int i = 0;
		for (; i < count; i++)
		{
			if (arr[i] == value)
				return i+1;				
		}
		return i+1;
	}

	//function for binary search
	int binarySearch(vector<int> arr, int l, int r, int value)
	{
		while (l <= r) {
				int m = l + (r - l) / 2;
				count1++;
				// Check if x is present at mid 
				if (arr[m] == value)
					return count1;
				// If x greater, ignore left half 
				if (arr[m] < value) 
				{
					l = m + 1;
				}
				// If x is smaller, ignore right half 
				else
				{
					r = m - 1;
				}	
		}

			// if we reach here, then element was 
			// not present 
	}
	
	int InterpolationSearch(vector<int> arr, int n, int x)
	{
			// Find indexes of two corners 
			int lo = 0, hi = (n - 1);

			// Since array is sorted, an element present 
			// in array must be in range defined by corner 
			while (lo <= hi && x >= arr[lo] && x <= arr[hi])
			{
				count2++;
				if (lo == hi)
				{
					if (arr[lo] == x)
						return count2;
					else
						return -1;
				}
				// Probing the position with keeping 
				// uniform distribution in mind. 
				int pos = lo + (((double)(hi - lo) /(arr[hi] - arr[lo])) * (x - arr[lo]));

				// Condition of target found 
				if (arr[pos] == x)
				{
					return count2;
				}
				// If x is larger, x is in upper part 
				if (arr[pos] < x)
				{
					lo = pos + 1;
				}
				// If x is smaller, x is in the lower part 
				else
				{
					hi = pos - 1; 
				}
			}
			
		
	}
	int JumpSearch(vector<int> arr, int n, int x)
	{
		
			// Finding block size to be jumped 
			int step = sqrt(n);

			// Finding the block where element is 
			// present (if it is present) 
			int prev = 0;
			while (arr[min(step, n) - 1] < x)
			{
				prev = step;
				step += sqrt(n);
				if (prev >= n)
					return -1;
				count3++;
			}

			// Doing a linear search for x in block 
			// beginning with prev. 
			while (arr[prev] < x)
			{
				prev++;

				// If we reached next block or end of 
				// array, element is not present. 
				if (prev == min(step, n))
					return -1;
				count3++;
			}
			// If element is found 
			if (arr[prev] == x)
				return count3;

			return count3;
	}
	
};

int main()
{
	int a, b, c, d, e, val1, val2, val3, val4;
	vector<int> arr1, arr2, arr3, arr4, arr5;
	string bigVect[5] = { "arr1", "arr2", "arr3", "arr4", "arr5" };

	ifstream text1("Set1.txt");
	ifstream text2("Set2.txt");
	ifstream text3("Set3.txt");
	ifstream text4("Set4.txt");
	ifstream text5("Set5.txt");

	for (int i = 0; i < 9999; i++)
	{
		text1 >> a;
		arr1.push_back(a);

		text2 >> b;
		arr2.push_back(b);

		text3 >> c;
		arr3.push_back(c);

		text4 >> d;
		arr4.push_back(d);

		text5 >> e;
		arr4.push_back(e);
	}
	MySearch s1;

	cout << "Enter a value not among the numbers\t-\t";
	cin >> val1;
	cout << "Enter a value among the first 100 numbers\t-\t";
	cin >> val2;
	cout << "Enter a value among the middle 100 numbers\t-\t";
	cin >> val3;
	cout << "Enter a value among the last 100 numbers\t-\t";
	cin >> val4;

	int unsortedLinear[4][5], sortedLinear[4][5], binary[4][5], jump[4][5], interpol[4][5];


	unsortedLinear[0][0] = s1.LeniarSearch(arr1, 9999, val1); unsortedLinear[0][1] = s1.LeniarSearch(arr1, 9999, val2); unsortedLinear[0][2] = s1.LeniarSearch(arr1, 9999, val3); unsortedLinear[0][3] = s1.LeniarSearch(arr1, 9999, val4);
	unsortedLinear[1][0] = s1.LeniarSearch(arr1, 9999, val1); unsortedLinear[1][1] = s1.LeniarSearch(arr1, 9999, val2); unsortedLinear[1][2] = s1.LeniarSearch(arr1, 9999, val3); unsortedLinear[1][3] = s1.LeniarSearch(arr1, 9999, val4);
	unsortedLinear[2][0] = s1.LeniarSearch(arr1, 9999, val1); unsortedLinear[2][1] = s1.LeniarSearch(arr1, 9999, val2); unsortedLinear[2][2] = s1.LeniarSearch(arr1, 9999, val3); unsortedLinear[2][3] = s1.LeniarSearch(arr1, 9999, val4);
	unsortedLinear[3][0] = s1.LeniarSearch(arr1, 9999, val1); unsortedLinear[3][1] = s1.LeniarSearch(arr1, 9999, val2); unsortedLinear[3][2] = s1.LeniarSearch(arr1, 9999, val3); unsortedLinear[3][3] = s1.LeniarSearch(arr1, 9999, val4);
	unsortedLinear[4][0] = s1.LeniarSearch(arr1, 9999, val1); unsortedLinear[4][1] = s1.LeniarSearch(arr1, 9999, val2); unsortedLinear[4][2] = s1.LeniarSearch(arr1, 9999, val3); unsortedLinear[4][3] = s1.LeniarSearch(arr1, 9999, val4);
	{}
	sort(arr1.begin(), arr1.end());
	sort(arr2.begin(), arr2.end());
	sort(arr3.begin(), arr3.end());
	sort(arr4.begin(), arr4.end());
	sort(arr5.begin(), arr5.end());

	sortedLinear[0][0] = s1.LeniarSearch(arr1, 9999, val1); sortedLinear[0][1] = s1.LeniarSearch(arr1, 9999, val2); sortedLinear[0][2] = s1.LeniarSearch(arr1, 9999, val3); sortedLinear[0][3] = s1.LeniarSearch(arr1, 9999, val4);
	sortedLinear[1][0] = s1.LeniarSearch(arr1, 9999, val1); sortedLinear[1][1] = s1.LeniarSearch(arr1, 9999, val2); sortedLinear[1][2] = s1.LeniarSearch(arr1, 9999, val3); sortedLinear[1][3] = s1.LeniarSearch(arr1, 9999, val4);
	sortedLinear[2][0] = s1.LeniarSearch(arr1, 9999, val1); sortedLinear[2][1] = s1.LeniarSearch(arr1, 9999, val2); sortedLinear[2][2] = s1.LeniarSearch(arr1, 9999, val3); sortedLinear[2][3] = s1.LeniarSearch(arr1, 9999, val4);
	sortedLinear[3][0] = s1.LeniarSearch(arr1, 9999, val1); sortedLinear[3][1] = s1.LeniarSearch(arr1, 9999, val2); sortedLinear[3][2] = s1.LeniarSearch(arr1, 9999, val3); sortedLinear[3][3] = s1.LeniarSearch(arr1, 9999, val4);
	sortedLinear[4][0] = s1.LeniarSearch(arr1, 9999, val1); sortedLinear[4][1] = s1.LeniarSearch(arr1, 9999, val2); sortedLinear[4][2] = s1.LeniarSearch(arr1, 9999, val3); unsortedLinear[4][3] = s1.LeniarSearch(arr1, 9999, val4);

	binary[0][0] = s1.binarySearch(arr1, 0, 9999, val1); binary[0][1] = s1.binarySearch(arr1, 0, 9999, val2); binary[0][2] = s1.binarySearch(arr1, 0, 9999, val3); binary[0][3] = s1.binarySearch(arr1, 0, 9999, val4);
	binary[1][0] = s1.binarySearch(arr1, 0, 9999, val1); binary[1][1] = s1.binarySearch(arr1, 0, 9999, val2); binary[1][2] = s1.binarySearch(arr1, 0, 9999, val3); binary[1][3] = s1.binarySearch(arr1, 0, 9999, val4);
	binary[2][0] = s1.binarySearch(arr1, 0, 9999, val1); binary[2][1] = s1.binarySearch(arr1, 0, 9999, val2); binary[2][2] = s1.binarySearch(arr1, 0, 9999, val3); binary[2][3] = s1.binarySearch(arr1, 0, 9999, val4);
	binary[3][0] = s1.binarySearch(arr1, 0, 9999, val1); binary[3][1] = s1.binarySearch(arr1, 0, 9999, val2); binary[3][2] = s1.binarySearch(arr1, 0, 9999, val3); binary[3][3] = s1.binarySearch(arr1, 0, 9999, val4);
	binary[4][0] = s1.binarySearch(arr1, 0, 9999, val1); binary[4][1] = s1.binarySearch(arr1, 0, 9999, val2); binary[4][2] = s1.binarySearch(arr1, 0, 9999, val3); binary[4][3] = s1.binarySearch(arr1, 0, 9999, val4);

	interpol[0][0] = s1.InterpolationSearch(arr1, 9999, val1); interpol[0][1] = s1.InterpolationSearch(arr1, 9999, val2); interpol[0][2] = s1.InterpolationSearch(arr1, 9999, val3); interpol[0][3] = s1.InterpolationSearch(arr1, 9999, val4);
	interpol[1][0] = s1.InterpolationSearch(arr1, 9999, val1); interpol[1][1] = s1.InterpolationSearch(arr1, 9999, val2); interpol[1][2] = s1.InterpolationSearch(arr1, 9999, val3); interpol[1][3] = s1.InterpolationSearch(arr1, 9999, val4);
	interpol[2][0] = s1.InterpolationSearch(arr1, 9999, val1); interpol[2][1] = s1.InterpolationSearch(arr1, 9999, val2); interpol[2][2] = s1.InterpolationSearch(arr1, 9999, val3); interpol[2][3] = s1.InterpolationSearch(arr1, 9999, val4);
	interpol[3][0] = s1.InterpolationSearch(arr1, 9999, val1); interpol[3][1] = s1.InterpolationSearch(arr1, 9999, val2); interpol[3][2] = s1.InterpolationSearch(arr1, 9999, val3); interpol[3][3] = s1.InterpolationSearch(arr1, 9999, val4);
	interpol[4][0] = s1.InterpolationSearch(arr1, 9999, val1); interpol[4][1] = s1.InterpolationSearch(arr1, 9999, val2); interpol[4][2] = s1.InterpolationSearch(arr1, 9999, val3); interpol[4][3] = s1.InterpolationSearch(arr1, 9999, val4);

	jump[0][0] = s1.JumpSearch(arr1, 9999, val1); jump[0][1] = s1.JumpSearch(arr1, 9999, val2); jump[0][2] = s1.JumpSearch(arr1, 9999, val3); jump[0][3] = s1.JumpSearch(arr1, 9999, val4);
	jump[1][0] = s1.JumpSearch(arr1, 9999, val1); jump[1][1] = s1.JumpSearch(arr1, 9999, val2); jump[1][2] = s1.JumpSearch(arr1, 9999, val3); jump[1][3] = s1.JumpSearch(arr1, 9999, val4);
	jump[2][0] = s1.JumpSearch(arr1, 9999, val1); jump[2][1] = s1.JumpSearch(arr1, 9999, val2); jump[2][2] = s1.JumpSearch(arr1, 9999, val3); jump[2][3] = s1.JumpSearch(arr1, 9999, val4);
	jump[3][0] = s1.JumpSearch(arr1, 9999, val1); jump[3][1] = s1.JumpSearch(arr1, 9999, val2); jump[3][2] = s1.JumpSearch(arr1, 9999, val3); jump[3][3] = s1.JumpSearch(arr1, 9999, val4);
	jump[4][0] = s1.JumpSearch(arr1, 9999, val1); jump[4][1] = s1.JumpSearch(arr1, 9999, val2); jump[4][2] = s1.JumpSearch(arr1, 9999, val3); jump[4][3] = s1.JumpSearch(arr1, 9999, val4);


	cout << "Unsorted Array - Linear Search\n***********************************" << endl;
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 4; j++)
			cout << unsortedLinear[i][j] << "\t\t";
		cout << endl;
	}
	cout << endl << endl;

	cout << "Sorted Array - Linear Search\n***********************************" << endl;
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 4; j++)
			cout << sortedLinear[i][j] << "\t\t";
		cout << endl;
	}
	cout << endl << endl;

	cout << "Sorted Array - Binary Search\n***********************************" << endl;
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 4; j++)
			cout << binary[i][j] << "\t\t";
		cout << endl;
	}
	cout << endl << endl;

	cout << "Sorted Array - Interpolation Search\n***********************************" << endl;
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 4; j++)
			cout << interpol[i][j] << "\t\t";
		cout << endl;
	}
	cout << endl << endl;

	cout << "Sorted Array - Jump Search\n***********************************" << endl;
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 4; j++)
			cout << jump[i][j] << "\t\t";
		cout << endl;
	}
	cout << endl << endl;

	system("pause");
	return 0;
}