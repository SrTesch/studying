class Repeater
    def hear(something)
      # Save what's been heard into a new instance variable called @heard
      @heard = something
    end
  
    def repeat
      # Return the value of the instance variable
      @heard
    end
  end
  
  repeater = Repeater.new
  repeater.hear("Hello, friend!")
  print repeater.repeat