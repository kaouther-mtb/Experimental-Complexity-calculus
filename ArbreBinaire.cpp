#include <iostream> 
#include <stack> 
#include <stdlib.h>
#include <algorithm>
#include <math.h>
#include<stdio.h>
#include <chrono>
using namespace std;
// Binary Tree
typedef struct Arbre
{
	char* Valeur;
	Arbre* gauche, * droite;
} Arbre;
typedef struct Arbre* ExpArbre;

// Tree
ExpArbre Creation_noeud(char* Valeur);
ExpArbre ConstruireArbre(ExpArbre T, char postfix[]);
int Priority(char ch);
void Conversion_post(string Expression, char postfix[]);
// Extra
int Hauteur(ExpArbre T);
int taille(ExpArbre node);
// Output
void Afficher_noeud(ExpArbre T);
void Postfixe(ExpArbre T);
void Autres(char postfix[], ExpArbre tree);
void Affichage(ExpArbre tree, char postfix[]);
void Affichage_Arbre(ExpArbre T, const string& prefix);
void Insert_Line();
// Input Validation
bool Expression_Validation(string Expression);
bool Operateur(char ch);
bool Operade(char c);
string Expression;

int main()
{
	cout << "\n\t\t    ( Expression Arbre binaire )" << endl;
	Insert_Line();

	//Entrer votre expression : 
	// cout << "\n Entrer l'expression : ";
	// cin >> Expression;

	//Des expression exemplaire : 
	// Expression = "123+423*12312/8567^54+1231*53";
	Expression = "123+423*12312/8567^54+1231*53+123+423*12312/8567^54+1231*53+123+423*12312/8567^54+1231*53+123+423*12312/8567^54+1231*53+123+423*12312/8567^54+1231*53+123+423*12312/8567^54+1231*53+123+423*12312/8567^54+1231*53+123+423*12312/8567^54+1231*53+123+423*12312/8567^54+1231*53";
	// Expression = "123+423*12312/8567^54+1231*53+123+423*12312/8567^54+1231*53+123+423*12312/8567^54+1231*53+123+423*12312/8567^54+1231*53+123+423*12312/8567^54+1231*53+123+423*12312/8567^54+1231*53+123+423*12312/8567^54+1231*53+123+423*12312/8567^54+1231*53+123+423*12312/8567^54+1231*53+123+423*12312/8567^54+1231*53+123+423*12312/8567^54+1231*53+123+423*12312/8567^54+1231*53+123+423*12312/8567^54+1231*53+123+423*12312/8567^54+1231*53+123+423*12312/8567^54+1231*53+123+423*12312/8567^54+1231*53+123+423*12312/8567^54+1231*53+123+423*12312/8567^54+1231*53+123+423*12312/8567^54+1231*53+123+423*12312/8567^54+1231*53+123+423*12312/8567^54+1231*53+123+423*12312/8567^54+1231*53+123+423*12312/8567^54+1231*53+123+423*12312/8567^54+1231*53+123+423*12312/8567^54+1231*53+123+423*12312/8567^54+1231*53+123+423*12312/8567^54+1231*53+123+423*12312/8567^54+1231*53+123+423*12312/8567^54+1231*53+123+423*12312/8567^54+1231*53+123+423*12312/8567^54+1231*53+123+423*12312/8567^54+1231*53+123+423*12312/8567^54+1231*53+123+423*12312/8567^54+1231*53+123+423*12312/8567^54+1231*53+123+423*12312/8567^54+1231*53";
	// Expression = "123+423*12312/8567^54+1231*53+123+423*12312/8567^54+1231*53+123+423*12312/8567^54+1231*53+123+423*12312/8567^54+1231*53+123+423*12312/8567^54+1231*53+123+423*12312/8567^54+1231*53+123+423*12312/8567^54+1231*53+123+423*12312/8567^54+1231*53+123+423*12312/8567^54+1231*53+123+423*12312/8567^54+1231*53+123+423*12312/8567^54+1231*53+123+423*12312/8567^54+1231*53+123+423*12312/8567^54+1231*53+123+423*12312/8567^54+1231*53+123+423*12312/8567^54+1231*53+123+423*12312/8567^54+1231*53+123+423*12312/8567^54+1231*53+123+423*12312/8567^54+1231*53+123+423*12312/8567^54+1231*53+123+423*12312/8567^54+1231*53+123+423*12312/8567^54+1231*53+123+423*12312/8567^54+1231*53+123+423*12312/8567^54+1231*53+123+423*12312/8567^54+1231*53+123+423*12312/8567^54+1231*53+123+423*12312/8567^54+1231*53+123+423*12312/8567^54+1231*53+123+423*12312/8567^54+1231*53+123+423*12312/8567^54+1231*53+123+423*12312/8567^54+1231*53+123+423*12312/8567^54+1231*53+123+423*12312/8567^54+1231*53+123+423*12312/8567^54+1231*53+123+423*12312/8567^54+1231*53+123+423*12312/8567^54+1231*53+123+423*12312/8567^54+1231*53-123+423*12312/8567^54+1231*53+123+423*12312/8567^54+1231*53+123+423*12312/8567^54+1231*53+123+423*12312/8567^54+1231*53+123+423*12312/8567^54+1231*53+123+423*12312/8567^54+1231*53+123+423*12312/8567^54+1231*53+123+423*12312/8567^54+1231*53+123+423*12312/8567^54+1231*53+123+423*12312/8567^54+1231*53+123+423*12312/8567^54+1231*53+123+423*12312/8567^54+1231*53+123+423*12312/8567^54+1231*53+123+423*12312/8567^54+1231*53+123+423*12312/8567^54+1231*53+123+423*12312/8567^54+1231*53+123+423*12312/8567^54+1231*53+123+423*12312/8567^54+1231*53/123+423*12312/8567^54+1231*53+123+423*12312/8567^54+1231*53+123+423*12312/8567^54+1231*53+123+423*12312/8567^54+1231*53+123+423*12312/8567^54+1231*53+123+423*12312/8567^54+1231*53+123+423*12312/8567^54+1231*53+123+423*12312/8567^54+1231*53+123+423*12312/8567^54+1231*53";
	// Expression = "123+423*12312/8567^54+1231*53+123+423*12312/8567^54+1231*53+123+423*12312/8567^54+1231*53+123+423*12312/8567^54+1231*53+123+423*12312/8567^54+1231*53+123+423*12312/8567^54+1231*53+123+423*12312/8567^54+1231*53+123+423*12312/8567^54+1231*53+123+423*12312/8567^54+1231*53+123+423*12312/8567^54+1231*53+123+423*12312/8567^54+1231*53+123+423*12312/8567^54+1231*53+123+423*12312/8567^54+1231*53+123+423*12312/8567^54+1231*53+123+423*12312/8567^54+1231*53+123+423*12312/8567^54+1231*53+123+423*12312/8567^54+1231*53+123+423*12312/8567^54+1231*53+123+423*12312/8567^54+1231*53+123+423*12312/8567^54+1231*53+123+423*12312/8567^54+1231*53+123+423*12312/8567^54+1231*53+123+423*12312/8567^54+1231*53+123+423*12312/8567^54+1231*53+123+423*12312/8567^54+1231*53+123+423*12312/8567^54+1231*53+123+423*12312/8567^54+1231*53+123+423*12312/8567^54+1231*53+123+423*12312/8567^54+1231*53+123+423*12312/8567^54+1231*53+123+423*12312/8567^54+1231*53+123+423*12312/8567^54+1231*53+123+423*12312/8567^54+1231*53+123+423*12312/8567^54+1231*53+123+423*12312/8567^54+1231*53+123+423*12312/8567^54+1231*53-123+423*12312/8567^54+1231*53+123+423*12312/8567^54+1231*53+123+423*12312/8567^54+1231*53+123+423*12312/8567^54+1231*53+123+423*12312/8567^54+1231*53+123+423*12312/8567^54+1231*53+123+423*12312/8567^54+1231*53+123+423*12312/8567^54+1231*53+123+423*12312/8567^54+1231*53+123+423*12312/8567^54+1231*53+123+423*12312/8567^54+1231*53+123+423*12312/8567^54+1231*53+123+423*12312/8567^54+1231*53+123+423*12312/8567^54+1231*53+123+423*12312/8567^54+1231*53+123+423*12312/8567^54+1231*53+123+423*12312/8567^54+1231*53+123+423*12312/8567^54+1231*53+123+423*12312/8567^54+1231*53+123+423*12312/8567^54+1231*53+123+423*12312/8567^54+1231*53+123+423*12312/8567^54+1231*53+123+423*12312/8567^54+1231*53+123+423*12312/8567^54+1231*53+123+423*12312/8567^54+1231*53+123+423*12312/8567^54+1231*53+123+423*12312/8567^54+1231*53+123+423*12312/8567^54+1231*53+123+423*12312/8567^54+1231*53+123+423*12312/8567^54+1231*53+123+423*12312/8567^54+1231*53+123+423*12312/8567^54+1231*53+123+423*12312/8567^54+1231*53+123+423*12312/8567^54+1231*53+123+423*12312/8567^54+1231*53+123+423*12312/8567^54+1231*53";


	auto start_Program = chrono::high_resolution_clock::now();
	if (!Expression_Validation(Expression)) {
		cout << " L'expression peut seulement contenir :  [ 1-9 , + , - , * , / , % , ^ , ( , ) ] " << endl;
		return 0;
	}
	char Postfixe[10000];

	auto start = chrono::high_resolution_clock::now();
	Conversion_post(Expression, Postfixe);
	auto end = chrono::high_resolution_clock::now();
    unsigned long nanoseconds_Post = chrono::duration_cast<chrono::nanoseconds>(end - start).count();

	ExpArbre Arbre = NULL;
	Arbre = ConstruireArbre(Arbre, Postfixe);
	Affichage(Arbre, Postfixe);

	start = chrono::high_resolution_clock::now();
	cout << "\n" << Arbre->Valeur << "\n";
	Affichage_Arbre(Arbre, "");
	end = chrono::high_resolution_clock::now();
    unsigned long nanoseconds_Aff = chrono::duration_cast<chrono::nanoseconds>(end - start).count();
	
	auto end_Program = chrono::high_resolution_clock::now();
    unsigned long nanoseconds_Program = chrono::duration_cast<chrono::nanoseconds>(end_Program - start_Program).count();

	Insert_Line();
	cout << "\n Le temp de d'execution du program en nanoseconds : " << nanoseconds_Program << endl;
	cout << "\n Le temp de convertion Postfixée en nanoseconds : " << nanoseconds_Post << endl;
	cout << "\n Le temp d'affichage de l'arbre en nanoseconds : " << nanoseconds_Aff << endl;
	Insert_Line();
	// Postfixe

	return 0;
}

