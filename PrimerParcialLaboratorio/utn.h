#ifndef UTN_H_INCLUDED
#define UTN_H_INCLUDED

void menu();

int getInt(int* pInput, char mensaje[]);
float getFloat(float* pInput, char mensaje[]);
void getString(char mensaje[],char input[]);
int esSoloLetras(char str[]);
int getStringLetras(char mensaje[],char input[]);
int esNumerico(char str[]);
int esNumericoFlotante(char str[]);
int getStringNumeros(char mensaje[],char input[]);
int getStringNumerosFlotantes(char mensaje[],char input[]);

#endif // UTN_H_INCLUDED
