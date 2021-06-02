import javax.swing.*;
import javax.swing.border.EtchedBorder;
import javax.swing.border.TitledBorder;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.util.ArrayList;

public class UserPage extends JFrame{

    private final LoginPage loginPage;

    private final JPanel panel, infoPanel, newPostPanel, postFeedPanel, friendsAndGroupsPanel;
    private final JTextArea usernameText, emailText, newPostText, postFeedText, suggestedFriendsText, newFriendText;
    private final JButton backButton, newPostButton, newFriendButton, joinGroupButton;
    private final JLabel suggestedFriendsLabel;
    private final JList<String> groupList;

    private final User user;
    private final DataManager dataManager;

    public UserPage(LoginPage loginPage, User user, DataManager dataManager) {

        this.loginPage = loginPage;
        this.user = user;
        this.dataManager = dataManager;

        // --INFO PANEL--
        usernameText = new JTextArea(user.getName());
        usernameText.setEditable(false);

        emailText = new JTextArea(user.getEmail());
        emailText.setEditable(false);

        backButton = new JButton("Back to Login Screen");
        backButton.addActionListener(new BackButtonListener());

        infoPanel = new JPanel(new GridLayout(1,3,10,10));
        infoPanel.setBorder(BorderFactory.createCompoundBorder(new EtchedBorder(), BorderFactory.createEmptyBorder(5,5,5,5)));
        infoPanel.add(usernameText);
        infoPanel.add(emailText);
        infoPanel.add(backButton);

        // --NEW POST PANEL--
        newPostText = new JTextArea("Enter Post Text Here\n\n\n");

        newPostButton = new JButton("Post");
        newPostButton.addActionListener(new PostButtonListener());

        newPostPanel = new JPanel(new BorderLayout());
        newPostPanel.setBorder(new TitledBorder( BorderFactory.createCompoundBorder(new EtchedBorder(), BorderFactory.createEmptyBorder(5,5,5,5)), "Create a new Post" ) );
        newPostPanel.add(newPostText, BorderLayout.CENTER);
        newPostPanel.add(newPostButton, BorderLayout.SOUTH);

        // --POST FEED PANEL--
        postFeedText = new JTextArea();
        postFeedText.setEditable(false);
        updatePostFeed();

        postFeedPanel = new JPanel(new BorderLayout());
        postFeedPanel.setBorder (new TitledBorder( BorderFactory.createCompoundBorder(new EtchedBorder(), BorderFactory.createEmptyBorder(5,5,5,5)), "Recent Posts by Friends" ) );
        postFeedPanel.add(postFeedText, BorderLayout.CENTER);

        // --FRIENDS AND GROUPS PANEL--

        // suggested friends
        suggestedFriendsLabel = new JLabel("Suggested Friends");

        suggestedFriendsText = new JTextArea();
        suggestedFriendsText.setEditable(false);
        updateSuggestedFriends();

        // add friends
        newFriendText = new JTextArea("Username");

        newFriendButton = new JButton("Add User as Friend");
        newFriendButton.addActionListener(new AddFriendButtonListener());

        // join groups
        groupList = new JList<>();
        updateGroups();

        joinGroupButton = new JButton("Join Group");
        joinGroupButton.addActionListener(new JoinGroupButtonListener());

        // panel setup
        friendsAndGroupsPanel = new JPanel(new GridLayout(2,3,15,5));
        friendsAndGroupsPanel.setBorder(BorderFactory.createCompoundBorder(new EtchedBorder(), BorderFactory.createEmptyBorder(5,5,5,5)));
        friendsAndGroupsPanel.add(suggestedFriendsLabel);
        friendsAndGroupsPanel.add(newFriendText);
        friendsAndGroupsPanel.add(groupList);
        friendsAndGroupsPanel.add(suggestedFriendsText);
        friendsAndGroupsPanel.add(newFriendButton);
        friendsAndGroupsPanel.add(joinGroupButton);


        // --MAIN PANEL SETUP--
        panel = new JPanel();
        panel.setBorder(BorderFactory.createEmptyBorder(5,10,10,10));
        panel.add(infoPanel);
        panel.add(Box.createVerticalStrut(15));
        panel.add(newPostPanel);
        panel.add(Box.createVerticalStrut(5));
        panel.add(postFeedPanel);
        panel.add(Box.createVerticalStrut(15));
        panel.add(friendsAndGroupsPanel);

        panel.setLayout(new BoxLayout(panel, BoxLayout.PAGE_AXIS));
        this.setContentPane(panel);

        this.setVisible(true);
        this.setSize(650,800);
        this.setLocationRelativeTo(null);
        this.setTitle("Είσοδος Χρήστη");
        this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
    }

