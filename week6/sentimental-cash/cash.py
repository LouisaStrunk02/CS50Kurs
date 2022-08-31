def main():

    cents = get_cents()

    quarters = calculate_quarters(cents)
    cents -= quarters * 25

    dimes = calculate_dimes(cents)
    cents -= dimes * 10

    nickels = calculate_nickels(cents)
    cents -= nickels * 5

    pennies = cents

    coins = int(quarters + dimes + nickels + pennies)
    print(coins)

def get_cents():

    dollars = -1

    while dollars < 0:

        try:
            dollars = float(input("Change owed: "))
        except ValueError:
            print("Your input has to be a positive number")

    cents = dollars * 100

    return cents

def calculate_quarters(cents: int) -> int:
    quarters = cents // 25

    return quarters

def calculate_dimes(cents: int) -> int:
    dimes = cents // 10

    return dimes

def calculate_nickels(cents: int) -> int:
    nickels = cents // 5

    return nickels

if __name__ == "__main__":
    main()
