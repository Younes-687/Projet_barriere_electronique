// Nom du fichier:Barrire Automatix
// Auteur : WAri Ali et Younes Abdellaoui
// Date de crŽation: Mars 2022
// Version: final
// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// Description :
// Le programme comporte deux modes: le mode manuel et le mode automatique.
// On accede au mode manuel en suivant les instructions qui s'affichent sur l'ecrant.
// En choisissant le mode manuel, la barriere s'ouvre des qu'on appuie sur le capteur s1 et se referme lorsque la voiture s'en eloigne de la barrire.
// En choisissant le mode automatique, la barriere ne s'ouvre que quand les capteurs ultrasons detectent la presence d'un vehicule <10cm , un code secret est alors
// demander au conducteur.
// Si le code est correct, la bariere s'ouvre sinon elle reste fermer.
// ----------------------------------------------------------------------------------------------------------------------
// Manuel d'utilisation :
// -Appuyer sur les boutons droit et gauche simultanement jusqu'apparition de nouvelles instructions ˆ l'ecran.
// Et on entre directement dans le mode manuel
//     * En mode manuel , le programme marche normalement sans aucune restriction.
//     * Il suffit d'appuyer sur le capteur S1 et  la barierre  s'ouvre
//       et ne se ferme qu'une fois que si l'objet s'en eloigne de la barrire.
// -Le choix du bouton du bas  donne acces au mode automatique.
//     * Ce mode permet une utilisation plus securiser de la barriere.
//     * Pour y acceder, un code secret qui correspond ˆ une combinaison des boutons  ˆ entrer.
//     * Voici le code secret:bouton droite , bouton gauche,bouton droite, bouton entrer.
// -Si vous vous voulez arreter le programme pour une raison ou pour une autre,
//  vous devez rentrer la combinaison des boutons  suivantes :bouton haut et bouton bas simultanement(vous irez dans le mode 3)
// -Ensuite vous devez confirmer votre choix (arreter le programme) en cliquant sur un bouton droit ou gauche n'importe lequel.
//========================================================================================================================

