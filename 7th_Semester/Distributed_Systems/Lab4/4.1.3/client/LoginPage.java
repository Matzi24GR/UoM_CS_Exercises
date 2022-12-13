import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.rmi.*;
import java.rmi.registry.*;
import java.util.Objects;

public class LoginPage extends JFrame {

    private final JPanel panel;
    private final JTextField usernameField, passwordField;
    private final JButton loginButton;
    private final JLabel usernamelabel, passwordLabel;

    public LoginPage() {


        // Components
        usernamelabel = new JLabel("Username");

        usernameField = new JTextField("");
        usernameField.setMaximumSize(new Dimension(Integer.MAX_VALUE, 50));

        passwordLabel = new JLabel("Password");

        passwordField = new JTextField("");
        passwordField.setMaximumSize(new Dimension(Integer.MAX_VALUE, 50));

        loginButton = new JButton("Login");
        loginButton.setMaximumSize(new Dimension(Integer.MAX_VALUE, 50));
        loginButton.addActionListener(new LoginButtonListener());

        // Ordering
        panel = new JPanel();
        panel.add(usernamelabel);
        panel.add(Box.createVerticalStrut(5));
        panel.add(usernameField);
        panel.add(Box.createVerticalStrut(5));
        panel.add(passwordLabel);
        panel.add(Box.createVerticalStrut(5));
        panel.add(passwordField);
        panel.add(Box.createVerticalStrut(15));
        panel.add(loginButton);

        // Window Setup
        this.setContentPane(panel);
        panel.setLayout(new BoxLayout(panel, BoxLayout.PAGE_AXIS));
        panel.setBorder(BorderFactory.createEmptyBorder(10,10,10,10));

        this.setVisible(true);
        this.setSize(450,500);
        this.setLocationRelativeTo(null);
        this.setTitle("Bank System");
        this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
    }

    String getUsername() {
        return usernameField.getText();
    }

    String getPassword() {
        return passwordField.getText();
    }

    // Login Button
    class LoginButtonListener implements ActionListener {

        @Override
        public void actionPerformed(ActionEvent actionEvent) {
            try {
                Registry registry = LocateRegistry.getRegistry(BankClient.HOST, BankClient.PORT);
                String rmiObjectName = "Bank";
                BankRPC ref = new BankRPC();
                String result = ref.login(getUsername(), getPassword());
                System.out.println(result);
                if (Objects.equals(result, "OK")) {
                    setVisible(false);
                    MainPage mainPage = new MainPage(getUsername());
                } else {
                    JOptionPane.showMessageDialog(null, "ERROR");
                }
            } catch (Exception e) {
                System.out.println(e);
            }

        }
    }

}