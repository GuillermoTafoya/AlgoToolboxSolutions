class priorityQueue:
    def __init__(self) -> None:
        self.queue = [0,0]
    def add(self, x:int) -> None:
        if x > self.queue[0]:
            self.shuffleUp(x)
    def shuffleUp(self,x:int) -> None:
        if x > self.queue[1]:
            self.queue[0] = self.queue[1]
            self.queue[1] = x
        else:
            self.queue[0] = x
    def product(self) -> int:
        return self.queue[0] * self.queue[1]

def max_pairwise_product(numbers):
    two_highest = priorityQueue() # Priority queue?
    for num in numbers:
        two_highest.add(num)
    return two_highest.product()

def max_pairwise_product_brute_force(numbers):
    n = len(numbers)
    max_product = 0
    for first in range(n):
        for second in range(first + 1, n):
            max_product = max(max_product,
                numbers[first] * numbers[second])
    return max_product

if __name__ == '__main__':
    input_n = int(input())
    input_numbers = [int(x) for x in input().split()]
    print(max_pairwise_product(input_numbers))
