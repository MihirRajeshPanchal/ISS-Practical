#include <iostream>
#include <string>

using namespace std;

string encrypt(string message, string key) {
    string ciphertext = "";
    for (int i = 0; i < message.length(); i++) {
        if (message[i] >= 'a' && message[i] <= 'z') {
            ciphertext += key[message[i] - 'a'];
        } else if (message[i] >= 'A' && message[i] <= 'Z') {
            ciphertext += toupper(key[message[i] - 'A']);
        } else {
            ciphertext += message[i];
        }
    }
    return ciphertext;
}

string decrypt(string ciphertext, string key) {
    string message = "";
    for (int i = 0; i < ciphertext.length(); i++) {
        if (ciphertext[i] >= 'a' && ciphertext[i] <= 'z') {
            message += 'a' + key.find(ciphertext[i]);
        } else if (ciphertext[i] >= 'A' && ciphertext[i] <= 'Z') {
            message += 'A' + key.find(tolower(ciphertext[i]));
        } else {
            message += ciphertext[i];
        }
    }
    return message;
}

int main() {
    string message = "hello world";
    string key = "qwertyuiopasdfghjklzxcvbnm";
    string ciphertext = encrypt(message, key);
    string decrypted_message = decrypt(ciphertext, key);
    cout << "Original message: " << message << endl;
    cout << "Encrypted message: " << ciphertext << endl;
    cout << "Decrypted message: " << decrypted_message << endl;
    return 0;
}
