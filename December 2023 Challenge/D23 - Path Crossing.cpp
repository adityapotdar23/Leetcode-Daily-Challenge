class Solution {
public:
    bool isPathCrossing(string path) {
        unordered_set<string> visitedPoints;
        int currX = 0, currY = 0;
        visitedPoints.insert(to_string(currX)+","+to_string(currY));

        for(auto direction: path)
        {
            if(direction=='N')
            {
                currY++;
            }
            else if(direction=='S')
            {
                currY--;
            }
            else if(direction=='E')
            {
                currX++;
            }
            else
            {
                currX--;
            }

            if(visitedPoints.count(to_string(currX)+","+to_string(currY)))
            {
                return true;
            }

            visitedPoints.insert(to_string(currX) + "," + to_string(currY));
        }

        return false;
    }
};
