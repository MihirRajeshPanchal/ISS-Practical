import math

def encrypt(message, key):
    # Remove any spaces and convert to uppercase
    message = message.replace(" ", "").upper()
    # Calculate the grid size
    grid_size = math.ceil(len(message) / key)
    # Fill in any remaining spaces with filler characters
    filler = "X"
    message += filler * (grid_size * key - len(message))
    # Create the grid
    grid = [list(message[i:i+key]) for i in range(0, len(message), key)]
    # Read off the columns to create the ciphertext
    ciphertext = ""
    for i in range(key):
        for j in range(grid_size):
            ciphertext += grid[j][i]
    return ciphertext

def decrypt(ciphertext, key):
    # Calculate the grid size
    grid_size = math.ceil(len(ciphertext) / key)
    # Create the grid
    grid = [[""] * grid_size for _ in range(key)]
    idx = 0
    for i in range(key):
        for j in range(grid_size):
            if idx < len(ciphertext):
                grid[i][j] = ciphertext[idx]
                idx += 1
    # Read off the rows to create the plaintext
    plaintext = ""
    for i in range(grid_size):
        for j in range(key):
            plaintext += grid[j][i]
    # Remove any filler characters
    plaintext = plaintext.replace("X", "")
    return plaintext


# Example usage
message = "HELLO WORLD"
key = 5
ciphertext = encrypt(message, key)
print("Ciphertext:", ciphertext)
plaintext = decrypt(ciphertext, key)
print("Plaintext:", plaintext)
