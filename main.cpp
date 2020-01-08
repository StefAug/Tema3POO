#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <typeinfo>
using namespace std;
enum class
TipMasina : uint8_t
{
	INVALID,
	COUPE,
	HOT_HATCH,
	CABRIO,
	SUPERSPORT
};



class Car
{
protected:
	TipMasina type;
	string name;
	int price;

public:
	Car()
		{
		type = TipMasina::INVALID;
		name= "INVALID";
		price=0;
	}
	Car(TipMasina _type)
		{
		type = _type;
		name= "INVALID";
		price=0;
	}

	Car(TipMasina _type, const string& _name)
		{
		type = _type;
		name= _name;
		price=0;
	}
	Car(TipMasina _type, const string& _name, int _price)
		{
		type = _type;
		name= _name;
		price=_price;
	}

	virtual ~Car()
	{
		type = TipMasina::INVALID;
		name.clear();
	}

	Car(const Car& other)
		{
		type = other.type;
		name= other.name;
		price=other.price;
	}

	Car& operator=(const Car& other)
	{
		this->type = other.type;
		this->name = other.name;
		this->price = other.price;
		return *this;
	}

	pair<string,int> GetPair()
	{
	    pair<string,int>o;
	    if(name!="INVALID" && price!=0)
	    {o=make_pair(name,price);
	    return o;
	    }
	    else
            throw runtime_error("INVALID PAIR");
	}

	TipMasina GetType()
	{
		return type;
	}

	virtual void display(ostream& out)
	{
		out<<"Tip masina ";
		if(type==TipMasina::COUPE) out<<"Coupe "; else if (type==TipMasina::HOT_HATCH) out<<"Hot-Hatch "; else if (type==TipMasina::CABRIO) out<<"Cabrio "; else if (type==TipMasina::SUPERSPORT) out<<"Supersport "; else out<<"Invalid ";
	     out<<"nume "<<name<<" pret "<<price<<endl;
	}

	friend istream &operator >> (istream &in, Car& a)
	{
	    cout<<"Introdu numele: ";
	    in>>a.name;
	    int x;
	    cout<<"Introdu tipul, 1-Coupe, 2-Hot-Hatch, 3-Cabrio, 4-Supersport: ";
	    in>>x;
	    if(x<0)
            throw runtime_error("Tipul este mai mic ca 0");
	    if(x==1)a.type=TipMasina::COUPE;else if (x==2)a.type=TipMasina::HOT_HATCH;else if(x==3)a.type=TipMasina::CABRIO;else if (x==4)a.type=TipMasina::SUPERSPORT;else a.type=TipMasina::INVALID;
	    cout<<"Introdu pretul: ";
	    in>>a.price;
	    return in;
	}
};

class CarCoupe : protected Car
{
public:
	CarCoupe():Car(TipMasina::COUPE, "Coupe")
	{}
	CarCoupe(int a):Car(TipMasina::COUPE, "Coupe",a)
	{}

	~CarCoupe()
	{
		this->type = TipMasina::INVALID;
		this->name.clear();
	}

	CarCoupe(CarCoupe& other)
	{
		this->type = other.type;
		this->name = other.name;
		this->price = other.price;
	}

	CarCoupe& operator=(const CarCoupe& other)
	{
		this->type = other.type;
		return *this;
	}

	virtual void display(std::ostream& out)
	{
		out << "Masina Coupe"<<endl;
	}
	friend istream &operator >> (istream &in, CarCoupe& a)
	{
	    cout<<"Introdu numele: ";
	    in>>a.name;
	    a.type=TipMasina::COUPE;
	    cout<<"Introdu pretul: ";
	    in>>a.price;
	    return in;
	}
};
class CarHotHatch : protected Car
{
public:
	CarHotHatch():Car(TipMasina::HOT_HATCH, "Hot-hatch")
	{}
	CarHotHatch(int a):Car(TipMasina::HOT_HATCH, "Hot-hatch", a)
	{}

	~CarHotHatch()
	{
		this->type = TipMasina::INVALID;
		this->name.clear();
	}

	CarHotHatch(CarHotHatch& other)
	{
		this->type = other.type;
		this->name = other.name;
		this->price = other.price;
	}

	CarHotHatch& operator=(const CarHotHatch& other)
	{
		this->type = other.type;
		return *this;
	}

