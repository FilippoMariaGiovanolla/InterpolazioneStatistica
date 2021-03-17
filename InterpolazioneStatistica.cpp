#include <cstdlib>
#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
    const int max=75;// numero massimo di coppie di dati su cui il programma può fare l'interpolazione
    double x[max];// vettore contenente le variabili indipendenti
    double y[max];// vettore contenente le variabili dipendenti
    double Mx;// media dei valori contenuti nel vettore x
    double My;// media dei valori contenuti nel vettore y
    double Sx, Sy;// somma dei valori contenuti rispettivamente nel vettore x e nel vettore y
    double x1[max];// vettore contenente gli scarti di ogni elemento del vettore x dalla media Mx
    double y1[max];// vettore contenente gli scarti di ogni elemento del vettore y dalla media My
    double x1y1[max];// vettore contenente il prodotto degli scarti sopra definiti
    double x2[max];// vettore contenente il quadrato di ogni elemento del vettore x1
    double s;// somma di tutti gli elementi contenuti nel vettore x1y1
    double s1;// somma di tutti gli elementi contenuti nel vettore x2
    int num_coppie;// quantità di coppie di numeri che l'utente vuole elaborare
    double a;// termine noto della funzione interpolante finale
    double b;// coefficiente della x nella funzione interpolante finale
    char risp;//risposta dell'utente che dice se intende o meno proseguire con una nuova interpolazione
    Sx=0;
    Sy=0;
    s=0;
    s1=0;
    risp='n';
    cout<<"Per una trattazione teorica dell\'interpolazione statistica si legga "; 
    cout<<"il file     caricato sulla pagina Internet dedicata a questo software.";
    cout<<'\n';
    do
    {
     Sx=0;
     Sy=0;
     s=0;
     s1=0;
     risp='n'; 
     cout<<'\n';
     do
      {
        cout<<"E\' possibile elaborare al massimo " <<max <<" coppie di numeri; quante ne vuoi inserire? ";
        cout<<"Digita la risposta in cifre e premi invio" <<'\n';
        cin>> num_coppie;
      }// fine while che controlla l'inserimento dell'utente
     while(num_coppie<0 || num_coppie>max);
     cout<<'\n';
     for(int i=0;i<num_coppie;i++)
     {
        cout<<"Inserisci la variabile INDIPENDENTE (x) in posizione " <<i+1 <<" e premi invio" <<'\n';
        cin>> x[i];
        Sx=Sx+x[i];
        cout<<"Inserisci la variabile DIPENDENTE (y) in posizione " <<i+1 <<" e premi invio" <<'\n';
        cin>> y[i];
        Sy=Sy+y[i];
     } // fine for per l'inserimento delle coppie di numeri ed il calcolo della somma degli elementi di ciascun vettore
     Mx=Sx/num_coppie;
     My=Sy/num_coppie;
     for(int i=0;i<num_coppie;i++)
     {
        x1[i]=x[i]-Mx;
        y1[i]=y[i]-My;
        x1y1[i]=x1[i]*y1[i];
        s=s+x1y1[i];
        x2[i]=x1[i]*x1[i];
        s1=s1+x2[i];
     } // fine for per inserimento dati nei vettori x1,y1,x1y1,x2 e nelle variabili s ed s1
     b=s/s1;
     a=My-b*Mx;
     cout<<'\n';     
     cout<<"La funzione interpolante (nella forma y=a+bx) che risulta dalle coppie di numeri inseriti e\' ";
     if(b>0)
        cout<<"y="<<a <<"+" <<b <<"x"<<'\n';
     else
        if(b<0)
            cout<<"y="<<a <<b <<"x"<<'\n';
        else
            cout<<"y="<<a <<"   (coefficiente della x e\' 0)"<<'\n';
     cout<<'\n';
     cout<<"Vuoi proseguire con una nuova interpolazione? Rispondi con S o N e premi invio" <<'\n';
     cin>> risp;
    } // fine while consente all'utente di continuare con altre interpolazioni statistiche
    while(risp=='s' || risp=='S');
    cout<<'\n';
    system("PAUSE");
    return EXIT_SUCCESS;
}
