#include "vcl.h"
#pragma hdrstop  
#include "UFormaElementaSprNomPropertiesNaborSostavCF.h"   
#include "UFormaElementaSprNomPropertiesNaborSostavImpl.h"  
#include "IFormaElementaSprNomPropertiesNaborSostav.h"  
#pragma package(smart_init)  
extern int NumObject;  
//---------------------------------------------------------------
TFormaElementaSprNomPropertiesNaborSostavCF::TFormaElementaSprNomPropertiesNaborSostavCF()   
{    
NumRefs=0; 
++NumObject; 
} 
//---------------------------------------------------------------
TFormaElementaSprNomPropertiesNaborSostavCF::~TFormaElementaSprNomPropertiesNaborSostavCF() 
{ 
--NumObject;  
} 
//---------------------------------------------------------------
int TFormaElementaSprNomPropertiesNaborSostavCF::kanQueryInterface(REFIID id_interface, void**ppv)  
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
int TFormaElementaSprNomPropertiesNaborSostavCF::kanAddRef(void) 
{     
return (++NumRefs);    
}    
//---------------------------------------------------------------
int TFormaElementaSprNomPropertiesNaborSostavCF::kanRelease(void)  
{  
if (--NumRefs==0)   
	{  
	delete this;   
	}    
return NumRefs;  
}  
//---------------------------------------------------------------
int TFormaElementaSprNomPropertiesNaborSostavCF::kanCreateInstance(REFIID id_interface, void ** ppv)  
{  
int result=0;  
		TFormaElementaSprNomPropertiesNaborSostavImpl * ob=new TFormaElementaSprNomPropertiesNaborSostavImpl();  
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
