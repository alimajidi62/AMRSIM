#pragma once
class AMRvehicle
{
private:
    double length;
    double width;
    double height;
    double posX;
    double posY;
    bool isDriving;
    double nextPosX;
    double nextPosY;

public:
    // Constructor
    AMRvehicle(double l, double w, double h, double x, double y);

    // Getters
    double getLength() const { return length; }
    double getWidth() const { return width; }
    double getHeight() const { return height; }
    double getPosX() const { return posX; }
    double getPosY() const { return posY; }
    bool getIsDriving() const { return isDriving; }
    double getNextPosX() const { return nextPosX; }
    double getNextPosY() const { return nextPosY; }

    // Setters
    void setLength(double l) { length = l; }
    void setWidth(double w) { width = w; }
    void setHeight(double h) { height = h; }
    void setPosX(double x) { posX = x; }
    void setPosY(double y) { posY = y; }
    void setIsDriving(bool driving) { isDriving = driving; }
    void setNextPosX(double x) { nextPosX = x; }
    void setNextPosY(double y) { nextPosY = y; }

    // Method to update position
    void updatePosition(double x, double y) {
        posX = x;
        posY = y;
    }

    // Method to print vehicle info
    void printInfo() const; 
};

