#include <iostream>
#include <string.h>
#include <string>
#include <cstdlib>
#include <stack>
#include <math.h>
#include "stringconvert.h"
using namespace std;


// funkcje
string char_to_string(char z)
{
	string p;
	p = z;
	return p;
}

bool string_parse(string s, double& x)
{
	char* wsk;
	x = strtod(s.c_str(), &wsk);
	if (strlen(wsk) != 0 || s.size() == 0)
		return false;
	else return true;
}

bool string_try_parse(string s)
{
	double x;
	char* wsk;
	x = strtod(s.c_str(), &wsk);
	if (strlen(wsk) != 0 || s.size() == 0)
		return false;
	else return true;
}

bool char_parse(char c, double& x)
{
	string s;
	s[0] = c;
	char* wsk;
	x = strtod(s.c_str(), &wsk);
	if (strlen(wsk) != 0 || s.size() == 0)
		return false;
	else return true;
}

bool char_try_parse(char c)
{
	string s = char_to_string(c);
	return string_try_parse(s);
}

string czysc_spacje(string wyrazenie)
{
	int licznik = 0;
	do
	{
		if (wyrazenie[licznik] == ' ')
		{
			wyrazenie.erase(licznik, 1);
			licznik--;
		}
		licznik++;
	} while (licznik != wyrazenie.size());
	return wyrazenie;
}

vector<string> math_expr(string dzialanie)
{
	//zmienne i obiekty
	vector<string> vec = {};
	string obecny{}, poprzedni{};
	stack<string> stos_glowny{};
	stack<string> stos_pomocniczy;

	dzialanie = czysc_spacje(dzialanie);
	int size = dzialanie.size();
	for (int i = 0; i < size; i++)
	{
		if (char_try_parse(dzialanie[i]))
		{
			if (stos_glowny.empty())
			{
				stos_glowny.push(char_to_string(dzialanie[i]));
			}
			else if (string_try_parse(obecny = stos_glowny.top()))
			{
				stos_glowny.pop();
				obecny += char_to_string(dzialanie[i]);
				stos_glowny.push(obecny);
			}
			else
			{
				if (stos_glowny.size() > 1)
				{
					if (obecny = stos_glowny.top(), stos_glowny.pop(), poprzedni = stos_glowny.top(), stos_glowny.push(obecny), (obecny == "+" || obecny == "-") && (string_try_parse(poprzedni) == false && poprzedni != ")"))
					{
						stos_glowny.pop();
						obecny += char_to_string(dzialanie[i]);
						stos_glowny.push(obecny);
					}
					else
					{
						stos_glowny.push(char_to_string(dzialanie[i]));
					}
				}
				else
				{
					if (obecny = stos_glowny.top(), obecny == "+" || obecny == "-")
					{
						stos_glowny.pop();
						obecny += char_to_string(dzialanie[i]);
						stos_glowny.push(obecny);
					}
					else
					{
						stos_glowny.push(char_to_string(dzialanie[i]));
					}
				}

			}
		}
		else if (dzialanie[i] == '.')
		{
			if (stos_glowny.empty())
			{
				stos_glowny.push(char_to_string(dzialanie[i]));
			}
			else
			{
				obecny = stos_glowny.top();
				stos_glowny.pop();
				obecny += ".";
				stos_glowny.push(obecny);
			}
		}
		else
		{
			if (stos_glowny.empty())
			{
				stos_glowny.push(char_to_string(dzialanie[i]));
			}
			else
			{
				obecny = char_to_string(dzialanie[i]);
				stos_glowny.push(obecny);
			}
		}
	}
	while (stos_glowny.size() != 0)
	{
		stos_pomocniczy.push(stos_glowny.top());
		stos_glowny.pop();
	}
	while (stos_pomocniczy.size() != 0)
	{
		vec.push_back(stos_pomocniczy.top());
		stos_pomocniczy.pop();
	}
	return vec;
}

bool litera(char lit)
{
	if (lit > 64 && lit < 91) return true;
	else if (lit > 96 && lit < 123) return true;
	else return false;
}

