#include <cstdlib>
#include "zadatak1.hpp"
#pragma once
#include <iostream>
#include <cstring>

using namespace std;

Book::~Book()
{
    delete[] naslov;
    delete[] autor;
}

void Book::sAuthor(char author[1024])
{
    autor = _strdup(author);
}
void Book::sTitle(char title[1024])
{
    naslov = _strdup(title);
}
void Book::sYear(int year)
{
    godina = year;
}
char* Book::gAuthor()
{
    return autor;
}
char* Book::gTitle()
{
    return naslov;
}
int Book::gYear()
{
    return godina;
}
int EBook::getMB()
{
    return MB;
}
EBook::~EBook()
{
    delete[] ime_datoteke;
}
Library::~Library()
{
    delete[] nizPointera;
}
char* EBook::getime_datoteke()
{
    return ime_datoteke;
}
void EBook::setMB(int Megabajti)
{
    MB = Megabajti;
}
void EBook::setIme(char nameDAT[1024])
{
    ime_datoteke = _strdup(nameDAT);
}

void HardCopyBook::setBrStranica(int page)
{
    broj_stranica = page;
}
int HardCopyBook::getBrStranica()
{
    return broj_stranica;
}

int HardCopyBook::getMB()
{
    return 0;
}

Library::Library()
{
    fvelicina = 10;
    lvelicina = 0;

    nizPointera = new Book*[fvelicina];
}

void HardCopyBook::kopija(HardCopyBook& A)
{
    naslov = A.naslov;
    godina = A.godina;
    autor = A.autor;
}

void EBook::kopija(EBook &knjiga)
{
    naslov = knjiga.ime_datoteke;
    MB = knjiga.MB;
}

void Library::setEBook(EBook &knjiga)
{
    if (fvelicina <= lvelicina)
    {
        fvelicina = fvelicina *2;
        Book** temp = new Book*[fvelicina];
        for (int i = 0; i<lvelicina; i++)
        {
            temp[i] = nizPointera[i];
            delete nizPointera[i];
        }
        delete nizPointera;
        nizPointera = temp;
    }

    EBook* b = new EBook;
    b->kopija(knjiga);
    nizPointera[lvelicina] = b;
    lvelicina++;
}

void Library::setHardCopyBook(HardCopyBook &knjiga)
{
    if (fvelicina <= lvelicina)
    {
        fvelicina = fvelicina *2;
        Book** temp = new Book*[fvelicina];
        for (int i = 0; i<lvelicina; i++)
        {
            temp[i] = nizPointera[i];
            delete nizPointera[i];
        }
        delete nizPointera;
        nizPointera = temp;
    }

    HardCopyBook* b1 = new HardCopyBook;
    b1->kopija(knjiga);
    nizPointera[lvelicina] = b1;
    lvelicina++;
}

char** Library::vratiSveNasloveAutora(char* Author, int& velicinaKonacnogNiza)
{
    char** niz_a = new char*[lvelicina];
    int j=0;

    for (int i = 0; i<lvelicina; i++)
    {
        if(strcmp(Author,nizPointera[i]->gAuthor()))
           {
               niz_a[j] = _strdup(nizPointera[i]->gTitle());
               j++;
           }
    }

    velicinaKonacnogNiza = j;

    return niz_a;
}
int Library::vratisveMegabajte(char* Autor)
{
    int velicina;
    for (int i = 0; i<lvelicina;i++)
    {
        if (!strcmp(Autor, nizPointera[i]->gAuthor()))
        {
            velicina = velicina+nizPointera[i]->getMB();
        }
    }

    return velicina;
}
Book** Library::vratiSveKnjige(char* dioNaslova)
{
    Book** niz_b = new Book*[lvelicina];
    int j = 0;

        for (int i = 0; i<lvelicina; i++)
        {
            if(strstr(nizPointera[i]->gTitle(),dioNaslova))
            {
                niz_b[j] = nizPointera[i];
                j++;
            }
        }

    return niz_b;
}
