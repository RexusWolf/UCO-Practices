#include <stdio.h>
#include <string.h>

#define NPROC 5

typedef struct params
{
    char nombre[10];
    int t_ejec;  // Se introducen
    int t_lleg;
    int t_com;   // Se calculan
    int t_fin;
    int t_ret;
    int t_esp;
    int t_rem;

} parametros;

int main(){

    int i, j, n = 5, quantum, flag = 0, time, remain = 5;
    int wait_time = 0 , turnaround_time = 0;

    // Inicialización de los datos de procesos
    parametros procesos[NPROC];
    strcpy(procesos[0].nombre, "A");
    procesos[0].t_ejec = 8;
    procesos[0].t_lleg = 0;
    procesos[0].t_com = 0;
    procesos[0].t_fin = procesos[0].t_ejec;
    procesos[0].t_ret = procesos[0].t_fin;
    procesos[0].t_esp = 0;
    procesos[0].t_rem = procesos[0].t_ejec;

    strcpy(procesos[1].nombre, "B");
    procesos[1].t_ejec = 4;
    procesos[1].t_lleg = 1;
    procesos[1].t_esp = 0;
    procesos[1].t_rem = procesos[1].t_ejec;

    strcpy(procesos[2].nombre, "C");
    procesos[2].t_ejec = 9;
    procesos[2].t_lleg = 2;
    procesos[2].t_esp = 0;
    procesos[2].t_rem = procesos[2].t_ejec;

    strcpy(procesos[3].nombre, "D");
    procesos[3].t_ejec = 5;
    procesos[3].t_lleg = 3;
    procesos[3].t_esp = 0;
    procesos[3].t_rem = procesos[3].t_ejec;

    strcpy(procesos[4].nombre, "E");
    procesos[4].t_ejec = 2;
    procesos[4].t_lleg = 4;
    procesos[4].t_esp = 0;
    procesos[4].t_rem = procesos[4].t_ejec;

 printf("Enter Time Quantum:\t");
 scanf("%d",&quantum);

 printf("\nProceso | t_comienzo | t_final | t_retorno | t_espera\n");
 printf("-------------------------------------------------------\n");
 for(time=0,i=0;remain!=0;)
 {
   procesos[i].t_com = time;
   if(procesos[i].t_rem<=quantum && procesos[i].t_rem>0)
   {
     time+=procesos[i].t_rem;
     procesos[i].t_rem=0;
     flag=1;
   }
   else if(procesos[i].t_rem>0)
   {
     procesos[i].t_rem-=quantum;
     time+=quantum;
   }
   if(procesos[i].t_rem==0 && flag==1)
   {
     procesos[i].t_fin = time;
     remain--;
     printf("   %s \t    %d \t\t %d \t   %d \t      %d\n",
     procesos[i].nombre,
     procesos[i].t_com,
     procesos[i].t_fin,
     time-procesos[i].t_lleg,
     time-procesos[i].t_lleg-procesos[i].t_ejec);

     wait_time+=time-procesos[i].t_lleg-procesos[i].t_ejec;
     turnaround_time+=time-procesos[i].t_lleg;
     flag=0;
   }
   if(i==n-1)
     i=0;
   else if(procesos[i+1].t_lleg<=time)
     i++;
   else
     i=0;
 }

 return 0;
}
