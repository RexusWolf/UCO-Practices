#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <string.h>

#define NPROC 5
using namespace std;
typedef struct params
{
    char nombre[10];
    int t_ejec;  // Se introducen
    int t_lleg;
    int t_com;   // Se calculan
    int t_fin;
    int t_ret;
    int t_esp;

} parametros;

/*
    this function is used for sorting all
    processes in increasing order of burst time
*/
bool comparison (parametros a, parametros b){
  return(a.t_ejec < b.t_ejec);
}

// function to find the waiting time for all processes
void findWaitingTime(parametros procesos[], int wt[])
{
    // waiting time for first process is 0
    wt[0] = 0;

    // calculating waiting time
    for (int i = 1; i < 5 ; i++)
    {
        wt[i] = procesos[i-1].t_ejec + wt[i-1] ;
    }
}

// function to calculate turn around time
void findTurnAroundTime(parametros procesos[], int wt[], int tat[])
{
    // calculating turnaround time by adding bt[i] + wt[i]
    for (int i = 0; i < 5; i++)
    {
        tat[i] = procesos[i].t_ejec + wt[i];
    }
}

// function to calculate average time
void findAverageTime(parametros procesos[])
{
    int wt[5], tat[5], total_wt = 0, total_tat = 0;

    // function to find waiting time of all processes
    findWaitingTime(procesos, wt);

    // function to find turn around time for all processes
    findTurnAroundTime(procesos, wt, tat);

    // display processes along with all details
    cout << "\nProcesses "<< " Burst time "
         << " Waiting time " << " Turn around time\n";

    // calculate total waiting time and total turn around time
    for (int i = 0; i < 5; i++)
    {
        total_wt = total_wt + wt[i];
        total_tat = total_tat + tat[i];
        cout << " " << procesos[i].nombre << "\t\t"
             << procesos[i].t_ejec << "\t " << wt[i]
             << "\t\t " << tat[i] <<endl;
    }

    cout << "Average waiting time = "
         << (float)total_wt / 5;
    cout << "\nAverage turn around time = "
         << (float)total_tat / 5;
}

int main(){

    int i;

    // Inicialización de los datos de procesos
    parametros procesos[NPROC];
    strcpy(procesos[0].nombre, "A");
    procesos[0].t_ejec = 8;
    procesos[0].t_lleg = 0;

    strcpy(procesos[1].nombre, "B");
    procesos[1].t_ejec = 4;
    procesos[1].t_lleg = 1;

    strcpy(procesos[2].nombre, "C");
    procesos[2].t_ejec = 9;
    procesos[2].t_lleg = 2;

    strcpy(procesos[3].nombre, "D");
    procesos[3].t_ejec = 5;
    procesos[3].t_lleg = 3;

    strcpy(procesos[4].nombre, "E");
    procesos[4].t_ejec = 2;
    procesos[4].t_lleg = 4;

    sort(procesos[0], procesos[4], comparison);

    printf("\nProceso | t_comienzo | t_final | t_retorno | t_espera\n");
    printf("-------------------------------------------------------\n");
    for(i=0; i< NPROC; i++)
    {
      printf("   %s \t    %d \t\t %d \t   %d \t      %d\n", procesos[i].nombre,procesos[i].t_com, procesos[i].t_fin, procesos[i].t_ret, procesos[i].t_esp);
    }

    findAverageTime(procesos);

    return 0;
}
