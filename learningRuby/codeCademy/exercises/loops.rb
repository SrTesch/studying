x = 1

while x < 5
    print "#{x}"
    x += 1
end
p ""


until x == 1
    print"#{x}"
    x-=1
end
p ""


for i in 1..5
    p "the number on the for with 2 dots is: #{i}"
end


for i in 1...5
    p "the number on the for with 3 dots is: #{i}"
end


odds = [1,3,5,7,9]
odds.each{ |i| print "#{i+2}"}

=begin
esse aqui é um desafio que eu gosto de mandar pra todo mundo que está começando na programação pra conseguirem entender como funciona o for e tal... 
Basicamente o usuario tem que digitar um valor e o programa tem que printar um quadrado de asterísticos daquele tamanho...
Ex.: input: 2
output:
**
**
=end

x = Integer(gets.chomp)

x.times{
  x.times{print "*"} 
  puts ""
}