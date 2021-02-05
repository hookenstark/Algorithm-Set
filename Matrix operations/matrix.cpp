#include <iostream>
using namespace std;

const int N=2;
const int M=3;
const int P=2;

void multiplication(int A[N][M], int B[M][P]){
	int C[N][P]; // multiplied matrix

	// iterate over the row
	for (int i = 0; i < N; i++){
		// iterate over column of each row
		for (int j = 0; j < P; j++){
			C[i][j] = 0;

			// iterate till the column of matrix A or row of matrix B
			for (int k = 0; k < M; k++){
				// multiply and add it to the new matrix
				C[i][j] += A[i][k]*B[k][j];
			}
		}
	}

	// print the final matrix
	cout << "Final matrix:" << endl;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < P; j++){
			cout << C[i][j];
			cout << ", ";
		}
		cout << endl;
	}
}

int main()
{
	//first
	int matrix_1[2][3] = {	{1,2,3},
							{4,5,6}};
	
	//second
	int matrix_2[3][2] = {	{1,4},
							{2,5},
							{3,6}};
							
	multiplication(matrix_1, matrix_2);
	
	return 0;
}