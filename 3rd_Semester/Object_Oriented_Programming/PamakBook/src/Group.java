import java.util.ArrayList;

public class Group {

    private String name;
    private String description;

    protected ArrayList<User> memberList = new ArrayList<>();

    public Group(String name, String description) {
        this.name = name;
        this.description = description;
    }

    // Requirement #1
    public boolean hasMember(User user) {

        for (User userToCheck: memberList) {
            if (userToCheck.equals(user))
                return true;
        }
        return false;

    }

    // Requirement #2
    public void addMember(User user) {
        // if user not a member yet add him
        if ( !hasMember(user) ) {
            memberList.add(user);
            user.addGroup(this);
            System.out.println( user.getName() + " has been successfully enrolled in group " + name);
        } else {
            System.out.println("FAILED: " + user.getName() + " cannot be enrolled in group " + name);
        }
    }

    // Requirement #3
    public void printMembers() {

        System.out.println("*******************************");
        System.out.println("Members of group " + name);
        System.out.println("*******************************");

        for (int i = 0; i < memberList.size(); i++) {
            System.out.println( i+1 + ": " + memberList.get(i).getName() );
        }

        System.out.println("-----------------------------");

    }

    public String getName() {
        return name;
    }
}
