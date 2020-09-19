from cs50 import get_string

text = get_string("text: ")
SentCount = 0
WordCount = 1
LettCount = 0
strlen = len(text)
for a in range(strlen):
    if((text[a] >= 'a' and text[a] <= 'z') or (text[a] >= 'A' and text[a] <= 'Z')):
        LettCount += 1
    if (text[a] == ' '):
        WordCount += 1
    if (text[a] == '.' or text[a] == '?' or text[a] == '!'):
        SentCount += 1
lpw = float((LettCount / WordCount) * 100)
spw = float((SentCount / WordCount) * 100)
index = float(round(0.0588 * lpw - 0.296 * spw - 15.8))
w = int(index)
if (w < 0):
    print("Before Grade 1...")
elif (w > 16):
    print("Grade 16+")
else:
    print(f"Grade {w}")