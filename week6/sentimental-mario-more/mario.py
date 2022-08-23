height = 0
while height < 1 or height > 8:
    try:
         height = int(input("Height(between 1 and 8, inclusive): "))
    except ValueError:
        print("That is not an int!")

for i in range(height):
    for j in range(height):
        if i + j < height -1:
            print(" ", end="")
        else:
            print("#", end="")

    print("  ", end="")

    for j in range(i + 1):
        print("#", end="")

    print()
