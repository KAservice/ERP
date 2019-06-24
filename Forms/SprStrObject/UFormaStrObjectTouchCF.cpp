#include "vcl.h"
#pragma hdrstop  
#include "UFormaStrObjectTouchCF.h"   
#include "UFormaStrObjectTouchImpl.h"

#pragma package(smart_init)  
extern int NumObject;  
//---------------------------------------------------------------
TFormaStrObjectTouchCF::TFormaStrObjectTouchCF()   
{    
NumRefs=0; 
++NumObject; 
} 
//---------------------------------------------------------------
TFormaStrObjectTouchCF::~TFormaStrObjectTouchCF() 
{ 
--NumObject;  
} 
//---------------------------------------------------------------
int TFormaStrObjectTouchCF::kanQueryInterface(REFIID id_interface, void**ppv)  
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
int TFormaStrObjectTouchCF::kanAddRef(void) 
{     
return (++NumRefs);    
}    
//---------------------------------------------------------------
int TFormaStrObjectTouchCF::kanRelease(void)  
{  
if (--NumRefs==0)   
	{  
	delete this;   
	}    
return NumRefs;  
}  
//---------------------------------------------------------------
int TFormaStrObjectTouchCF::kanCreateInstance(REFIID id_interface, void ** ppv)  
{  
int result=0;  
		TFormaStrObjectTouchImpl * ob=new TFormaStrObjectTouchImpl();  
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
