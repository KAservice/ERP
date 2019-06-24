#include "vcl.h"
#pragma hdrstop  
#include "UDMStSpr1CF.h"   
#include "UDMStSpr1Impl.h"  
#include "IDMStSpr1.h"  
#pragma package(smart_init)  
extern int NumObject;  
//---------------------------------------------------------------
TDMStSpr1CF::TDMStSpr1CF()   
{    
NumRefs=0; 
++NumObject; 
} 
//---------------------------------------------------------------
TDMStSpr1CF::~TDMStSpr1CF() 
{ 
--NumObject;  
} 
//---------------------------------------------------------------
int TDMStSpr1CF::kanQueryInterface(REFIID id_interface, void**ppv)  
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
int TDMStSpr1CF::kanAddRef(void) 
{     
return (++NumRefs);    
}    
//---------------------------------------------------------------
int TDMStSpr1CF::kanRelease(void)  
{  
if (--NumRefs==0)   
	{  
	delete this;   
	}    
return NumRefs;  
}  
//---------------------------------------------------------------
int TDMStSpr1CF::kanCreateInstance(REFIID id_interface, void ** ppv)  
{  
int result=0;  
		TDMStSpr1Impl * ob=new TDMStSpr1Impl();  
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
