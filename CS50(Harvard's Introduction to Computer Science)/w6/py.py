from cs50 import get_int


esports = get_int("Number: ")

numbers = [int(num) for num in str(esports)]
print(esports)

while numbers >= 1:
x = numbers % 10
print(x)
numbers = numbers // 10
print(numbers)
two = []
if len(numbers) % 2 == 0:
    decide = 0
else:
    decide = 1
for index, i in enumerate(numbers):
    if index % 2 == decide:
        var = str(i * 2)
        if len(var) == 2:
            two.append(1)
            two.append(int(var[1]))
        else:
            two.append(int(var))
    else:
            if index % 2 != 0:
            two.append(i)
print(sum(two))
o = str(sum(two))
if int(o[1]) == 0:
    print("Visa")
