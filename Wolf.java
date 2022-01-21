package prove02;

import java.awt.*;
import java.util.Random;

public class Wolf extends Creature implements Movable, Aware, Aggressor, Spawner {

    public Wolf() {
        _health = 1;
        rand = new Random();
        dir = rand.nextInt(4);
        canSpawn = false;
    }

    @Override
    public void attack(Creature target) {
        if(target instanceof Animal || target instanceof Human) {
            target.takeDamage(5);
            if(target instanceof Animal){
                this.canSpawn = true;
            }
        }
    }

    @Override
    public void senseNeighbors(Creature above, Creature below, Creature left, Creature right) {

        //First check for Animals in the wolf's line of sight.
        switch (dir) {
            case 0:
                if(right != null) {
                    if (right instanceof Animal || right instanceof Human) {
                        return;
                    }
                }
                break;
            case 1:
                if (left != null) {
                    if(left instanceof Animal || left instanceof Human){
                        return;
                    }
                }
                break;
            case 2:
                if (below != null) {
                    if(below instanceof Animal || below instanceof Human) {
                        return;
                    }
                }
                break;
            case 3:
                if(above != null) {
                    if(above instanceof Animal || above instanceof Human) {
                        return;
                    }
                }
                break;
            default:
                break;
        }
        //If the wolf isn't facing the target. Check all directions starting with above, clockwise

        if(above != null) {
            if(above instanceof Animal || above instanceof Human){
                this.dir = 3;
                return;
            }
        }
        if(right != null) {
            if(right instanceof Animal || right instanceof Human){
                this.dir = 0;
                return;
            }
        }
        if(below != null) {
            if(below instanceof Animal || below instanceof Human){
                this.dir = 2;
                return;
            }
        }
        if(left != null) {
            if(left instanceof Animal || left instanceof Human){
                this.dir = 1;
                return;
            }
        }
    }

    @Override
    Shape getShape() {
        return Shape.Square;
    }

    @Override
    Color getColor() {
        return new Color(96, 96, 96);
    }

    @Override
    Boolean isAlive() {
        return _health > 0;
    }

    @Override
    public void move() {

        switch(dir) {
            case 0:
                _location.x++;
                break;
            case 1:
                _location.x--;
                break;
            case 2:
                _location.y++;
                break;
            case 3:
                _location.y--;
                break;
            default:
                break;
        }
    }

    @Override
    public Creature spawnNewCreature() {
        if(canSpawn) {
            canSpawn = false;
            Wolf newWolf = new Wolf();
            newWolf.setLocation(new Point(_location.x - 1, _location.y));
            return newWolf;
        }
        return null;
    }

    Random rand;
    int dir;
}
