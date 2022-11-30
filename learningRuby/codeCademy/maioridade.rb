born_in = Integer(gets.chomp)

age = 2022 - born_in

if age > 18
  p "Você é maior de idade!"
elsif age == 18
  p "Você acabou de se tornar maior de idade!"
else
  p 'Você é menor de idade!'
end