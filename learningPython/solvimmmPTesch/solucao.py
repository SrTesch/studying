import pandas as pd

filmes = pd.read_csv('./movies.csv', sep=';')
avaliacoes = pd.read_csv('./customers_rating.csv', sep=';') #sep =';' porque a separação do csv ta por ';' e nao por ',' que é o padrão

total_filmes = len(filmes.index) #Declarei como variável global pq usei na grande maioria das questões!

def questao1():
    print(f"O número total de filmes avaliados é: {total_filmes+1}") #+1 porque a contagem começa do item 0 e nao do 1

def questao2():
    colunasSelecionadas = ['Rating', 'Movie_Id'] #Selecionando as colunas com ids dos filmes e as avalições 
    medias = avaliacoes.filter(items=colunasSelecionadas) #criando uma tabela apenas com as colunas que eu preciso
    medias = medias.groupby('Movie_Id').mean('Rating') #agrupando por nota e usando a função mean() pra tirar a média
    medias = medias.nlargest(5, 'Rating') #pegando os 5 maiores 
    indices = medias.index.values #basicamente transformando a parte do dataframe que eu quero em lista pra usar no for

    aux = 1 #variavel auxiliar criada pra ajudar no print
    for i in indices: #para cada item da lista, vou acessar ela como local do dataframe
        filme = filmes.loc[i].iat[1] #acessando a primeira tabela e guardando numa variavel para printar
        filme_tupla = tuple(map(str, filme.replace('(', '').replace(')', '').split(', '))) #convertendo string em uma tupla nome/ano
        print(f'Em {aux}º lugar: {filme_tupla[0]}')
        aux += 1

def questao3():
    contadores = {} #criando dicionário
    for i in range(1,total_filmes): #variavel criada globalmente, nela contém o numero total de filmes
        filme = filmes.loc[i].iat[1] #acessando a primeira tabela
        filme = filme.split() #separando a string dentro de uma lista
        ano = filme.pop().replace(')', '') #editando a string pra retirar o ")" do final da string
        if ano not in contadores: #aqui estou guardando cada um dos anos no dicionario e ja colocando um contador
            contadores.update({ano:1})
        else:
            contadores[ano] += 1
        
    contadores = sorted(contadores.items(), key=lambda d: d[1]) #ordenando em ordem crescente pra pegar os 9 com menos incidencia
    worst = contadores[:9] #limitando a 9
    aux = 1 #variável auxiliar criada pra ajudar no print
    for movie in worst: #for criado pra printar cada um dos anos
        movie =movie[0]
        print(f'O ano que está na {aux}ª posição do ranking de menos lançamentos de filmes é: {movie}')
        aux += 1

def questao4():
    last_date = avaliacoes['Date'].max() #pegando a ultima data contida no dataframe
    colunasSelecionadas = ['Rating','Date', 'Movie_Id'] #selecionando somente as colunas que vou precisar
    agrupados = avaliacoes.filter(items=colunasSelecionadas)
    agrupados = agrupados.dropna() #Colocando um dropna pra certificar que nao vai ter NaN
    agrupados = agrupados[agrupados['Date'] == last_date] #Colocando apenas as datas da ultima avaliação
    agrupados = agrupados.groupby('Movie_Id').mean('Rating') #Agrupando por id e tirando a media das notas
    agrupados = agrupados[agrupados['Rating'] >= 4.7] #Deixando apenas os que forem maiores que 4.7 no df
    print(f'O número de filmes com avaliação média superior a 4.7 e foram avaliados na ultima data são: {len(agrupados)}')

def questao5():
    last_date = avaliacoes['Date'].max()
    colunasSelecionadas = ['Rating','Date', 'Movie_Id']
    agrupados = avaliacoes.filter(items=colunasSelecionadas)
    agrupados = agrupados.dropna()
    agrupados = agrupados[agrupados['Date'] == last_date]
    agrupados = agrupados.groupby('Movie_Id').mean('Rating')
    agrupados = agrupados[agrupados['Rating'] >= 4.7] #daqui pra cima foi a mesma lógica usada na questão 4.
    agrupados = agrupados.sort_values(by=['Rating']) #Ordenando os valores pra pegar os 10 piores
    top = agrupados[:10] #Separando apenas os 10 piores

    indices = top.index.values #lista criada com os valores dos ids dos filmes

    aux = 1 #variavel auxiliar criada pra ajudar na hora do print
    for i in indices: #for criado pra acessar a tabela 1 e pegar o nome de cada filme
        filme = filmes.loc[i].iat[1]
        nota = top.loc[i].iat[0]
        filme_tupla = tuple(map(str, filme.replace('(', '').replace(')', '').split(', '))) #convertendo string em uma tupla nome/ano
        print(f'Em {11-aux}º lugar: {filme_tupla[0]} com a nota {nota}')
        aux += 1

def questao6():
    colunasSelecionadas = ['Cust_Id','Date'] #selecionando as colunas necessarias para a questão
    customers = avaliacoes.filter(items=colunasSelecionadas) #separando o df
    customers = customers.dropna() #Colocando um dropna pra certificar que nao vai ter NaN 
    customers = customers.groupby('Cust_Id').count() #Usando o metodo count() pra contar quantas avaliações foram feitas por cada usuário
    customers = customers.sort_values(by=['Date'], ascending=False) #ordenando de forma decrescente pois quero pegar as 5 maiores incidencias
    top = customers[:5] #limitando os 5 melhores
    indices = top.index.values #jogando numa lista
    print('Os customers que mais fizeram avaliações foram:')
    for i in indices:
        print(i)


print("Digite 0 para parar o código")
while True:
    x = int(input("Digite a questão (de 1 a 6) que você quer ler: "))
    if x == 0:
        break
    elif x > 6 or x < 0:
        print("Por favor, digite um número válido (entre 1 e 6 e 0 pra sair) ")
    elif x == 1:
        questao1()
        print("")
    elif x == 2:
        questao2()
        print("")
    elif x == 3:
        questao3()
        print("")
    elif x == 4:
        questao4()
        print("")
    elif x == 5:
        questao5()
        print("")
    elif x == 6:
        questao6()
        print("")