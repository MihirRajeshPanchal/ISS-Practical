#include <iostream>
#include <string>

using namespace std;

// Hexadecimal to binary conversion
string hex2bin(string s) {
  string bin = "";
  for (char c : s) {
    switch (c) {
      case '0': bin += "0000"; break;
      case '1': bin += "0001"; break;
      case '2': bin += "0010"; break;
      case '3': bin += "0011"; break;
      case '4': bin += "0100"; break;
      case '5': bin += "0101"; break;
      case '6': bin += "0110"; break;
      case '7': bin += "0111"; break;
      case '8': bin += "1000"; break;
      case '9': bin += "1001"; break;
      case 'A': bin += "1010"; break;
      case 'B': bin += "1011"; break;
      case 'C': bin += "1100"; break;
      case 'D': bin += "1101"; break;
      case 'E': bin += "1110"; break;
      case 'F': bin += "1111"; break;
    }
  }
  return bin;
}

// Binary to hexadecimal conversion
string bin2hex(string s) {
  string hex = "";
  for (int i = 0; i < s.size(); i += 4) {
    int val = stoi(s.substr(i, 4), 2);
    switch (val) {
      case 0: hex += "00"; break;
      case 1: hex += "01"; break;
      case 2: hex += "02"; break;
      case 3: hex += "03"; break;
      case 4: hex += "04"; break;
      case 5: hex += "05"; break;
      case 6: hex += "06"; break;
      case 7: hex += "07"; break;
      case 8: hex += "08"; break;
      case 9: hex += "09"; break;
      case 10: hex += "0A"; break;
      case 11: hex += "0B"; break;
      case 12: hex += "0C"; break;
      case 13: hex += "0D"; break;
      case 14: hex += "0E"; break;
      case 15: hex += "0F"; break;
    }
  }
  return hex;
}

// Binary to decimal conversion
int bin2dec(string s) {
  int val = 0;
  for (int i = 0; i < s.size(); i++) {
    val = val * 2 + (s[i] - '0');
  }
  return val;
}

// Decimal to binary conversion
string dec2bin(int n) {
  string bin = "";
  while (n > 0) {
    bin += (n % 2) + '0';
    n /= 2;
  }
  reverse(bin.begin(), bin.end());
  return bin;
}

// Permute function to rearrange the bits
string permute(string k, int *arr, int n) {
  string permuted = "";
  for (int i = 0; i < n; i++) {
    permuted += k[arr[i] - 1];
  }
  return permuted;
}

// Shifting the bits towards left by nth shifts
string shift_left(string k, int n) {
  string s = "";
  for (int i = 0; i < n; i++) {
    s += k[k.size() - 1];
  }
  for (int i = 0; i < k.size() - n; i++) {
    s +=
