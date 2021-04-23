class Board {
    public:
    void drawScene();
    int checkWin(int x, int y);
    int dropAtSpot(int playerID, int value);
    int map[7][6];
};