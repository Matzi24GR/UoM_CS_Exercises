import java.util.ArrayList;

public class Board {

    private static final char emptyCell = ' ';

    private int columns = 7;
    private int rows = 6;
    protected char[][] boardArray;
    private int[] counterArray;
    private Location lastMove;

    public Board() {
        initializeBoard();
    }
    public Board(int columns, int rows) {
        this.columns = columns;
        this.rows = rows;
        initializeBoard();
    }

    // 1. Set the board to the empty cell character
    // 2. Set the counter array to 0
    private void initializeBoard() {
        boardArray = new char[rows][columns];
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < columns; j++) {
                boardArray[i][j] = emptyCell;
            }
        }
        counterArray = new int[columns];
        for (int i = 0; i < columns; i++) {
            counterArray[i] = 0;
        }
    }

    public char[][] getBoardArray() {
        return boardArray;
    }

    public char getDiskAt(Location location) {
        return boardArray[location.row][location.column];
    }

    public boolean addDiskToColumn(char disk, int column) {
        if (column < 0 || column >= columns || counterArray[column] == rows) {
            return false;
        }
        int row = rows - counterArray[column]-1;
        boardArray[row][column] = disk;
        counterArray[column]++;
        lastMove = new Location(row, column);
        return true;
    }

    public Location getLastMove() {
        return lastMove;
    }


    public int getMaxMoves() {
        return columns*rows;
    }

    public void print() {
        // 1. Column Number Row
        for (int i = 1; i < columns+1; i++) {
            String toPrint;
            // Print number or dash for full columns
            if (counterArray[i-1] == rows) {
                toPrint = "-";
            } else {
                toPrint = String.valueOf(i);
            }
            System.out.print("  " + toPrint);
            // Add a space for single digit numbers
            // so the column numbering doesn't mess up
            if (toPrint.length() == 1) {
                System.out.print(" ");
            }
        }
        // 2. Horizontal Line
        System.out.println();
        for (int i = 0; i < columns; i++) {
            System.out.print("----");
        }
        System.out.println("-");
        // 3. Game Table
        for (char[] row: boardArray) {
            System.out.print("| ");
            for (char cell: row) {
                System.out.print(cell + " | ");
            }
            System.out.println();
        }
        // 4. Horizontal Line
        for (int i = 0; i < columns; i++) {
            System.out.print("----");
        }
        System.out.println("-");
    }

    // --- Methods For Getting Partial Lines From The Board (-3 +3 from last move) ---

    public ArrayList<Location> getPartialHorizontal() {

        ArrayList<Location> result = new ArrayList<>();

        // Left To Right (col asc)
        for (int column=lastMove.column-3; column<=lastMove.column+3; column++) {

            if ( column<0 ) continue;
            if ( column>=columns ) break;

            Location currentCell = new Location(lastMove.row, column);
            result.add(currentCell);

        }

        return result;

    }

    public ArrayList<Location> getPartialVertical() {

        ArrayList<Location> result = new ArrayList<>();

        // Top To Bottom (row asc)
        for (int row=lastMove.row-3; row<=lastMove.row+3; row++) {

            if ( row<0 ) continue;
            if ( row>=rows ) break;

            Location currentCell = new Location(row, lastMove.column);
            result.add(currentCell);

        }

        return result;

    }

    public ArrayList<Location> getPartialDiagonal() {

        ArrayList<Location> result = new ArrayList<>();

        // Top To Bottom (row asc)
        // Left To Right (col asc)
        for (int row = lastMove.row - 3, column = lastMove.column - 3; row <= lastMove.row + 3 && column <= lastMove.column + 3; row++, column++) {

            if (row < 0) continue;
            if (row >= rows) break;

            if (column < 0) continue;
            if (column >= columns) break;

            Location currentCell = new Location(row, column);
            result.add(currentCell);

        }

        return result;

    }

    public ArrayList<Location> getPartialReverseDiagonal() {

        ArrayList<Location> result = new ArrayList<>();

        // Top To Bottom (row asc)
        // Right To Left (col desc)
        for (int row = lastMove.row - 3, column = lastMove.column + 3; row <= lastMove.row + 3 && column >= lastMove.column - 3; row++, column--) {

            if (row < 0) continue;
            if (row >= rows) break;

            if (column < 0) break;
            if (column >= columns) continue;

            Location currentCell = new Location(row, column);
            result.add(currentCell);

        }

        return result;

    }

}
