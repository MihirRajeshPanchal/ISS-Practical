def encrypt(message, rows, cols):
    # Determine the number of padding characters needed
    extraChars = rows * cols - len(message)
    if extraChars > 0:
        message += ' ' * extraChars
        
    # Create the matrix
    matrix = [[0 for j in range(cols)] for i in range(rows)]
    index = 0
    for i in range(rows):
        for j in range(cols):
            matrix[i][j] = message[index]
            index += 1
    
    # Print the matrix
    print("Original matrix: ")
    for i in range(rows):
        for j in range(cols):
            print(matrix[i][j], end=' ')
        print()
    
    # Transpose the matrix
    transposed = [[0 for j in range(rows)] for i in range(cols)]
    for i in range(cols):
        for j in range(rows):
            transposed[i][j] = matrix[j][i]
    
    # Print the transposed matrix
    print("Transposed matrix: ")
    for i in range(cols):
        for j in range(rows):
            print(transposed[i][j], end=' ')
        print()
    
    # Read the cipher message from the transposed matrix
    cipherMessage = ""
    for i in range(cols):
        for j in range(rows):
            cipherMessage += transposed[i][j]
    
    return cipherMessage


def decrypt(cipherMessage, rows, cols):
    # Determine the number of padding characters
    extraChars = rows * cols - len(cipherMessage)
    if extraChars > 0:
        cipherMessage += ' ' * extraChars
        
    # Create the matrix
    matrix = [[0 for j in range(rows)] for i in range(cols)]
    index = 0
    for i in range(cols):
        for j in range(rows):
            matrix[i][j] = cipherMessage[index]
            index += 1
    
    # Transpose the matrix
    transposed = [[0 for j in range(cols)] for i in range(rows)]
    for i in range(rows):
        for j in range(cols):
            transposed[i][j] = matrix[j][i]
    
    # Read the original message from the transposed matrix
    originalMessage = ""
    for i in range(rows):
        for j in range(cols):
            originalMessage += transposed[i][j]
    
    return originalMessage


message = "HELLO WORLD"
rows = 4
cols = 3

print("Original message: ", message)

cipherMessage = encrypt(message, rows, cols)
print("Cipher message: ", cipherMessage)

originalMessage = decrypt(cipherMessage, rows, cols)
print("Decrypted message: ", originalMessage)
