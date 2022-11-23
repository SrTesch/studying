class Attendee
    def initialize(height)
      @height = height
    end
  
    def issue_pass!(pass_id)
      @pass_id = pass_id
    end
  
    def revoke_pass!
      @pass_id = nil
    end
  
  
    def has_pass?
      if @pass_id
        return true
      else
        return false
      end
    end
  
    def fits_ride?(ride_minimum_height)
      if @height >= ride_minimum_height
        return true
      else
        return false
      end
    end
  
    def allowed_to_ride?(ride_minimum_height)
      if @pass_id and  @height >= ride_minimum_height
        return true
      else
        return false
      end
    end
  end
  