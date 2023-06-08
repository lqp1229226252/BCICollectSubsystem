#ifndef IIRFILTER_H
#define IIRFILTER_H
#include<QString>
#include<QDebug>
class IIRFILTER
{
public:
    static const int N=11;
    int N_IIR=5;
    IIRFILTER();
    void initW();
    //70Hz的低通滤波
    double bl[5][3] = {
        {
           0.4314910061647,                 0,                 0
        },
        {
                         1,                 2,                 1
        },
        {
           0.3112377257993,                 0,                 0
        },
        {
                         1,                 2,                 1
        },
        {
                         1,                 0,                 0
        }
      };
     double al[5][3] = {
        {
                         1,                 0,                 0
        },
        {
                         1,   0.2723753556633,   0.4535886689957
        },
        {
                         1,                 0,                 0
        },
        {
                         1,   0.1964664038167,  0.04848449938038
        },
        {
                         1,                 0,                 0
        }
      };
     double bh[5][3] = {
      {
         0.9951749097956,                 0,                 0
      },
      {
                       1,                -2,                 1
      },
      {
         0.9884847019825,                 0,                 0
      },
      {
                       1,                -2,                 1
      },
      {
                       1,                 0,                 0
      }
    };
     double ah[5][3] = {
      {
                       1,                 0,                 0
      },
      {
                       1,   -1.990271241662,   0.9904283975206
      },
      {
                       1,                 0,                 0
      },
      {
                       1,   -1.976891354287,   0.9770474536429
      },
      {
                       1,                 0,                 0
      }
    };
    //带通
    double b_band[5][3] = {
      {
         0.5885328063491,                 0,                 0
      },
      {
                       1,                 0,                -1
      },
      {
         0.5885328063491,                 0,                 0
      },
      {
                       1,                 0,                -1
      },
      {
                       1,                 0,                 0
      }
    };
    double a_band[5][3] = {
      {
                       1,                 0,                 0
      },
      {
                       1,   -1.982229221321,   0.9823873691001
      },
      {
                       1,                 0,                 0
      },
      {
                       1,   0.2156413940988,    0.182322903007
      },
      {
                       1,                 0,                 0
      }
    };

    double matrixh[32][5][3];
    double matrixl[32][5][3];



    double iir(double *a, double *b, double *w, double xin, int N_IIR);
    double B_filter(int i,double xn);
    int n_N=20;
    double x[32][21];
    double y[32][21];

};

#endif // IIRFILTER_H
