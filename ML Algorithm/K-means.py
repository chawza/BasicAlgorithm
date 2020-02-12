import numpy as np
import matplotlib.pyplot as plt
import random

class data:
    def __init__(self, x, y):
        self.xAxis = x
        self.yAxis = y
    cluster = 0

def rect_distance(a, b):
    return abs(a.xAxis - b.xAxis) + abs(a.yAxis - b.yAxis)

# initialize
arrayList = []
dataLength = 50
centroid = []
centroid_number =  3

#intial the sentroid location
for strd in range(centroid_number):
    x = random.randint(1, 100)
    y = random.randint(1, 100)
    centroid.append(data(x,y))

#k-mean
while True:
    