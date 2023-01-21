from zeep import Client
client = Client('http://127.0.0.1:8000/?wsdl')

login_response = ""
username = ""
while login_response != "OK":
    print("Login")
    username = input("Enter username: ")
    password = input("Enter password: ")
    login_response = client.service.login(username, password)
    print(login_response)
    if login_response != "OK": print("Wrong username/password")

option = ""
while option != "4":
    print("1. Balance")
    print("2. Deposit")
    print("3. Withdraw")
    print("4. Quit")
    option = input("Enter option: ")
    print("----")
    match option:
        case "1":
            print(f"Balance: {client.service.balance(username)}")
        case "2":
            amount = input("Enter Deposit Amount: ")
            response = client.service.deposit(username, amount)
            print(response)
            print(f"New Balance: {client.service.balance(username)}")
        case "3":
            amount = input("Enter Deposit Amount: ")
            response = client.service.withdraw(username, amount)
            print(response)
            print(f"New Balance: {client.service.balance(username)}")
    print("-----")
