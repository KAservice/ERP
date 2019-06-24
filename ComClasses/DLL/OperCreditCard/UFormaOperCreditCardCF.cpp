#include "vcl.h"
#pragma hdrstop  
#include "UFormaOperCreditCardCF.h"   
#include "UFormaOperCreditCardImpl.h"

#pragma package(smart_init)  
extern int NumObject;  
//---------------------------------------------------------------
TFormaOperCreditCardCF::TFormaOperCreditCardCF()   
{    
NumRefs=0; 
++NumObject; 
} 
//---------------------------------------------------------------
TFormaOperCreditCardCF::~TFormaOperCreditCardCF() 
{ 
--NumObject;  
} 
//---------------------------------------------------------------
int TFormaOperCreditCardCF::kanQueryInterface(REFIID id_interface, void**ppv)  
{    
int result=0;  
if (id_interface==IID_IkanUnknown) 
	{  
	*ppv=static_cast<IkanUnknown*> (this);  
	result=-1;  
	} 
else if (id_interface==IID_IkanClassFactory) 
	{  
	*ppv=static_cast<IkanClassFactory*> (this); 
	result=-1; 
	} 
else  
	{   
	*ppv=NULL;  
	result=0;  
	return result;  
	}
kanAddRef();
return result;  
}   
//---------------------------------------------------------------
int TFormaOperCreditCardCF::kanAddRef(void) 
{     
return (++NumRefs);    
}    
//---------------------------------------------------------------
int TFormaOperCreditCardCF::kanRelease(void)  
{  
if (--NumRefs==0)   
	{  
	delete this;   
	}    
return NumRefs;  
}  
//---------------------------------------------------------------
int TFormaOperCreditCardCF::kanCreateInstance(REFIID id_interface, void ** ppv)  
{  
int result=0;  
		TFormaOperCreditCardImpl * ob=new TFormaOperCreditCardImpl();  
		if (ob->kanQueryInterface(id_interface, ppv)==-1)   
			{       
			result=-1;  
			}    
		else     
			{           
			delete ob;   
			result=0;   
			}      
return result;  
}       
//---------------------------------------------------------------
