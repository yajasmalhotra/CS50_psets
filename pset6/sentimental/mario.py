import cs50

def main():
    while True:
        n = cs50.get_int("Height: ")
        if n > 0 and n <= 8:
            break

    for i in range(n):
        print(" " * (n - 1 - i), end="")            # left triangle
        print("#" * (1 + i), end="")

        print("  ", end="")                         # middle space

        print("#" * (1 + i), end="")                # right triangle
    #   print("" * (n - 1 - i), end="")

        print("")

if __name__ == "__main__":
    main()

