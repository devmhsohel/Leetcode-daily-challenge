bool isReachableAtTime(int sx, int sy, int fx, int fy, int t){
    int xd = abs(sx - fx), yd = abs(sy - fy);
    if (xd == 0 && yd == 0 && t == 1)
        return false;
    return t >= (xd > yd ? xd : yd);
}