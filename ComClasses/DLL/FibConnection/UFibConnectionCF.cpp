//---------------------------------------------------------------------------


#pragma hdrstop

#include "UFibConnectionCF.h"
#include "UDMFibConnectionImpl.h"
#include "IDMFibConnection.h"
//---------------------------------------------------------------------------

#pragma package(smart_init)
//----------------------------------------------------------------------------
TFibConnectionCF::TFibConnectionCF()
{



}
//----------------------------------------------------------------------------
TFibConnectionCF::~TFibConnectionCF()
{



}
//----------------------------------------------------------------------------

bool TFibConnectionCF::kanQueryInterface(int id_interface, void**ppv)
{
bool result=false;



return result;
}
//------------------------------------------------------------------------------
bool TFibConnectionCF::kanCreateInstance(int id_class, int id_interface, void ** ppv)
{
bool result=false;

switch (id_class)
	{
	case 1:
		{   //DMFibCnnection
				switch (id_interface)
					{
					case 1:
						{  //получаем итерфейс
						IDMFibConnection * i_dm;
						TDMFibConnectionImpl * ob=new TDMFibConnectionImpl();

						i_dm=ob;
						*ppv=i_dm;
						}break;

					}
		}break;


	default:
		{
		result=false;
		}
	}


return result;
}
//------------------------------------------------------------------------