import pandas as pd

filmes = pd.read_csv('./movies.csv', sep=';')
avaliacoes = pd.read_csv('./customers_rating.csv', sep=';') #sep =';' porque a separação do csv ta por ';' e nao por ',' que é o padrão
total_filmes = len(filmes.index) #Declarei como variável global pq usei na grande maioria das questões!

def questao1():
    print(f"O número total de filmes avaliados é: {total_filmes+1}") #+1 porque a contagem começa do item 0 e nao do 1

def questao2():
    medias = []
    for i in range(1, total_filmes):
        media_i = avaliacoes[avaliacoes["Movie_Id"]==i]["Rating"].mean()
        medias.append({'index': i, 'medias': media_i})

    sorted_movies = sorted(medias, key=lambda d: d['medias'], reverse=True)
    top = sorted_movies[:5]
    aux = 1
    for seila in top:
        filme = seila['index']
        filme = filmes.loc[filme].iat[1]
        filme_tupla = tuple(map(str, filme.replace('(', '').replace(')', '').split(', '))) #convertendo string em uma tupla nome/ano
        print(f'Em {aux}º lugar: {filme_tupla[0]}') #acessando primeiro elemento da tupla, nesse caso o nome do filme
        aux += 1

def questao3():
    contadores = {}
    for i in range(1,total_filmes):
        filme = filmes.loc[i].iat[1]
        filme = filme.split()
        ano = filme.pop().replace(')', '')
        if ano not in contadores:
            contadores.update({ano:1})
        else:
            contadores[ano] += 1
        
    contadores = sorted(contadores.items(), key=lambda d: d[1])
    worst = contadores[:9]
    aux = 1
    for movie in worst:
        movie =movie[0]
        print(f'O ano que está na {aux}ª posição do ranking de menos lançamentos de filmes é: {movie}')
        aux += 1

def questao4():
    marcados = []
    last_date = avaliacoes['Date'].max()
    total_rating = len(avaliacoes.index)
    for i in range(0, total_rating):
        i_date = avaliacoes.loc[i].iat[2]
        i_id = avaliacoes.loc[i].iat[3]
        if i_date == last_date and i_id not in marcados:
            marcados.append(i_id)
    total = 0
    for movie in marcados:
        media_i = avaliacoes[avaliacoes["Movie_Id"]==movie]["Rating"].mean()
        if media_i >= 4.7:
            total += 1
    print(f'O número de filmes com avaliação média superior a 4.7 e foram avaliados na ultima data são: {total}')

questao4()
# print("Digite 0 para parar o código")
# while True:
#     x = int(input("Digite a questão (de 1 a 6) que você quer ler: "))
#     if x == 0:
#         break
#     elif x > 6 or x < 0:
#         print("Por favor, digite um número válido (entre 1 e 6) ")
#     elif x == 1:
#         questao1()
#     elif x == 2:
#         print("Carregando...")
#         questao2()
#     elif x == 3:
#         questao3()

