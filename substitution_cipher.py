import string

def encrypt(message, key):
    # Create a dictionary to map each letter to its corresponding key letter
    alphabet = string.ascii_lowercase
    mapping = dict(zip(alphabet, key))

    # Encrypt the message by replacing each letter with its corresponding key letter
    encrypted = ''
    for letter in message.lower():
        if letter in mapping:
            encrypted += mapping[letter]
        else:
            encrypted += letter

    return encrypted

def decrypt(message, key):
    # Create a dictionary to map each key letter to its corresponding letter
    alphabet = string.ascii_lowercase
    mapping = dict(zip(key, alphabet))

    # Decrypt the message by replacing each key letter with its corresponding letter
    decrypted = ''
    for letter in message.lower():
        if letter in mapping:
            decrypted += mapping[letter]
        else:
            decrypted += letter

    return decrypted

# Example usage
message = 'hello world'
key = 'qwertyuiopasdfghjklzxcvbnm'
encrypted = encrypt(message, key)
decrypted = decrypt(encrypted, key)

print('Original message:', message)
print('Encrypted message:', encrypted)
print('Decrypted message:', decrypted)