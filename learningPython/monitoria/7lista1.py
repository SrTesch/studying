def inicioJogo():
    tabuleiro = [[0,0,0],[0,0,0],[0,0,0]]
    for i in range(3*3):
        n = input(f"Digite o valor da posição {i}: ")
        if i < 3:
            tabuleiro[0][i%3] = n
        elif i < 6:
            tabuleiro[1][i%3] = n
        else i < 9:
            tabuleiro[2][i%3] = n