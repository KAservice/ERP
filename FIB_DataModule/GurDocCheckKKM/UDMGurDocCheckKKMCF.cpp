#include "vcl.h"
#pragma hdrstop  
#include "UDMGurDocCheckKKMCF.h"   
#include "UDMGurDocCheckKKMImpl.h"  
#include "IDMGurDocCheckKKM.h"  
#pragma package(smart_init)  
extern int NumObject;  
//---------------------------------------------------------------
TDMGurDocCheckKKMCF::TDMGurDocCheckKKMCF()   
{    
NumRefs=0; 
++NumObject; 
} 
//---------------------------------------------------------------
TDMGurDocCheckKKMCF::~TDMGurDocCheckKKMCF() 
{ 
--NumObject;  
} 
//---------------------------------------------------------------
int TDMGurDocCheckKKMCF::kanQueryInterface(REFIID id_interface, void**ppv)  
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
int TDMGurDocCheckKKMCF::kanAddRef(void) 
{     
return (++NumRefs);    
}    
//---------------------------------------------------------------
int TDMGurDocCheckKKMCF::kanRelease(void)  
{  
if (--NumRefs==0)   
	{  
	delete this;   
	}    
return NumRefs;  
}  
//---------------------------------------------------------------
int TDMGurDocCheckKKMCF::kanCreateInstance(REFIID id_interface, void ** ppv)  
{  
int result=0;  
		TDMGurDocCheckKKMImpl * ob=new TDMGurDocCheckKKMImpl();  
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
