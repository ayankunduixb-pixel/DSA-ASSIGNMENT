class Stack:
    def __init__(self,size=100):
        self.stack = []
        self.size = size

    def push(self,val):
        if len(self.stack) == self.size:
            print("Stack Overflow")
        else:
            self.stack.append(val)
            print(f"{val} pushed")

    def pop(self):
        if not self.stack:
            print("Stack Underflow")
        else:
            val = self.stack.pop()
            print(f"{val} popped")

    def display(self):
        if not self.stack:
            print("Stack is empty")
        else:
            print("Stack elements: ",self.stack[::-1])

    def peek(self):
        if not self.stack:
            print("Stack is empty")
            return None
        return self.stack[-1]

    def isEmpty(self):
        return len(self.stack) == 0


s = Stack(5)
s.push(10)
s.push(20)
s.push(30)
s.display()
s.pop()
s.display()