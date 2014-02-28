#include <stdio.h>
using namespace std;

/*
In England the currency is made up of pound, £, and pence, p, and there are eight coins in general circulation:

    1p, 2p, 5p, 10p, 20p, 50p, £1 (100p) and £2 (200p).

It is possible to make £2 in the following way:

    1×£1 + 1×50p + 2×20p + 1×5p + 1×2p + 3×1p

How many different ways can £2 be made using any number of coins?

*/

//coin type      1p 	2p 		5p 		10p 	20p 	50p 	100p 	200p
//max number	 200 	100 	40 		20 		10 		4 		2 		1
int values[8] = {1,2,5,10,20,50,100,200};
int maxNum[8] = {200, 100, 40, 20, 10, 4, 2,1};
int sumCount;

// - given: an index of value and max numbers; the current sum
// - loop from max number -> 0: 
// 		- if current sum + current value == 200 -> count ++; continue the loop
// 		- if current sum + current value > 200; continue the loop
//		- if current sum + current value < 200, recursive call for index + 1
// - base case: when index > 7 -> just return
void checkCoinSum(int index, int currentSum)
{
	if(index == 8)
		return;
	int whatLeft = 200 - currentSum; //some significant pruning here!
	
	for(int i = whatLeft/values[index]; i >= 0; i--)
	{
		
		int currentValue = i * values[index];
		currentSum += currentValue;
		//printf("\n currentSum: %d", currentSum);
		if(currentSum > 200)
		{
			currentSum -= currentValue;
			continue;
		} 
		else if(currentSum == 200)
		{
			//printf("\n pick number: %d", i);
			sumCount++;
			currentSum -= currentValue;
			continue;
		}
		else if(currentSum < 200)
		{
			checkCoinSum(index + 1, currentSum);
		}
		currentSum -= currentValue;
	}
}

int main()
{
	sumCount = 0;
	checkCoinSum(0,0);
	printf("the result is: %d", sumCount);
}