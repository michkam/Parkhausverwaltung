#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <time.h>

enum{ STRLEN = 50 };

typedef struct {
  char fID[STRLEN], title[STRLEN];
	unsigned int jahr, minuten, sekunden;
  
} Fahrzeug;



Fahrzeug befahren( void ) {
  Fahrzeug s;
	printf("FahrzeugID?: \n");
fgets(s.fID,STRLEN,stdin);
s.fID[strlen(s.fID)-1]='\0';
	
	return s;
 }


/* Diese Funktion gibt alle Fahrzeuge aus */
 void ausgeben( Fahrzeug Fahrzeug, int i ) {

	 printf("%.3d: %s \n", i+1, Fahrzeug.fID);
  
 }



int verlassen( Fahrzeug *parkhaus, int pos, int PLLEN ) {
    Fahrzeug p[PLLEN];
    int l=0;
	if(pos>PLLEN-1){     //falls gesuchte Position glößer als PLLEN des Arrays
		printf("Fehlermeldung! Eingegebene Position ist ungültig."); //gib Felher aus
      return PLLEN;	
	}
	parkhaus[pos-1]=p[l];  //gewünsche Position aus Array entfernen
	return PLLEN;	
  
 }



int fahrzeugsuchen( Fahrzeug *parkhaus, char *fID, int PLLEN ) {	
int i,y=0,j;
  for(i=0;i<PLLEN;i++){
    for(j=0;j<strlen(fID);){
  if(parkhaus[i].fID[j]==fID[j])
    j++;
  
    else
        j= 101;}
    if(j==strlen(fID)){
    ausgeben(parkhaus[i],i);
      y++;}
  }
      return y;
 }





int main( void ) {
  
int PLLEN= 100;     
Fahrzeug parkhaus[PLLEN];  
int laenge=0, fertig = 0;
char eingabe;
int pos;
char muster[PLLEN];
srand(time(NULL));
int antwort, rest=PLLEN;  
int etageAnzahl, maxFahrzeugPlaetze;

    
printf("Das Parkhaus verfügt momentan über %d Parkplaetze\n", PLLEN);    
printf("Möchten Das Parkhaus anpassen? (0:Ja, sonst:Nein)  ");
    scanf("%d",&antwort);
    if(antwort==0){
        printf("Wie viel Etage möchten Sie hinzufügen?  ");
        scanf("%d", &etageAnzahl);
        printf("Wie viel Fahrzeuge pro Etage?  ");
        scanf("%d", &maxFahrzeugPlaetze);
        PLLEN=PLLEN+(etageAnzahl*maxFahrzeugPlaetze);    
    printf("\nDas Parkhaus verfügt jetzt über %d Parkplaetze\n", PLLEN);  
printf("++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++");    
    }
     getchar();
     
printf("\n\nWas möchten Sie tun?\n");
  while ( !fertig ) {
    
   
   
    printf("b: Parkhaus befahren\n");
    printf("v: Parkhaus verlassen\n");
    printf("a: geparkte Fahrzeuge anzeigen\n");
    printf("s: Ein Fahrzeug suchen\n");
    printf("f: Anzahl freier Plaetze\n");
    printf("e: beenden\n\n");
    printf("Eingabe: ");
    
    scanf(" %c", &eingabe );
    getchar();
  
     
    switch( eingabe ) {
     // program endet

      case 'e': fertig = 1; break;
         
	  case 'b': parkhaus[laenge]= befahren();
                laenge++;
                   rest--;
                            break;
	
	  case 'a':   for(pos=0; pos<laenge; pos++)   // Fahrzeug der parkhaus komplett ausgeben
	  {
				    ausgeben(parkhaus[pos], pos);
                   
	  }
            printf("\n");
                            break;
         
	  case 'v':  printf("Welches Fahrzeug soll das Parkhaus verlassen? Geben Sie bitte die Position des Fahrzeug ein!\n");
	           scanf("%d", &pos);
		      PLLEN=verlassen(parkhaus,pos,PLLEN);
            printf("Das Fahzeug mit der Positionnummer %d hat das Parkhaus verlassen\n", pos);
            rest++;
 			 printf("\n");
                            break;
		
     case's':
        printf("FahrzeugID eingeben:\n");
        fgets(muster,PLLEN,stdin);// gewünscher FahrzeugID im parkhaus eingeben
        muster[strlen(muster)-1]='\0';
	printf("%d wurde(n) gefunden!\n\n",fahrzeugsuchen(parkhaus,muster,PLLEN));  // alle Fahrzeuge des gewünschen FahrzeugID aus parkhaus sortieren
       printf("\n");
	break;		
		
     case 'f':  printf("Es sind noch %d Plaetze frei\n", rest);
                            break;
                    
      default: printf("Funktion nicht verfuebar!\n\n");
    }
    
  }
  
  return 0;
}
        