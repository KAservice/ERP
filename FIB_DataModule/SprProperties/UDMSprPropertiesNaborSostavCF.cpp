#include "vcl.h"
#pragma hdrstop  
#include "UDMSprPropertiesNaborSostavCF.h"   
#include "UDMSprPropertiesNaborSostavImpl.h"  
#include "IDMSprPropertiesNaborSostav.h"  
#pragma package(smart_init)  
extern int NumObject;  
//---------------------------------------------------------------
TDMSprPropertiesNaborSostavCF::TDMSprPropertiesNaborSostavCF()   
{    
NumRefs=0; 
++NumObject; 
} 
//---------------------------------------------------------------
TDMSprPropertiesNaborSostavCF::~TDMSprPropertiesNaborSostavCF() 
{ 
--NumObject;  
} 
//---------------------------------------------------------------
int TDMSprPropertiesNaborSostavCF::kanQueryInterface(REFIID id_interface, void**ppv)  
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
int TDMSprPropertiesNaborSostavCF::kanAddRef(void) 
{     
return (++NumRefs);    
}    
//---------------------------------------------------------------
int TDMSprPropertiesNaborSostavCF::kanRelease(void)  
{  
if (--NumRefs==0)   
	{  
	delete this;   
	}    
return NumRefs;  
}  
//---------------------------------------------------------------
int TDMSprPropertiesNaborSostavCF::kanCreateInstance(REFIID id_interface, void ** ppv)  
{  
int result=0;  
		TDMSprPropertiesNaborSostavImpl * ob=new TDMSprPropertiesNaborSostavImpl();  
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