	virtual void display(ostream& out)
	{
		out << "Masina Hot-Hatch numita " << this->name <<endl;
	}
	friend istream &operator >> (istream &in, CarHotHatch& a)
	{
	    cout<<"Introdu numele: ";
	    in>>a.name;
	    a.type=TipMasina::HOT_HATCH;
	    cout<<"Introdu pretul: ";
	    in>>a.price;
	    return in;
	}
};

class CarCabrio : protected Car
{
public:
	CarCabrio():Car(TipMasina::CABRIO, "Cabrio")
	{}
	CarCabrio(int a):Car(TipMasina::CABRIO, "Cabrio", a)
	{}

	~CarCabrio()
	{
		this->type = TipMasina::INVALID;
		this->name.clear();
	}

	CarCabrio(CarCabrio& other)
	{
		this->type = other.type;
		this->name = other.name;
		this->price = other.price;
	}

	CarCabrio& operator=(const CarCabrio& other)
	{
		this->type = other.type;
		return *this;
	}

	virtual void display(ostream& out)
	{
		out << "Masina Cabrio numita " << this->name <<endl;
	}
	friend istream &operator >> (istream &in, CarCabrio& a)
	{
	    cout<<"Introdu numele: ";
	    in>>a.name;
	    a.type=TipMasina::CABRIO;
	    cout<<"Introdu pretul: ";
	    in>>a.price;
	    return in;
	}
};

class CarSupersport : protected Car
{
private:
    int sold=0;
public:
	CarSupersport():Car(TipMasina::SUPERSPORT, "Supersport")
	{sold=0;}
	CarSupersport(int a):Car(TipMasina::SUPERSPORT, "Supersport", a)
	{sold=0;}

	~CarSupersport()
	{
		this->type = TipMasina::INVALID;
		this->name.clear();
	}

	CarSupersport(const CarSupersport& other)
	{
		this->type = other.type;
		this->name = other.name;
		this->price = other.price;
	}

	CarSupersport(const string& name):Car(TipMasina::SUPERSPORT, name)
	{sold=0;}
	CarSupersport(const string& name, int a):Car(TipMasina::SUPERSPORT, name, a)
	{sold=0;}

	CarSupersport& operator=(const CarSupersport& other)
	{
		this->type = other.type;
		return *this;
	}
	void setsold(int a){sold=a;}
	int getsold(){return sold;}

	virtual void display(ostream& out)
	{
	    if(sold==0)
		out << "Nume masina " << this->name << " pret " <<this->price <<endl;
	}

	bool operator==(const CarSupersport& other)
	{
		return (this->type == other.type && this->name == other.name && this->price == other.price);
	}
	friend istream &operator >> (istream &in, CarSupersport& a)
	{
	    cout<<"Introdu numele: ";
	    in>>a.name;
	    a.type=TipMasina::SUPERSPORT;
	    cout<<"Introdu pretul: ";
	    in>>a.price;
	    return in;
	}
	int get_price(){return price;}
};


template <class CarT>
class Expozitie
{
private:
	vector<CarT> cars;

public:
	Expozitie():cars()
	{}

	~Expozitie() = default;

	Expozitie(const Expozitie<CarT>& other):cars()
	{
		swap(this->cars, other.cars);
	}

	Expozitie<CarT>& operator=(const Expozitie<CarT>& other)
	{
		this->cars = other.cars;
		return *this;
	}

	Expozitie<CarT>& operator-=(const CarT& car_inst)
	{
		for (int i = 0; i < cars.size(); ++i)
		{
			if (cars[i] == car_inst)
			{
				cars.erase(cars.begin()+i); //nu cred ca merge
				break;
			}
		}

		return *this;
	}

	Expozitie<CarT>& operator+=(const CarT& car_inst)
	{
		cars.push_back(car_inst);

		return *this;
	}

	CarT& operator[](int idx)
	{

		return cars[idx];
	}

	int GetSize() const
	{
		return cars.size();
	}

	void displayexp(std::ostream& out)
	{
		for (int i = 0; i < cars.size(); ++i)
		{
			if (&cars[i] != NULL)
            {
                out<<i<<" ";
                cars[i].display(out);
            }

		}
	}

	friend istream& operator>>(istream& in, Expozitie<CarT>& ex)
	{
	    in>>(const CarT &) ex;
		return in;
	}

