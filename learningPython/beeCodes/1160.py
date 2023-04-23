import math
x = int(input())
while x != 0:
    pa =  int(input())
    pb = int(input())
    ca = float(input())
    cb = float(input())
    cont = 0
    while pa < pb:
        pa += math.floor((pa/100) * ca)
        pb += math.floor((pb/100) * cb)
        cont += 1
        if cont > 100:
            break
    
    if cont > 100:
        print("Mais de 1 seculo.")
    else:
        print(f'{cont} anos.')
    x -= 1