#include <iostream> 
#include <stack> 
#include <stdlib.h>
#include <algorithm>
#include <math.h>
#include <chrono>

using namespace std;

// Binary Tree
typedef struct Arbre
{
	char Valeur;
	Arbre* gauche, * droite;
} Arbre;
typedef struct Arbre* ExpArbre;

// Tree
ExpArbre Creation_noeud(int Valeur);
ExpArbre ConstruireArbre(ExpArbre T, char postfix[]);
int Priority(char ch);
void Conversion_post(string Expression, char postfix[]);
// Extra
void Expression_resultat(char postfix[]);
int Hauteur(ExpArbre T);
int taille(ExpArbre node);
// Output
void Afficher_noeud(ExpArbre T);
void Prefixe(ExpArbre T);
void Postfixe(ExpArbre T);
void Infixe(ExpArbre T);
void Autres(char postfix[], ExpArbre tree);
void Affichage(ExpArbre tree, char postfix[]);
void Affichage_Arbre(ExpArbre T, const string& prefix);
void Insert_Line();
// Input Validation
bool Expression_Validation(string Expression);
bool Operateur(char ch);
bool Operade(char c);


int main()
{
	cout << "\n\t\t    ( Expression Arbre binaire )" << endl;
	Insert_Line();
	cout << "\n Entrer l'expression : ";
	string Expression;
	cin >> Expression;

	
	auto start_Program = chrono::high_resolution_clock::now();
	if (!Expression_Validation(Expression)) {
		cout << " L'expression peut seulement contenir :  [ 1-9 , + , - , * , / , % , ^ ( , ) ] " << endl;
		return 0;
	}
	char* Postfixe = (char*)malloc(sizeof(char) * Expression.length());

	
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


	return 0;
}

void Insert_Line()
{
	cout << "__________________________________________________________________" << endl;
}
void Affichage(ExpArbre Arbre, char postfix[])
{
	Insert_Line();
	cout << "\n Expression PreFixée (Parent, Gauche, Droit) : [ ";
	Prefixe(Arbre);
	cout << "]" << endl;
	Insert_Line();
	cout << "\n Expression PostFixée (Gauche, Droit, Parent) : [ ";
	Postfixe(Arbre);
	cout << "]" << endl;
	Insert_Line();
	cout << "\n Expression Infixée (Gauche, Parent, Droit) : [ ";
	Infixe(Arbre);
	cout << "]" << endl;
	Insert_Line();
	Autres(postfix, Arbre);
	
}
void Autres(char postfix[], ExpArbre Arbre)
{
	cout << "\n\n\n\t ( Autres fonctionnalites Ajouter au projet )" << endl << "\n\n";
	Insert_Line();
	cout << "\n Resultat : ";
	Infixe(Arbre);
	Expression_resultat(postfix);
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
// Create a new Tree Node
ExpArbre Creation_noeud(int Valeur)
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
	stack<Arbre*> st;
	Arbre* temp_Arbre1;
	Arbre* temp_Arbre2;
	while (postfixe[i] != '\0')
	{
		if (!(postfixe[i] == '+' || postfixe[i] == '-' || postfixe[i] == '*' || postfixe[i] == '/'
			|| postfixe[i] == '%' || postfixe[i] == '^'))
		{
			Arbre_binaire = Creation_noeud(postfixe[i]);
			st.push(Arbre_binaire);
		}
		else
		{
			Arbre_binaire = Creation_noeud(postfixe[i]);
			temp_Arbre1 = st.top(); st.pop();
			temp_Arbre2 = st.top(); st.pop();
			Arbre_binaire->droite = temp_Arbre1;
			Arbre_binaire->gauche = temp_Arbre2;
			st.push(Arbre_binaire);
		}
		i++;
	}
	return Arbre_binaire;
}

void Afficher_noeud(ExpArbre T)
{
	cout << T->Valeur << " ";
}
void Prefixe(ExpArbre T)
{
	if (T != NULL)
	{
		Afficher_noeud(T);
		Prefixe(T->gauche);
		Prefixe(T->droite);
	}
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
void Infixe(ExpArbre T)
{
	if (T != NULL)
	{
		Infixe(T->gauche);
		Afficher_noeud(T);
		Infixe(T->droite);
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
	unsigned int counter1 = 0;
	stack<char> Pile_Parenth;
	int postCount = 0;
	char element;
	while (counter1 < Expression.length())
	{
		element = Expression[counter1];
		if (element == '(')
		{
			Pile_Parenth.push(element);
			counter1++;
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
			counter1++;
			continue;
		}

		if (Priority(element) == 0)
		{
			postfix[postCount++] = element;
		}
		else
		{
			if (Pile_Parenth.empty())
			{
				Pile_Parenth.push(element);
			}
			else
			{
				while (!Pile_Parenth.empty() && Pile_Parenth.top() != '(' &&
					Priority(element) <= Priority(Pile_Parenth.top()))
				{
					postfix[postCount++] = Pile_Parenth.top();
					Pile_Parenth.pop();
				}
				Pile_Parenth.push(element);
			}
		}
		counter1++;
	}

	while (!Pile_Parenth.empty())
	{
		postfix[postCount++] = Pile_Parenth.top();
		Pile_Parenth.pop();
	}
	postfix[postCount] = '\0';
}
//EXTRA
void Expression_resultat(char postfix[])
{
	stack<float> result;
	int k = 0;
	bool error = false;
	while (postfix[k] && !error)
	{
		char ch = postfix[k];
		if (Operade(ch))
		{
			result.push((float)postfix[k] - '0');
		}
		else if (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '%' || ch == '^')
		{
			float num1 = result.top();
			result.pop();
			float num2 = result.top();
			result.pop();
			float calc = 0;
			switch (ch)
			{
			case '+':
				calc = num2 + num1;
				break;
			case '-':
				calc = num2 - num1;
				break;
			case '*':
				calc = num2 * num1;
				break;
			case '/':
				if (num1 == 0)
				{
					cout << "\n Math Error: Can't Divide by Zero " << endl;
					error = true;
					break;
				}
				calc = num2 / num1;
				break;
			case '%':
				if (num1 == 0)
				{
					cout << "\n Math Error: Can't Divide by Zero " << endl;
					error = true;
					break;
				}
				calc = ((int)num2) % ((int)num1);
				break;
			case '^':
				calc = pow(num2, num1);
				break;
			}
			result.push(calc);
		}
		k++;
	}
	if (!error)
		cout << " = " << result.top() << endl;
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

        bool hasLeft = (T->gauche != NULL);
        bool hasRight = (T->droite != NULL);

        if (!hasLeft && !hasRight)
        {
                return;
        }

        cout << prefix;
        cout << ((hasLeft  && hasRight) ? "├── " : "");
        cout << ((!hasLeft && hasRight) ? "└── " : "");

        if (hasRight)
        {
                bool printStrand = (hasLeft && hasRight && (T->droite->droite != NULL || T->droite->gauche != NULL));
                string newPrefix = prefix + (printStrand ? "│   " : "    ");
                cout << T->droite->Valeur << endl;
                Affichage_Arbre(T->droite, newPrefix);
        }

        if (hasLeft)
        {
                cout << (hasRight ? prefix : "") << "└── " << T->gauche->Valeur << endl;
                Affichage_Arbre(T->gauche, prefix + "    ");
        }
}

