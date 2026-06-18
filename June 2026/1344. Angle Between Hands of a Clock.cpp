double angleClock(int hour, int minutes) {
        double hourHandDeg= hour*30;
        hourHandDeg += (0.5*minutes);
        double minHandDeg = 6*minutes;
        double res = abs(minHandDeg-hourHandDeg);
        return min(res,360-res);
    }