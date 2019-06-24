#include "vcl.h"
#pragma hdrstop  
#include "UREM_FormaElementaSprModelPropertiesValueCF.h"   
#include "UREM_FormaElementaSprModelPropertiesValueImpl.h"  
#include "IREM_FormaElementaSprModelPropertiesValue.h"  
#pragma package(smart_init)  
extern int NumObject;  
//---------------------------------------------------------------
TREM_FormaElementaSprModelPropertiesValueCF::TREM_FormaElementaSprModelPropertiesValueCF()   
{    
NumRefs=0; 
++NumObject; 
} 
//---------------------------------------------------------------
TREM_FormaElementaSprModelPropertiesValueCF::~TREM_FormaElementaSprModelPropertiesValueCF() 
{ 
--NumObject;  
} 
//---------------------------------------------------------------
int TREM_FormaElementaSprModelPropertiesValueCF::kanQueryInterface(REFIID id_interface, void**ppv)  
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
int TREM_FormaElementaSprModelPropertiesValueCF::kanAddRef(void) 
{     
return (++NumRefs);    
}    
//---------------------------------------------------------------
int TREM_FormaElementaSprModelPropertiesValueCF::kanRelease(void)  
{  
if (--NumRefs==0)   
	{  
	delete this;   
	}    
return NumRefs;  
}  
//---------------------------------------------------------------
int TREM_FormaElementaSprModelPropertiesValueCF::kanCreateInstance(REFIID id_interface, void ** ppv)  
{  
int result=0;  
		TREM_FormaElementaSprModelPropertiesValueImpl * ob=new TREM_FormaElementaSprModelPropertiesValueImpl();  
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
