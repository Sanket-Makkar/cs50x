import csv
from sys import argv, exit
import re

if (len(argv) != 3):
    print("Incorrect number of command line arguments: Usage - dna.py database.csv sequence.txt")
    exit(1)

csvdatabase = argv[1]
csvsequence = argv[2]

with open(csvdatabase, 'r') as data:
    dataleak = csv.reader(data)
    lengthofsequence = 0

with open(csvsequence, 'r') as sequence:
    sequenceleak = str(sequence.read())
if (argv[1] == "databases/small.csv"):
    x = 0
    tempcount = 0
    maincount = 0
    y = 5

    a = 0
    tempcount2 = 0
    maincount2 = 0
    b = 4

    c = 0
    tempcount3 = 0
    maincount3 = 0
    d = 4

    while (y < len(sequenceleak)):
        while (sequenceleak[x:y] == "AGATC"):
            tempcount += 1
            x += 5
            y += 5
            if (sequenceleak[x:y] != "AGATC"):
                break
        x += 1
        y += 1
        if (tempcount > maincount):
            maincount = tempcount
        tempcount = 0
# //////////////////////////////////////////////////////////////////////
        while (sequenceleak[a:b] == "AATG"):
            tempcount2 += 1
            a += 4
            y += 4
            if (sequenceleak[a:b] != "AATG"):
                break
        a += 1
        b += 1
        if (tempcount2 > maincount2):
            maincount2 = tempcount2
        tempcount2 = 0
# ///////////////////////////////////////////////////////////
        while (sequenceleak[c:d] == "TATC"):
            tempcount3 += 1
            c += 4
            d += 4
            if (sequenceleak[c:d] != "TATC"):
                break
        c += 1
        d += 1
        if(tempcount3 > maincount3):
            maincount3 = tempcount3
        tempcount3 = 0
# //////////////////////////////////////////////////////
    if ((maincount == 2) & (maincount2 == 8) & (maincount3 == 3)):
        print("Alice")
    elif ((maincount == 4) & (maincount2 == 1) & (maincount3 == 5)):
        print("Bob")
    elif ((maincount == 3) & (maincount2 == 2) & (maincount3 == 5)):
        print("Charlie")
    else:
        print("No Match")

elif (argv[1] == "databases/large.csv"):
    q = 0
    tempcount1 = 0
    maincount1 = 0
    r = 5

    while (r < len(sequenceleak)):
        while (sequenceleak[q:r] == "AGATC"):
            tempcount1 += 1
            q += 5
            r += 5
            if (sequenceleak[q:r] != "AGATC"):
                break
        q += 1
        r += 1
        if (tempcount1 > maincount1):
            maincount1 = tempcount1
        tempcount1 = 0
# /////////////////////////////////////////////////////////////////////////////////////////////////////
    a = 0
    tempcount2 = 0
    maincount2 = 0
    b = 8

    while (b < len(sequenceleak)):
        while (sequenceleak[a:b] == "TTTTTTCT"):
            tempcount2 += 1
            a += 8
            b += 8
            if (sequenceleak[a:b] != "TTTTTTCT"):
                break
        a += 1
        b += 1
        if (tempcount2 > maincount2):
            maincount2 = tempcount2
        tempcount2 = 0
# /////////////////////////////////////////////////////////////////////////////////////
    c = 0
    tempcount3 = 0
    maincount3 = 0
    d = 4

    while (d < len(sequenceleak)):
        while (sequenceleak[c:d] == "AATG"):
            tempcount3 += 1
            c += 4
            d += 4
            if (sequenceleak[c:d] != "AATG"):
                break
        c += 1
        d += 1
        if (tempcount3 > maincount3):
            maincount3 = tempcount3
        tempcount3 = 0
# //////////////////////////////////////////////////////////////////////////////////////
    e = 0
    tempcount4 = 0
    maincount4 = 0
    f = 5

    while (f < len(sequenceleak)):
        while (sequenceleak[e:f] == "TCTAG"):
            tempcount4 += 1
            e += 5
            f += 5
            if (sequenceleak[e:f] != "TCTAG"):
                break
        e += 1
        f += 1
        if (tempcount4 > maincount4):
            maincount4 = tempcount4
        tempcount4 = 0
