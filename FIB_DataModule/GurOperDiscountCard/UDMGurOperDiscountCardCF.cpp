#include "vcl.h"
#pragma hdrstop  
#include "UDMGurOperDiscountCardCF.h"   
#include "UDMGurOperDiscountCardImpl.h"  
#include "IDMGurOperDiscountCard.h"  
#pragma package(smart_init)  
extern int NumObject;  
//---------------------------------------------------------------
TDMGurOperDiscountCardCF::TDMGurOperDiscountCardCF()   
{    
NumRefs=0; 
++NumObject; 
} 
//---------------------------------------------------------------
TDMGurOperDiscountCardCF::~TDMGurOperDiscountCardCF() 
{ 
--NumObject;  
} 
//---------------------------------------------------------------
int TDMGurOperDiscountCardCF::kanQueryInterface(REFIID id_interface, void**ppv)  
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
int TDMGurOperDiscountCardCF::kanAddRef(void) 
{     
return (++NumRefs);    
}    
//---------------------------------------------------------------
int TDMGurOperDiscountCardCF::kanRelease(void)  
{  
if (--NumRefs==0)   
	{  
	delete this;   
	}    
return NumRefs;  
}  
//---------------------------------------------------------------
int TDMGurOperDiscountCardCF::kanCreateInstance(REFIID id_interface, void ** ppv)  
{  
int result=0;  
		TDMGurOperDiscountCardImpl * ob=new TDMGurOperDiscountCardImpl();  
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
