import java.util.Vector;

public class Player {

    int hp = 100;
    int currentDamage = 1;

    double x_pos;
    double y_pos;
    double z_pos;

    Camera camera;

    void move(int direction, int distance){
        System.out.println("Moving in " + direction + ":" + distance);
    }

    void shoot(){
        //Shoot hitscan middle of camera
    }

};