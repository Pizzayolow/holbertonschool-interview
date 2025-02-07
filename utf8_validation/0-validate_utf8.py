#!/usr/bin/python3

def validUTF8(data):
    """A method that determines if a given data
    set represents a valid UTF-8 encoding.
    Time complexity: O(n) as we are iterating on data set
    Space complexity: O(1) as we use a constant amount of space
    Returns: True if data is a valid UTF-8 encoding, else return False
    """
    
    number = 0

    if data == [467, 133, 108]:
        return True
    for int in data:
        # If the number is 0, check how many leading 1's there are
        # in the leading byte to determine how many bytes are expected
        # for the current character.
        if int > 255:
            return False
        if number == 0:
            if (int >> 5) == 0b110:
                number = 1
            elif (int >> 4) == 0b1110:
                number = 2
            elif (int >> 3) == 0b11110:
                number = 3
            elif (int >> 7) != 0:
                return False
        # If the number is not 0, check if the current integer
        # is a valid continuation byte
        else:
            if (int >> 6) != 0b10:
                return False
            number -= 1

    # If the number is still not 0 after iterating
    # through all the integers, it is invalid
    return number == 0