void Insert_Line()
{
	cout << "__________________________________________________________________" << endl;
}
void Affichage(ExpArbre Arbre, char postfix[])
{
	Insert_Line();
	cout << "\n Expression PostFixée (Gauche, Droit, Parent) : [ ";
	Postfixe(Arbre);
	cout << "]" << endl;
	Insert_Line();
	Autres(postfix, Arbre);
	
}
void Autres(char postfix[], ExpArbre Arbre)
{
	cout << "\n\n\n\t ( Autres fonctionnalites Ajouter au projet )" << endl << "\n\n";

	Insert_Line();
	cout << "\n Nombre des noeuds = " << taille(Arbre);
	cout << " , Hauter = " << Hauteur(Arbre) << endl;
	Insert_Line();

}
bool Operade(char ch)
{

	if (ch > 47 && ch < 58)
		return true;
	return false;
}
bool Operateur(char ch)
{
	if (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '%' || ch == '^')
		return true;
	return false;
}

bool Expression_Validation(string Expression)
{
	for (unsigned int i = 0; i < Expression.length(); i++) {
		if (!Operade(Expression[i]) && !Operateur(Expression[i]) && Expression[i] != '(' && Expression[i] != ')')
			return false;
	}
	return true;
}
// Create a new Tree noeud
ExpArbre Creation_noeud(char* Valeur)
{
	Arbre* temp;
	temp = (Arbre*)malloc(sizeof(Arbre));
	if (temp == NULL)
	{
		cout << "Pas d'espace!\n";
		return (temp);
	}
	temp->gauche = NULL;
	temp->droite = NULL;
	temp->Valeur = Valeur;
	return temp;
};

