#pragma once
#include <iostream>
#include <vector>
using namespace std;


//functions

string czysc_spacje(string wyrazenie); // deletes spaces

vector<string> math_expr(string dzialanie); // expression to vector

vector<string> alg_expr(string dzialanie); // expression to vector, algebraic expresion

vector<string> ONP_expr(vector<string> dzialanie); // makes RPN

bool string_parse(string s, double& x); // checks whether string is a number or not, returns double

bool string_try_parse(string s); // checks whether string is a number or not

bool char_parse(char c, double& x); // checks whether char is a number or not, returns double

bool char_try_parse(char c); // checks whether char is a number or not

string char_to_string(char z); // converts char to string

double kalk_ONP(vector<string> dzialanie); // RPN calculator

bool litera(char lit); // checks wheter given char is a sign or not