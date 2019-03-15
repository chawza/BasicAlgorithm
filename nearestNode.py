import math


class Node:
    posx = 0
    poxy = 0
    name = 0

    def __init__(self, name, x, y):
        self.name = name
        self.posx = x
        self.posy = y

#create and return Node object
def get_main_node(name):

    file = open("node_list.bin", "r")
    str = []
    for line in range(name+1):
        str = file.readline().split(",")


    return Node(int(str[0]), int(str[1]), int(str[2]))

#find length of to nodes
def find_length(x1, y1, x2, y2):
    x = x1 - x2
    y = y1 - y2

    return math.sqrt(math.pow(x, 2) + math.pow(y, 2))


# body starts here
userInput = 0
while userInput != 2:

    print("Menu\n1. find something\n2. exit program")
    userInput = int(input("User choice: "))

    if userInput == 1:
        # find first node
        inp_name = int(input("please enter dot to find: "))
        main_node = get_main_node(inp_name)


        # the second node
        buff = open("node_list.bin", "r")  # creating file
        name2 = 0
        x2 = 0
        y2 = 0

        #diuble code because python doesn't have do-while loop, please correct this
        str = buff.readline().split(",")
        name2 = int(str[0])
        x2 = int(str[1])
        y2 = int(str[2])

        length_nodes = find_length(main_node.posx, main_node.posy, x2, y2)

        try:
            while True:
                str2 = buff.readline().split(",")
                if find_length(main_node.posx, main_node.posy, int(str2[1]), int(str2[2])) < length_nodes:
                    name2 = int(str2[0])
                    x2 = int(str2[1])
                    y2 = int(str2[2])

        except:
            print("all node has been scanned!")

        print("the nearest node from {} node is from {} node, with is {} units".format(main_node.name, name2, find_length(main_node.posx, main_node.posy, x2, y2)))

        buff.close()


    elif userInput == 2:
        # exits program
        input("thank you for using the program")


    else:
        print("you chose the wrong input!")
