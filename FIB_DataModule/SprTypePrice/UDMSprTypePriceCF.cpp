#include <vcl.h>
#pragma hdrstop
#include "UDMSprTypePriceCF.h"   
#include "UDMSprTypePriceImpl.h"  
#include "IDMSprTypePrice.h"  
#pragma package(smart_init)  
extern int NumObject;  
//---------------------------------------------------------------
TDMSprTypePriceCF::TDMSprTypePriceCF()   
{    
NumRefs=0; 
++NumObject; 
} 
//---------------------------------------------------------------
TDMSprTypePriceCF::~TDMSprTypePriceCF() 
{ 
--NumObject;  
} 
//---------------------------------------------------------------
int TDMSprTypePriceCF::kanQueryInterface(REFIID id_interface, void**ppv)  
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
int TDMSprTypePriceCF::kanAddRef(void) 
{     
return (++NumRefs);    
}    
//---------------------------------------------------------------
int TDMSprTypePriceCF::kanRelease(void)  
{  
if (--NumRefs==0)   
	{  
	delete this;
	return 0;
	}    
return NumRefs;  
}  
//---------------------------------------------------------------
int TDMSprTypePriceCF::kanCreateInstance(REFIID id_interface, void ** ppv)  
{  
int result=0;  
		TDMSprTypePriceImpl * ob=new TDMSprTypePriceImpl();  
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
