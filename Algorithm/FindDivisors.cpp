#include "pch.h"
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long getDivisor(long n, long m)
{
	int maxIndex = 0;	//배열 최대 인덱스 값
	long result = 0;	//리턴 값

	/* 약수 개수 구하기 */
	for (int i = 1; i * i <= n; i++)
		if (n % i == 0) maxIndex++;	

	maxIndex *= 2;
	/* 약수 개수 구하기 끝 */

	long *divisors = new long[maxIndex]; //약수 자료구조

	int curIndex = 0; //현재 인덱스 값

	/* 약수 데이터 집어넣기*/
	for (int i = 1;  curIndex * 2 < maxIndex; i++)
	{
		if (i >= n) break;
		if (i*i > n) break;

		if (n % i == 0)
		{
			divisors[curIndex] = i;
			divisors[maxIndex - 1 - curIndex] = n / i;
			curIndex++;
		}
	}

	/* 결과값 출력 */
	if (m <= maxIndex)
		result = divisors[m - 1];
	delete[] divisors;
	return result;
}

int main()
{
	long test = getDivisor(1000, 3);
	cout << test;

	return 0;
}
