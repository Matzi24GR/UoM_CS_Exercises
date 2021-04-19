public class ClosedGroup extends Group {

    private boolean isLocked = false;  // false until the first member enters then true

    public ClosedGroup(String name, String description) {
        super(name, description);
    }

    public void addMember(User user) {

        if ( isLocked ) {
            // Group Locked
            // check if user is eligible for entry
            boolean toAdd = false;
            for (User member: memberList) {
                if ( member.isFriendWith(user) )
                    toAdd = true;
            }
            if (toAdd)
                super.addMember(user);
            else
                //System.out.println("FAILED: " + user.getName() + " cannot be enrolled in group " + super.getName());
                throw new IllegalArgumentException("FAILED: " + user.getName() + " is not allowed to join group: " + getName());

        } else {
            // Group Unlocked
            // add user
            super.addMember(user);
            // lock the group
            isLocked = true;
        }

    }
}
