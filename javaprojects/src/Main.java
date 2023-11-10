import java.util.Scanner;
import java.util.concurrent.TimeUnit;

public class Main {
    public static void main(String[] args) throws InterruptedException {
        Scanner in = new Scanner(System.in);
        Util.Hello();
        Util.InputPlayer();
        for (int i = 0; i < 3; i++) {
            Util.InputUnit(0,i+1);
        }
        for (int i = 0; i < 3; i++) {
            Util.InputUnit(1,i+1);
        }
        Unit target;
        Player activePlayer;
        Player enemyPlayer;
        Unit activeUnit;
        while (true) {
            activePlayer  = Counter.getActivePlayer();
            enemyPlayer = Counter.getEnemyPlayer();
            Util.PlayerHod(activePlayer);
            for(int i=0; i<3;i++) {
                activeUnit = activePlayer.getOneUnit(i);
                if (activeUnit.isDead()) {continue;}
                System.out.print("Кого атакавать юнитом: "); Util.UnitInfo(activeUnit);
                System.out.println("Колода врага: ");
                Util.ListUnitInfo(enemyPlayer);
                target =enemyPlayer.getOneUnit(Util.getTarget()) ;
                activeUnit.attack(target);
                TimeUnit.SECONDS.sleep(1);
                if(enemyPlayer.AllIsDead()) {
                    Util.Winner(activePlayer);
                    return;
                }
            }
            enemyPlayer.HealDeadUnits();
            Counter.plusRound();
        }
    }
}