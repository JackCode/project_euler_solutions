#include <vector>
#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>

// Function for finding sum of larger numbers 
std::string findSum(std::string str1, std::string str2) 
{ 
    // Before proceeding further, make sure length 
    // of str2 is larger. 
    if (str1.length() > str2.length()) 
        std::swap(str1, str2); 
  
    // Take an empty string for storing result 
    std::string str = ""; 
  
    // Calculate length of both string 
    int n1 = str1.length(), n2 = str2.length(); 
  
    // Reverse both of strings 
    std::reverse(str1.begin(), str1.end()); 
    std::reverse(str2.begin(), str2.end()); 
  
    int carry = 0; 
    for (int i=0; i<n1; i++) 
    { 
        // Do school mathematics, compute sum of 
        // current digits and carry 
        int sum = ((str1[i]-'0')+(str2[i]-'0')+carry); 
        str.push_back(sum%10 + '0'); 
  
        // Calculate carry for next step 
        carry = sum/10; 
    } 
  
    // Add remaining digits of larger number 
    for (int i=n1; i<n2; i++) 
    { 
        int sum = ((str2[i]-'0')+carry); 
        str.push_back(sum%10 + '0'); 
        carry = sum/10; 
    } 
  
    // Add remaining carry 
    if (carry) 
        str.push_back(carry+'0'); 
  
    // reverse resultant string 
    std::reverse(str.begin(), str.end()); 
  
    return str; 
} 


int main() {
  std::string aNumber = "";
  std::string sum = "";
  std::ifstream numbers("large_sum.txt");

  if (numbers.is_open()) {
    while(getline(numbers, aNumber)) {
      sum = findSum(sum, aNumber);
    }
    numbers.close();

    for (int i = 0; i < 10; i++) {
      std::cout << sum[i];
    }
    std::cout << std::endl;
  } else {
    std::cout << "Unable to open file.\n";
  }
}