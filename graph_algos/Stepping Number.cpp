// A C++ program to find all the Stepping Number in [n, m] 
#include<bits/stdc++.h> 
using namespace std; 
  
// This function checks if an integer n is a Stepping Number 
bool isStepNum(int n) 
{ 
    // Initalize prevDigit with -1 
    int prevDigit = -1; 
  
    // Iterate through all digits of n and compare difference 
    // between value of previous and current digits 
    while (n) 
    { 
        // Get Current digit 
        int curDigit = n % 10; 
  
        // Single digit is consider as a 
        // Stepping Number 
        if (prevDigit == -1) 
            prevDigit = curDigit; 
        else
        { 
            // Check if absolute difference between 
            // prev digit and current digit is 1 
            if (abs(prevDigit - curDigit) != 1) 
                 return false; 
        } 
        prevDigit = curDigit; 
        n /= 10; 
    } 
  
    return true; 
} 
  
// A brute force approach based function to find all 
// stepping numbers. 
void displaySteppingNumbers(int n, int m) 
{ 
    // Iterate through all the numbers from [N,M] 
    // and check if it’s a stepping number. 
    for (int i=n; i<=m; i++) 
        if (isStepNum(i)) 
            cout << i << " "; 
} 
  
// Driver program to test above function 
int main() 
{ 
    int n,m;
    cout<<"Enter the range of the numbers : ";
    cin>>n>>m;
  
    // Display Stepping Numbers in 
    // the range [n, m] 
    cout<<"the Stepping numbers are :";
    displaySteppingNumbers(n, m); 
  
    return 0; 
} 