vector<string> alg_expr(string dzialanie)
{
	//zmienne i obiekty
	vector<string> vec = {};
	string obecny{}, poprzedni{};
	stack<string> stos_glowny{};
	stack<string> stos_pomocniczy;

	dzialanie = czysc_spacje(dzialanie);
	int size = dzialanie.size();
	for (int i = 0; i < size; i++)
	{
		if (char_try_parse(dzialanie[i]))
		{
			if (stos_glowny.empty())
			{
				stos_glowny.push(char_to_string(dzialanie[i]));
			}
			else if (string_try_parse(obecny = stos_glowny.top()))
			{
				stos_glowny.pop();
				obecny += char_to_string(dzialanie[i]);
				stos_glowny.push(obecny);
			}
			else
			{
				if (stos_glowny.size() > 1)
				{
					if (obecny = stos_glowny.top(), stos_glowny.pop(), poprzedni = stos_glowny.top(), stos_glowny.push(obecny), (obecny == "+" || obecny == "-") && (string_try_parse(poprzedni) == false && poprzedni != ")" && !litera(poprzedni[0])))
					{
						stos_glowny.pop();
						obecny += char_to_string(dzialanie[i]);
						stos_glowny.push(obecny);
					}
					else
					{
						stos_glowny.push(char_to_string(dzialanie[i]));
					}
				}
				else
				{
					if (obecny = stos_glowny.top(), obecny == "+" || obecny == "-")
					{
						stos_glowny.pop();
						obecny += char_to_string(dzialanie[i]);
						stos_glowny.push(obecny);
					}
					else
					{
						stos_glowny.push(char_to_string(dzialanie[i]));
					}
				}

			}
		}
		else if (dzialanie[i] == '.')
		{
			if (stos_glowny.empty())
			{
				stos_glowny.push(char_to_string(dzialanie[i]));
			}
			else
			{
				obecny = stos_glowny.top();
				stos_glowny.pop();
				obecny += ".";
				stos_glowny.push(obecny);
			}
		}
		else if (litera(dzialanie[i]))
		{
			stos_glowny.push(char_to_string(dzialanie[i]));
		}
		else
		{
			if (stos_glowny.empty())
			{
				stos_glowny.push(char_to_string(dzialanie[i]));
			}
			else
			{
				obecny = char_to_string(dzialanie[i]);
				stos_glowny.push(obecny);
			}
		}
	}
	while (stos_glowny.size() != 0)
	{
		stos_pomocniczy.push(stos_glowny.top());
		stos_glowny.pop();
	}
	while (stos_pomocniczy.size() != 0)
	{
		vec.push_back(stos_pomocniczy.top());
		stos_pomocniczy.pop();
	}
	return vec;
}

int waga(string znak)
{
	if (znak == "+" || znak == "-") return 1;
	else if (znak == "*" || znak == "/") return 2;
	else if (znak == "^") return 3;
	else if (znak == "(") return 0;
}

vector<string> ONP_expr(vector<string> dzialanie)
{
	stack<string> stos_onp;
	stack<string> stos_znakow;
	vector<string> vec;
	string obecny;
	///////////////////////////////////
	for (int i = 0; i < dzialanie.size(); i++)
	{
		if (string_try_parse(dzialanie[i]))
		{
			stos_onp.push(dzialanie[i]);
		}
		else if (litera(dzialanie[i][0]))
		{
			stos_onp.push(dzialanie[i]);
		}
		else
		{
			if (stos_znakow.empty())
			{
				stos_znakow.push(dzialanie[i]);
			}
			else
			{
				if (dzialanie[i] == "(")
				{
					stos_znakow.push(dzialanie[i]);
				}
				else if (dzialanie[i] == ")")
				{
					while (stos_znakow.top() != "(")
					{
						stos_onp.push(stos_znakow.top());
						stos_znakow.pop();
					}
					stos_znakow.pop();
				}
				else
				{
					obecny = stos_znakow.top();
					if (waga(obecny) >= waga(dzialanie[i]))
					{
						while (!stos_znakow.empty() && stos_znakow.top() != "(")
						{
							stos_onp.push(stos_znakow.top());
							stos_znakow.pop();
						} 
						stos_znakow.push(dzialanie[i]);
					}
					else
					{
						stos_znakow.push(dzialanie[i]);
					}
				}
			}
		}
	}
	while (!stos_onp.empty())
	{
		stos_znakow.push(stos_onp.top());
		stos_onp.pop();
	}
	while (!stos_znakow.empty())
	{
		vec.push_back(stos_znakow.top());
		stos_znakow.pop();
	}
	return vec;
}

double kalk_ONP(vector<string> dzialanie)
{
	stack<double> stos;
	double liczba,x,y;

	//////
	for (int i = 0; i < dzialanie.size(); i++)
	{
		if (string_parse(dzialanie[i],liczba))
		{
			stos.push(liczba);
		}
		else
		{
			x = stos.top();
			stos.pop();
			y = stos.top();
			stos.pop();
			switch (dzialanie[i][0])
			{
			case '+':
				stos.push(x + y);
				break;
			case '-':
				stos.push(y - x);
				break;
			case '*':
				stos.push(x * y);
				break;
			case '/':
				stos.push(y / x);
				break;
			case '^':
				stos.push(pow(y , x));
				break;
			}
		}
	}
	return stos.top();
}