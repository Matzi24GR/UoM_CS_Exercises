import org.mariadb.jdbc.client.result.Result;

import java.rmi.server.*;
import java.rmi.registry.*;
import java.sql.*;

/*
 * Execute:
 * java FactorialServer
 */
public class BankServer {
	
	private static final String HOST = "localhost";
	private static final int PORT = Registry.REGISTRY_PORT; // 1099
	
	public static void main(String[] args) throws Exception {

		DatabaseUtils.initializeDatabase();
				
		// Should be first, especially if server is NOT localhost
		System.setProperty("java.rmi.server.hostname", HOST);
                
		// Remote object creation
		Bank robj = new BankImpl();
		
		// Choose the appropriate method:
		// get if rmi registry is already running, create otherwise
		Registry registry = LocateRegistry.createRegistry(PORT);
		
		// Bind remote object to a name and publish in rmi registry

		String rmiObjectName = "Bank";
		registry.rebind(rmiObjectName, robj);
		System.out.println("Remote object bounded.");

		while (true) {
			Thread.sleep(Long.MAX_VALUE);
		}

	}
}

