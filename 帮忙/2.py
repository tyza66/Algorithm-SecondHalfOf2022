#上次作业的数据
stuInfo=[
['20012132', '于华美', '女', '90'],
['20012133', '井瑶函', '女', '96'],
['20012141', '刘美玲', '女', '72'],
['20012179', '阳运飚', '男', '88'],
['20012184', '王乳宁', '女', '52'],
['20012186', '艾浩枫', '男', '66'],
['20012248', '王佳铭', '男', '71'],
['20012260', '孟祥竹', '男', '96'],
['20012270', '高艺嘉', '女', '83'],
['20012282', '白益豪', '男', '74'],
['20012285', '刘福聪', '男', '60'],
['20012287', '吴明鹏', '男', '92'],
['20012325', '姜建名', '男', '89'],
['20012327', '艾佳馨', '女', '62'],
['20012330', '张小涵', '女', '57'],
['20012351', '何嘉杰', '男', '66'],
['20012353', '宋杭弛', '男', '53'],
['20012356', '苗旺', '男', '61'],
['20012375', '袁萍', '女', '66']
]
#字典用的键
head=['学号','姓名','性别','成绩']
#绑定字典并创建学生信息字典
students=[]
for item in stuInfo:
    students.append(dict(zip(head,item)))
#(2)统计各个分数段比例
print("(2)我是括号二")
youxiu,lianghao,zhongdeng,jige,bujige=0,0,0,0,0
for item in students:
    if int(item['成绩'])>=90:
        youxiu+=1
    elif int(item['成绩'])>=80:
        lianghao+=1
    elif int(item['成绩'])>=70:
        zhongdeng+=1
    elif int(item['成绩'])>=60:
        jige+=1
    else:
        bujige+=1
print("优秀率：",round(youxiu/len(students)*100,2),"%")
print("良好率：",round(lianghao/len(students)*100,2),"%")
print("中等率：",round(zhongdeng/len(students)*100,2),"%")
print("及格率：",round(jige/len(students)*100,2),"%")
print("不及格率：",round(bujige/len(students)*100,2),"%")
#(3)找到所有男同学并放进新的列表
print("(3)我是括号三")
nan = []
for item in students:
    if item['性别']=='男':
        nan.append(item)
print("男生列表：")
print(nan)
#(4)统计男生同学和女同学数
print("(4)我是括号四")
n1,n2=0,0
for item in students:
    if item['性别']=='男':
        n1+=1
    else:
        n2+=1
print('男生人数：',n1)
print('女生人数：',n2)
#(5)输出分数最高同学的信息
print("(5)我是括号五")
max = 0
final = {}
for item in students:
    if int(item['成绩'])>max:
        max = int(item['成绩'])
        final = item
print("分数最高的同学信息：")
print("学号：",final['学号'],"   姓名：",final['姓名'],"  性别：",final['性别'],"  成绩：",final['成绩'])
#(6)定义一个空列表score，每个同学的学号成绩形成一个元组，作为列表score的一个元素，并且按格式输出
print("(6)我是括号六")
score=[]
for item in students:
    score.append(tuple([item['学号'],item['成绩']]))
for item in score:
    print(item[0],"--",item[1])