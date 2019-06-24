#include "vcl.h"
#pragma hdrstop  
#include "UDMSprCustomerMainMenuGrpCF.h"   
#include "UDMSprCustomerMainMenuGrpImpl.h"  
#include "IDMSprCustomerMainMenuGrp.h"  
#pragma package(smart_init)  
extern int NumObject;  
//---------------------------------------------------------------
TDMSprCustomerMainMenuGrpCF::TDMSprCustomerMainMenuGrpCF()   
{    
NumRefs=0; 
++NumObject; 
} 
//---------------------------------------------------------------
TDMSprCustomerMainMenuGrpCF::~TDMSprCustomerMainMenuGrpCF() 
{ 
--NumObject;  
} 
//---------------------------------------------------------------
int TDMSprCustomerMainMenuGrpCF::kanQueryInterface(REFIID id_interface, void**ppv)  
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
int TDMSprCustomerMainMenuGrpCF::kanAddRef(void) 
{     
return (++NumRefs);    
}    
//---------------------------------------------------------------
int TDMSprCustomerMainMenuGrpCF::kanRelease(void)  
{  
if (--NumRefs==0)   
	{  
	delete this;   
	}    
return NumRefs;  
}  
//---------------------------------------------------------------
int TDMSprCustomerMainMenuGrpCF::kanCreateInstance(REFIID id_interface, void ** ppv)  
{  
int result=0;  
		TDMSprCustomerMainMenuGrpImpl * ob=new TDMSprCustomerMainMenuGrpImpl();  
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
