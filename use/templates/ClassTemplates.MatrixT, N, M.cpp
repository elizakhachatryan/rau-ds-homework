#include <iostream>
#include <cassert>
using namespace std;

template <typename T, int N, int M>
class Matrix {
private:
    T data[N][M];

public:
    void set(int row, int col, T value) {
        data[row][col] = value;
    }
    T get(int row, int col) {
        return data[row][col];
    }
    void print() {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                cout << data[i][j] << " ";
            }
            cout << endl;
        }
    }
    Matrix<T, N, M> operator+(const Matrix<T, N, M>& other) {
        Matrix<T, N, M> result;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                result.data[i][j] = data[i][j] + other.data[i][j];
            }
        }

        return result;
    }
};

int main() {
    Matrix<int, 2, 2> a;
    Matrix<int, 2, 2> b;
    a.set(0, 0, 1);
    a.set(0, 1, 2);
    a.set(1, 0, 3);
    a.set(1, 1, 4);
    b.set(0, 0, 5);
    b.set(0, 1, 6);
    b.set(1, 0, 7);
    b.set(1, 1, 8);
    Matrix<int, 2, 2> result = a + b;
    assert(result.get(0, 0) == 6);
    assert(result.get(0, 1) == 8);
    assert(result.get(1, 0) == 10);
    assert(result.get(1, 1) == 12);
    cout << "Result:" << endl;
    result.print();
    cout << "All tests passed!" << endl;

    return 0;
}

