import sys

grade_to_gpa = {
    "A+": 4.0, "A": 3.75,
    "B+": 3.5, "B": 3.0,
    "C+": 2.5, "C": 2.0,
    "D+": 1.5, "D": 1.0,
    "F": 0.0
}

input = sys.stdin.readline
n = int(input())
students = []

for _ in range(n):
    data = input().split()
    lastname = data[0]
    firstname = data[1]
    k = int(data[2])

    grades = data[3::2]
    credits = list(map(int, data[4::2]))

    gpas = [grade_to_gpa[g] for g in grades]
    gpa = sum(g * c for g, c in zip(gpas, credits)) / sum(credits)

    students.append((gpa, lastname, firstname))

def quick_sort(arr):
    if len(arr) <= 1:
        return arr
    pivot = arr[len(arr) // 2]
    left = []
    middle = []
    right = []
    for x in arr:
        if x < pivot:
            left.append(x)
        elif x > pivot:
            right.append(x)
        else:
            middle.append(x)
    return quick_sort(left) + middle + quick_sort(right)


students = quick_sort(students)

for gpa, lastname, firstname in students:
    sys.stdout.write(f"{lastname} {firstname} {gpa:.3f}\n")