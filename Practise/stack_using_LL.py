class Node:
    def __init__(self,data):
        self.data = data
        self.next = None

class Stack:
    def __init__(self):
        self.top = None

    def push(self,val):
        new_node = Node(val)
        new_node.next = self.top
        self.top = new_node
        print(f"{val} pushed")

    def pop(self):
        if self.top is None:
            print("Stack underflow\n")
            return
        val = self.top.data
        self.top = self.top.next
        print(f"{val} pooped")

    def peek(self):
        if self.top is None:
            print("Stack is empty")
            return None
        return self.top.data

    def display(self):
        if self.top is None:
            print("Stack is empty")
            return
        temp = self.top
        print("Stack elements:", end=" ")
        while temp:
            print(temp.data, end=" ")
            temp = temp.next
        print()

s = Stack()
s.push(10)
s.push(20)
s.push(30)
s.display()
print("Top element:", s.peek())
s.pop()
s.display()