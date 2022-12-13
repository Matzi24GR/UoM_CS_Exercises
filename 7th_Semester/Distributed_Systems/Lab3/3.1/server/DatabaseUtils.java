import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.SQLException;
import java.sql.Statement;

public class DatabaseUtils {

    static void initializeDatabase() {
        try(Connection conn = DriverManager.getConnection("jdbc:mariadb://localhost:3306", "root", "changethispassword"); Statement stmt = conn.createStatement()) {
            stmt.executeQuery("CREATE DATABASE IF NOT EXISTS BANK_DB");
            stmt.executeQuery("use BANK_DB");
            stmt.executeQuery(
                    """
                                CREATE TABLE IF NOT EXISTS users (
                                   username VARCHAR(50) NOT NULL PRIMARY KEY,
                                   password VARCHAR(255) NOT NULL,
                                   balance DOUBLE NOT NULL
                               )
                       """);
            stmt.executeQuery("INSERT IGNORE INTO users VALUES (\"Deliverer3334\", \"Y4B&JLkb$6fj\", 2136.32)");
            stmt.executeQuery("INSERT IGNORE INTO users VALUES (\"Partridge6105\", \"xzjUj@M5PqY#\", 8420.12)");
            stmt.executeQuery("INSERT IGNORE INTO users VALUES (\"Truffle8604\", \"8vo5c9&nFx\\$q\", 320.87)");
            stmt.executeQuery("INSERT IGNORE INTO users VALUES (\"admin\", \"admin\", 320.87)");
        } catch (SQLException e) {
            System.out.println(e);
        }
    }
}
