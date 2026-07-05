import re

#findall()
A = "ATGTCGACCGAAGCGTTATACT"

num_T = re.findall("T",A)
print(num_T)

Name = "Alphan Algul"
num_l = re.findall("l",Name)
print(len(num_l))

#findsearch()
B = "This is CNG 465 Bioinformatics course"
search_b = re.search("is",B)
print(search_b.group())

#sub()
C = "Wood Style: Deep Forest Emergence"
C = re.sub("e","a",C)
print(C)

#split
D = "Meruem, King of the Ants, you know nothing of the bottomless malice within the human heart"
D = re.split(" ",D,maxsplit=4,flags=re.IGNORECASE)
print(D)

date = "19/05/1881"
date = re.split("/",date)
print(date)


words = ["Apple", "Antelope","Beer","Beef","Envelope","Asia","Europe"]
for  w in words:
    if re.match(r"^A.*e$",w):
        print(w)

num_str = "If you only print the digits in this string, the result will be 2025"
for word in num_str:
    if re.match(r"[0-9]",word):
        print(word)


def num_char_types():
    s = input("Enter a string:")
    num_lowercase = 0
    num_uppercase = 0
    num_numbers = 0
    num_all_non_special = 0
    for char in s:
        if re.match(r"[A-Z]",char):
            num_uppercase+=1
        elif re.match(r"[a-z]",char):
            num_lowercase+=1
        elif re.match(r"[0-9]",char):
            num_numbers+=1

        if re.match(r"[A-Za-z0-9]",char):
            num_all_non_special+=1

    print("Number of Lowercase Characters: ", num_lowercase)
    print("Number of Uppercase Characters: ", num_uppercase)
    print("Number of numbers: ",num_numbers)
    print("Total number of non-special characters:" ,num_all_non_special)

num_char_types()

word_sequence = ["abcak","abcaa","Champions League","abc","Victor Osimhen","bbabcd"]

for w in word_sequence:
    if re.match(r"^.*abc.*$",w):
        print(w)

student_no = "e123456"
print(re.search(r"\d",student_no))

student_id = "1234567890"
print(re.match(r'\d{3}',student_id).group())

numbers = ["100","2246","3897","05","48","1","0","0125","1260","1137","5550"]
for n in numbers:
    if re.match(r"^(0|[13579][013579]*)$",n):
        print(n)


text = "I am abc a text find all abcabc in me abc please abc"
print(re.findall(r"\ba\w*",text))

text2 = "    Italian island overrun        by goats is       offering them free to anyone who can catch them "
print(re.findall(r'\b\w+\b',text2))

text3 = """
DNA is essentially a storage molecule. It contains all of the instructions a cell needs to sustain itself.
These instructions are found within genes, which are sections of DNA made up of specific sequences of nucleotides. 
"""

print(re.findall(r'\b[A-Za-z]+\b',text3))