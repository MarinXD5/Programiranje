class vehicle
{
public:
    virtual char gettype() = 0  ;
    virtual int getPass() = 0;
};

class watercraft : virtual public vehicle
{
public:
    char gettype() override;
    int getPass() override;
};

class aircraft : virtual public vehicle
{
public:
    char gettype() override;
    int getPass() override;
};

class ferry : public watercraft
{
public:
    int getPass()
    {
        return 450;
    }

    int getVeh()
    {
        return 52;
    }
    virtual ~ferry(){};
};

class catamaran : public watercraft
{
public:
    int getPass()
    {
        return 50;
    }
    virtual ~catamaran() {};
};

class seaplane : public aircraft, public watercraft
{
public:
    int getPass()
    {
        return 5;
    }
    char gettype()
    {
        return 'v';
    }
    virtual ~seaplane() {};
};

class counter
{
public:
    int ukupanBrPutnika(int fery, int splne, int cat);
};
