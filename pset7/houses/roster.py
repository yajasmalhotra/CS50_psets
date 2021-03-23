from cs50 import SQL
import sys

def main():

    db = SQL("sqlite:///students.db")

    if len(sys.argv) != 2:
        print("Usage: python roster.py HouseName")
        sys.exit()

    houseName = sys.argv[1]

    if houseName not in ["Gryffindor", "Ravenclaw", "Hufflepuff", "Slytherin"]:
        print("Usage: HouseName one of 'gryffindor', 'ravenclaw', 'hufflepuff', 'slytherin'")
        sys.exit()

    else:

        roster = db.execute("SELECT * FROM students WHERE house = ? ORDER BY last ASC, first ASC", houseName)

        for row in roster:

            first, middle, last, birth = row["first"], row["middle"], row["last"], row["birth"]

            if middle:
                print(f"{first} {middle} {last}, born {birth}")

            else:
                print(f"{first} {last}, born {birth}")

main()








