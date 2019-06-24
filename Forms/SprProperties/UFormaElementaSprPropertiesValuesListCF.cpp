#include "vcl.h"
#pragma hdrstop  
#include "UFormaElementaSprPropertiesValuesListCF.h"   
#include "UFormaElementaSprPropertiesValuesListImpl.h"  
#include "IFormaElementaSprPropertiesValuesList.h"  
#pragma package(smart_init)  
extern int NumObject;  
//---------------------------------------------------------------
TFormaElementaSprPropertiesValuesListCF::TFormaElementaSprPropertiesValuesListCF()   
{    
NumRefs=0; 
++NumObject; 
} 
//---------------------------------------------------------------
TFormaElementaSprPropertiesValuesListCF::~TFormaElementaSprPropertiesValuesListCF() 
{ 
--NumObject;  
} 
//---------------------------------------------------------------
int TFormaElementaSprPropertiesValuesListCF::kanQueryInterface(REFIID id_interface, void**ppv)  
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
int TFormaElementaSprPropertiesValuesListCF::kanAddRef(void) 
{     
return (++NumRefs);    
}    
//---------------------------------------------------------------
int TFormaElementaSprPropertiesValuesListCF::kanRelease(void)  
{  
if (--NumRefs==0)   
	{  
	delete this;   
	}    
return NumRefs;  
}  
//---------------------------------------------------------------
int TFormaElementaSprPropertiesValuesListCF::kanCreateInstance(REFIID id_interface, void ** ppv)  
{  
int result=0;  
		TFormaElementaSprPropertiesValuesListImpl * ob=new TFormaElementaSprPropertiesValuesListImpl();  
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
