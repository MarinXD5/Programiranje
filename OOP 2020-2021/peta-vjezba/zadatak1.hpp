class Book
{
    protected:
        char* autor;
        char* naslov;
        int godina;
    public:
        ~Book();
        void sAuthor(char author[1024]);
        void sTitle(char title[1024]);
        void sYear(int year);
        char* gAuthor();
        char* gTitle();
        int gYear();
        virtual int getMB()=0;
};

class EBook : public Book
{
    private:
        int MB;
        char* ime_datoteke;
    public:
        int getMB();
        char* getime_datoteke();
        void setMB(int Megabajti);
        void setIme(char nameDAT[1024]);
        void setEbook(EBook& knjiga);
        void kopija(EBook& knjiga);
        ~EBook();

};

class HardCopyBook : public Book
{
    private:
        int broj_stranica;
    public:
        void setBrStranica(int page);
        int getBrStranica();
        void setHardCopyBook(HardCopyBook& knjiga);
        void kopija(HardCopyBook &knjiga);
        int getMB();
};

class Library
{
    private:
        Book** nizPointera;
        int lvelicina;
        int fvelicina;
    public:
        Library();
        ~Library();
        void setEBook(EBook& knjiga);
        void setHardCopyBook(HardCopyBook& knjiga);
        char** vratiSveNasloveAutora(char* Author, int& velicinaKonacnogNiza);
        int vratisveMegabajte(char* Autor);
        Book** vratiSveKnjige(char* dioNaslova);
};
