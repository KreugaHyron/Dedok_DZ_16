#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
int main()
{
    setlocale(LC_ALL, "RUS");
    //Task_1
    const int SIZE = 10;
    int array[SIZE];

    srand(time(0));
    for (int i = 0; i < SIZE; i++) {
        array[i] = rand() % 100;
    }

    cout << "Массив: ";
    for (int i = 0; i < SIZE; i++) {
        cout << array[i] << " ";
    }
    cout << "\n";

    int minElement = array[0];
    int maxElement = array[0];

    for (int i = 1; i < SIZE; i++) {
        if (array[i] < minElement) {
            minElement = array[i];
        }
        else if (array[i] > maxElement) {
            maxElement = array[i];
        }
    }
    cout << "Минимальный элемент: " << minElement << "\n";
    cout << "Максимальный элемент: " << maxElement << "\n";
    cout << "\n";

    //Task_2
    const int Array_size = 10;
    int ARRAY[Array_size];
    int minRange;
    int maxRange;

    cout << "Введите минимальное значение диапазона: ";
    cin >> minRange;
    cout << "Введите максимальное значение диапазона: ";
    cin >> maxRange;

    srand(time(0));
    for (int i = 0; i < Array_size; i++) {
        ARRAY[i] = minRange + rand() % (maxRange - minRange + 1);
    }

    cout << "Наш массив: ";
    for (int i = 0; i < Array_size; i++) {
        cout << ARRAY[i] << " ";
    }
    cout << "\n";

    int sum = 0;
    int userValue;
    cout << "Введите значение, с которым будут сравниваться элементы: ";
    cin >> userValue;
    for (int i = 0; i < Array_size; i++) {
        if (ARRAY[i] < userValue) {
            sum += ARRAY[i];
        }
    }
    cout << "Сумма элементов меньше " << userValue << ": " << sum << "\n";
    cout << "\n";

    //Task_4
    const int MAX_SIZE = 50;
    double array_1[MAX_SIZE];
    int size;

    cout << "Введите размер массива (не более " << MAX_SIZE << "): ";
    cin >> size;

    cout << "Введите элементы массива: ";
    for (int i = 0; i < size; i++) {
        cin >> array_1[i];
    }

    //1)
    double negativeSum = 0;
    for (int i = 0; i < size; i++) {
        if (array_1[i] < 0) {
            negativeSum += array_1[i];
        }
    }
    cout << "Сумма отрицательных элементов: " << negativeSum << "\n";

    //2)
    double minElement_1 = array_1[0];
    double maxElement_1 = array_1[0];
    int minIndex = 0;
    int maxIndex = 0;
    for (int i = 1; i < size; i++) {
        if (array[i] < minElement_1) {
            minElement_1 = array[i];
            minIndex = i;
        }
        else if (array[i] > maxElement_1) {
            maxElement_1 = array[i];
            maxIndex = i;
        }
    }

    double product = 1;
    if (minIndex < maxIndex) {
        for (int i = minIndex + 1; i < maxIndex; i++) {
            product *= array[i];
        }
    }
    else {
        for (int i = maxIndex + 1; i < minIndex; i++) {
            product *= array[i];
        }
    }
    cout << "Произведение элементов, находящихся между min и max элементами: " << product << "\n";

    //3)
    double evenProduct = 1;
    for (int i = 1; i < size; i += 2) {
        evenProduct *= array[i];
    }
    cout << "Произведение элементов с четными номерами: " << evenProduct << "\n";

    //4)
    double firstNegative = 0;
    double lastNegative = 0;
    bool foundFirstNegative = false;
    bool foundLastNegative = false;
    double sumBetweenNegatives = 0;
    for (int i = 0; i < size; i++) {
        if (!foundFirstNegative && array[i] < 0) {
            firstNegative = array[i];
            foundFirstNegative = true;
        }
        else if (array[i] < 0) {
            lastNegative = array[i];
            foundLastNegative = true;
        }
        else if (foundFirstNegative && !foundLastNegative) {
            sumBetweenNegatives += array[i];
        }
    }
    cout << "Сумма элементов, находящихся между первым и последним отрицательными элементами: " << sumBetweenNegatives << "\n";
    cout << "\n";
}
