#include "vcl.h"
#pragma hdrstop  
#include "UDMDocCheckCF.h"   
#include "UDMDocCheckImpl.h"  
#include "IDMDocCheck.h"  
#pragma package(smart_init)  
extern int NumObject;  
//---------------------------------------------------------------
TDMDocCheckCF::TDMDocCheckCF()   
{    
NumRefs=0; 
++NumObject; 
} 
//---------------------------------------------------------------
TDMDocCheckCF::~TDMDocCheckCF() 
{ 
--NumObject;  
} 
//---------------------------------------------------------------
int TDMDocCheckCF::kanQueryInterface(REFIID id_interface, void**ppv)  
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
int TDMDocCheckCF::kanAddRef(void) 
{     
return (++NumRefs);    
}    
//---------------------------------------------------------------
int TDMDocCheckCF::kanRelease(void)  
{  
if (--NumRefs==0)   
	{  
	delete this;   
	}    
return NumRefs;  
}  
//---------------------------------------------------------------
int TDMDocCheckCF::kanCreateInstance(REFIID id_interface, void ** ppv)  
{  
int result=0;  
		TDMDocCheckImpl * ob=new TDMDocCheckImpl();  
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
