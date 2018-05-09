/*
Dennis Matveyev - Unloaded Die 
First Draft .. hope my math is right...
*/

#include <iostream>
#include <cmath>
#include <string>
#include <vector>
#include <iomanip>
using namespace std;

/*
 Picks a side (1 - 6) 
 Computes special probability for that side so that total weighed rolls equal to 3.5
 computes difference bweteen the chosen side and computed side
*/
double trySide(int chosen, vector<double> prob)
{
	vector<double>computed(6);

	/* Figure out weighted values */
	for (int side = 1; side <= 6; side++)
		computed[side - 1] = prob[side - 1] * side;

	/* Figure out result without the chosen side */
	double sum = 0;
	for (int side = 1; side <= 6; side++)
		if (side != chosen) sum += computed[side - 1];


	double probability = (3.5 - sum) / chosen;

	double difference = chosen - chosen*probability / prob[chosen - 1];

	return abs(difference);
}

int main()
{
	vector<double> prob;
	prob.resize(6);
	for (int i = 0; i < 6; i++)
		cin >> prob[i];

	double min = 666;
	/* finds min side*/
	for (int side = 1; side <= 6; side++)
	{
		double result = trySide(side, prob);

//              cout << "side" << side << ": " << result << endl;
		if (result < min) min = result;
	}
	cout << fixed << setprecision(3) << min << endl;

	return 0;
}

    
