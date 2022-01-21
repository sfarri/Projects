package prove02;

import java.awt.*;
import java.util.Random;

public class Human extends Creature implements Movable, Aware, Aggressor, Spawner{

    Human() {
        _health = 10;
        rand = new Random();
        dir = rand.nextInt(4);
        canSpawn = false;
    }
    @Override
    public void attack(Creature target) {
        if(target instanceof Animal || target instanceof Wolf) {
            target.takeDamage(5);
            if(target instanceof Animal) {
                this.canSpawn = true;
            }
        }
        if(target instanceof Plant) {
            target.canSpawn = true;
        }
    }

    @Override
    public void senseNeighbors(Creature above, Creature below, Creature left, Creature right) {
        //First check for Animals in the wolf's line of sight.
        switch (dir) {
            case 0:
                if(right != null) {
                    if (right instanceof Animal) {
                        return;
                    }
                    if(right instanceof Wolf || right instanceof Zombie) {
                        dir = 1;
                        return;
                    }
                }
                break;
            case 1:
                if (left != null) {
                    if(left instanceof Animal){
                        return;
                    }
                    if(left instanceof Wolf || left instanceof Zombie) {
                        dir = 0;
                        return;
                    }
                }
                break;
            case 2:
                if (below != null) {
                    if(below instanceof Animal) {
                        return;
                    }
                    if(below instanceof Wolf || below instanceof Zombie) {
                        dir = 3;
                        return;
                    }
                }
                break;
            case 3:
                if(above != null) {
                    if(above instanceof  Animal) {
                        return;
                    }
                    if(above instanceof Wolf || above instanceof Zombie) {
                        dir = 2;
                        return;
                    }
                }
                break;
            default:
                break;
        }
        //If the wolf isn't facing the target. Check all directions starting with above, clockwise

        if(above != null) {
            if(above instanceof Animal){
                this.dir = 3;
                return;
            }
            if(above instanceof Wolf || above instanceof Zombie) {
                dir = 2;
                return;
            }
        }
        if(right != null) {
            if(right instanceof Animal){
                this.dir = 0;
                return;
            }
            if(right instanceof Wolf || right instanceof Zombie) {
                dir = 1;
                return;
            }
        }
        if(below != null) {
            if(below instanceof Animal){
                this.dir = 2;
                return;
            }
            if(below instanceof Wolf || below instanceof Zombie) {
                dir = 3;
                return;
            }
        }
        if(left != null) {
            if(left instanceof Animal){
                this.dir = 1;
                return;
            }
            if(left instanceof Wolf || left instanceof Zombie) {
                dir = 0;
                return;
            }
        }
    }

    @Override
    Shape getShape() {
        return Shape.Circle;
    }

    @Override
    Color getColor() {
        return new Color(250, 125, 0);
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
            Human newHuman = new Human();
            newHuman.setLocation(new Point(_location.x - 1, _location.y));
            return newHuman;
        }
        return null;
    }
    Random rand;
    int dir;

}
