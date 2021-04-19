import java.util.Random;
import java.util.Scanner;

public class Connect4 {

    private char[] availableDiscs = {'x', 'o'};

    private Board board;

    private Player[] players = new Player[2];

    public Connect4() {
        // Default Players with disks
        players[0] = new Player("Player 1", availableDiscs[0]);
        players[1] = new Player("Player 2", availableDiscs[1]);
        // Default Board (6 rows, 7 columns)
        board = new Board();
    }

    public void setAvailableDisks(char char1, char char2) {
        this.availableDiscs = new char[] {char1, char2};
        // Reload new Defaults
        players[0] = new Player("Player 1", availableDiscs[0]);
        players[1] = new Player("Player 2", availableDiscs[1]);
    }

    public void readPlayerNames() {
        Scanner scanner = new Scanner(System.in);
        String input;

        for (int i = 0; i < players.length; i++) {

            while (true) {

                switch (i) {
                    case 0: System.out.print("Please enter the name of the 1st player: "); break;
                    case 1: System.out.print("Please enter the name of the 2nd player: "); break;
                }

                input = scanner.nextLine();
                if (!input.isBlank()) {
                    players[i] = new Player(input);
                    break;
                } else {
                    System.out.print("Incorrect input. ");
                }

            }

        }

    }

    public void readDiscs() {
        Scanner scanner = new Scanner(System.in);
        System.out.print(players[0].getName() + ", please select your chip (" + availableDiscs[0] + " or " + availableDiscs[1] + "): ");
        String selectedDisk = scanner.nextLine();

        if (selectedDisk.length() == 1) {

            if (selectedDisk.charAt(0) == availableDiscs[0]) {

                players[0].setDisc(availableDiscs[0]);
                players[1].setDisc(availableDiscs[1]);
                System.out.println(players[1].getName() + ", your chip is " + availableDiscs[1]);

            } else if (selectedDisk.charAt(0) == availableDiscs[1]) {

                players[0].setDisc(availableDiscs[1]);
                players[1].setDisc(availableDiscs[0]);
                System.out.println(players[1].getName() + ", your chip is " + availableDiscs[0]);

            } else {

                System.out.print("Incorrect Input. ");
                readDiscs();

            }

        }
    }

    public void readBoardSize() {
        Scanner scanner = new Scanner(System.in);
        int input;
        int columns;
        int rows;

        while (true) {
            System.out.print("Please enter the number of rows: ");
            input = scanner.nextInt();
            if (input >= 4 && input <= 15) {
                rows = input;
                break;
            } else {
                System.out.print("Incorrect input. ");
            }
        }

        while (true) {
            System.out.print("Please enter the number of columns: ");
            input = scanner.nextInt();
            if (input >= 4 && input <= 15) {
                columns = input;
                break;
            } else {
                System.out.print("Incorrect input. ");
            }
        }

        board = new Board(columns, rows);
    }

    private Player[] getRandomizedPlayers() {
        Random random = new Random();
        boolean toReverse = random.nextBoolean();

        if (toReverse) {
            return new Player[] { players[1], players[0] };
        }
        return players;
    }

    private void makeMove(Player player) {
        Scanner scanner = new Scanner(System.in);
        System.out.print(player.getName() + ", your turn. Select column: ");

        int input = scanner.nextInt();
        boolean success = board.addDiskToColumn(player.getDisc(), input-1);
        if ( !success ){
            System.out.print("Incorrect input. ");
            makeMove(player);
        }

        board.print();
    }

    public void run() {

        board.print();

        Player[] randomPlayers = getRandomizedPlayers();

        for (int moveCount = 0; moveCount < board.getMaxMoves(); moveCount++ ) {

            Player currentPlayer = randomPlayers[ moveCount%2 ];
            makeMove(currentPlayer);

            Evaluator evaluator = new Evaluator(board);

            boolean horizontalWin = evaluator.check(board.getPartialHorizontal());
            if ( horizontalWin ) {
                printPlayerWin(currentPlayer, evaluator.getResultBoard());
                break;
            }

            boolean verticalWin = evaluator.check(board.getPartialVertical());
            if ( verticalWin ) {
                printPlayerWin(currentPlayer, evaluator.getResultBoard());
                break;
            }

            boolean diagonalWin = evaluator.check(board.getPartialDiagonal());
            if ( diagonalWin ) {
                printPlayerWin(currentPlayer, evaluator.getResultBoard());
                break;
            }

            boolean diagonalWin2 = evaluator.check(board.getPartialReverseDiagonal());
            if ( diagonalWin2 ) {
                printPlayerWin(currentPlayer, evaluator.getResultBoard());
                break;
            }

            if (moveCount == board.getMaxMoves()-1) {
                System.out.println("GAMEOVER. WE HAVE A DRAW");
            }

        }

    }

    private void printPlayerWin(Player player, ResultBoard board) {
        board.print();
        System.out.println("GAMEOVER. THE WINNER IS " + player.getName());
    }

}

