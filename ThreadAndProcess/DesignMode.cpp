#include "DesignMode.h"

//Product.cpp 
Product::Product()
{

}
Product::~Product()
{
}
ConcreteProduct::ConcreteProduct()
{
	cout << "ConcreteProduct...." << endl;
}
ConcreteProduct::~ConcreteProduct()
{
}


Factory::Factory()
{
}
Factory::~Factory()
{
}
ConcreteFactory::ConcreteFactory()
{
	cout << "ConcreteFactory....." << endl;
}
ConcreteFactory::~ConcreteFactory()
{
}
Product* ConcreteFactory::CreateProduct()
{
	return new ConcreteProduct();
}
