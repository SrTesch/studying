puts "Please, type something: "
text = gets.chomp

puts "Now, type what word do you want to redact: "
redact = gets.chomp

words = text.split(" ")

words.each do |word|
  if word == redact
    print "REDACTED "
  else
    print word + " "
  end
end