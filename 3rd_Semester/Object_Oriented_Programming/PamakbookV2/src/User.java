import java.util.ArrayList;
import java.util.HashSet;

public class User {

    private String name;
    private String email;
    private static final String validEmailPattern = "(ics|iis|dai)\\d{3,5}@uom.edu.gr";

    private ArrayList<User> friendList = new ArrayList<>();
    private ArrayList<Group> groupList = new ArrayList<>();
    private ArrayList<Post>  postList = new ArrayList<>();

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

    public boolean isFriendWith(User user) {

        for (User userToCheck: friendList) {
            if (userToCheck.equals(user))
                return true;
        }

        return false;

    }

    public void addFriend(User newUser) {
        // check that input is not the same user or an existing friend
        if ( !newUser.equals(this) && !newUser.isFriendWith(this)) {

            System.out.println(this.name + " and " + newUser.name + " are now friends!");
            // Add to both friends lists
            friendList.add(newUser);
            newUser.friendList.add(this);

        }

    }

    // NOT to be used
    // used by the groups addMember method
    // only works when addMember has done its part already
    protected void addGroup(Group group) {
        if (group.hasMember(this)) {
            groupList.add(group);
        }
    }

    public ArrayList<User> getPossiblyInfectedUsers() {
        HashSet<User> possiblyInfectedUsers = new HashSet<>(friendList);
        for (User friend: friendList) {
            possiblyInfectedUsers.addAll(friend.friendList);
        }
        possiblyInfectedUsers.remove(this);
        return new ArrayList<>(possiblyInfectedUsers);
    }

    public void createPost(String content) {
        if (content.length() > 0) {
            Post post = new Post(this, content);
            postList.add(post);
        }
    }

    public ArrayList<Post> getPostFeed() {
        ArrayList<Post> sortedFeed = new ArrayList<>();
        sortedFeed.addAll(postList);
        for (User friend: friendList) {
            sortedFeed.addAll(friend.postList);
        }
        sortedFeed.sort(new PostComparator());
        return sortedFeed;
    }

    public ArrayList<User> getSuggestedFriends() {
        HashSet<User> suggestedFriends = new HashSet<>();
        for (User friend: friendList) {
            suggestedFriends.addAll(friend.friendList);
        }
        suggestedFriends.remove(this);
        suggestedFriends.removeAll(friendList);
        return new ArrayList<>(suggestedFriends);
    }

    @Override
    public boolean equals(Object object) {

        if (object.getClass() == this.getClass()) {
            User userToCheck  = (User) object;
            return userToCheck.name.equals(this.name) && userToCheck.email.equals(this.email);
        }
        return false;

    }

    @Override
    public String toString() {
        return "User{" + "name='" + name + '\'' + '}';
    }

    public String getName() {
        return name;
    }

    public String getEmail() {
        return email;
    }
}