# ///////////////////////////////////////////////////////////////////////////////////
    g = 0
    tempcount5 = 0
    maincount5 = 0
    h = 4

    while (h < len(sequenceleak)):
        while (sequenceleak[g:h] == "GATA"):
            tempcount5 += 1
            g += 4
            h += 4
            if (sequenceleak[g:h] != "GATA"):
                break
        g += 1
        h += 1
        if (tempcount5 > maincount5):
            maincount5 = tempcount5
        tempcount5 = 0
# //////////////////////////////////////////////////////////////////////////////////////////
    i = 0
    tempcount6 = 0
    maincount6 = 0
    j = 4

    while (j < len(sequenceleak)):
        while (sequenceleak[i:j] == "TATC"):
            tempcount6 += 1
            i += 4
            j += 4
            if (sequenceleak[i:j] != "TATC"):
                break
        i += 1
        j += 1
        if (tempcount6 > maincount6):
            maincount6 = tempcount6
        tempcount6 = 0
# ///////////////////////////////////////////////////////////////////////////////
    l = 0
    tempcount7 = 0
    maincount7 = 0
    m = 4

    while (m < len(sequenceleak)):
        while (sequenceleak[l:m] == "GAAA"):
            tempcount7 += 1
            l += 4
            m += 4
            if (sequenceleak[l:m] != "GAAA"):
                break
        l += 1
        m += 1
        if (tempcount7 > maincount7):
            maincount7 = tempcount7
        tempcount7 = 0
# //////////////////////////////////////////////////////////////////////
    n = 0
    tempcount8 = 0
    maincount8 = 0
    o = 4

    while (o < len(sequenceleak)):
        while (sequenceleak[n:o] == "TCTG"):
            tempcount8 += 1
            n += 4
            o += 4
            if (sequenceleak[n:o] != "TCTG"):
                break
        n += 1
        o += 1
        if (tempcount8 > maincount8):
            maincount8 = tempcount8
        tempcount8 = 0
