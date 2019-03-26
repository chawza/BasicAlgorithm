
# file name to read and write : "data.txt"
# priority type: Low, Medium, high


class Activity:
    act_type = ""
    act_time = ""
    act_name = ""
    act_des = ""

    def __init__(self, a, b, c,):
        self.act_type = a
        self.act_time = b
        self.act_des = c


def show_act():
    with open("data.txt", "r") as file:
        if file is None:
            return

        counter = 1
        for line in file:
            line = line.split("#")
            print("{}. Type: {}\tTime: {}\n   Description:\n   {}\n".format(counter, line[0], line[1], line[2]))
            counter = counter + 1


def add_act(act_type, act_time, act_des):
    with open("data.txt", "a") as file:
        file.write("{}#{}#{}\n".format(act_type, act_time, act_des))


def del_act(index):
    main_list = []

    with open("data.txt", "r") as file:
        for line in file:
            temp = line.split("#")
            main_list.append(Activity(temp[0], temp[1], temp[2]))

    main_list.pop(index)

    with open("data.txt", "w") as file:

        for line in main_list:
            file.write("{}#{}#{}".format(line.act_type, line.act_time, line.act_des))


def sort_list():

    main_list = []
    with open("data.txt", "r") as file:
        for line in file:
            line = line.split("#")
            main_list.append(Activity(line[0], line[1], line[2]))

    low_list = []
    med_list = []
    high_list = []

    for obj in main_list:
        if obj.act_type.upper() == "LOW":
            low_list.append(obj)

        elif obj.act_type.upper() == "MEDIUM":
            med_list.append(obj)

        elif obj.act_type.upper() == "HIGH":
            high_list.append(obj)

    med_list.extend(low_list)
    high_list.extend(med_list)
    main_list = high_list

    with open("data.txt", "w") as file:
        for line in main_list:
            file.write("{}#{}#{}".format(line.act_type, line.act_time, line.act_des))


def print_blanks():
    for a in range(20):
        print("\n")

# dunno why it wont works
def set_time_input():
    time_input = ""
    while time_input:
        time_str = input("set time between 00:00 to 24:00: ").split(":")

        hour = int(time_str[0])
        minute = int(time_str[1])

        if 0 <= hour >= 24 and 0 <= minute >= 60:
            return time_input


# body starts here
userInput = 0
while userInput != 4:
    print_blanks()
    userInput = int(input("Menu:\n1. Show all activity\n2. Add task\n3. Delete task\n4. Exits Program\n"))

    if userInput == 1:
        # show tasks
        choice = input("do you want to sort the list[Y/N]?")
        if choice.upper() == "Y":
            sort_list()

        show_act()
        input("press enter to continue...")

    elif userInput == 2:
        # add tasks
        prio1 = input("set Priority [Low, Medium, High]:  ")
        time1 = input("set time between 00:00 to 24:00: ")
        des1 = input("Description:\n")

        add_act(prio1.upper(), time1.upper(), des1.upper())

    elif userInput == 3:
        # delete tasks
        show_act()
        try:
            act_index = int(input("please chose activity to delete by number: "))
        except TypeError:
            print("index input must be number!")
            break

        del_act(act_index-1)

    elif userInput == 4:
        # exits task
        print("thank you for using the program")

    else:
        print("Please re-enter again")
