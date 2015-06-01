#include <stdio.h>

int pUglyNumbers[1501];

int Min(int number1, int number2, int number3)
{
	int min = (number1 < number2) ? number1 : number2;
    min = (min < number3) ? min : number3;
    return min;
}

int GetUglyNumber(int index)
{
	if(index <= 0)
        return 0;

    pUglyNumbers[0] = 1;

    int nextUglyIndex = 1;

    int index2 = 0;
    int index3 = 0;
    int index5 = 0;

    while(nextUglyIndex < index)
	{
		int min = Min(pUglyNumbers[index2] * 2, pUglyNumbers[index3] * 3, pUglyNumbers[index5] * 5);
        pUglyNumbers[nextUglyIndex] = min;

		while(pUglyNumbers[index2] * 2 <= pUglyNumbers[nextUglyIndex])
			++index2;
        while(pUglyNumbers[index3] * 3 <= pUglyNumbers[nextUglyIndex])
            ++index3;
        while(pUglyNumbers[index5] * 5 <= pUglyNumbers[nextUglyIndex])
            ++index5;
        
		++nextUglyIndex;
    }

    int ugly = pUglyNumbers[nextUglyIndex - 1];

    return ugly;
}

int main()
{
	int n;
	while(~scanf("%d",&n))
		printf("%d\n",GetUglyNumber(n));

	return 0;

}
