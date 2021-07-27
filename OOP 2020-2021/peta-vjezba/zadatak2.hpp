class Igrac
{
    private:
        int brojIgraca;
    public:
        int setbrojIgraca();

};

class Igra
{
    private:
        int pet_kuna;
        int dvije_kune;
        int jedna_kuna;
        int prazna_ruka;
    public:
        Igra();
        void gameLogic(Igrac Player);

};
