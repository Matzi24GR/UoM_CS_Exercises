import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.io.IOException;
import java.util.ArrayList;

public class LoginPage extends JFrame {

    private final JPanel panel;
    private final JTextField usernameField, emailField;
    private final JButton loginButton, infectionsButton, newUserButton, saveButton;
    private final JLabel namelabel, emailLabel;

    private final DataManager dataManager;

    public LoginPage(DataManager dataManager) {

        this.dataManager = dataManager;

        // Components
        namelabel = new JLabel("Please enter your name");

        usernameField = new JTextField("");
        usernameField.setMaximumSize(new Dimension(Integer.MAX_VALUE, 50));

        emailLabel = new JLabel("Please enter your email (Only for creating a new user)");

        emailField = new JTextField("");
        emailField.setMaximumSize(new Dimension(Integer.MAX_VALUE, 50));

        newUserButton = new JButton("New User");
        newUserButton.setMaximumSize(new Dimension(Integer.MAX_VALUE, 50));
        newUserButton.addActionListener(new NewUserButtonListener());

        loginButton = new JButton("Enter User Page");
        loginButton.setMaximumSize(new Dimension(Integer.MAX_VALUE, 50));
        loginButton.addActionListener(new UserPageButtonListener());

        infectionsButton = new JButton("Show Potential Infections");
        infectionsButton.setMaximumSize(new Dimension(Integer.MAX_VALUE, 50));
        infectionsButton.addActionListener(new InfectionsButtonListener());

        saveButton = new JButton("Save PamakBook");
        saveButton.setMaximumSize(new Dimension(Integer.MAX_VALUE, 50));
        saveButton.addActionListener(new SaveButtonListener());

        // Ordering
        panel = new JPanel();
        panel.add(namelabel);
        panel.add(Box.createVerticalStrut(5));
        panel.add(usernameField);
        panel.add(Box.createVerticalStrut(5));
        panel.add(emailLabel);
        panel.add(Box.createVerticalStrut(5));
        panel.add(emailField);
        panel.add(Box.createVerticalStrut(15));
        panel.add(loginButton);
        panel.add(Box.createVerticalStrut(5));
        panel.add(newUserButton);
        panel.add(Box.createVerticalStrut(20));
        panel.add(infectionsButton);
        panel.add(Box.createVerticalStrut(15));
        panel.add(saveButton);

        // Window Setup
        this.setContentPane(panel);
        panel.setLayout(new BoxLayout(panel, BoxLayout.PAGE_AXIS));
        panel.setBorder(BorderFactory.createEmptyBorder(10,10,10,10));

        this.setVisible(true);
        this.setSize(450,500);
        this.setLocationRelativeTo(null);
        this.setTitle("Σελίδα Χρήστη");
        this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
    }

    private User getUserFromInput() {
        String name = usernameField.getText();
        User validUser = null;
        try {
            for (User user: dataManager.getUserlist()) {
                if (user.getName().equals(name)) {
                    validUser = user;
                }
            }
        } catch (NullPointerException ignored) {}
        return validUser;
    }

    // --BUTTON LISTENERS--

    // Login Button
    class UserPageButtonListener implements ActionListener {

        @Override
        public void actionPerformed(ActionEvent actionEvent) {
            User user = getUserFromInput();
            if (user != null) {
                setVisible(false);
                UserPage userPage = new UserPage(LoginPage.this, user, dataManager);
            } else {
                JOptionPane.showMessageDialog(null, "User " + usernameField.getText() + " Not Found");
            }
        }
    }

    // New User Button
    class NewUserButtonListener implements ActionListener {

        @Override
        public void actionPerformed(ActionEvent actionEvent) {
            if ( !usernameField.getText().isBlank() ){
                if (getUserFromInput() == null) {
                    try {
                        dataManager.addUser(new User(usernameField.getText(), emailField.getText()));
                        JOptionPane.showMessageDialog(null, "Successfully created user: " + usernameField.getText());
                    } catch (IllegalArgumentException e) {
                        JOptionPane.showMessageDialog(null, "Invalid Email Format");
                    }
                } else {
                    JOptionPane.showMessageDialog(null, "User Already Exists");
                }
            }
        }
    }

    // Infections Button
    class InfectionsButtonListener implements ActionListener {

        @Override
        public void actionPerformed(ActionEvent actionEvent) {
            User user = getUserFromInput();
            if (user != null) {
                setVisible(false);
                InfectionPage infectionPage = new InfectionPage(LoginPage.this, user);
            } else {
                JOptionPane.showMessageDialog(null, "User " + usernameField.getText() + " Not Found");
            }
        }
    }

    // Save Button
    class SaveButtonListener implements ActionListener {

        @Override
        public void actionPerformed(ActionEvent actionEvent) {
            try {
                dataManager.saveData();
                JOptionPane.showMessageDialog(null, "Successfully Saved PamakBook");
            } catch (IOException e) {
                JOptionPane.showMessageDialog(null, "Save Failed");
            }
        }
    }

}

