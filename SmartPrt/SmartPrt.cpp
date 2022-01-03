// SmartPrt.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//


#include <iostream>	
#include <memory>

using namespace std;

	class Rectangle {
		int length;
		int breadth;

	public:
		Rectangle(int l, int b) {
			length = l;
			breadth = b;
		}

		int area() {
			return length * breadth;
		}
	};

	int main() {

		/*************unique PTR****************/
		cout << "Using Unique_Ptr" << endl;
		cout << "*********************************" << endl;
		unique_ptr<Rectangle> P11(new Rectangle(10, 5));
		cout << "Area of rectangle is : "<<P11->area() << endl; // This'll print 50

		// unique_ptr<Rectangle> P2(P1);
		unique_ptr<Rectangle> P21;
		P21 = move(P11);

		// This'll print 50
		cout << "Area of rectangle is : " << P21->area() << endl;
		cout << "*********************************" << endl;
		cout<<"Using Shered ptr" << endl;
		cout << "*********************************" << endl;
		/*************Shered PTR****************/

		shared_ptr<Rectangle> P1(new Rectangle(10, 5));
		// This'll print 50
		cout << "Area of rectangle is : " << P1->area() << endl;

		shared_ptr<Rectangle> P2;
		P2 = P1;

		// This'll print 50
		//cout << P2->area() << endl;

		// This'll now not give an error,
		cout << "Area of rectangle is : " << P1->area() << endl;

		// This'll also print 50 now
		// This'll print 2 as Reference Counter is 2
		cout << "conter is :"<< P1.use_count() << endl;
		cout << "*********************************" << endl;
		cout << "Using Weak_Ptr" << endl;
		cout << "*********************************" << endl;
		/*************Weak PTR****************/
		shared_ptr<Rectangle> sp = make_shared<Rectangle>(10,5);

		cout << "conter is :" << sp.use_count() << endl;

		weak_ptr<Rectangle> wp(sp);

		cout << "conter is :" << sp.use_count() << endl;
		cout << "Area of rectangle is : " << sp->area() << endl;
		return 0;
	}
		






// Exécuter le programme : Ctrl+F5 ou menu Déboguer > Exécuter sans débogage
// Déboguer le programme : F5 ou menu Déboguer > Démarrer le débogage

// Astuces pour bien démarrer : 
//   1. Utilisez la fenêtre Explorateur de solutions pour ajouter des fichiers et les gérer.
//   2. Utilisez la fenêtre Team Explorer pour vous connecter au contrôle de code source.
//   3. Utilisez la fenêtre Sortie pour voir la sortie de la génération et d'autres messages.
//   4. Utilisez la fenêtre Liste d'erreurs pour voir les erreurs.
//   5. Accédez à Projet > Ajouter un nouvel élément pour créer des fichiers de code, ou à Projet > Ajouter un élément existant pour ajouter des fichiers de code existants au projet.
//   6. Pour rouvrir ce projet plus tard, accédez à Fichier > Ouvrir > Projet et sélectionnez le fichier .sln.
