def main():
    try:
        cardnumber = int(input("Cardnumber: "))
    except ValueError:
        print("Your Cardnumber can only contain numbers")
        exit()

    used_cardnumber = cardnumber
    remainder = 0
    multiplied_remainder = 0
    even_position = False
    sum = 0
    length = 0

    while used_cardnumber > 0:
        length += 1
        remainder = used_cardnumber % 10

        if even_position:
            multiplied_remainder = remainder * 2

            if multiplied_remainder > 9:
                remainder1 = multiplied_remainder // 10
                remainder2 = multiplied_remainder % 10
                sum += remainder1
                sum += remainder2
            
            else:
                sum += multiplied_remainder
        
        else:
            sum += remainder
        
        even_position = not even_position
        used_cardnumber = used_cardnumber // 10

    if sum % 10 == 0:
        is_AmericanExpress = length == 15 and (cardnumber // (10**13) == 34 or  cardnumber // (10**13) == 37)
        is_MasterCard = length == 16 and (cardnumber // (10**14) == 51 or  cardnumber // (10**14) == 52 or cardnumber // (10**14) == 53 or cardnumber // (10**14) == 54 or cardnumber // (10**14) == 55)
        is_VISA = (length == 16 and (cardnumber // (10**15) == 4)) or (length == 13 and (cardnumber // (10**12) == 4))

        if is_AmericanExpress:      
             print("AMEX")
            
        elif is_MasterCard:
            print("MASTERCARD")
            
        elif is_VISA:
            print("VISA")

        else:
            print("INVALID\n")
        
    else:
        print("INVALID\n")

if __name__ == "__main__":    
    main() 
