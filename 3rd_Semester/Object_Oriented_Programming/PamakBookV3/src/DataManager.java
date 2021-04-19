import org.jgrapht.Graph;
import org.jgrapht.alg.shortestpath.GraphMeasurer;
import org.jgrapht.graph.DefaultEdge;
import org.jgrapht.graph.DefaultUndirectedGraph;

import java.io.*;
import java.util.ArrayList;
import java.util.HashMap;

public class DataManager {

    HashMap<String, User> usersMap = new HashMap<>();
    HashMap<String, Group> groupMap = new HashMap<>();

    private static final String userDataPath = "users.ser";
    private static final String groupDataPath = "groups.ser";

    public DataManager() {
        setupDefaults();
        restoreData();  // Overrides default data
    }

    private void setupDefaults() {

        // Add Default Users
        usersMap.put("Makis" , new User("Makis" , "iis1998@uom.edu.gr" ));
        usersMap.put("Petros", new User("Petros", "ics1924@uom.edu.gr" ));
        usersMap.put("Maria" , new User("Maria" , "iis2012@uom.edu.gr" ));
        usersMap.put("Gianna", new User("Gianna", "iis19133@uom.edu.gr"));
        usersMap.put("Nikos" , new User("Nikos" , "dai1758@uom.edu.gr" ));
        usersMap.put("Babis" , new User("Babis" , "ics19104@uom.edu.gr"));
        usersMap.put("Stella", new User("Stella", "dai1827@uom.edu.gr" ));
        //users.put("Eleni", new User("Eleni", "ics2086@gmail.com"));

        // Add Friend Relations
        usersMap.get("Makis").addFriend(usersMap.get("Petros"));
        usersMap.get("Makis").addFriend(usersMap.get("Nikos"));
        usersMap.get("Nikos").addFriend(usersMap.get("Babis"));
        usersMap.get("Maria").addFriend(usersMap.get("Gianna"));
        usersMap.get("Maria").addFriend(usersMap.get("Petros"));
        usersMap.get("Gianna").addFriend(usersMap.get("Babis"));
        usersMap.get("Nikos").addFriend(usersMap.get("Maria"));
        usersMap.get("Makis").addFriend(usersMap.get("Babis"));
        usersMap.get("Nikos").addFriend(usersMap.get("Petros"));
        usersMap.get("Stella").addFriend(usersMap.get("Makis"));

        // Add Default Groups
        groupMap.put("WebGurus", new Group("WebGurus", "A group for web passionates"));
        groupMap.put("ExamSolutions", new ClosedGroup("ExamSolutions", "Solutions to common exam questions"));

        // Add Group Members
        groupMap.get("WebGurus").addMember(usersMap.get("Gianna"));
        groupMap.get("WebGurus").addMember(usersMap.get("Maria"));
        groupMap.get("WebGurus").addMember(usersMap.get("Petros"));
        groupMap.get("ExamSolutions").addMember(usersMap.get("Gianna"));
        //groupMap.get("ExamSolutions").addMember(usersMap.get("Nikos"));
        groupMap.get("ExamSolutions").addMember(usersMap.get("Babis"));
        groupMap.get("ExamSolutions").addMember(usersMap.get("Nikos"));

    }

    public void saveData() throws IOException {

        FileOutputStream fileOut;
        ObjectOutputStream out;

        // Save Users
        fileOut = new FileOutputStream(userDataPath);
        out = new ObjectOutputStream(fileOut);

        out.writeObject(usersMap);

        System.out.println("Saved user data");

        // Save Groups
        fileOut = new FileOutputStream(groupDataPath);
        out = new ObjectOutputStream(fileOut);

        out.writeObject(groupMap);

        System.out.println("Saved group data");

        out.close();
        fileOut.close();
    }

    public void restoreData() {
        try {
            // User Data
            FileInputStream fileIn = new FileInputStream(userDataPath);
            ObjectInputStream in = new ObjectInputStream(fileIn);
            usersMap = (HashMap<String, User>) in.readObject();
            in.close();
            fileIn.close();

            // Group Data
            fileIn = new FileInputStream(groupDataPath);
            in = new ObjectInputStream(fileIn);
            groupMap = (HashMap<String, Group>) in.readObject();
            in.close();
            fileIn.close();

            System.out.println("Restored Previous Data Successfully");
        } catch (IOException | ClassNotFoundException e) {
            System.out.println(e.getMessage());
        }

    }

    public double getFriendGraphDiameter() {

        Graph<User, DefaultEdge> graph = new DefaultUndirectedGraph<>(DefaultEdge.class);

        for (User user: getUserlist()) {
            graph.addVertex(user);
        }

        for (User user: getUserlist()) {
            for (User friend: user.getFriendList()) {
                graph.addEdge(user, friend);
            }
        }

        GraphMeasurer<User, DefaultEdge> graphMeasurer = new GraphMeasurer<>(graph);
        return graphMeasurer.getDiameter();
    }

    public void addUser(User user) throws IllegalArgumentException{
        usersMap.put(user.getName(), user);
        System.out.println("New User Added: " + user.getName());
    }

    public ArrayList<User> getUserlist() {
        return new ArrayList<>(usersMap.values());
    }

    public ArrayList<Group> getGroupList() {
        return new ArrayList<>(groupMap.values());
    }

    public HashMap<String, User> getUsersMap() {
        return usersMap;
    }

    public HashMap<String, Group> getGroupMap() {
        return groupMap;
    }
}
