#include "vcl.h"
#pragma hdrstop  
#include "UFormaGurDocCheckKKM2CF.h"   
#include "UFormaGurDocCheckKKM2Impl.h"  
#include "IFormaGurDocCheckKKM2.h"  
#pragma package(smart_init)  
extern int NumObject;  
//---------------------------------------------------------------
TFormaGurDocCheckKKM2CF::TFormaGurDocCheckKKM2CF()   
{    
NumRefs=0; 
++NumObject; 
} 
//---------------------------------------------------------------
TFormaGurDocCheckKKM2CF::~TFormaGurDocCheckKKM2CF() 
{ 
--NumObject;  
} 
//---------------------------------------------------------------
int TFormaGurDocCheckKKM2CF::kanQueryInterface(REFIID id_interface, void**ppv)  
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
int TFormaGurDocCheckKKM2CF::kanAddRef(void) 
{     
return (++NumRefs);    
}    
//---------------------------------------------------------------
int TFormaGurDocCheckKKM2CF::kanRelease(void)  
{  
if (--NumRefs==0)   
	{  
	delete this;
	return 0;
	}    
return NumRefs;  
}  
//---------------------------------------------------------------
int TFormaGurDocCheckKKM2CF::kanCreateInstance(REFIID id_interface, void ** ppv)  
{  
int result=0;  
		TFormaGurDocCheckKKM2Impl * ob=new TFormaGurDocCheckKKM2Impl();  
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
