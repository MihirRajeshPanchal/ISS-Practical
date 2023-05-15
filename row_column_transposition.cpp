#include <iostream>
#include <string>
#include <vector>

using namespace std;

string encrypt(string message, int rows, int cols) {
    // Determine the number of padding characters needed
    int extraChars = rows * cols - message.length();
    if (extraChars > 0) {
        message.append(extraChars, ' ');
    }
    
    // Create the matrix
    vector<vector<char>> matrix(rows, vector<char>(cols));
    int index = 0;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            matrix[i][j] = message[index++];
        }
    }
    
    // Print the matrix
    cout << "Original matrix: " << endl;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    // Transpose the matrix
    vector<vector<char>> transposed(cols, vector<char>(rows));
    for (int i = 0; i < cols; i++) {
        for (int j = 0; j < rows; j++) {
            transposed[i][j] = matrix[j][i];
        }
    }
    
    // Print the transposed matrix
    cout << "Transposed matrix: " << endl;
    for (int i = 0; i < cols; i++) {
        for (int j = 0; j < rows; j++) {
            cout << transposed[i][j] << " ";
        }
        cout << endl;
    }
    
    // Read the cipher message from the transposed matrix
    string cipherMessage;
    for (int i = 0; i < cols; i++) {
        for (int j = 0; j < rows; j++) {
            cipherMessage.push_back(transposed[i][j]);
        }
    }
    
    return cipherMessage;
}

string decrypt(string cipherMessage, int rows, int cols) {
    // Determine the number of padding characters
    int extraChars = rows * cols - cipherMessage.length();
    if (extraChars > 0) {
        cipherMessage.append(extraChars, ' ');
    }
    
    // Create the matrix
    vector<vector<char>> matrix(cols, vector<char>(rows));
    int index = 0;
    for (int i = 0; i < cols; i++) {
        for (int j = 0; j < rows; j++) {
            matrix[i][j] = cipherMessage[index++];
        }
    }
    
    // Transpose the matrix
    vector<vector<char>> transposed(rows, vector<char>(cols));
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            transposed[i][j] = matrix[j][i];
        }
    }
    
    // Read the original message from the transposed matrix
    string originalMessage;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            originalMessage.push_back(transposed[i][j]);
        }
    }
    
    return originalMessage;
}

int main() {
    string message = "HELLO WORLD";
    int rows = 4;
    int cols = 3;
    
    cout << "Original message: " << message << endl;
    
    string cipherMessage = encrypt(message, rows, cols);
    cout << "Cipher message: " << cipherMessage << endl;
    
    string originalMessage = decrypt(cipherMessage, rows, cols);
    cout << "Decrypted message: " << originalMessage << endl;
    
    return 0;
}
