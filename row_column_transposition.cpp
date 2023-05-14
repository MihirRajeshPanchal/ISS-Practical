int matrix[rows][cols];
cout << "Enter the matrix elements: " << endl;
for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
        cin >> matrix[i][j];
    }
}

int transposed[cols][rows];
for (int i = 0; i < cols; i++) {
    for (int j = 0; j < rows; j++) {
        transposed[i][j] = matrix[j][i];
    }
}

cout << "Transposed matrix: " << endl;
for (int i = 0; i < cols; i++) {
    for (int j = 0; j < rows; j++) {
        cout << transposed[i][j] << " ";
    }
    cout << endl;
}

return 0;