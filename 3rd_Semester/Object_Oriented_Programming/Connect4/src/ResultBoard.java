import java.util.ArrayList;

public class ResultBoard extends Board {

    Board initialBoard;
    private static final char winIndicator = '@';

    public ResultBoard(Board initialBoard) {
        super(
                initialBoard.getBoardArray()[0].length,
                initialBoard.getBoardArray().length
        );
        this.initialBoard = initialBoard;
    }

    public void setWinningDisks(ArrayList<Location> list, char disk) {
        for (Location cell: list) {
            boardArray[cell.row][cell.column] = disk;
        }
    }

    public void setWinningDisks(ArrayList<Location> list) {
        for (Location cell: list) {
            boardArray = initialBoard.getBoardArray();
            boardArray[cell.row][cell.column] = winIndicator;
        }
    }

}