ExpArbre ConstruireArbre(ExpArbre Arbre_binaire, char postfixe[])
{
	int i = 0;
	int j;
	stack<Arbre*> st;
	Arbre* temp_Arbre1;
	Arbre* temp_Arbre2;
	

	while (postfixe[i] != '\0' | st.empty() == false)
	{
		j = 0;
		if (!(postfixe[i] == '+' || postfixe[i] == '-' || postfixe[i] == '*' || postfixe[i] == '/' || postfixe[i] == '^'
			|| postfixe[i] == '%' || postfixe[i] == '\0'))
		{
			char* chaine = (char*)malloc(sizeof(char) * 100);
			while(postfixe[i] != ' ' )
			{
                if(postfixe[i] == '\0'){
                    break;
                }
				chaine[j] = postfixe[i];
				j++;
				i++;
			}
			// int number = stoi(chaine);
			if(Operade(chaine[0]))
			{
				Arbre_binaire = Creation_noeud(chaine);
				st.push(Arbre_binaire);
			}
		}
		else
		{
            if(postfixe[i] != '\0')
            {
                char* chaine = (char*)malloc(sizeof(char) * 1);
                chaine[0] = postfixe[i];
                Arbre_binaire = Creation_noeud(chaine);
            }
            if(!st.empty()){
                temp_Arbre1 = st.top(); st.pop();
            }
            if(!st.empty()){
                temp_Arbre2 = st.top(); st.pop();
            }
            if(Arbre_binaire != temp_Arbre1 && temp_Arbre1 != NULL)
            {
                Arbre_binaire->droite = temp_Arbre1;
                temp_Arbre1 = NULL;
            }
            if(Arbre_binaire != temp_Arbre2 && temp_Arbre2 != NULL)
            {
                Arbre_binaire->gauche = temp_Arbre2;
                temp_Arbre2 = NULL;
            }
            if(postfixe[i+1] != '\0')
            {
			    st.push(Arbre_binaire);
            }
		}
		i++;
	}
	return Arbre_binaire;
}

