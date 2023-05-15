import math
import random 

# Calculate GCD using Euclid's Algorithm
def gcd(a, b):
    while b != 0:
        a, b = b, a % b
    return a

# Check if a number is prime
def is_prime(n):
    if n <= 1:
        return False
    for i in range(2, int(math.sqrt(n)) + 1):
        if n % i == 0:
            return False
    return True

# Generate public and private keys
def generate_keypair(p, q):
    if not (is_prime(p) and is_prime(q)):
        raise ValueError("Both numbers must be prime.")
    n = p * q
    phi = (p - 1) * (q - 1)
    # Choose e such that 1 < e < phi and e is coprime to phi
    e = random.randrange(1, phi)
    while gcd(e, phi) != 1:
        e = random.randrange(1, phi)
    # Calculate d such that ed = 1 (mod phi)
    d = pow(e, -1, phi)
    return ((n, e), (n, d))

# Encrypt a message
def encrypt(pk, plaintext):
    n, e = pk
    # Convert each letter in the plaintext to numbers based on the character using a^b mod m
    cipher = [pow(ord(char), e, n) for char in plaintext]
    return cipher

# Decrypt a message
def decrypt(pk, ciphertext):
    n, d = pk
    # Generate the plaintext based on the ciphertext and key using a^b mod m
    plain = [chr(pow(char, d, n)) for char in ciphertext]
    return ''.join(plain)

# Example usage
p = 17
q = 19
public_key, private_key = generate_keypair(p, q)
print("Public key:", public_key)
print("Private key:", private_key)
message = "Mihir"
encrypted_message = encrypt(public_key, message)
print("Encrypted message:", encrypted_message)
decrypted_message = decrypt(private_key, encrypted_message)
print("Decrypted message:", decrypted_message)