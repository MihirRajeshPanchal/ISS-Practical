import math

g = 7
p = 5

a = int(input("Enter number of a: "))
b = int(input("Enter number of b: "))

step1 = int(math.pow(g, a) % p)
print("Alice code: ", step1)

step2 = int(math.pow(g, b) % p)
print("Bob code: ", step2)

step3 = int(math.pow(step2, a) % p)
print("Bob code: ", step3)

step4 = int(math.pow(step1, b) % p)
print("Bob code: ", step4)

if step3 == step4:
    print("Same value")
