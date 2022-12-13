import java.lang.constant.Constable;
import java.rmi.*;
import java.sql.*;
import java.util.Objects;
import java.util.concurrent.locks.Lock;
import java.util.concurrent.locks.ReentrantLock;

public class Bank  {
	
	private static final long serialVersionUID = 1;

	private Boolean loggedIn = false;
	private String username = "";
	private Lock userLock = new ReentrantLock();

	public Bank() {

	}

	public String login(String message) {
		userLock.lock();
		message = message.replace("LOGIN","");
		String[] split = message.split("####");
		String username = split[0];
		String password = split[1];
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
		userLock.unlock();
		loggedIn = false;
		return "AUTH_ERROR";
	}

	public String withdraw(String message) {
		message = message.replace("WITHDRAW","");
		double amount = Double.parseDouble(message);
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

	public String deposit(String message) {
		message = message.replace("DEPOSIT","");
		double amount = Double.parseDouble(message);
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
