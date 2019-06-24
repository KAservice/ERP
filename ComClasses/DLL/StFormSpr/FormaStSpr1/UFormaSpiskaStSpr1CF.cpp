#include "vcl.h"
#pragma hdrstop  
#include "UFormaSpiskaStSpr1CF.h"   
#include "UFormaSpiskaStSpr1Impl.h"  
#include "IFormaSpiskaStSpr1.h"  
#pragma package(smart_init)  
extern int NumObject;  
//---------------------------------------------------------------
TFormaSpiskaStSpr1CF::TFormaSpiskaStSpr1CF()   
{    
NumRefs=0; 
++NumObject; 
} 
//---------------------------------------------------------------
TFormaSpiskaStSpr1CF::~TFormaSpiskaStSpr1CF() 
{ 
--NumObject;  
} 
//---------------------------------------------------------------
int TFormaSpiskaStSpr1CF::kanQueryInterface(REFIID id_interface, void**ppv)  
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
int TFormaSpiskaStSpr1CF::kanAddRef(void) 
{     
return (++NumRefs);    
}    
//---------------------------------------------------------------
int TFormaSpiskaStSpr1CF::kanRelease(void)  
{  
if (--NumRefs==0)   
	{  
	delete this;   
	}    
return NumRefs;  
}  
//---------------------------------------------------------------
int TFormaSpiskaStSpr1CF::kanCreateInstance(REFIID id_interface, void ** ppv)  
{  
int result=0;  
		TFormaSpiskaStSpr1Impl * ob=new TFormaSpiskaStSpr1Impl();  
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
