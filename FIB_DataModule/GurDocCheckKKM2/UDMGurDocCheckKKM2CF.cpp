#include "vcl.h"
#pragma hdrstop  
#include "UDMGurDocCheckKKM2CF.h"   
#include "UDMGurDocCheckKKM2Impl.h"  
#include "IDMGurDocCheckKKM2.h"  
#pragma package(smart_init)  
extern int NumObject;  
//---------------------------------------------------------------
TDMGurDocCheckKKM2CF::TDMGurDocCheckKKM2CF()   
{    
NumRefs=0; 
++NumObject; 
} 
//---------------------------------------------------------------
TDMGurDocCheckKKM2CF::~TDMGurDocCheckKKM2CF() 
{ 
--NumObject;  
} 
//---------------------------------------------------------------
int TDMGurDocCheckKKM2CF::kanQueryInterface(REFIID id_interface, void**ppv)  
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
int TDMGurDocCheckKKM2CF::kanAddRef(void) 
{     
return (++NumRefs);    
}    
//---------------------------------------------------------------
int TDMGurDocCheckKKM2CF::kanRelease(void)  
{  
if (--NumRefs==0)   
	{  
	delete this;   
	}    
return NumRefs;  
}  
//---------------------------------------------------------------
int TDMGurDocCheckKKM2CF::kanCreateInstance(REFIID id_interface, void ** ppv)  
{  
int result=0;  
		TDMGurDocCheckKKM2Impl * ob=new TDMGurDocCheckKKM2Impl();  
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
