public class Unit {
    protected int randMin = 1;
    protected int randMax = 100;
    protected int health =115;
    protected int defence =70;
    protected int power = 10;
    protected int crit = 10;
    protected float critChance = 0.2f;
    protected float ParryChance = 0.2f;

    public String getName() {
        return name;
    }

    protected   String name = "Knight";


    public int getHealth() {
        return health;
    }
    public void setHealth(int health) {
        this.health = health;
    }

    public void setDefence(int defence) {
        this.defence = defence;
    }

    public void setPower(int power) {
        this.power = power;
    }

    public void setCritChance(float critChance) {
        this.critChance = critChance;
    }

    public void setParryChance(float parryChance) {
        ParryChance = parryChance;
    }

    public int getDefence() {
        return defence;
    }

    public int getPower() {
        return power;
    }

    public float getCritChance() {
        return critChance;
    }

    public float getParryChance() {
        return ParryChance;
    }
    public static int rnd(int min, int max)
    {
        max -= min;
        return (int) (Math.random() * ++max) + min;
    }

    public void attack(Unit unit) {
        if (this.defence>0 && rnd(randMin,randMax)<=randMax*critChance) {
            System.out.println("ОГО у вас крит удар, вы наносите "+(this.power+crit)+" урона!");
            unit.getDamage(this.power+crit);
        } else {
            unit.getDamage(this.power);
        }
        if(defence>0) {
            this.defence -= 20;
        } else {
            this.defence+=10;
        }
    }

    @Override
    public String toString() {
        return "Knight" + " health=" + health + ", defence=" + defence +", power ="+power;
    }

    public void getDamage(int damage) {
        if (defence>=20 && rnd(randMin,randMax)<=randMax*ParryChance) {
            System.out.println("ОГО противник уворачивается от вашего удара!");
        } else {
            this.health -= damage;
            this.defence+=10;
        }
    }
    public boolean isDead() {
        return this.health<=0;
    }
    public void Heal() {
        if(isDead()) {
            this.health += 4;
            this.defence += 20;
        }
    }


}
