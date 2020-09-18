// Cracking the Coding Interview - Interview Questions 
// (1.7) - Rotate Matrix: Given an image represented by an NxN matrix, where each pixel in the image is 4
//         bytes, write a method to rotate the image by 90 degrees. Can you do this in place? 

#include <iostream>

using namespace std;

void helper_transpose(int **matrix, int N)
{
    for(int i = 0; i < N; ++i)
    {
        for(int j = i+1; j < N; ++j)
        {
            if(i != j)
            {
                swap(matrix[i][j], matrix[j][i]);
            }
        }
    }
    return;
}
void helper_reverse(int *row, int N)
{
    for(int i = 0; i < N/2; ++i)
    {
        swap(row[i], row[N-i-1]);
    }
    return;
}
void rotate1(int **matrix, int N)
{
    // Transpose matrix. 
    helper_transpose(matrix, N);

    // Reverse each row. 
    for(int i = 0; i < N; ++i)
    {
        helper_reverse(matrix[i], N);
    }
    return;
}
void rotate2(int **matrix, int N)
{
    for(int i = 0; i < N/2; ++i)
    {
        for(int j = i; i < N-i-1; ++j)
        {
            int temp = matrix[i][j];
            matrix[i][j] = matrix[j][N-i-1];
            matrix[j][N-i-1] = matrix[N-i-1][N-j-1];
            matrix[N-i-1][N-j-1] = matrix[N-j-1][i];
            matrix[N-j-1][i] = temp;
        }
    }
    return;
}
void printMatrix(int **matrix, int N)
{
    for(int i = 0; i < N; ++i)
    {
        for(int j = 0; j < N; ++j)
        {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    return;
}
int main()
{
    int N;

    cout << "Enter N for NxN matrix: ";
    cin >> N;

    int **matrix = new int *[N];

    for(int i = 0; i < N; ++i)
    {
        matrix[i] = new int [N];
    }
    for(int i = 0; i < N; ++i)
    {
        for(int j = 0; j < N; ++j)
        {
            cin >> matrix[i][j];
        }
    }

    cout << "Rotated matrix by 90 (clockwise):" << endl;

    rotate1(matrix, N);
    printMatrix(matrix, N);

    cout << "Rotated matrix again by 90 (anticlockwise):" << endl;

    rotate2(matrix, N);
    printMatrix(matrix, N);

    return 0;
}