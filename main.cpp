#include <iostream>

using namespace std;

void MinAtRow(int **t,int w, int k, int m[]) ///void MinimaWierszami(int t[][15],int w, int k, int m[]);
{
    int lowest;
    for(int i=0;i<w;i++)
    {
        lowest=t[w-1][0];
        for(int j=0;j<k;j++)
        {
            if(t[i][j]<lowest)
            lowest=t[i][j];
        }
        m[i]=lowest;
    }

}

template <typename T>
void WriteMulti_DimensionalArray(T **t,int r, int c)
{
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        {
            if(i%2)
            t[i][j]=(j+1)*2;
            else
            {
                t[i][j]=i;
            }
        }
    }

    t[r-3][c-3]=99;
    t[r-2][c-2]=-11;
    t[0][0]=-11;
    t[r-1][c-1]=99;

}
template <typename T>
void ShowMulti_DimensionalArray(T **t, int r, int c)
{
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        {
            cout<<"["<<i<<"]["<<j<<"]: "<<t[i][j]<<"  ";
        }
        cout<<endl<<endl;
    }
}
template <typename T>
void ShowArray(T tab, int Size)
{
        for(int i=0;i<Size;i++)
    {
        cout<<"["<<i<<"]"<<tab[i]<<endl;
    }
    cout<<endl<<endl<<endl;
}


void ClearArray(double *tab, int Size)
{
    for(int i=0;i<Size;i++)
    {
        tab[i]=0;
    }
}

void SumColumns(double **t,int r, int c, double *s) //void SumyKolumnami(double t[][5],int w, int k, double s[]);
{
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        {
            s[j]+=t[i][j];
        }
    }
}


template <typename T>
double SumMatrixElements(T **tab, int r, int c)
{
    double sum=0;
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        {
            sum+=tab[i][j];
        }
    }
    return sum;

}


void SeparatingText(char c, string s)
{
    int n=100;
    cout<<endl<<endl;
    while(n>50)
    {
        cout<<c;
        n--;
    }
    cout<<s;
        while(n>0)
    {
        cout<<c;
        n--;
    }
    cout<<endl<<endl;
}

int main()
{
    SeparatingText('-', "Task 9");
    //Testing task number 9
        int r = 15;
        int c = 15;
        int **tab = new int*[r];
        for(int i=0;i<r;i++)
            tab[i] = new int[c];

        int *t = new int[r];
        WriteMulti_DimensionalArray(tab, r, c);
        ShowMulti_DimensionalArray(tab, r, c);
        MinAtRow(tab,r,c,t);
        cout<<endl<<endl<<"Min value in rows: "<<endl;
        ShowArray(t,r);

    SeparatingText('-', "Task 10");

    //Testing task number 10
        int r_d = 5;
        int c_d = 5;
        double *s = new double[c_d];
        double **sab = new double*[r_d];
        for(int i=0;i<r_d;i++)
            sab[i] = new double[c_d];

        ClearArray(s,c_d);
        WriteMulti_DimensionalArray(sab, r_d, c_d);
        ShowMulti_DimensionalArray(sab, r_d, c_d);
        SumColumns(sab,r_d,c_d,s);

        cout<<endl<<endl<<"Sum of columns: "<<endl;
        ShowArray(s,c_d);

    SeparatingText('-', "Task 11");

    //Testing task number 11
    int Mtab_r = 5;
    int Mtab_c = 5;
    double **Mtab = new double*[Mtab_r];
    for(int i=0;i<Mtab_r;i++)
        Mtab[i] = new double[Mtab_c];

    WriteMulti_DimensionalArray(Mtab,Mtab_r, Mtab_c);
    ShowMulti_DimensionalArray(Mtab,Mtab_r,Mtab_c);
    cout<<"Sum of matrix elements = " <<SumMatrixElements(Mtab, Mtab_r, Mtab_c)<< endl;


    SeparatingText('-', "");
    //deleting array
    for(int i=0;i<r;i++)
        delete [] tab[i];

    delete [] tab;
    delete [] t;

    for(int i=0;i<r_d;i++)
        delete [] sab[i];

    delete [] sab;
    delete [] s;


    for(int i=0;i<Mtab_r;i++)
        delete [] Mtab[i];

    delete [] Mtab;
    return 0;
}
