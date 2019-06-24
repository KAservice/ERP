#include "vcl.h"
#pragma hdrstop  
#include "UFormaSpiskaSprDiscountCard_1CF.h"   
#include "UFormaSpiskaSprDiscountCard_1Impl.h"  
#include "IFormaSpiskaSprDiscountCard_1.h"  
#pragma package(smart_init)  
extern int NumObject;  
//---------------------------------------------------------------
TFormaSpiskaSprDiscountCard_1CF::TFormaSpiskaSprDiscountCard_1CF()   
{    
NumRefs=0; 
++NumObject; 
} 
//---------------------------------------------------------------
TFormaSpiskaSprDiscountCard_1CF::~TFormaSpiskaSprDiscountCard_1CF() 
{ 
--NumObject;  
} 
//---------------------------------------------------------------
int TFormaSpiskaSprDiscountCard_1CF::kanQueryInterface(REFIID id_interface, void**ppv)  
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
int TFormaSpiskaSprDiscountCard_1CF::kanAddRef(void) 
{     
return (++NumRefs);    
}    
//---------------------------------------------------------------
int TFormaSpiskaSprDiscountCard_1CF::kanRelease(void)  
{  
if (--NumRefs==0)   
	{  
	delete this;   
	}    
return NumRefs;  
}  
//---------------------------------------------------------------
int TFormaSpiskaSprDiscountCard_1CF::kanCreateInstance(REFIID id_interface, void ** ppv)  
{  
int result=0;  
		TFormaSpiskaSprDiscountCard_1Impl * ob=new TFormaSpiskaSprDiscountCard_1Impl();  
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
