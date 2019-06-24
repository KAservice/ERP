#include "vcl.h"
#pragma hdrstop  
#include "UDMSprCustomerUserCF.h"   
#include "UDMSprCustomerUserImpl.h"  
#include "IDMSprCustomerUser.h"  
#pragma package(smart_init)  
extern int NumObject;  
//---------------------------------------------------------------
TDMSprCustomerUserCF::TDMSprCustomerUserCF()   
{    
NumRefs=0; 
++NumObject; 
} 
//---------------------------------------------------------------
TDMSprCustomerUserCF::~TDMSprCustomerUserCF() 
{ 
--NumObject;  
} 
//---------------------------------------------------------------
int TDMSprCustomerUserCF::kanQueryInterface(REFIID id_interface, void**ppv)  
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
int TDMSprCustomerUserCF::kanAddRef(void) 
{     
return (++NumRefs);    
}    
//---------------------------------------------------------------
int TDMSprCustomerUserCF::kanRelease(void)  
{  
if (--NumRefs==0)   
	{  
	delete this;   
	}    
return NumRefs;  
}  
//---------------------------------------------------------------
int TDMSprCustomerUserCF::kanCreateInstance(REFIID id_interface, void ** ppv)  
{  
int result=0;  
		TDMSprCustomerUserImpl * ob=new TDMSprCustomerUserImpl();  
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
