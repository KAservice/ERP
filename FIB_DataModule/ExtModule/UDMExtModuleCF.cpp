#include "vcl.h"
#pragma hdrstop  
#include "UDMExtModuleCF.h"   
#include "UDMExtModuleImpl.h"  
#include "IDMExtModule.h"  
#pragma package(smart_init)  
extern int NumObject;  
//---------------------------------------------------------------
TDMExtModuleCF::TDMExtModuleCF()   
{    
NumRefs=0; 
++NumObject; 
} 
//---------------------------------------------------------------
TDMExtModuleCF::~TDMExtModuleCF() 
{ 
--NumObject;  
} 
//---------------------------------------------------------------
int TDMExtModuleCF::kanQueryInterface(REFIID id_interface, void**ppv)  
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
int TDMExtModuleCF::kanAddRef(void) 
{     
return (++NumRefs);    
}    
//---------------------------------------------------------------
int TDMExtModuleCF::kanRelease(void)  
{  
if (--NumRefs==0)   
	{  
	delete this;   
	}    
return NumRefs;  
}  
//---------------------------------------------------------------
int TDMExtModuleCF::kanCreateInstance(REFIID id_interface, void ** ppv)  
{  
int result=0;  
		TDMExtModuleImpl * ob=new TDMExtModuleImpl();  
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
