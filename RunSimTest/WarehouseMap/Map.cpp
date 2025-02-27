#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <nlohmann/json.hpp>

using json = nlohmann::json;

class Map {
public:
    struct Position {
        int x;
        int y;
    };

    struct Wall {
        Position start;
        Position end;
    };

    struct Obstacle {
        Position position;
    };

    Map(const std::string& jsonFilePath) {
        std::ifstream file(jsonFilePath);
        if (file.is_open()) {
            json j;
            file >> j;
            parseJson(j);
        } else {
            std::cerr << "Unable to open file: " << jsonFilePath << std::endl;
        }
    }

    const std::vector<Wall>& getWalls() const {
        return walls;
    }

    const std::vector<Obstacle>& getObstacles() const {
        return obstacles;
    }

    const std::vector<Position>& getCorridors() const {
        return corridors;
    }

private:
    std::vector<Wall> walls;
    std::vector<Obstacle> obstacles;
    std::vector<Position> corridors;

    void parseJson(const json& j) {
        for (const auto& wall : j["walls"]) {
            walls.push_back({{wall["start"]["x"], wall["start"]["y"]}, {wall["end"]["x"], wall["end"]["y"]}});
        }

        for (const auto& obstacle : j["obstacles"]) {
            obstacles.push_back({{obstacle["x"], obstacle["y"]}});
        }

        for (const auto& corridor : j["corridors"]) {
            corridors.push_back({corridor["x"], corridor["y"]});
        }
    }
};

int main() {
    Map map("map.json");

    // Example usage
    const auto& walls = map.getWalls();
    const auto& obstacles = map.getObstacles();
    const auto& corridors = map.getCorridors();

    // Print walls
    for (const auto& wall : walls) {
        std::cout << "Wall from (" << wall.start.x << ", " << wall.start.y << ") to ("
                  << wall.end.x << ", " << wall.end.y << ")\n";
    }

    // Print obstacles
    for (const auto& obstacle : obstacles) {
        std::cout << "Obstacle at (" << obstacle.position.x << ", " << obstacle.position.y << ")\n";
    }

    // Print corridors
    for (const auto& corridor : corridors) {
        std::cout << "Corridor at (" << corridor.x << ", " << corridor.y << ")\n";
    }

    return 0;
}