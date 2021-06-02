import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.util.ArrayList;

public class UserPage extends JFrame{

    private LoginPage loginPage;

    private JPanel panel, infoPanel, newPostPanel, postFeedPanel, suggestedFriendsPanel, contentPanel;
    private JTextArea usernameText, emailText, newPostText, postFeedText, suggestedFriendsText;
    private JButton backButton, newPostButton;
    private JLabel postFeedLabel, suggestedFriendsLabel;

    private User user;

    public UserPage(LoginPage loginPage, User user) {

        this.loginPage = loginPage;
        this.user = user;

        // -INFO PANEL-
        usernameText = new JTextArea(user.getName());
        usernameText.setEditable(false);

        emailText = new JTextArea(user.getEmail());
        emailText.setEditable(false);

        backButton = new JButton("Back to Login Screen");
        backButton.addActionListener(new BackButtonListener());

        infoPanel = new JPanel(new GridLayout(1,3,10,10));
        infoPanel.setBorder(BorderFactory.createEmptyBorder(10,10,10,10));
        infoPanel.add(usernameText);
        infoPanel.add(emailText);
        infoPanel.add(backButton);

        // -NEW POST PANEL-
        newPostText = new JTextArea("Enter Post Text Here\n\n\n");

        newPostButton = new JButton("Post");
        newPostButton.addActionListener(new PostButtonListener());

        newPostPanel = new JPanel(new BorderLayout());
        newPostPanel.setBorder(BorderFactory.createEmptyBorder(10,10,10,10));
        newPostPanel.add(newPostText, BorderLayout.CENTER);
        newPostPanel.add(newPostButton, BorderLayout.SOUTH);

        // -POST FEED PANEL-
        postFeedLabel = new JLabel("Recent Posts by Friends");

        postFeedText = new JTextArea();
        postFeedText.setEditable(false);
        updatePostFeed();

        postFeedPanel = new JPanel(new BorderLayout());
        postFeedPanel.setBorder(BorderFactory.createEmptyBorder(10,10,10,10));
        postFeedPanel.add(postFeedLabel, BorderLayout.NORTH);
        postFeedPanel.add(postFeedText, BorderLayout.CENTER);

        // -SUGGESTED FRIENDS PANEL-
        suggestedFriendsLabel = new JLabel("Suggested Friends");

        suggestedFriendsText = new JTextArea();
        suggestedFriendsText.setEditable(false);

        ArrayList<User> suggestedFriends = user.getSuggestedFriends();
        String suggestedString ="";
        for (User friend: suggestedFriends) {
            suggestedString+= friend.getName() + "\n";
        }
        suggestedFriendsText.setText(suggestedString.trim());

        suggestedFriendsPanel = new JPanel();
        suggestedFriendsPanel.setBorder(BorderFactory.createEmptyBorder(10,10,10,10));
        suggestedFriendsPanel.add(suggestedFriendsLabel);
        suggestedFriendsPanel.add(suggestedFriendsText);


        // MAIN CONTENT PANEL
        contentPanel = new JPanel(new BorderLayout());
        contentPanel.add(newPostPanel, BorderLayout.NORTH);
        contentPanel.add(postFeedPanel, BorderLayout.CENTER);
        contentPanel.add(suggestedFriendsPanel, BorderLayout.SOUTH);


        // Window Setup
        panel = new JPanel();
        panel.add(infoPanel);
        panel.add(contentPanel);

        this.setContentPane(panel);
        panel.setLayout(new BoxLayout(panel, BoxLayout.PAGE_AXIS));

        this.setVisible(true);
        this.setSize(600,800);
        this.setLocationRelativeTo(null);
        this.setTitle("Είσοδος Χρήστη");
        this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
    }

    private void updatePostFeed() {
        ArrayList<Post> postList = user.getPostFeed();
        String postFeedString = "";
        for (Post post: postList) {
            postFeedString += post.getAuthor().getName() + ", " + post.getTimestamp().toString() + "\n";
            postFeedString += post.getContent() + "\n\n";
        }
        if (postList.size() == 0) {
            postFeedText.setText("\n  No Recent Posts Found.");
        } else {
            postFeedText.setText(postFeedString);
        }
    }

    class PostButtonListener implements ActionListener {

        @Override
        public void actionPerformed(ActionEvent actionEvent) {
            String content = newPostText.getText().trim();
            user.createPost(content);
            updatePostFeed();
            newPostText.setText("\n\n\n");
        }
    }

    class BackButtonListener implements ActionListener {

        @Override
        public void actionPerformed(ActionEvent actionEvent) {
            loginPage.setVisible(true);
            UserPage.this.dispose();
        }
    }

}
