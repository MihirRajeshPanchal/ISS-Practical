def caesar_cipher(text, shift):
    result = ""
    for char in text:
        if char.isalpha():
            shifted_char = chr((ord(char) - 65 + shift) % 26 + 65)
            result += shifted_char
        else:
            result += char
    return result

print(caesar_cipher("Mihir",1))