import math
import numpy as np

# variables
np.random.seed(0)
weight = np.array(np.random.rand(5))   #prerandom number
input = np.array([2, -1, 4, -3, 1])

#declare functions
def sigmoid(a):
    return 1/(1 + np.exp(-a))

def step(a):
    if a >= 0:
        return 1
    else:
        return 0

def tanh(a):
    return (np.exp(a) - np.exp(-a)) / (np.exp(a) + np.exp(-a))

def ReLu(a):
    if a <= 0:
        return 0
    return a

# reference: https://mlfromscratch.com/activation-functions-explained/#/
def gaussian(a):
    number = np.sqrt(2 / (np.pi * (a + 0.044715 * np.power(a, 3))))
    return 0.5 * a * (1 + tanh(number))

num = weight.dot(input.T)

print("weight\t: ", weight)
print('input\t: ', input)
print('\nLinear\t: ', num)
print('step\t: ', step(num))
print('sigmoid\t: ', sigmoid(num))
print('tanH\t: ', tanh(num))
print('ReLu\t: ', ReLu(num))
print('Gaussian: ', gaussian(num))
