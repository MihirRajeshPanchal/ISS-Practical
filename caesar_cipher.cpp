#include <iostream>
#include <string>

using namespace std;

string encrypt(string message, int key) {
    string result = "";

    for (int i = 0; i < message.length(); i++) {
        if (isupper(message[i])) {
            result += char(int(message[i] + key - 65) % 26 + 65);
        }
        else {
            result += char(int(message[i] + key - 97) % 26 + 97);
        }
    }

    return result;
}

string decrypt(string message, int key) {
    return encrypt(message, 26 - key);
}

int main() {
    string message = "HELLO WORLD";
    int key = 3;

    string encrypted_message = encrypt(message, key);
    string decrypted_message = decrypt(encrypted_message, key);

    cout << "Original message: " << message << endl;
    cout << "Encrypted message: " << encrypted_message << endl;
    cout << "Decrypted message: " << decrypted_message << endl;

    return 0;
}