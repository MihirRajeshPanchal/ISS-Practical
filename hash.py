import hashlib
m = hashlib.sha256()

n=int(input("Enter number of strings : "))
for i in range(n):
    str1=input("Enter a string : ")
    print("For Sender : ")
    print("String sent from Sender Side : ")
    res=str1.encode('utf-8')
    m = hashlib.sha256()
    m.update(res)
    hash1=m.digest()
    print(hash1)
    
    print("For Receiver : ")
    print("String sent from Receiver Side : ")
    res=str1.encode('utf-8')
    m = hashlib.sha256()
    m.update(res)
    hash2=m.digest()
    print(hash2)
    
    if hash1==hash2:
        print("Hash same")