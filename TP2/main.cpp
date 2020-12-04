#include <iostream>
#include <cstring>
using namespace std;

//------------------------------------------------------ Include personnel
#include "Catalogue.h"
#include "Trajet.h"
#include "TrajetSimple.h"
#include "TrajetCompose.h"
#include "Etape.h"
#include "Liste.h"

char *getString () {
	char w = getc(stdin);
	char *s = new char[100];
	int i = 0;

	if (w != '\n') {
		s[i] = w;
		i++;
	}
	while ((w = getc(stdin)) != '\n') {
		s[i] = w;
		i++;
	}
	return s;
}

int main(){
	// const TrajetSimple *ts1 = new TrajetSimple("Lyon", "Hanoi", "bateau");

	// const TrajetSimple *ts2 = new TrajetSimple("Hanoi", "Paris", "avion");

	// const TrajetSimple *ts3 = new TrajetSimple("Bangkok", "Danang", "train");

	// Liste *L = new Liste;

	// L->AjouterTrajet(ts1);
	// L->AjouterTrajet(ts2);
	// L->AjouterTrajet(ts3);
	// L->Afficher();

	// const TrajetCompose *tc1 = new TrajetCompose(L->getPremiereEtape()->getTrajet()->getDepart(), 
	// 											 L->getDerniereEtape()->getTrajet()->getArrivee(), 
	// 											 L);
	// tc1->Afficher();
	// cout << tc1->getDepart() << " " << tc1->getArrivee() << endl;

	//Catalogue *C = new Catalogue;
	//C->AjouterTrajetSimple(ts1);
	//C->Afficher();

	Catalogue *C = new Catalogue;

	while (1) {
		cout << "\n";
		cout << "|***************************************|\n";
		cout << "| 1 - Ajouter Trajet Simple             |\n";
		cout << "| 2 - Ajouter Trajet Compose            |\n";
		cout << "| 3 - Afficher Catalogue                |\n";
		cout << "| 4 - Rechercher simple de parcours     |\n";
		cout << "| 5 - Rechercher avancee de parcourd    |\n";
		cout << "| 6 - Quitter l'application             |\n";
		cout << "| Que souhaitez-vous choisir ?          |\n";
	 	cout << "  "; 
		char option;
		cin >> option;

		if (option == '1') {
			char *villeDepart;
			char *villeArrivee;
			char *transport;

			cout << "Ville de depart : ";
			villeDepart = getString();
			cout << "Ville d'arrivee : ";
			villeArrivee = getString();
			cout << "Moyen de transport : ";
			transport = getString();

			const TrajetSimple *trajet_simple = new TrajetSimple(villeDepart, villeArrivee, transport);
			C->AjouterTrajetSimple(trajet_simple);

			trajet_simple->Afficher(); 
			cout << "a ete ajoute au catalogue.\n";
		} 
		else if (option == '2') {
			cout << "Entrez le nombre d'etapes que vous souhaitez deplacer (N > 1). N = ";
			int N; cin >> N;
			if (N < 2) {
				cout << "Il faut (N > 1). N = ";
				cin >> N;
			}

			Liste *L = new Liste;

			char *villeDepart;
			cout << "Ville de depart : ";
			villeDepart = getString();

			for (int i = 1; i <= N; i++) {
				char *villeSuivant;
				if (i < N) {
					cout << "Ville suivante : ";
				} else {
					cout << "Ville d'arrivee : ";
				}
				villeSuivant = getString();

				char *transport;
				cout << "Moyen de transport de etape " << i << " : ";
				transport = getString();

				const TrajetSimple *trajet_simple = new TrajetSimple(villeDepart, villeSuivant, transport);
				L->AjouterTrajet(trajet_simple);
				villeDepart = villeSuivant;
			}

			const TrajetCompose *trajet_compose = new TrajetCompose(L->getPremiereEtape()->getTrajet()->getDepart(), 
																	L->getDerniereEtape()->getTrajet()->getArrivee(), 
												 					L);
			C->AjouterTrajetCompose(trajet_compose);

			trajet_compose->Afficher(); 
			cout << "a ete ajoute au catalogue.\n";
		}
		else if (option == '3') {
			C->Afficher();
		}
		else if (option == '4') {
			
		}
		else if (option == '5') {
			
		}
		else if (option == '6') {
			cout << "Toutes les donnees seront perdues. Avez-vous encore besoin de quitter ce programme? (Y/N) ";
			char x;
			cin >> x;
			if (x == 'Y' || x == 'y') {
				cout << "BYE\n";
				break;
			}
		} else {
			cout << "Choix invalide. Entre 1 et 6, svp...\n";
		}
	}



	


	return 0;
}