#include <iostream>
#include <cmath>
using namespace std;

// Function to check if a number is prime or not
bool isPrime(int n) {
    if (n <= 1) {
        return false;
    }
    for (int i = 2; i <= sqrt(n); i++) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

// Function to find GCD of two numbers
int gcd(int a, int b) {
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}

int main() {
    // Step 1: Choose two prime numbers
    int p = 17, q = 11;

    // Step 2: Compute n and phi
    int n = p * q;
    int phi = (p - 1) * (q - 1);

    // Step 3: Choose an integer e such that 1 < e < phi and gcd(e, phi) = 1
    int e = 7;
    while (e < phi) {
        if (gcd(e, phi) == 1) {
            break;
        }
        e++;
    }

    // Step 4: Compute the secret key d
    int k = 2;
    int d = (1 + (k * phi)) / e;
    while (d > phi) {
        k++;
        d = (1 + (k * phi)) / e;
    }

    // Step 5: Print the public and private keys
    cout << "Public key: {" << e << ", " << n << "}" << endl;
    cout << "Private key: {" << d << ", " << n << "}" << endl;

    // Step 6: Encrypt the message
    string message = "HELLO";
    int encrypted[message.length()];
    for (int i = 0; i < message.length(); i++) {
        int m = message[i];
        int c = fmod(pow(m, e), n);
        encrypted[i] = c;
    }

    // Step 7: Decrypt the message
    string decrypted;
    for (int i = 0; i < message.length(); i++) {
        int c = encrypted[i];
        int m = fmod(pow(c, d), n);
        decrypted += (char)m;
    }

    // Step 8: Print the encrypted and decrypted messages
    cout << "Encrypted message: ";
    for (int i = 0; i < message.length(); i++) {
        cout << encrypted[i] << " ";
    }
    cout << endl;
    cout << "Decrypted message: " << decrypted << endl;

    return 0;
}
