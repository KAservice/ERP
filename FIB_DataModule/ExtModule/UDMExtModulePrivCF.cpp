#include "vcl.h"
#pragma hdrstop  
#include "UDMExtModulePrivCF.h"   
#include "UDMExtModulePrivImpl.h"  
#include "IDMExtModulePriv.h"  
#pragma package(smart_init)  
extern int NumObject;  
//---------------------------------------------------------------
TDMExtModulePrivCF::TDMExtModulePrivCF()   
{    
NumRefs=0; 
++NumObject; 
} 
//---------------------------------------------------------------
TDMExtModulePrivCF::~TDMExtModulePrivCF() 
{ 
--NumObject;  
} 
//---------------------------------------------------------------
int TDMExtModulePrivCF::kanQueryInterface(REFIID id_interface, void**ppv)  
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
int TDMExtModulePrivCF::kanAddRef(void) 
{     
return (++NumRefs);    
}    
//---------------------------------------------------------------
int TDMExtModulePrivCF::kanRelease(void)  
{  
if (--NumRefs==0)   
	{  
	delete this;   
	}    
return NumRefs;  
}  
//---------------------------------------------------------------
int TDMExtModulePrivCF::kanCreateInstance(REFIID id_interface, void ** ppv)  
{  
int result=0;  
		TDMExtModulePrivImpl * ob=new TDMExtModulePrivImpl();  
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
