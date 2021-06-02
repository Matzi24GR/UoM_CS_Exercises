public class Main {

    public static void main(String[] args) {

        User u1 = new User("Makis", "iis1998@uom.edu.gr");                // Makis   1
        User u2 = new User("Petros", "ics1924@uom.edu.gr");               // Petros  2
        User u3 = new User("Maria", "iis2012@uom.edu.gr");                // Maria   3
        User u4 = new User("Gianna", "iis19133@uom.edu.gr");              // Gianna  4
        User u5 = new User("Nikos", "dai1758@uom.edu.gr");                // Nikos   5
        User u6 = new User("Babis", "ics19104@uom.edu.gr");               // Babis   6
        User u7 = new User("Stella", "dai1827@uom.edu.gr");               // Stella  7
        User u8 = new User("Eleni", "ics2086@gmail.com");                 // Eleni   8

        Group g1 = new Group("WebGurus", "A group for web passionates");
        ClosedGroup g2 = new ClosedGroup("ExamSolutions", "Solutions to common exam questions");

        u1.addFriend(u2);
        u1.addFriend(u5);
        u5.addFriend(u6);
        u3.addFriend(u4);
        u3.addFriend(u2);
        u4.addFriend(u6);
        u5.addFriend(u3);
        u1.addFriend(u6);
        u5.addFriend(u2);
        u7.addFriend(u1);

        u5.printMutualFriendsWith(u4);
        u1.printMutualFriendsWith(u5);

        u1.printFriends();
        u3.printFriends();

        g1.addMember(u4);
        g1.addMember(u3);
        g1.addMember(u2);
        g2.addMember(u4);
        g2.addMember(u5);
        g2.addMember(u6);
        g2.addMember(u5);

        u4.printGroups();

        g1.printMembers();
        g2.printMembers();

        u4.printPossiblyInfectedFriends();

    }

}
