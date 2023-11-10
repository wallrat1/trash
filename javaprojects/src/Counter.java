public class Counter {
    private static int numberRound = 0;

    public static int getNumberRound() {
        return numberRound;
    }

    public static void setNumberRound(int numberRound) {
        Counter.numberRound = numberRound;
    }

    public static void plusRound() {
        setNumberRound(numberRound+1);
    }
    public static Player getActivePlayer() {
        return Game.getOnePlayer(numberRound%2);
    }
    public static Player getEnemyPlayer() {
        return Game.getOnePlayer((numberRound+1)%2);
    }
}
