#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <random>
using namespace std;

int main()
{

	unsigned long long n;
	cin >> n;
	unsigned long long totalComparisons = n*(n - 1) / 2;
	unsigned long long halftotalComparisons = totalComparisons / 2;
	unsigned long long k = 1;

	/*
	sum comparisons up to and including row k, until we hit half of the comparisons
	k*n - (k*k + k) / 2  is the total sum of comparisons in k rows, starting from first
	......... k = 1
	 ........ k = 2
	  ....... k = 3
	   etc
	*/
	while (k*n - (k*k + k) / 2 < halftotalComparisons) k++;

	/*
	If we happen to have ODD total comparisons, and our "half comparisons" equal exactly to include full k rows, increment the row to get to the "middle" comparison
	*/
	if (totalComparisons % 2 == 1 && k*n - (k*k + k) / 2 == halftotalComparisons) k++;
	cout << k << endl;

	return 0;
}
