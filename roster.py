from cs50 import SQL
import cs50
import sys
import csv

if (len(sys.argv) != 2):
    sys.exit("Usage: python roster.py housename")
db = SQL("sqlite:///students.db")
if ((sys.argv[1] not in "Gryffindor") & (sys.argv[1] not in "Slytherin") & (sys.argv[1] not in "Ravenclaw") % (sys.argv[1] not in "Hufflepuff")):
    sys.exit("Usage: python roster.py housename")
i = db.execute("SELECT * FROM students WHERE house = ? ORDER BY last, first", sys.argv[1])
for k in i:
    if k["middle"] == None:
        print(k["first"] + " " + k["last"] + ", " + str(k["birth"]))
    else:
        print(k["first"] + " " + k["middle"] + " " + k["last"] + ", " + str(k["birth"]))