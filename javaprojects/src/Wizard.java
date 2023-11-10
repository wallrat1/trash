public class Wizard extends Unit {
    private int mana = 60;
    public Wizard() {
        this.power = 25;
        this.defence=50;
        this.health=60;
        this.name = "Wizard";
    }

    @Override
    public String toString() {
        return "Wizard" + " health=" + health + ", defence=" + defence +", mana="+mana+", power ="+power;
    }

    @Override
    public void attack(Unit unit){
        if(this.mana>0){
            this.mana-=10;
            super.attack(unit);
        } else {
            System.out.println("Нет маны - нет урона(((");
        }

    }
    @Override
    public void getDamage(int damage) {
        int temp = this.health;
        if (this.mana<=0) {
            mana+=10;
        }
        super.getDamage(damage);
        if(this.health == temp) {
            mana-=10;
        }
    }
    @Override
    public void Heal() {
        if(isDead()) {
            this.health += 2;
            this.defence += 5;
        }
    }
}
