import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.util.ArrayList;

public class LoginPage extends JFrame {

    private JPanel panel;
    private JTextField usernameField;
    private JButton loginButton, infectionsButton;
    private JLabel label;

    private ArrayList<User> userList;

    public LoginPage(ArrayList<User> userList) {

        this.userList = userList;

        // Components
        usernameField = new JTextField("");
        usernameField.setMaximumSize(new Dimension(Integer.MAX_VALUE, 50));

        loginButton = new JButton("Enter User Page");
        loginButton.setMaximumSize(new Dimension(Integer.MAX_VALUE, 50));
        loginButton.addActionListener(new UserPageButtonListener());

        infectionsButton = new JButton("Show Potential Infections");
        infectionsButton.setMaximumSize(new Dimension(Integer.MAX_VALUE, 50));
        infectionsButton.addActionListener(new InfectionsButtonListener());

        label = new JLabel("Please enter your name");

        // Ordering
        panel = new JPanel();
        panel.add(label);
        panel.add(Box.createVerticalStrut(5));
        panel.add(usernameField);
        panel.add(Box.createVerticalStrut(20));
        panel.add(loginButton);
        panel.add(Box.createVerticalStrut(5));
        panel.add(infectionsButton);

        // Window Setup
        this.setContentPane(panel);
        panel.setLayout(new BoxLayout(panel, BoxLayout.PAGE_AXIS));
        panel.setBorder(BorderFactory.createEmptyBorder(10,10,10,10));

        this.setVisible(true);
        this.setSize(400,400);
        this.setLocationRelativeTo(null);
        this.setTitle("Σελίδα Χρήστη");
        this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
    }

    private User getUserFromInput() {
        String name = usernameField.getText();
        User validUser = null;
        for (User user: userList) {
            if (user.getName().equals(name)) {
                validUser = user;
            }
        }
        if (validUser == null) {
            JOptionPane.showMessageDialog(null, "User " + name + " Not Found");
        }
        return validUser;
    }

    class UserPageButtonListener implements ActionListener {

        @Override
        public void actionPerformed(ActionEvent actionEvent) {
            User user = getUserFromInput();
            if (user != null) {
                setVisible(false);
                UserPage userPage = new UserPage(LoginPage.this, user);
            }
        }
    }

    class InfectionsButtonListener implements ActionListener {

        @Override
        public void actionPerformed(ActionEvent actionEvent) {
            User user = getUserFromInput();
            if (user != null) {
                setVisible(false);
                InfectionPage infectionPage = new InfectionPage(LoginPage.this, user);
            }
        }
    }

}

