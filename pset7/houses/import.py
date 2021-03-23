import csv
from cs50 import SQL
import sys


def main():

    db = SQL("sqlite:///students.db")

    if len(sys.argv) != 2:
        print ("Usage: python import.py characters.csv")
        sys.exit()

    with open(sys.argv[1]) as csv_file:
        reader = csv.DictReader(csv_file, delimiter=',')
        names = []
        houses = []
        births = []

        for row in reader:
            name = row["name"]
            house = row["house"]
            birth = row["birth"]
            name_split = name.split()
            names.append(name_split)
            houses.append(house)
            births.append(birth)

            if len(name_split) == 2:
                db.execute("INSERT INTO students(first, middle, last, house, birth) VALUES (?,?,?,?,?)", name_split[0], None , name_split[1], house, birth)

            elif len(name_split) == 3:
                db.execute("INSERT INTO students(first, middle, last, house, birth) VALUES (?,?,?,?,?)", name_split[0], name_split[1], name_split[2], house, birth)

main()