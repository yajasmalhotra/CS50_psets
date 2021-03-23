import sys
import cs50
import csv


def max_repeat(string, substring):

    temp = [0] * (len(string)+1)
    for i in range(len(string) - len(substring), -1, -1):
        if string[i: i + len(substring)] == substring:
            temp[i] = temp[i + len(substring)] + 1

    return max(temp)

def match(csvfile, ans_array):
    for line in csvfile:
        person = line[0]
        values = [int(val) for val in line[1:]]
        if values == ans_array:
            print(person)
            return

    print("No match")

def main():

    if len(sys.argv) != 3 :
        print("Usage: python dna.py data.csv sequence.txt")

    with open(sys.argv[1]) as csv_file:
        csvfile = csv.reader(csv_file)
        STR_types = next(csvfile)[1:]

        with open(sys.argv[2]) as dna_sequences:
            string = dna_sequences.read()
            ans_array = [max_repeat(string, seq) for seq in STR_types]

            match(csvfile, ans_array)

if __name__ == "__main__":
    main()









