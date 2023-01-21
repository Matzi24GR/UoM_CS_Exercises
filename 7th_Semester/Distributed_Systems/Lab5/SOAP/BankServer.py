from mysql.connector import cursor
from spyne import Application, rpc, ServiceBase, Iterable, Integer, Unicode

from spyne.protocol.soap import Soap11
from spyne.server.wsgi import WsgiApplication

import mysql.connector as database

connection = database.connect(
    user="root",
    password="changethispassword",
    host="localhost",
    database="")
cursor = connection.cursor()


def initializeDB():
    try:
        statement = """
            CREATE DATABASE IF NOT EXISTS BANK_DB;
            use BANK_DB;
            CREATE TABLE IF NOT EXISTS users (
                           username VARCHAR(50) NOT NULL PRIMARY KEY,
                           password VARCHAR(255) NOT NULL,
                           balance DOUBLE NOT NULL
                       );
          """
        cursor.execute(statement, multi=True)
        connection.commit()
    except database.Error as e:
        print(f"Error retrieving entry from database: {e}")


def add_users():
    try:
        statement = "INSERT IGNORE INTO users (username,password,balance) VALUES (%s, %s, %s);"
        data = ("admin", "admin", "320.87")
        cursor.execute(statement, data)
        data = ("Deliverer3334", "JLkb$6fj", "2136.32")
        cursor.execute(statement, data)
        data = ("Truffle8604", "8vo5c9&nFx$q", "320.87")
        cursor.execute(statement, data)
        data = ("Partridge6105", "xzjUj@M5PqY#", "8420.12")
        cursor.execute(statement, data)
        connection.commit()
    except database.Error as e:
        print(f"Error retrieving entry from database: {e}")


# def getUsers():
#     try:
#         statement = "SELECT * FROM users;"
#         cursor.execute(statement)
#         for (username, password, balance) in cursor.fetchall():
#             print(f"Successfully retrieved {username}")
#     except database.Error as e:
#         print(f"Error retrieving entry from database: {e}")


class BankService(ServiceBase):
    @rpc(Unicode, Unicode, _returns=Unicode)
    def login(self, username, password):
        cursor.execute(f"SELECT username, password FROM users WHERE username = \"{username}\"")
        for (username, real_password) in cursor:
            if real_password == password:
                return "OK"
            else:
                return "AUTH_ERROR"

    @rpc(Unicode, Unicode, _returns=Unicode)
    def withdraw(self, username, amount):
        cursor.execute(f"SELECT balance, username FROM users WHERE username = \"{username}\"")
        for (balance, username) in cursor:
            if float(balance) < float(amount): return "BALANCE_ERROR"
            new_balance = float(balance) - float(amount)
            cursor.execute(f"UPDATE users SET balance = {new_balance} WHERE username = \"{username}\"")
            return "OK"

    @rpc(Unicode, Unicode, _returns=Unicode)
    def deposit(self, username, amount):
        cursor.execute(f"SELECT balance, username FROM users WHERE username = \"{username}\"")
        for (balance, username) in cursor:
            new_balance = float(balance) + float(amount)
            cursor.execute(f"UPDATE users SET balance = {new_balance} WHERE username = \"{username}\"")
            return "OK"

    @rpc(Unicode, _returns=Unicode)
    def balance(self, username):
        cursor.execute(f"SELECT balance, username FROM users WHERE username = \"{username}\"")
        for (balance, username) in cursor:
            return f"{balance}"


application = Application([BankService], 'spyne.examples.hello.soap',
                          in_protocol=Soap11(validator='lxml'),
                          out_protocol=Soap11())

wsgi_application = WsgiApplication(application)

if __name__ == '__main__':
    initializeDB()
    connection = database.connect(
        user="root",
        password="changethispassword",
        host="localhost",
        database="BANK_DB")
    cursor = connection.cursor()
    add_users()
    import logging

    from wsgiref.simple_server import make_server

    logging.basicConfig(level=logging.DEBUG)
    logging.getLogger('spyne.protocol.xml').setLevel(logging.DEBUG)

    logging.info("listening to http://127.0.0.1:8000")
    logging.info("wsdl is at: http://localhost:8000/?wsdl")

    server = make_server('127.0.0.1', 8000, wsgi_application)
    server.serve_forever()
