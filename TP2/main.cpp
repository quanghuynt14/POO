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


int main(){
	// const TrajetSimple *ts1 = new TrajetSimple("A", "B", "1");

	// const TrajetSimple *ts2 = new TrajetSimple("B", "C", "1");

	// const TrajetSimple *ts3 = new TrajetSimple("B", "Y", "3");
	// const TrajetSimple *ts4 = new TrajetSimple("Y", "C", "2");
	// Liste *L1 = new Liste;
	// L1->AjouterTrajet(ts3);
	// L1->AjouterTrajet(ts4);
	// const TrajetCompose *tc1 = new TrajetCompose(L1->getPremiereEtape()->getTrajet()->getDepart(), 
	// 											 L1->getDerniereEtape()->getTrajet()->getArrivee(), 
	// 											 L1);

	// const TrajetSimple *ts5 = new TrajetSimple("A", "Z", "2");
	// const TrajetSimple *ts6 = new TrajetSimple("Z", "C", "1");
	// Liste *L2 = new Liste;
	// L2->AjouterTrajet(ts5);
	// L2->AjouterTrajet(ts6);
	// const TrajetCompose *tc2 = new TrajetCompose(L2->getPremiereEtape()->getTrajet()->getDepart(), 
	// 											 L2->getDerniereEtape()->getTrajet()->getArrivee(), 
	// 											 L2);


	// Catalogue *C = new Catalogue;
	// C->AjouterTrajetSimple(ts1);
	// C->AjouterTrajetSimple(ts2);
	// C->AjouterTrajetCompose(tc1);
	// C->AjouterTrajetCompose(tc2);

	// C->Afficher();

	// C->RechercheAvancee("A", "C");


	Catalogue *C = new Catalogue;

	while (1) {
		cout << '\n';
		cout << "|***************************************|\n";
		cout << "| 1 - Ajouter Trajet Simple             |\n";
		cout << "| 2 - Ajouter Trajet Compose            |\n";
		cout << "| 3 - Afficher Catalogue                |\n";
		cout << "| 4 - Rechercher simple de parcours     |\n";
		cout << "| 5 - Rechercher avancee de parcours    |\n";
		cout << "| 6 - Quitter l'application             |\n";
		cout << "Que souhaitez-vous choisir ?               ";

		char option;
		cin >> option;

		if (option == '1') {

			C->AjouterTrajetSimple();

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

				const TrajetSimple *trajet_simple = 
				  new TrajetSimple(villeDepart, villeSuivant, transport);

				L->AjouterTrajet(trajet_simple);
				villeDepart = villeSuivant;
			}

			const TrajetCompose *trajet_compose = new TrajetCompose(L);
								
			C->AjouterTrajetCompose(trajet_compose);

			trajet_compose->Afficher(); 
			cout << "a ete ajoute au catalogue.";
		}
		else if (option == '3') {
			C->Afficher();
		}
		else if (option == '4') {
			char *villeDepart;
			char *villeArrivee;

			cout << "Ville de depart : ";
			villeDepart = getString();
			cout << "Ville d'arrivee : ";
			villeArrivee = getString();

			C->RechercheSimple(villeDepart, villeArrivee);
		}
		else if (option == '5') {
			char *villeDepart;
			char *villeArrivee;

			cout << "Ville de depart : ";
			villeDepart = getString();
			cout << "Ville d'arrivee : ";
			villeArrivee = getString();

			C->RechercheAvancee(villeDepart, villeArrivee);
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
			cout << "Choix invalide. Entre 1 et 6, svp...";
		}
	}
	cout << "\n";

	return 0;
}