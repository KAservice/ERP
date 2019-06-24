#include "vcl.h"
#pragma hdrstop  
#include "UDMRegAdvanceCustomerCF.h"   
#include "UDMRegAdvanceCustomerImpl.h"  
#include "IDMRegAdvanceCustomer.h"  
#pragma package(smart_init)  
extern int NumObject;  
//---------------------------------------------------------------
TDMRegAdvanceCustomerCF::TDMRegAdvanceCustomerCF()   
{    
NumRefs=0; 
++NumObject; 
} 
//---------------------------------------------------------------
TDMRegAdvanceCustomerCF::~TDMRegAdvanceCustomerCF() 
{ 
--NumObject;  
} 
//---------------------------------------------------------------
int TDMRegAdvanceCustomerCF::kanQueryInterface(REFIID id_interface, void**ppv)  
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
int TDMRegAdvanceCustomerCF::kanAddRef(void) 
{     
return (++NumRefs);    
}    
//---------------------------------------------------------------
int TDMRegAdvanceCustomerCF::kanRelease(void)  
{  
if (--NumRefs==0)   
	{  
	delete this;   
	}    
return NumRefs;  
}  
//---------------------------------------------------------------
int TDMRegAdvanceCustomerCF::kanCreateInstance(REFIID id_interface, void ** ppv)  
{  
int result=0;  
		TDMRegAdvanceCustomerImpl * ob=new TDMRegAdvanceCustomerImpl();  
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