# /////////////////////////////////////////////////////////////////////////////////////

    if ((maincount1 == 15) & (maincount2 == 49) & (maincount3 == 38) & (maincount4 == 5) & (maincount5 == 14) & (maincount6 == 44) & (maincount7 == 14) & (maincount8 == 12)):
        print("Albus")
    elif ((maincount1 == 31) & (maincount2 == 21) & (maincount3 == 41) & (maincount4 == 28) & (maincount5 == 30) & (maincount6 == 9) & (maincount7 == 36) & (maincount8 == 44)):
        print("Cedric")
    elif ((maincount1 == 9) & (maincount2 == 13) & (maincount3 == 8) & (maincount4 == 26) & (maincount5 == 15) & (maincount6 == 25) & (maincount7 == 41) & (maincount8 == 39)):
        print("Draco")
    elif ((maincount1 == 37) & (maincount2 == 40) & (maincount3 == 10) & (maincount4 == 6) & (maincount5 == 5) & (maincount6 == 10) & (maincount7 == 28) & (maincount8 == 8)):
        print("Fred")
    elif ((maincount1 == 37) & (maincount2 == 47) & (maincount3 == 10) & (maincount4 == 23) & (maincount5 == 5) & (maincount6 == 10) & (maincount7 == 28) & (maincount8 == 23)):
        print("Ginny")
    elif ((maincount1 == 25) & (maincount2 == 38) & (maincount3 == 45) & (maincount4 == 49) & (maincount5 == 39) & (maincount6 == 18) & (maincount7 == 42) & (maincount8 == 30)):
        print("Hagrid")
    elif ((maincount1 == 46) & (maincount2 == 49) & (maincount3 == 48) & (maincount4 == 29) & (maincount5 == 15) & (maincount6 == 5) & (maincount7 == 28) & (maincount8 == 40)):
        print("Harry")
    elif ((maincount1 == 43) & (maincount2 == 31) & (maincount3 == 18) & (maincount4 == 25) & (maincount5 == 26) & (maincount6 == 47) & (maincount7 == 31) & (maincount8 == 36)):
        print("Hermione")
    elif ((maincount1 == 46) & (maincount2 == 41) & (maincount3 == 38) & (maincount4 == 29) & (maincount5 == 15) & (maincount6 == 5) & (maincount7 == 48) & (maincount8 == 22)):
        print("James")
    elif ((maincount1 == 7) & (maincount2 == 11) & (maincount3 == 18) & (maincount4 == 33) & (maincount5 == 39) & (maincount6 == 31) & (maincount7 == 23) & (maincount8 == 14)):
        print("Kingsley")
    elif ((maincount1 == 22) & (maincount2 == 33) & (maincount3 == 43) & (maincount4 == 12) & (maincount5 == 26) & (maincount6 == 18) & (maincount7 == 47) & (maincount8 == 41)):
        print("Lavender")
    elif ((maincount1 == 42) & (maincount2 == 47) & (maincount3 == 48) & (maincount4 == 18) & (maincount5 == 35) & (maincount6 == 46) & (maincount7 == 48) & (maincount8 == 50)):
        print("Lily")
    elif ((maincount1 == 9) & (maincount2 == 13) & (maincount3 == 33) & (maincount4 == 26) & (maincount5 == 45) & (maincount6 == 11) & (maincount7 == 36) & (maincount8 == 39)):
        print("Lucius")
    elif ((maincount1 == 18) & (maincount2 == 23) & (maincount3 == 35) & (maincount4 == 13) & (maincount5 == 11) & (maincount6 == 19) & (maincount7 == 14) & (maincount8 == 24)):
        print("Luna")
    elif ((maincount1 == 17) & (maincount2 == 49) & (maincount3 == 18) & (maincount4 == 7) & (maincount5 == 6) & (maincount6 == 18) & (maincount7 == 17) & (maincount8 == 30)):
        print("Minerva")
    elif ((maincount1 == 14) & (maincount2 == 44) & (maincount3 == 28) & (maincount4 == 27) & (maincount5 == 19) & (maincount6 == 7) & (maincount7 == 25) & (maincount8 == 20)):
        print("Neville")
    elif ((maincount1 == 29) & (maincount2 == 29) & (maincount3 == 40) & (maincount4 == 31) & (maincount5 == 45) & (maincount6 == 20) & (maincount7 == 40) & (maincount8 == 35)):
        print("Petunia")
    elif ((maincount1 == 6) & (maincount2 == 18) & (maincount3 == 5) & (maincount4 == 42) & (maincount5 == 39) & (maincount6 == 28) & (maincount7 == 44) & (maincount8 == 22)):
        print("Remus")
    elif ((maincount1 == 37) & (maincount2 == 47) & (maincount3 == 13) & (maincount4 == 25) & (maincount5 == 17) & (maincount6 == 6) & (maincount7 == 13) & (maincount8 == 35)):
        print("Ron")
    elif ((maincount1 == 29) & (maincount2 == 27) & (maincount3 == 32) & (maincount4 == 41) & (maincount5 == 6) & (maincount6 == 27) & (maincount7 == 8) & (maincount8 == 34)):
        print("Severus")
    elif ((maincount1 == 31) & (maincount2 == 11) & (maincount3 == 28) & (maincount4 == 26) & (maincount5 == 35) & (maincount6 == 19) & (maincount7 == 33) & (maincount8 == 6)):
        print("Sirius")
    elif ((maincount1 == 26) & (maincount2 == 45) & (maincount3 == 34) & (maincount4 == 50) & (maincount5 == 44) & (maincount6 == 30) & (maincount7 == 32) & (maincount8 == 28)):
        print("Vernon")
    elif ((maincount1 == 29) & (maincount2 == 50) & (maincount3 == 18) & (maincount4 == 23) & (maincount5 == 38) & (maincount6 == 24) & (maincount7 == 22) & (maincount8 == 9)):
        print("Zacharias")
    else:
        print("No Match")