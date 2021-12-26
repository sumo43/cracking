class square():
    x0 = None
    y0 = None
    x1 = None
    y1 = None
    def __init__(self, x0, y0, x1, y1):
        self.x0 = x0
        self.y0 = y0
        self.x1 = x1
        self.y1 = y1
    def bisect(self, other):
        center_1 = ((self.x0 + self.x1) / 2, (self.y0 + self.y1) / 2)
        center_2 = ((other.x0 + other.x1) / 2, (other.y0 + other.y1) / 2)
        return (center_1, center_2)
def bisect():
    square1 = square(5, 5, 10, 10)
    square2 = square(20, 10, 25, 15)
    fr, to = square1.bisect(square2)
    x0, y0 = fr
    x1, y1 = to
    slope = (y1 - y0) / (x1 - x0)
    b = y0 / (slope * x0)
    print(f"y = {slope}x + {b}")
if __name__ == "__main__":
    bisect()


