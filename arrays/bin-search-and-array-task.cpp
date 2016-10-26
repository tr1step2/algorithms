#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <sstream>
#include <exception>
#include <stdexcept>
#include <thread>
#include <chrono>
#include <sstream>
/*
    Найти в массиве два числа, сумма которых равна третьему
*/

using namespace std;

const size_t N = 10;


void printa(const vector<int> & array)
{
	for (const auto & a : array)
		std::cout << a << " ";

	std::cout << std::endl;
}

void randomizea(vector<int> & array)
{
	array.reserve(N);
	for(size_t i = 0; i < N; ++i)
		array.push_back(rand() % 10);
}

size_t findPlace(const vector<int> & a, const int x)
{
	int index = 0;

	int right = a.size() - 1;
	int left = 0;

	//todo: chech statement
	while(right - left > 1)
	{
		index = (right + left) / 2;
		if (x > a[index])
		{
			left = index;
		}
		else
		{
			right = index;
		}
	}

	if (a[left] > x)
		return left;
	if (a[right] < x)
		return right;

	return left + 1;
}

pair<int, int> findXY(const vector<int> & array, const int x)
{
	auto index = findPlace(array, x);
	if (index && array[index] > x)
		index -= 1;

	size_t leftIndex = 0;

	while(index > leftIndex)
	{
		if (array[index] + array[leftIndex] == x)
			return make_pair(array[index], array[leftIndex]);

		if (array[index] + array[leftIndex] > x)
			index -= 1;
		else
			leftIndex += 1;
	}

	return make_pair(-1, -1);
}

std::vector<int> preparea()
{
	std::vector<int> a;
	randomizea(a);
	std::sort(a.begin(), a.end());
	printa(a);

	return a;
}

int preparex(int argc, char ** argv)
{
	int x = 0;
	if (argc > 1)
	{
		std::stringstream ss;
		ss << argv[1];
		ss >> x;
	}

	std::cout << "X : " << x << std::endl;
	return x;
}

int main(int argc, char **argv)
{
	auto x = preparex(argc, argv);
	auto a = preparea();
	auto f = findPlace(a, x);
	auto xy = findXY(a, x);

	cout << "find index : " << f << endl;
	cout << "X : " << xy.first << " Y : " << xy.second << endl;
}