    // --Methods for filling ui with data--

    private void updatePostFeed() {

        ArrayList<Post> postList = user.getPostFeed();
        String postFeedString = "";

        for (Post post: postList) {
            postFeedString += "-- " + post.getAuthor().getName() + ", " + post.getTimestamp().toString() + " --"+ "\n";
            postFeedString += "> " + post.getContent() + "\n\n";
        }

        if (postList.size() == 0) {
            postFeedText.setText("\n  No Recent Posts Found.");
        } else {
            postFeedText.setText(postFeedString);
        }
    }

    private void updateSuggestedFriends() {

        ArrayList<User> suggestedFriends = user.getSuggestedFriends();
        String suggestedString ="";

        for (User friend: suggestedFriends) {
            suggestedString+= friend.getName() + "\n";
        }

        suggestedFriendsText.setText(suggestedString.trim());
    }

    private void updateGroups() {
        DefaultListModel<String> model = new DefaultListModel<>();

        for (Group group : dataManager.getGroupList()) {

            String toAdd = group.getName();
            if (group.hasMember(user)) toAdd+= " ✓";
            model.addElement(toAdd);
        }
        groupList.setModel(model);
    }

    // --BUTTON LISTENERS--

    // Post Button
    class PostButtonListener implements ActionListener {

        @Override
        public void actionPerformed(ActionEvent actionEvent) {
            String content = newPostText.getText().trim();
            user.createPost(content);
            updatePostFeed();
            newPostText.setText("");
        }
    }

    // Add Friend Button
    class AddFriendButtonListener implements ActionListener {

        @Override
        public void actionPerformed(ActionEvent actionEvent) {
            try {

                String userString = newFriendText.getText();
                User friend = dataManager.getUsersMap().get(userString);
                user.addFriend(friend);

                System.out.println("Friend graph diameter is now " + dataManager.getFriendGraphDiameter());
                JOptionPane.showMessageDialog(null, "Successfully Added " + friend.getName() + " as a friend");
                updateSuggestedFriends();

            } catch (NullPointerException e) {
                JOptionPane.showMessageDialog(null, "Can't Find User: " + newFriendText.getText());
            } catch (IllegalArgumentException e) {
                JOptionPane.showMessageDialog(null, e.getMessage());
            }

        }
    }

    // Join Group Button
    class JoinGroupButtonListener implements ActionListener {

        @Override
        public void actionPerformed(ActionEvent actionEvent) {
            try {

                String selectedString = groupList.getSelectedValue().replaceAll(" ✓","");
                Group group = dataManager.getGroupMap().get(selectedString);

                group.addMember(user);

                JOptionPane.showMessageDialog(null, "Successfully Joined Group " + group.getName());
                updateGroups();

            } catch (NullPointerException e) {
                JOptionPane.showMessageDialog(null, "Please Choose A Group To Join");
            } catch (IllegalArgumentException e) {
                JOptionPane.showMessageDialog(null, e.getMessage());
            }
        }
    }
    // Back Button
    class BackButtonListener implements ActionListener {

        @Override
        public void actionPerformed(ActionEvent actionEvent) {
            loginPage.setVisible(true);
            UserPage.this.dispose();
        }
    }

}
