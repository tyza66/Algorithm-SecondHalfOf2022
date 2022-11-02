class Node(object):  #节点
    def __init__(self,data):
        self.data=data
        self.next=None

class SingleLinkedList(object):  #
    def __init__(self):
        self.head = Node(None)

    #创建单链表函数√
    def CreateSingleLinkedList(self,list):
        for one in list:
            self.InsertElementInTail(one)

    #遍历单链表函数√
    def TraverseElement1(self):
        if self.IsEmpty1():
            print("单链表为空",end="")
        else:
            temp = self.head
            while True:
                print(temp.data,end=" ")
                temp = temp.next
                if temp == None:
                    break
        print()

    #获取单链表长度函数√
    def GetLength(self):
        num = 0
        if self.IsEmpty1():
            return num
        else:
            temp = self.head
            while True:
                num += 1
                temp = temp.next
                if temp==None:
                    break
        return num

    #判断单链表是否为空函数1√
    def IsEmpty1(self):
        if self.head.data == None:
            return True
        else:
            return False

    #判断单链表是否为空函数2√
    def IsEmpty2(self):
        if self.GetLength() == 0:
            return True
        else:
            return False

    #尾端插入元素函数√
    def InsertElementInTail(self,a):
        one = Node(a)
        if self.IsEmpty1():
            self.head = one
        else:
            end = self.head
            while end.next != None:
               end = end.next
            end.next = one

    #首端插入元素函数√
    def InsertElementInHead(self,a):
        one = Node(a)
        temp = self.head
        self.head = one
        one.next = temp

    #查找指定元素并返回其位置函数√
    def FindElement(self,a):
        if self.IsEmpty1():
            return -1
        else:
            temp = self.head
            now = 1
            while True:
                if temp.data == a:
                    return now
                temp = temp.next
                now += 1
                if temp.next==None:
                    break
        return -1

    #删除元素函数√
    def DeleteElement(self,a):
        if self.IsEmpty1():
             return False
        else:
             temp = self.head
             if temp.data == a:
                self.head = self.head.next
             now = 1
             while True:
                  if temp.next.data == a:
                    temp.next = temp.next.next
                    return True
                  temp = temp.next
                  now += 1
                  if temp.next == None:
                      break
        return False

    #在指定位置插入指定元素函数：检验位置合法性√
    def InsElePos(self,a,b):
        if a < 1:
            return False
        if a > self.GetLength()+1:
            return False
        if a == 1:
            self.InsertElementInHead(b)
            return True
        temp = self.head
        for i in range(1, a - 1):
            temp = temp.next
        one = Node(b)
        one.next = temp.next
        temp.next = one
        return True

    #在指定值后插入指定元素函数√
    def InsElement2(self,a,b):
        p=self.FindElement(a)
        temp = self.head
        for i in range(1, p):
            temp = temp.next
        one = Node(b)
        one.next = temp.next
        temp.next = one




#测试
linklist = SingleLinkedList()
print("现在列表空1：",linklist.IsEmpty1())
print("现在列表空2：",linklist.IsEmpty2())
linklist.CreateSingleLinkedList([1,1,1])
print("现在长度是：",linklist.GetLength())
print("现在列表空1：",linklist.IsEmpty1())
print("现在列表空2：",linklist.IsEmpty2())
linklist.InsertElementInTail(1)
linklist.InsertElementInTail(2)
linklist.InsertElementInTail(3)
linklist.TraverseElement1()
print("现在长度是：",linklist.GetLength())
linklist.InsertElementInHead(8)
linklist.TraverseElement1()
print("8的位置在第",linklist.FindElement(8))
linklist.DeleteElement(8)
linklist.DeleteElement(3)
linklist.TraverseElement1()
linklist.InsertElementInHead(7)
linklist.InsElePos(1,2)
linklist.TraverseElement1()
linklist.InsElePos(2,88)
linklist.TraverseElement1()
linklist.InsElePos(9,66)
linklist.TraverseElement1()
linklist.InsElement2(2,33)
linklist.TraverseElement1()