task main()
{

int mode;
mode = 0;
int capteur1;
float distance1,distance2;
int etat=0;
SensorType[S4]= sensorEV3_Color;
SensorType[S2] = sensorEV3_Ultrasonic;
SensorType[S3] = sensorEV3_Ultrasonic;
    capteur1 = SensorValue[S1];
		distance1 = getUSDistance(S2);
		distance2 = getUSDistance(S3);

while (getButtonPress(buttonLeft) == false || getButtonPress(buttonRight)==false){
	displayCenteredTextLine( 8 , " Projet Barriere Automatix"  );
sleep(1000);
}
displayCenteredTextLine( 8 , " Demmarage du projet... " ) ;
sleep(1500);
    // Tant qu'on appuie sur les deux boutons (droite et gauche ) en meme temps il demarre le programme :(1)



while ( getButtonPress(buttonLeft)==false || getButtonPress(buttonRight)==false){
//si on fait le (1) on sera dans le mode manuel c'est a dire le mode == 0
		while( mode == 0){
		displayCenteredTextLine( 8 , "mode manuel");
            //Tant que mode = 0 Ça affiche mode manuel
		if (getButtonPress(buttonDown) == true){
			mode = 1;
            //Si on appuie le bouton du haut le programmme nous envoie au mode automatique c'est a dire mode=1
		}

		if (SensorValue[S1] == 1){
		setMotorTarget(motorA, 90, 50);
		displayCenteredTextLine(10 , "Bienvenue");
		sleep(2000);
// Si on appuie sur le capteur S1 la barrière s'ouvre à 90° avec 50% de sa vitesse

	}
		distance1 = getUSDistance(S2);
		distance2 = getUSDistance(S3);
		if (distance1 > 10 && distance2 >10){
			setMotorTarget(motorA,0,50);
				displayCenteredTextLine(10 , "Barriere fermer");
			sleep(2000);
            // si la distance 1 et la distance2 de l'objet sont superieur à 10 cm la barrière se ferme à 0° avec 50% de sa vitesse

		}
      if( getButtonPress(buttonUp)==true && getButtonPress(buttonDown)==true){
                    mode=3;
                  }
                          // si on appuie le bouton du haut et du bas en meme temps le mode = 3 et si le mode = 3 le programme s'arrete

	if (mode == 3 ) {
		displayCenteredTextLine( 8 ," Arret du programme");
			displayCenteredTextLine(10,"confirmez vous l'arret ?");
	}


		while ( mode == 1){
		displayCenteredTextLine ( 8 , " mode Automatique");
			displayCenteredTextLine( 10, "Entrez le code");
			sleep(100);
            //Tant que le mode =1 le programme affiche le mode automaique
		if (getButtonPress(buttonUp) == true ) {
			mode = 0;

            //Tant qu'on appuie sur le bouton d'en bas le programme nous envoie a la mode manuel cest a dire mode=0;
		}
				if( getButtonPress(buttonRight)== true  && ( etat==0)) {
                    //si le bouton droit est appuyé et que etat =0;on passe a etat = 1
			etat=1;
			}
			sleep(200);
			if (getButtonPress(buttonLeft)==true && ( etat ==1 )){
                // si on appuie le bouton gauche et que etat = 1; on passe a etat = 2;
				etat=2;
				}
				sleep(200);
				if (getButtonPress(buttonRight)==true && (etat==2)) {
					etat=3;
                    // si on appuie le bouton droite et que etat = 2; on passe a etat = 3;
					}
					sleep(200);
					if (getButtonPress(buttonEnter)==true && (etat==3)){
						etat=4;}
            // si on appuie le bouton d'entrer et que etat = 3; on passe a etat = 4; et si etat = 4 il nous demande le code
						sleep(200);
						if (etat==4) {
                            // si etat = 4 alors
								distance1 = getUSDistance(S2);
		distance2 = getUSDistance(S3);
				if (distance1 < 10 && distance2 <10){
			setMotorTarget(motorA,90,50);
				displayCenteredTextLine(10 , "Bienvenue");
		sleep(2000);
                    //si la distance1 et la distance2 sont inferieur a 10cm alors la barrière s'ouvre a 90° avec une vitessse de 50% de sa puissance et affiche bienvenue

		}
		if (distance1 < 10) {
			setMotorTarget(motorA,90,50);
			displayCenteredTextLine(10 , "Bienvenue");
		sleep(2000);
            // si la distance1 est inferieure a 10cm la barrière s'ouvre a 90° avec une vitesse de 50% de sa puissance et affiche bienvenue
		}
		if(distance2 < 10) {
			setMotorTarget(motorA,90,50);
			displayCenteredTextLine(10 , "Bienvenue");
		sleep(2000);
            // si la distance2 est inferieure a 10cm la barrière s'ouvre a 90° avec une vitesse de 50% de sa puissance et affiche bienvenue
		}
			distance1 = getUSDistance(S2);
		distance2 = getUSDistance(S3);
		if (distance1 > 10 && distance2 >10){
			setMotorTarget(motorA,0,50);

			etat=0;
            // si la distance1 et la distance2 sont superieur a 10cm la barrière se referme a 0° avec une vitesse de 50% de sa vitesse , afffiche fermeture et etat se remet a zero(0)

	}
}
if( getButtonPress(buttonUp)==true && getButtonPress(buttonDown)==true){
                    mode=3;
                  }
                          // si on appuie le bouton du haut et du bas en meme temps le mode = 3 et si le mode = 3 le programme s'arrete avec la confirmation de l'utilisateur en cliquant sur un bouton droit ou gauche.

	if (mode == 3 ) {
		displayCenteredTextLine( 8 ," Arret du programme");
		displayCenteredTextLine(10,"confirmez vous l'arret ?");
	}
}
}
}


}
