import random

student = list(range(1,31))
print('班里所有人')
print(student)

wanhui = random.sample(student,5)
print('参加晚会的人')
print(wanhui)

for i in range(5):
    student.remove(wanhui[i])
jiangzuo = random.sample(student,12)
print('参见讲座的人')
print(jiangzuo)