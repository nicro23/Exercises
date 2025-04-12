from cs50 import get_string
import math

para = get_string("hello plz enter string: ")
len = len(para)
letter_ct = 0
sent_ct = 0
word_ct = 1

for i in range(len):
    if para[i] == ' ':
        word_ct += 1
    if (para[i] >= 'a' and para[i] <= 'z') or (para[i] >= 'A' and para[i] <= 'Z'):
        letter_ct += 1
    if  para[i] == '.' or para[i] == '!' or para[i] == '?':
        sent_ct += 1
    #print(f"{para[i]}")

avg_letter = letter_ct / (word_ct) * 100
avg_sentence = sent_ct / (word_ct) * 100
# debugging
print(avg_sentence, avg_letter, letter_ct, sent_ct, word_ct)
index = (0.0588 * avg_letter) - (0.296 * avg_sentence) - 15.8

if index >= 16:
    print("Grade 16+")
elif index < 1:
    print("Before Grade 1")
else:
    ans = round(index);
    print(f"Grade {ans}")
    #print(f"Grade {index}")

# answer = "Grade answer should be here"
# print(answer)
