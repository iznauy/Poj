#include <iostream>
#include <algorithm>
using namespace std;

struct Plant {
    int x, y;
} plants[5001];
int r, c, n;

int searchPath(Plant startPlant, int dx, int dy);

int main()
{
    cin >> r >> c >> n;
    for (int i = 0; i < n; i++)
        cin >> plants[i].x >> plants[i].y;

    int dx, dy, steps, max = 2;
    sort(plants, plants + n);

    for (int i = 0; i < n - 2; i++) {
        for (int j = i + 1; j < n - 1; j++) {
            dx = plants[j].x - plants[i].x;
            dy = plants[j].y - plants[i].y;
            int px = plants[i].x - dx;
            int py = plants[i].y - dy;
            if ((px >= 1) && (px <= r) && (py >= 1) && (py <= c))
                continue;
            if (plants[i].x + (max - 1) * dx > r)
                break;
            if ((plants[i].y + (max - 1) * dy > c) || (plants[i].y + (max - 1) * dx < 1))
                continue;
            steps = searchPath(plants[i], dx, dy);
            max = steps > max ? steps : max;
        }
    }

    cout << (max > 2 ? max : 0);
    return 0;

}

bool operator < (const Plant &p1, const Plant &p2)
{
    if (p1.x == p2.x)
        return p1.y < p2.y;
    return p1.x < p2.x;
}

int searchPath(Plant startPlant, int dx, int dy)
{
    Plant plant;
    int steps = 2;
    plant.x = startPlant.x + steps * dx;
    plant.y = startPlant.y + steps * dy;
    while (plant.x <= r && plant.x >= 1 && plant.y <= c && plant.y >= 1) {
        if (!binary_search(plants, plants + n, plant)) {
            steps = 0;
            break;
        }
        plant.x += dx;
        plant.y += dy;
        steps++;
    }
    return steps;
}

