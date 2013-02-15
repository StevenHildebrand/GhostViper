/*
Initial code for core randomizer
May want to include special handling services within this code
rather than other classes and functions dealing with them
Project code named:  Ghost Viper
*/

#include <iostream>
#include <random>		// C++11 header
#include <stdio.h>
#include <stdlib.h>
#include <time.h>		// for randomizer seed
#include <algorithm> 		// required for sort()
#include <iomanip>
#include <vector>
#include <numeric>
			/* <vector> not necessary until arrays replaced by vector
			<array> not necessary until more complicated
			array methods implemented*/

//#include <array>

using namespace std;

/*
void randomizer ()		//randomizer() function required for C++98
{

    srand (time(NULL));

}
*/

void dice (int num, int sides)
{
    default_random_engine rne((unsigned int)time(0));
			/*This is C++11 compliant, flag must be set for C++11 or C++0x
			otherwise compiler will throw an error
			*/

    			/* Other C++11 randomizer code to test
    default_random_engine generator;
    uniform_int_distribution<int> distribution(1,sides);
    auto toss = bind ( distribution, generator );
    			*/

    int roll[num];
    int sum=0;

			
    for (int x=0; x<num; x++) // for loop generates randoms, populates array, and sums
    {
        int r = 0;
        r = rne() % sides + 1;
        roll[x]=r;
        sum +=r;
    }
			/* C++ arrays are difficult to work with;
			'size' is not a method for arrays like other languages
			size (as number of elements) must be calculated on next line*/
    int n = (sizeof(roll) / sizeof(roll[0]));
    int e = n-1;

			// Some method-like algorithms can be implemented
    sort (roll, roll+n);

			/* remaining lines to close bracket are all formatting
			to look good on console
			won't be needed when GUI is implemented*/
    cout << num << "d" << sides << ":\t" << sum <<"\t[";

    for (int i=0; i<e; i++)
    {
        cout << roll[i] << " ";
    }

    cout << roll[e] << "]" << endl;
}

vector<int> diceVector (int num, int sides)
{
    /*mt19937_64 rne((unsigned int)time(0));
    	other generators for testing later */
    random_device rne;

    vector<int> roll;
    int sum=0;

	for (int x=0; x<num; x++)
    {
        int r = 0;
        r = rne() % sides + 1;
        roll.push_back(r);
        sum +=r;
    }

    sort (roll.begin(), roll.end());
    // int last = roll.end();

    //int sum = (int)accumulate(roll.begin(), roll.end(), 0);

    cout << num << "d" << sides << ":\t" << sum <<"\t[";

    for (unsigned int i = 0; i < roll.size()-1; i++)
    {

       cout << roll[i] << " ";
    }

    cout << roll[num-1] << "]" << endl;

    return roll;
}

void tests()
{
    default_random_engine test1((unsigned int)time(0));
    random_device test2;
    int tst1[7];
    int tst2[7];

    for (int x = 0; x<10000; x++)
    {
        int v = test1() % 6 +1;
        tst1[v] +=1;
        tst1[0] +=1;
    }

    for (int x = 0; x<10000; x++)
    {
        int v = test2() % 6 +1;
        tst2[v] +=1;
        tst2[0] +=1;
    }

    cout << "Generator Tests" << endl << endl;

    cout << "Default" << endl;
    for (int a = 0; a<7; a++)
    {
        cout << a << ": " << tst1[a] <<endl;
    }

    cout << endl << "Random Device" << endl;
    for (int a = 0; a<7; a++)
    {
        cout << a << ": " << tst2[a] <<endl;
    }


}


int main()
{
    //randomizer();  Not neccessary with C++11 random methods
    dice(4,4);
    dice(3,6);
    dice(5,8);
    dice(2,10);
    dice(6,12);
    dice(3,20);
    dice(4,100);
    dice(6,13);

    cout << endl << "diceVector()" << endl;
    diceVector(4,4);
    diceVector(3,6);
    diceVector(5,8);
    diceVector(2,10);
    diceVector(6,12);
    diceVector(3,20);
    diceVector(4,100);
    diceVector(6,13);

    tests();

    return 0;
}
