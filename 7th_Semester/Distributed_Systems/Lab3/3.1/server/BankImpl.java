import java.rmi.*;
import java.rmi.server.*;
import java.sql.*;
import java.util.Objects;
import java.util.concurrent.locks.Lock;
import java.util.concurrent.locks.ReentrantLock;

public class BankImpl extends UnicastRemoteObject implements Bank {
	
	private static final long serialVersionUID = 1;

	private Boolean loggedIn = false;
	private String username = "";
	private Lock userLock = new ReentrantLock();

	protected BankImpl() throws RemoteException {
	}

	@Override
	public String login(String username, String password) throws RemoteException {
		userLock.lock();
		try(Connection conn = DriverManager.getConnection("jdbc:mariadb://localhost:3306/BANK_DB", "root", "changethispassword"); Statement stmt = conn.createStatement()) {
			ResultSet result = stmt.executeQuery("SELECT username, password FROM users WHERE username = \"" + username + "\"");
			if (result.next()) {
				String truePassword = result.getString("password");
				if (Objects.equals(password, truePassword)) {
					loggedIn = true;
					this.username = username;
					return "OK";
				} else {
					loggedIn = false;
				}
			}
		} catch (SQLException e) {
			System.out.println(e);
		} finally {
			userLock.unlock();
		}
		loggedIn = false;
		return "AUTH_ERROR";
	}

	@Override
	public String withdraw(double amount) throws RemoteException {
		if (!loggedIn) return "LOGIN_ERROR";
		if (amount < 0 ) return "AMOUNT_ERROR";
		userLock.lock();
		try(Connection conn = DriverManager.getConnection("jdbc:mariadb://localhost:3306/BANK_DB", "root", "changethispassword"); Statement stmt = conn.createStatement()) {
			ResultSet result = stmt.executeQuery("SELECT balance FROM users WHERE username = \"" + username + "\"");
			if (result.next()) {
				Double balance = result.getDouble("balance");
				if (balance < amount) return "BALANCE_ERROR";
				Double newBalance = balance - amount;
				result = stmt.executeQuery("UPDATE users SET balance = "+ newBalance +" WHERE username = \"" + username + "\"");
				return "OK";
			}
		} catch (SQLException e) {
			System.out.println(e);
		} finally {
			userLock.unlock();
		}
		return "ERROR";
	}

	@Override
	public String deposit(double amount) throws RemoteException {
		if (!loggedIn) return "LOGIN_ERROR";
		if (amount < 0 ) return "AMOUNT_ERROR";
		userLock.lock();
		try(Connection conn = DriverManager.getConnection("jdbc:mariadb://localhost:3306/BANK_DB", "root", "changethispassword"); Statement stmt = conn.createStatement()) {
			ResultSet result = stmt.executeQuery("SELECT balance FROM users WHERE username = \"" + username + "\"");
			if (result.next()) {
				Double balance = result.getDouble("balance");
				Double newBalance = balance + amount;
				result = stmt.executeQuery("UPDATE users SET balance = "+ newBalance +" WHERE username = \"" + username + "\"");
				return "OK";
			}
		} catch (SQLException e) {
			System.out.println(e);
		} finally {
			userLock.unlock();
		}
		return "ERROR";
	}

	@Override
	public String balance() throws RemoteException {
		if (!loggedIn) return "LOGIN_ERROR";
		try(Connection conn = DriverManager.getConnection("jdbc:mariadb://localhost:3306/BANK_DB", "root", "changethispassword"); Statement stmt = conn.createStatement()) {
			ResultSet result = stmt.executeQuery("SELECT balance FROM users WHERE username = \"" + username + "\"");
			if (result.next()) {
				Double balance = result.getDouble("balance");
				return balance.toString();
			}
		} catch (SQLException e) {
			System.out.println(e);
		}
		return "ERROR";
	}
}
