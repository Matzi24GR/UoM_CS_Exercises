import java.util.ArrayList;
import java.util.HashMap;

public class Main {

    public static void main(String[] args) {

        HashMap<String, User> users = new HashMap<>();

        users.put("Makis", new User("Makis", "iis1998@uom.edu.gr"));
        users.put("Petros", new User("Petros", "ics1924@uom.edu.gr"));
        users.put("Maria", new User("Maria", "iis2012@uom.edu.gr"));
        users.put("Gianna", new User("Gianna", "iis19133@uom.edu.gr"));
        users.put("Nikos", new User("Nikos", "dai1758@uom.edu.gr"));
        users.put("Babis", new User("Babis", "ics19104@uom.edu.gr"));
        users.put("Stella", new User("Stella", "dai1827@uom.edu.gr"));
        //users.put("Eleni", new User("Eleni", "ics2086@gmail.com"));

        Group g1 = new Group("WebGurus", "A group for web passionates");
        ClosedGroup g2 = new ClosedGroup("ExamSolutions", "Solutions to common exam questions");

        users.get("Makis").addFriend(users.get("Petros"));
        users.get("Makis").addFriend(users.get("Nikos"));
        users.get("Nikos").addFriend(users.get("Babis"));
        users.get("Maria").addFriend(users.get("Gianna"));
        users.get("Maria").addFriend(users.get("Petros"));
        users.get("Gianna").addFriend(users.get("Babis"));
        users.get("Nikos").addFriend(users.get("Maria"));
        users.get("Makis").addFriend(users.get("Babis"));
        users.get("Nikos").addFriend(users.get("Petros"));
        users.get("Stella").addFriend(users.get("Makis"));

        g1.addMember(users.get("Gianna"));
        g1.addMember(users.get("Maria"));
        g1.addMember(users.get("Petros"));
        g2.addMember(users.get("Gianna"));
        g2.addMember(users.get("Nikos"));
        g2.addMember(users.get("Babis"));
        g2.addMember(users.get("Nikos"));

        LoginPage loginPage = new LoginPage(new ArrayList<>(users.values()));
    }

}
