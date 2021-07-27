class zivotinja
{
protected:
    int noga;
    int n;
public:
    int virtual postaviBrojNogu() = 0;
    void virtual setNoge(int n) = 0;
    int virtual getNoge() = 0;
};

class pas : public zivotinja
{
public:
    int postaviBrojNogu();
    void setNoge(int n);
    int getNoge();
    ~pas(){};
};

class macka : public zivotinja
{
public:
    int postaviBrojNogu();
    void setNoge(int n);
    int getNoge();
    ~macka(){};
};

class zohar : public zivotinja
{
public:
    int postaviBrojNogu();
    void setNoge(int n);
    int getNoge();
    ~zohar(){};
};
