import java.util.ArrayList;

public class User {

    private String name;
    private String email;
    private static final String validEmailPattern = "(ics|iis|dai)\\d{3,5}@uom.edu.gr";

    private ArrayList<User> friendList = new ArrayList<>();
    private ArrayList<Group> groupList = new ArrayList<>();

    public User(String name, String email) {

        // Check if email is valid
        if ( email.matches(validEmailPattern) ) {
            this.name = name;
            this.email = email;
        } else {
            System.out.println("User " + name + " has not been created. Email format is not acceptable.");
            //throw new IllegalArgumentException("User " + name + " has not been created. Email format is not acceptable.");
        }

    }

    // Requirement #1
    public boolean isFriendWith(User user) {

        for (User userToCheck: friendList) {
            if (userToCheck.equals(user))
                return true;
        }

        return false;

    }

    // Requirement #2
    public void addFriend(User newUser) {
        // check that input is not the same user or an existing friend
        if ( !newUser.equals(this) && !newUser.isFriendWith(this)) {

            System.out.println(this.name + " and " + newUser.name + " are now friends!");
            // Add to both friends lists
            friendList.add(newUser);
            newUser.friendList.add(this);

        }

    }

    // Requirement #3
    public ArrayList<User> getMutualFriendsWith(User user) {
        // new List
        ArrayList<User> mutualFriendsList = new ArrayList<>();

        // loop through both lists
        for (User a: this.friendList) {
            for (User b: user.friendList) {

                // if friend is the same user add it to the result list
                if ( a.equals(b) ) {
                    mutualFriendsList.add(a);
                }

            }
        }

        // return resulting list
        return mutualFriendsList;
    }

    // Calls getMutualFriendsWith(User user) for data
    public void printMutualFriendsWith(User user) {
        System.out.println("**************************************");
        System.out.println("Common friends of " + this.getName() + " and " + user.getName());
        System.out.println("**************************************");

        ArrayList<User> mutualFriends = this.getMutualFriendsWith(user);
        for (int i = 0; i < mutualFriends.size(); i++) {
            System.out.println( i+1 + ": " + mutualFriends.get(i).getName() );
        }

        System.out.println("--------------------------------------");
    }

    // Requirement #4
    public void printFriends() {

        System.out.println("**************************************");
        System.out.println("Friends of " + name);
        System.out.println("**************************************");

        for (int i = 0; i < friendList.size(); i++) {
            System.out.println( i+1 + ": " + friendList.get(i).getName() );
        }

        System.out.println("--------------------------------------");

    }

    // NOT to be used
    // used by the groups addMember method
    // only works when addMember has done its part already
    protected void addGroup(Group group) {
        if (group.hasMember(this)) {
            groupList.add(group);
        }
    }

    // Requirement #5
    public void printGroups() {

        System.out.println("**************************************");
        System.out.println("Groups that " + name +" been enrolled in");
        System.out.println("**************************************");

        for (int i = 0; i < groupList.size(); i++) {
            System.out.println( i+1 + ": " + groupList.get(i).getName() );
        }

        System.out.println("--------------------------------------");

    }

    // Requirement #6
    public ArrayList<User> getPossiblyInfectedUsers() {
        // new list for results
        ArrayList<User> possiblyInfectedUsers = new ArrayList<>();

        // loop through friends lists
        // there must be a better solution than a triple for loop
        for (User friend: friendList) {
            // Depth 1
            possiblyInfectedUsers.add(friend);
            for (User friend2: friend.friendList) {
                // Depth 2
                boolean alreadyIncluded = false;
                for (User included: possiblyInfectedUsers) {
                    alreadyIncluded = included.equals(friend2);
                    if (alreadyIncluded) break;
                }
                // Dont include this user or any duplicates
                if ( !friend2.equals(this) && !alreadyIncluded) {
                    possiblyInfectedUsers.add(friend2);
                }
            }
        }
        // return resulting list
        return possiblyInfectedUsers;
    }

    // Calls getPossiblyInfectedUsers() for data
    public void printPossiblyInfectedFriends() {
        System.out.println("*******************************");
        System.out.println( this.getName() + " has been infected. The following users have to be tested" );
        System.out.println("*******************************");

        ArrayList<User> possiblyInfectedFriends = this.getPossiblyInfectedUsers();
        for (int i = 0; i < possiblyInfectedFriends.size(); i++) {
            System.out.println( i+1 + ": " + possiblyInfectedFriends.get(i).getName() );
        }

        System.out.println("-----------------------------");
    }

    public boolean equals(Object object) {

        if (object.getClass() == this.getClass()) {
            User userToCheck  = (User) object;
            return userToCheck.name.equals(this.name) && userToCheck.email.equals(this.email);
        }
        return false;

    }

    public String getName() {
        return name;
    }
}
