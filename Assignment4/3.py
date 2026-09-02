# Write a program to collect height & weight of N students. Find the highest weight/height
# ratio using linked list.

class Node:
    def __init__(self,data):
        self.data = data
        self.next = None

class LinkedList:
    def __init__(self):
        self.head = None

    def insert_end(self,data):
        new_node = Node(data)
        if not self.head:
            self.head = new_node
            return
        temp = self.head
        while temp.next:
            temp = temp.next
        temp.next = new_node

    def highest_ratio(self):
        temp = self.head
        max_ratio = 0
        max_index = 0
        index = 0
        while temp:
            if temp.data > max_ratio:
                max_ratio = temp.data
                max_index = index
            temp = temp.next
            index += 1
            return max_ratio,max_index+1

n = int(input("Enter number of students: "))
ll = LinkedList()

for i in range(n):
    h,w = map(float,input(f"Enter height and weight of student {i+1}: ").split())
    ll.insert_end(w/h)

ratio,student = ll.highest_ratio()
print(f"Highest weight/height ratio = {ratio:.2f} (Student {student})")