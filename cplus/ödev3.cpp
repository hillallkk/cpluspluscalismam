#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <numeric>
 
using namespace std;
 
#define SIZE 500  
#define MIN 10    
#define MAX 35    
#define TARGET_AVG 25
#define TOLERANCE 5
 
 
double calculateAverage(const vector<int>& data) {
   return accumulate(data.begin(), data.end(), 0.0) / data.size();
}
 
int main() {
setlocale(LC_ALL,"Turkish");
   srand(time(0));
 
   vector<int> numbers(SIZE);
 
   double avg = 0.0;
   do {
       
       for (int i = 0; i < SIZE; i++) {
           numbers[i] = rand() % (MAX - MIN + 1) + MIN;
       }
     
       avg = calculateAverage(numbers);
   } while (avg < (TARGET_AVG - TOLERANCE) || avg > (TARGET_AVG + TOLERANCE));
 
 
   cout << "Generated Numbers (10-35):" << endl;
   for (int i = 0; i < SIZE; i++) {
       cout << numbers[i] << " ";
       if ((i + 1) % 20 == 0)
           cout << endl;
   }
 
   cout << "\nSayýlarýn ortalamasý: " << avg << endl;
 
   return 0;
}
