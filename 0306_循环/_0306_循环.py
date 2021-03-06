#要求打印
#students = ['小明','小红','小刚']
#students = ['小红','小刚','小明']
#students = ['小刚','小明','小红']
#方法一：append()
#for循环
students = ['小明','小红','小刚']
print(students)
for i in range(2):
    students.append(students[0])
    del students[0]
    print(students)
#while循环
students2 = ['小明','小红','小刚']
count=0
while count<3:
    print(students2)
    students2.append(students2[0])
    del students2[0]
    count+=1
#方法二：pop()
#for循环
students3 = ['小明','小红','小刚']
print(students3)
for i in range(2):
    name=students3.pop(0)
    students3.append(name)
    print(students3)
#while循环
students4 = ['小明','小红','小刚']
count2=1
while count2<=3:
    print(students4)
    name=students4.pop(0)
    students4.append(name)
    count2+=1