	friend ostream& operator<<(ostream& out, Expozitie<CarT>& ex)
	{
		return out;
	}
	void Get_pairs(vector<pair<string,int>>& o)
	{

	    for(int i=0;i<cars.size();i++)
        {
            pair<string,int> u =cars[i].GetPair();
             o.push_back(u);
        }

	}
	void Show()
	{
	    cout << "Type: " << typeid(CarT).name() <<endl;
	}

};
template <>
class Expozitie<char*>
{
private:
	vector<CarSupersport> cars;
	vector<CarSupersport> sold_cars;

public:
	Expozitie():cars(),sold_cars()
	{}

	~Expozitie() = default;

	Expozitie(const Expozitie<char*>& other):cars(),sold_cars()
	{

		this->cars		= other.cars;
		this->sold_cars = other.sold_cars;
	}

	Expozitie<char*>& operator=(const Expozitie<char*>& other)
	{
		this->cars = other.cars;
		this->sold_cars = other.sold_cars;
	}

	Expozitie<char*>& operator-=(const CarSupersport& car_inst) //nu merge
	{ int i=0, pp;
	    vector<CarSupersport>::iterator ptr;
	    vector<CarSupersport>::iterator gtr;


		for (ptr = cars.begin() ; ptr != cars.end();i++)
		{
			if (cars[i] == car_inst)
			{
			    cout<<i<<endl;
			    gtr=ptr;
				break;
			}
			else
                ptr++;
		}
		cars.erase(std::remove(cars.begin(), cars.end(), car_inst));
		return *this;


	}
	void delete_car(int index)
	{
	    cars[index]=NULL;

	}

	Expozitie<char*>& operator+=(const CarSupersport& car_inst)
	{
		cars.push_back(car_inst);
		return *this;
	}

	CarSupersport& operator[](int idx)
	{
	    if(idx<0)
            throw runtime_error("Indexul este mai mic ca 0");

		return cars[idx];
	}

	int GetSize() const
	{
		return cars.size();
	}

	void display(ostream& out)
	{
		for (int i = 0; i < cars.size(); ++i)
		{
			if(&cars[i] != NULL && cars[i].getsold() == 0)
            {
                out<<i<<" ";
                cars[i].display(out);
            }

		}
	}
	void display_sold(ostream& out)
	{
		for (int i = 0; i < cars.size(); ++i)
		{
			if(&sold_cars[i] != NULL)
				sold_cars[i].display(out);
		}
	}
	void set_sold(int index,vector<pair<CarSupersport,int>>& o)
	{
	    if(index<0)
            throw runtime_error("Indexul este mai mic ca 0");
	    if(cars[index].getsold()==0 && index < cars.size())
        {
            pair<CarSupersport,int> x = make_pair(cars[index],cars[index].get_price());
            o.push_back(x);

        }
	    cars[index].setsold(1);
	}


	friend std::istream& operator>>(istream& is, Expozitie<char*>& expo)
	{
		return is;
	}

	friend std::ostream& operator<<(ostream& os, Expozitie<char*>& expo)
	{
		return os;
	}
};
Test1()
{
    int n=3;
   vector<pair<CarSupersport,int>> o;
   string nume;
   int pret;
   Expozitie<char*> exp;
   for(int i=0;i<n;i++)
   {
    cout<<"Introdu numele masinii: ";
    cin>>nume;
    cout<<"Introdu pretul masinii: ";
    cin>>pret;
    exp+=CarSupersport(nume,pret);
   }
   exp.display(cout);
   cout<<endl;
   for(int i=0;i<2;i++)
   {

      cout<<"Introdu numarul masinii pe care vrei sa o cumperi: ";
      int x;
      cin>>x;
      exp.set_sold(x,o);
      exp.display(cout);


   }
   cout<<"Masini vandute: ";
   cout<<o.size()<<endl;
   for(int i=0;i<o.size();i++)
        o[i].first.display(cout);
}
Test2()
{
Expozitie<Car> x;
x+=Car(TipMasina::COUPE,"Dacia",8000);
x+=Car(TipMasina::HOT_HATCH,"Porsche",80000);
x.displayexp(cout);
x.Show();
vector<pair<string,int>> s;
x.Get_pairs(s);
for(int i=0;i<s.size();i++)
    cout<<s[i].first<<"   "<<s[i].second<<endl;


}
int main()
{
    Test2();



    return 0;
}
