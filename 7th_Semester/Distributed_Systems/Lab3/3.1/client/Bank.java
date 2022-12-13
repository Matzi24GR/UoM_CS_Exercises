import java.rmi.*;

public interface Bank extends Remote {

	public String login(String username, String password) throws RemoteException;
	public String withdraw(double amount) throws RemoteException;
	public String deposit(double amount) throws RemoteException;
	public String balance() throws RemoteException;

}
