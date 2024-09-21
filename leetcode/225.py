class MyStack:

    def __init__(self):
      self.stack = []

    def push(self, x:int):
      self.stack.append(x)

    def pop(self) -> int:
      return self.stack.pop()

    def top(self) -> int:
      return self.stack[-1]

    def empty(self) -> bool:
      return len(self.stack) == 0

