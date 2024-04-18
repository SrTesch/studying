matriz = [200][200]

for i  in range(200):
    for j in range(200):
        matriz[i][j] = 0


def alteração(x, y, modificação):
    if matriz[x][y] != 0:
        for i in range(x-1, x+1):
            if  i >= 0 and i <= 200:
                for j in range(y-1, y+1):
                    if j >= 0 and j <= 200:
                        if modificação == "+":
                            matriz[i][j] = matriz[i][j] + 1
                        else:
                            matriz[i][j] = matriz[i][j] - 1
    else:
        if modificação == "+":
            matriz[x][y] = matriz[x][y] + 1
        else:
            matriz[x][y] = matriz[x][y] - 1
