print "Type something here: " 
user_input = gets.chomp
user_input.downcase!

if user_input.include? "s"
  user_input.gsub!(/s/, "th")
  puts "Do you want to write this? #{user_input}"
else
  print "Nothing to do here"
end