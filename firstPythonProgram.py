#this program will make Account objects inside the list
class Account:
    username = ""
    password = ""
    fullName = ""
    age = 0
    massage = ""

    #you need to define the constructor
    def __init__(self, username, password, fullName, age, massage):
        self.username = username
        self.password = password
        self.fullName = fullName
        self.age = age
        self.massage = massage

    def printMassage(self):
        print(self.massage)

#the main body, why the hell python doesn't have main body function!!!

#prints tons of newlines
def printBlanks():
    for a in range(15):
        print("\n")

#the program starts
list = []
list.append(Account("chawza", "asdf", "Nabeel Kahlil Maulana", 18, "derp"))


userInput = 0
while userInput != 4:
    print("1. Log in\n2. Sign up\n3. show all signed up accounts\n4. Exits program")
    userInput = int(input("User Choice: "))
    if userInput == 1:
        printBlanks()
        #user log in
        loginName = input("Enter your account username: ")
        loginPass = input("Enter your account password: ")
        for a in range(len(list)):
            if list[a].username == loginName:
                if list[a].password == loginPass:
                    print("\nsecret massage is: ", end='')
                    list[a].printMassage()
                else:
                    print("You write the wrong username or password, please try again")

        input("press enter to return")

    elif userInput == 2:
        printBlanks()
        #user sign up for new account
        newUsername = input("enter your new username: ")
        newPass = input("enter your new Password: ")
        newName = input("enter your Full name: ")
        newAge = input("enter your age: ")
        newMassage = input("enter your secret massage: ")
        list.append(Account(newUsername, newPass, newName, newAge, newMassage))
        print("Welcome ",newUsername,", your account has been added!")
        #I should have put the input() in the constructor but fck it

    elif userInput == 3:
        #show all signed up accounts
        printBlanks()
        print("All availabe account registered:")
        for a in range(len(list)):
            print(list[a].username)
        input("Press enter to continue...")

    elif userInput == 4:
        #exits program
        print("\nThank you for using the program")

    else:
        print("\nYou chose the wrong input, please try again!")

    printBlanks()
