import numpy as np
import matplotlib.pyplot as plt
import random

class data:
    def __init__(self, x, y):
        self.xAxis = x
        self.yAxis = y

    def nearest(self, centroid_list):
        idx, value = 0, 0 #first centroid have the lowest value
        for row, centroid in enumerate(centroid_list):
            range = abs(self.xAxis - centroid.xAxis) + abs(self.yAxis - centroid.yAxis) #calculate the rect distance
            if range < value:   # if found lower than current centroid, that swap
                idx = row
                value = centroid
        return idx


def rect_distance(a, b):
    return abs(a.xAxis - b.xAxis) + abs(a.yAxis - b.yAxis)

# initialize
arrayList = []
dataLength = 50
centroid = []
centroid_number =  3

#initial data location


#intial the sentroid location
for strd in range(centroid_number):
    x = random.randint(1, 100)
    y = random.randint(1, 100)
    centroid.append(data(x,y))

#k-mean

while True:
    centroid_list = [0] * centroid_number   #this list will change on each iteration
    for data in arrayList:
        index = data.nearest(centroid)
        centroid_list[index] = centroid_list[index] + 1

    #update the centroid value
    for idx in range(centroid_number):
        #calculate the avg
        average = 0
        for each in centroid_list:
            