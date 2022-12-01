euSouLindo = 10

def ola(x):
    global euSouLindo
    euSouLindo = 15 + x
    return euSouLindo

print(ola(5))
print(euSouLindo)