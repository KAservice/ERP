#include "vcl.h"
#pragma hdrstop  
#include "UREM_FormaSpiskaSprProducerModelCF.h"   
#include "UREM_FormaSpiskaSprProducerModelImpl.h"  
#include "IREM_FormaSpiskaSprProducerModel.h"  
#pragma package(smart_init)  
extern int NumObject;  
//---------------------------------------------------------------
TREM_FormaSpiskaSprProducerModelCF::TREM_FormaSpiskaSprProducerModelCF()   
{    
NumRefs=0; 
++NumObject; 
} 
//---------------------------------------------------------------
TREM_FormaSpiskaSprProducerModelCF::~TREM_FormaSpiskaSprProducerModelCF() 
{ 
--NumObject;  
} 
//---------------------------------------------------------------
int TREM_FormaSpiskaSprProducerModelCF::kanQueryInterface(REFIID id_interface, void**ppv)  
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
int TREM_FormaSpiskaSprProducerModelCF::kanAddRef(void) 
{     
return (++NumRefs);    
}    
//---------------------------------------------------------------
int TREM_FormaSpiskaSprProducerModelCF::kanRelease(void)  
{  
if (--NumRefs==0)   
	{  
	delete this;   
	}    
return NumRefs;  
}  
//---------------------------------------------------------------
int TREM_FormaSpiskaSprProducerModelCF::kanCreateInstance(REFIID id_interface, void ** ppv)  
{  
int result=0;  
		TREM_FormaSpiskaSprProducerModelImpl * ob=new TREM_FormaSpiskaSprProducerModelImpl();  
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
