#include "vcl.h"
#pragma hdrstop  
#include "UDMRegVsRaschCF.h"   
#include "UDMRegVsRaschImpl.h"  
#include "IDMRegVsRasch.h"  
#pragma package(smart_init)  
extern int NumObject;  
//---------------------------------------------------------------
TDMRegVsRaschCF::TDMRegVsRaschCF()   
{    
NumRefs=0; 
++NumObject; 
} 
//---------------------------------------------------------------
TDMRegVsRaschCF::~TDMRegVsRaschCF() 
{ 
--NumObject;  
} 
//---------------------------------------------------------------
int TDMRegVsRaschCF::kanQueryInterface(REFIID id_interface, void**ppv)  
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
int TDMRegVsRaschCF::kanAddRef(void) 
{     
return (++NumRefs);    
}    
//---------------------------------------------------------------
int TDMRegVsRaschCF::kanRelease(void)  
{  
if (--NumRefs==0)   
	{  
	delete this;   
	}    
return NumRefs;  
}  
//---------------------------------------------------------------
int TDMRegVsRaschCF::kanCreateInstance(REFIID id_interface, void ** ppv)  
{  
int result=0;  
		TDMRegVsRaschImpl * ob=new TDMRegVsRaschImpl();  
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
