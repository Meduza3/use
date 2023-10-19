#ifndef PLAYER_H
#define PLAYER_H

class Player {
public:
     void setXPos(double x_pos);
     double getXPos();
     void setYPos(double y_pos);
     double getYPos();
     void setZPos(double z_pos);
     double getZPos();

private:
    int hp {100};
    int currentDamage {1};
    double x_pos {0};
    double y_pos {0};
    double z_pos {0};

    void move(int direction, int distance);
    void shoot();
    
};

#endif