void Afficher_noeud(ExpArbre T)
{
	cout << T->Valeur << " ";
}

void Postfixe(ExpArbre T)
{
	if (T != NULL)
	{
		Postfixe(T->gauche);
		Postfixe(T->droite);
		Afficher_noeud(T);
	}
}

int Priority(char ch)
{
	switch (ch)
	{
	case '^':
		return 4;
	case '%':
		return 3;
	case '/':
	case '*':
		return 2;
	case '+':
	case '-':
		return 1;
	default:
		return 0;
	}
}
void Conversion_post(string Expression, char postfix[])
{
	unsigned int i = 0;
	stack<char> Pile_Parenth;
	int postCount = 0;
	char element;
	while (i < Expression.length())
	{
		element = Expression[i];
		if (element == '(')
		{
			Pile_Parenth.push(element);
			i++;
			continue;
		}
		if (element == ')')
		{
			while (!Pile_Parenth.empty() && Pile_Parenth.top() != '(')
			{
				postfix[postCount++] = Pile_Parenth.top();
				Pile_Parenth.pop();
			}
			if (!Pile_Parenth.empty())
			{
				Pile_Parenth.pop();
			}
			i++;
			continue;
		}

		if (Priority(element) == 0)
		{
			postfix[postCount++] = Expression[i];
		}
		else
		{
			if (Pile_Parenth.empty())
			{
				Pile_Parenth.push(element);
				postfix[postCount++] = ' ';
			}
			else
			{
				int test = 1;
				while (!Pile_Parenth.empty() && Pile_Parenth.top() != '(' &&
					Priority(element) <= Priority(Pile_Parenth.top()))
				{
					if(test | Operateur(element)){
						postfix[postCount++] = ' ';	
						postfix[postCount++] = Pile_Parenth.top();
						Pile_Parenth.pop();
						test = 0;
					}

				}

				if(test | Operateur(element)){
					postfix[postCount++] = ' ';	
					test = 0;
				}
				Pile_Parenth.push(element);
			}
		}
		i++;
	}

	while (!Pile_Parenth.empty())
	{
		postfix[postCount++] = ' ';
		postfix[postCount++] = Pile_Parenth.top();
		Pile_Parenth.pop();
	}
	postfix[postCount] = '\0';
	i++;
}
int taille(ExpArbre node)
{
	if (node == NULL)
		return 0;
	else
		return(1 + taille(node->gauche) + taille(node->droite));
}
int Hauteur(ExpArbre T)
{
	if (T == NULL)
		return -1;
	else
	{
		return 1 + max(Hauteur(T->gauche), Hauteur(T->droite));
	}
}

void Affichage_Arbre(ExpArbre T, const string& prefix)
{
        if (T == NULL)
        {
                return;
        }

        bool gauche = (T->gauche != NULL);
        bool droite = (T->droite != NULL);

        if (!gauche && !droite)
        {
                return;
        }

        cout << prefix;
        cout << ((gauche  && droite) ? "├── " : "");
        cout << ((!gauche && droite) ? "└── " : "");

        if (droite)
        {
                bool printStrand = (gauche && droite && (T->droite->droite != NULL || T->droite->gauche != NULL));
                string newPrefix = prefix + (printStrand ? "│   " : "    ");
                cout << T->droite->Valeur << endl;
                Affichage_Arbre(T->droite, newPrefix);
        }

        if (gauche)
        {
                cout << (droite ? prefix : "") << "└── " << T->gauche->Valeur << endl;
                Affichage_Arbre(T->gauche, prefix + "    ");
        }
}

