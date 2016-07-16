#include "aircraft.h"


void Aircraft::print()
{
    cout<<" ** PRINTING AICRAFT DATA **"<<endl;
    for (map<string, double>::iterator it=data.begin(); it!=data.end(); ++it)
    {
        string key = it->first;
        double value = it->second;
        //cout<<it->first<<" = "<<it->second<<endl;
        cout<<key<<" = "<<value<<endl;
    }
    cout<<" ** END PRINTING **"<<endl;
}


void Aircraft::computeData()
{
    double b = data["wing_span"];
    double S = data["wing_area"];
    double ar = (b*b) / S;
    data["wing_ar"] = ar;

    double cr = data["wing_root_chord"];
    double lambda = 2*S/(b*cr) - 1.;
    //if (lambda>1.) cerr<<"WARNING: lambda > 1"<<endl;
    data["wing_lambda"] = lambda;

    double lambda2 = lambda*lambda;
    double mac = (2./3.) * cr * (1.+lambda+lambda2) / (1+lambda);
    double yle = (b/6.) * (1+2.*lambda) / (1+lambda);
    double sweep_r = data["wing_sweep"]/180.*PI;
    double xle = data["wing_pos_apex_lon"] + yle * tan(sweep_r);
    data["wing_mac"] = mac;
    data["wing_xle"] = xle;
    data["wing_yle"] = 0.0;
}
