#include "vcl.h"
#pragma hdrstop  
#include "UDMSprStorageLocationCF.h"   
#include "UDMSprStorageLocationImpl.h"  
#include "IDMSprStorageLocation.h"  
#pragma package(smart_init)  
extern int NumObject;  
//---------------------------------------------------------------
TDMSprStorageLocationCF::TDMSprStorageLocationCF()   
{    
NumRefs=0; 
++NumObject; 
} 
//---------------------------------------------------------------
TDMSprStorageLocationCF::~TDMSprStorageLocationCF() 
{ 
--NumObject;  
} 
//---------------------------------------------------------------
int TDMSprStorageLocationCF::kanQueryInterface(REFIID id_interface, void**ppv)  
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
int TDMSprStorageLocationCF::kanAddRef(void) 
{     
return (++NumRefs);    
}    
//---------------------------------------------------------------
int TDMSprStorageLocationCF::kanRelease(void)  
{  
if (--NumRefs==0)   
	{  
	delete this;   
	}    
return NumRefs;  
}  
//---------------------------------------------------------------
int TDMSprStorageLocationCF::kanCreateInstance(REFIID id_interface, void ** ppv)  
{  
int result=0;  
		TDMSprStorageLocationImpl * ob=new TDMSprStorageLocationImpl();  
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
