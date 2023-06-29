//#include<iostream>
//#include"time.h"
//using namespace std;
//int main()
//{
//
//	int const n = 10, a = 10, b = 20;
//	int mass[n];
//	int min, max;
//	srand(time(NULL));
//
//		for (int i = 0; i < n; i++)
//		{
//			mass[i] = a + rand() % (b - a);
//			cout << mass[i] << " ";
//		}
//	min = mass[0];
//	max = mass[0];
//	for (int i = 1; i < n; i++)
//	{
//		if (mass[i] > max)
//		{
//			max = mass[i];
//		}
//		if (mass[i] < min)
//		{
//			min = mass[i];
//		}
//
//	}
//	cout << "min:" << min << ", max:" << max;
//	return 0;
//}


//#include <iostream>
//#include "time.h"
//using namespace std;
//int main()
//{
//	int const n = 10;
//	int mass[n];
//	int a, b, sum, level;
//	srand(time(NULL));
//	cout << "Enter the start of the range to generate "
//		"numbers:\n";
//	cin >> a;
//	cout << "Enter the end of the range:\n";
//	cin >> b;
//	cout << "Enter the level value:\n";
//	cin >> level;
//	for (int i = 0; i < n; i++)
//	{
//			mass[i] = a + rand() % (b - a);
//		cout << mass[i] << " ";
//	}
//	sum = 0;
//	for (int i = 0; i < n; i++)
//	{
//		if (mass[i] < level)
//		{
//			sum = sum + mass[i];
//		}
//
//	}
//
//	cout << "\nSum:" << sum;
//	return 0;
//}

//#include <iostream>
//using namespace std;
//int main()
//{
//	int const n = 12;
//	int profit[n];
//	int start, end, minPrMonth, maxPrMonth;
//	for (int i = 0; i < n; i++)
//	{
//		cout << "Enter your profit for " << i + 1;
//		cout << " month:\n";
//		cin >> profit[i];
//	}
//	cout << "Enter the start of the range "
//		"interested for you:\n";
//	cin >> start;
//	cout << "Enter the end of the range interested "
//		"for you:\n";
//	cin >> end;
//	minPrMonth = start - 1;
//	maxPrMonth = start - 1;
//	for (int i = start; i <= end - 1; i++)
//	{
//		if (profit[i] > profit[maxPrMonth])
//		{
//			maxPrMonth = i;
//		}
//		if (profit[i] < profit[minPrMonth])
//		{
//			minPrMonth = i;
//		}
//	}
//		cout << "You got the min. profit in "
//		<< minPrMonth + 1 << " month.\n";
//	cout << "You got the max. profit in "
//		<< maxPrMonth + 1 << " month.\n";
//	return 0;
//}


#include <iostream>
#include <limits>

int main() {
    const int size = 8;
    double array[size] = { 2.5, -1.3, 4.7, -0.8, 3.2, -2.1, 5.9, -3.6 };

    double sumNegative = 0.0;
    double productMinMax = 1.0;
    double productEvenIndices = 1.0;
    double sumBetweenNegatives = 0.0;

    int minIndex = 0;
    int maxIndex = 0;
    int firstNegativeIndex = -1;
    int lastNegativeIndex = -1;

    for (int i = 0; i < size; i++) {
        if (array[i] < 0) {
            sumNegative += array[i];

            if (firstNegativeIndex == -1) {
                firstNegativeIndex = i;
            }
            else {
                lastNegativeIndex = i;
            }
        }

        if (array[i] < array[minIndex]) {
            minIndex = i;
        }

        if (array[i] > array[maxIndex]) {
            maxIndex = i;
        }

        if (i % 2 == 0) {
            productEvenIndices *= array[i];
        }
    }

    if (firstNegativeIndex != -1 && lastNegativeIndex != -1) {
        for (int i = firstNegativeIndex + 1; i < lastNegativeIndex; i++) {
            sumBetweenNegatives += array[i];
        }
    }

    if (minIndex < maxIndex) {
        for (int i = minIndex + 1; i < maxIndex; i++) {
            productMinMax *= array[i];
        }
    }
    else {
        for (int i = maxIndex + 1; i < minIndex; i++) {
            productMinMax *= array[i];
        }
    }

    std::cout << "Sum of negative elements: " << sumNegative << std::endl;
    std::cout << "Product of elements between min and max: " << productMinMax << std::endl;
    std::cout << "Product of elements with even indices: " << productEvenIndices << std::endl;
    std::cout << "Sum of elements between the first and last negative elements: " << sumBetweenNegatives << std::endl;

    return 0;
}