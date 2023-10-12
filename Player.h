#ifndef PLAYER_H
#define PLAYER_H

class Player {
public:
    double x_pos;
    double y_pos;
    double z_pos;

private:
    int hp {100};
    int currentDamage {1};

    void move(int direction, int distance);
    void shoot();
};

#endif
