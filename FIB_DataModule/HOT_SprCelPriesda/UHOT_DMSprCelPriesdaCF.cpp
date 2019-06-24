#include "vcl.h"
#pragma hdrstop  
#include "UHOT_DMSprCelPriesdaCF.h"   
#include "UHOT_DMSprCelPriesdaImpl.h"  
#include "IHOT_DMSprCelPriesda.h"  
#pragma package(smart_init)  
extern int NumObject;  
//---------------------------------------------------------------
THOT_DMSprCelPriesdaCF::THOT_DMSprCelPriesdaCF()   
{    
NumRefs=0; 
++NumObject; 
} 
//---------------------------------------------------------------
THOT_DMSprCelPriesdaCF::~THOT_DMSprCelPriesdaCF() 
{ 
--NumObject;  
} 
//---------------------------------------------------------------
int THOT_DMSprCelPriesdaCF::kanQueryInterface(REFIID id_interface, void**ppv)  
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
int THOT_DMSprCelPriesdaCF::kanAddRef(void) 
{     
return (++NumRefs);    
}    
//---------------------------------------------------------------
int THOT_DMSprCelPriesdaCF::kanRelease(void)  
{  
if (--NumRefs==0)   
	{  
	delete this;   
	}    
return NumRefs;  
}  
//---------------------------------------------------------------
int THOT_DMSprCelPriesdaCF::kanCreateInstance(REFIID id_interface, void ** ppv)  
{  
int result=0;  
		THOT_DMSprCelPriesdaImpl * ob=new THOT_DMSprCelPriesdaImpl();  
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
