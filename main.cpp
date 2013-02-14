/*
Initial code for core randomizer
May want to include special handling services within this code
rather than other classes and functions dealing with them
Project code named:  Ghost Viper
*/

#include <iostream>
#include <random>  	// C++11 header
#include <stdio.h>
#include <stdlib.h>
#include <time.h>		// for randomizer seed
#include <algorithm> 	// required for array sort
#include <iomanip>
			/* <vector> not necessary until arrays replaced by vector
			<array> not necessary until more complicated 
			array methods implemented*/
//#include <vector>
//#include <array>

using namespace std;
			
/*
vector<int> roll;		//Would like to replace array with vector eventually

			
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

	
    roll.clear();
    			*/

    int roll[num];
    int sum=0;

			// for loop generates randoms, populates array, and sums
    for (int x=0; x<num; x++)
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

    return 0;
}
