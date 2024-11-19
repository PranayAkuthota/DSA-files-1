#include <iostream>
using namespace std;

template <typename T>
class Array {
private:
    T *arr;
    int size;
public:
    Array(int s) : size(s) {
        arr = new T[size];
    }

    void input() {
        cout << "Enter elements of the array: ";
        for (int i = 0; i < size; i++) {
            cin >> arr[i];
        }
    }

    T findMax() {
        T max = arr[0];
        for (int i = 1; i < size; i++) {
            if (arr[i] > max)
                max = arr[i];
        }
        return max;
    }

    T findMin() {
        T min = arr[0];
        for (int i = 1; i < size; i++) {
            if (arr[i] < min)
                min = arr[i];
        }
        return min;
    }

    ~Array() {
        delete[] arr;
    }
};

int main() {
    int n;
    cout << "Enter the size of the integer array: ";
    cin >> n;
    Array<int> intArr(n);
    intArr.input();
    cout << "Max: " << intArr.findMax() << endl;
    cout << "Min: " << intArr.findMin() << endl;

    cout << "Enter the size of the float array: ";
    cin >> n;
    Array<float> floatArr(n);
    floatArr.input();
    cout << "Max: " << floatArr.findMax() << endl;
    cout << "Min: " << floatArr.findMin() << endl;

    return 0;
}
