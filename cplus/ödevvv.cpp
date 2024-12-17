#include <iostream>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

using namespace std;
 
 
int determinant(int matrix[3][3]) {
   return matrix[0][0] * (matrix[1][1] * matrix[2][2] - matrix[1][2] * matrix[2][1]) -
          matrix[0][1] * (matrix[1][0] * matrix[2][2] - matrix[1][2] * matrix[2][0]) +
          matrix[0][2] * (matrix[1][0] * matrix[2][1] - matrix[1][1] * matrix[2][0]);
}
 
int main() {
   int A[3][3], B[3][3], C[3][3], D[3][3];
 
   cout << "3x3 boyutlarýndaki A matrisinin elemanlarini giriniz:\n";
   for (int i = 0; i < 3; i++) {
       for (int j = 0; j < 3; j++) {
           cin >> A[i][j];
       }
   }
 
   cout << "3x3 boyutlarýndaki B matrisinin elemanlarini giriniz:\n";
   for (int i = 0; i < 3; i++) {
       for (int j = 0; j < 3; j++) {
           cin >> B[i][j];
       }
   }
 
   
   for (int i = 0; i < 3; i++) {
       for (int j = 0; j < 3; j++) {
           C[i][j] = A[i][j] + B[i][j];
       }
   }
 
 
   for (int i = 0; i < 3; i++) {
       for (int j = 0; j < 3; j++) {
           D[i][j] = 0;
           for (int k = 0; k < 3; k++) {
               D[i][j] += A[i][k] * B[k][j];
           }
       }
   }
 
 
   int detA = determinant(A);
   int detB = determinant(B);
 
 
   cout << "\nMatris A:\n";
   for (int i = 0; i < 3; i++) {
       for (int j = 0; j < 3; j++) {
           cout << A[i][j] << " ";
       }
       cout << endl;
   }
 
   cout << "\nMatris B:\n";
   for (int i = 0; i < 3; i++) {
       for (int j = 0; j < 3; j++) {
           cout << B[i][j] << " ";
       }
       cout << endl;
   }
 
   cout << "\nMatris C = A + B:\n";
   for (int i = 0; i < 3; i++) {
       for (int j = 0; j < 3; j++) {
           cout << C[i][j] << " ";
       }
       cout << endl;
   }
 
   cout << "\nMatris D = A x B:\n";
   for (int i = 0; i < 3; i++) {
       for (int j = 0; j < 3; j++) {
           cout << D[i][j] << " ";
       }
       cout << endl;
   }
 
   cout << "\nMatris A'nin determinantý: " << detA << endl;
   cout << "Matris B'nin determinantý: " << detB << endl;
	
	
	
	
	
	
	
	return 0;
}
