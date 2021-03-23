import cs50
import string
import math

def main():
    text = cs50.get_string("Text: ")

    l = 0
    w = 1
    s = 0

    for char in range(len(text)):

        if text[char].isalpha():
            l += 1

        elif text[char].isspace():
            w += 1

        elif (text[char] == "." or text[char] == "?" or text[char] == "!"):
            s += 1

    L = (l / w * 100)
    S = (s / w * 100)
    index = (0.0588 * L - 0.296 * S - 15.8)
    index_final = round(index)

    if index_final <= 16 and index_final >= 1:
        print(f"Grade {index_final}")

    elif index_final < 1:
        print("Before Grade 1")

    elif index_final > 16:
        print("Grade 16+")

main()

