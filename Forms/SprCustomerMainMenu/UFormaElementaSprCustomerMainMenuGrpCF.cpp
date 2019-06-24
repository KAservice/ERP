#include "vcl.h"
#pragma hdrstop  
#include "UFormaElementaSprCustomerMainMenuGrpCF.h"   
#include "UFormaElementaSprCustomerMainMenuGrpImpl.h"  
#include "IFormaElementaSprCustomerMainMenuGrp.h"  
#pragma package(smart_init)  
extern int NumObject;  
//---------------------------------------------------------------
TFormaElementaSprCustomerMainMenuGrpCF::TFormaElementaSprCustomerMainMenuGrpCF()   
{    
NumRefs=0; 
++NumObject; 
} 
//---------------------------------------------------------------
TFormaElementaSprCustomerMainMenuGrpCF::~TFormaElementaSprCustomerMainMenuGrpCF() 
{ 
--NumObject;  
} 
//---------------------------------------------------------------
int TFormaElementaSprCustomerMainMenuGrpCF::kanQueryInterface(REFIID id_interface, void**ppv)  
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
int TFormaElementaSprCustomerMainMenuGrpCF::kanAddRef(void) 
{     
return (++NumRefs);    
}    
//---------------------------------------------------------------
int TFormaElementaSprCustomerMainMenuGrpCF::kanRelease(void)  
{  
if (--NumRefs==0)   
	{  
	delete this;   
	}    
return NumRefs;  
}  
//---------------------------------------------------------------
int TFormaElementaSprCustomerMainMenuGrpCF::kanCreateInstance(REFIID id_interface, void ** ppv)  
{  
int result=0;  
		TFormaElementaSprCustomerMainMenuGrpImpl * ob=new TFormaElementaSprCustomerMainMenuGrpImpl();  
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
