#ifndef ENGINE_H_INCLUDED
#define ENGINE_H_INCLUDED


class Engine
{
    public:
        int number_of_engines;
        virtual double Thrust(double h, double v) { return 0.0; } ;
};

class PistonEngine : public Engine
{
    public:
        double PSL;
        double eta_p;
        double SFC;
};

class TurbofanEngine : public Engine
{
    public:
        double TSL;
        double SFC;
};

class TurbopropEngine : public Engine
{
    public:
        double TSL;
        double PSL;
        double BSFC;
};



#endif // ENGINE_H_INCLUDED
