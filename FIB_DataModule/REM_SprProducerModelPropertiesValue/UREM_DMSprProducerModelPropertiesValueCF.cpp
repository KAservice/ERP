#include "vcl.h"
#pragma hdrstop  
#include "UREM_DMSprProducerModelPropertiesValueCF.h"   
#include "UREM_DMSprProducerModelPropertiesValueImpl.h"  
#include "IREM_DMSprProducerModelPropertiesValue.h"  
#pragma package(smart_init)  
extern int NumObject;  
//---------------------------------------------------------------
TREM_DMSprProducerModelPropertiesValueCF::TREM_DMSprProducerModelPropertiesValueCF()   
{    
NumRefs=0; 
++NumObject; 
} 
//---------------------------------------------------------------
TREM_DMSprProducerModelPropertiesValueCF::~TREM_DMSprProducerModelPropertiesValueCF() 
{ 
--NumObject;  
} 
//---------------------------------------------------------------
int TREM_DMSprProducerModelPropertiesValueCF::kanQueryInterface(REFIID id_interface, void**ppv)  
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
int TREM_DMSprProducerModelPropertiesValueCF::kanAddRef(void) 
{     
return (++NumRefs);    
}    
//---------------------------------------------------------------
int TREM_DMSprProducerModelPropertiesValueCF::kanRelease(void)  
{  
if (--NumRefs==0)   
	{  
	delete this;   
	}    
return NumRefs;  
}  
//---------------------------------------------------------------
int TREM_DMSprProducerModelPropertiesValueCF::kanCreateInstance(REFIID id_interface, void ** ppv)  
{  
int result=0;  
		TREM_DMSprProducerModelPropertiesValueImpl * ob=new TREM_DMSprProducerModelPropertiesValueImpl();  
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
