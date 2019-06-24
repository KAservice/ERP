#include "vcl.h"
#pragma hdrstop  
#include "UREM_DMSprModelPropertiesValueCF.h"   
#include "UREM_DMSprModelPropertiesValueImpl.h"  
#include "IREM_DMSprModelPropertiesValue.h"  
#pragma package(smart_init)  
extern int NumObject;  
//---------------------------------------------------------------
TREM_DMSprModelPropertiesValueCF::TREM_DMSprModelPropertiesValueCF()   
{    
NumRefs=0; 
++NumObject; 
} 
//---------------------------------------------------------------
TREM_DMSprModelPropertiesValueCF::~TREM_DMSprModelPropertiesValueCF() 
{ 
--NumObject;  
} 
//---------------------------------------------------------------
int TREM_DMSprModelPropertiesValueCF::kanQueryInterface(REFIID id_interface, void**ppv)  
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
int TREM_DMSprModelPropertiesValueCF::kanAddRef(void) 
{     
return (++NumRefs);    
}    
//---------------------------------------------------------------
int TREM_DMSprModelPropertiesValueCF::kanRelease(void)  
{  
if (--NumRefs==0)   
	{  
	delete this;   
	}    
return NumRefs;  
}  
//---------------------------------------------------------------
int TREM_DMSprModelPropertiesValueCF::kanCreateInstance(REFIID id_interface, void ** ppv)  
{  
int result=0;  
		TREM_DMSprModelPropertiesValueImpl * ob=new TREM_DMSprModelPropertiesValueImpl();  
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
