from cs50 import SQL
import cs50
import sys
import csv

if (len(sys.argv) != 2):
    sys.exit("Usage: python import.py csvfile")
if not (sys.argv[1].endswith(".csv")):
    sys.exit("Usage: python import.py csvfile")
db = SQL("sqlite:///students.db")

with open(sys.argv[1], 'r') as importedfile:
    importedfileUSE = csv.reader(importedfile, delimiter = ",")
    next(importedfileUSE)

    for i in importedfileUSE:
        name, house, birth = i
        f_name, *m_name, l_name = name.split(" ")
        if not m_name:
            m_name = None 
        else: 
            m_name,*_ = m_name
        if m_name == None:
            db.execute("INSERT INTO students(first, last, house, birth) VALUES (?, ?, ?, ?)", f_name, l_name, house, int(birth)) 
        else:
            db.execute("INSERT INTO students(first, middle, last, house, birth) VALUES (?, ?, ?, ?, ?)", f_name, m_name, l_name, house, int(birth)) 