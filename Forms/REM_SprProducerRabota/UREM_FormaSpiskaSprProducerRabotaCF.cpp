#include "vcl.h"
#pragma hdrstop  
#include "UREM_FormaSpiskaSprProducerRabotaCF.h"   
#include "UREM_FormaSpiskaSprProducerRabotaImpl.h"  
#include "IREM_FormaSpiskaSprProducerRabota.h"  
#pragma package(smart_init)  
extern int NumObject;  
//---------------------------------------------------------------
TREM_FormaSpiskaSprProducerRabotaCF::TREM_FormaSpiskaSprProducerRabotaCF()   
{    
NumRefs=0; 
++NumObject; 
} 
//---------------------------------------------------------------
TREM_FormaSpiskaSprProducerRabotaCF::~TREM_FormaSpiskaSprProducerRabotaCF() 
{ 
--NumObject;  
} 
//---------------------------------------------------------------
int TREM_FormaSpiskaSprProducerRabotaCF::kanQueryInterface(REFIID id_interface, void**ppv)  
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
int TREM_FormaSpiskaSprProducerRabotaCF::kanAddRef(void) 
{     
return (++NumRefs);    
}    
//---------------------------------------------------------------
int TREM_FormaSpiskaSprProducerRabotaCF::kanRelease(void)  
{  
if (--NumRefs==0)   
	{  
	delete this;   
	}    
return NumRefs;  
}  
//---------------------------------------------------------------
int TREM_FormaSpiskaSprProducerRabotaCF::kanCreateInstance(REFIID id_interface, void ** ppv)  
{  
int result=0;  
		TREM_FormaSpiskaSprProducerRabotaImpl * ob=new TREM_FormaSpiskaSprProducerRabotaImpl();  
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
