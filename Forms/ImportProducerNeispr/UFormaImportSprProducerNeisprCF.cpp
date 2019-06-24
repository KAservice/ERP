#include "vcl.h"
#pragma hdrstop  
#include "UFormaImportSprProducerNeisprCF.h"   
#include "UFormaImportSprProducerNeisprImpl.h"  
#include "IFormaImportSprProducerNeispr.h"  
#pragma package(smart_init)  
extern int NumObject;  
//---------------------------------------------------------------
TFormaImportSprProducerNeisprCF::TFormaImportSprProducerNeisprCF()   
{    
NumRefs=0; 
++NumObject; 
} 
//---------------------------------------------------------------
TFormaImportSprProducerNeisprCF::~TFormaImportSprProducerNeisprCF() 
{ 
--NumObject;  
} 
//---------------------------------------------------------------
int TFormaImportSprProducerNeisprCF::kanQueryInterface(REFIID id_interface, void**ppv)  
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
int TFormaImportSprProducerNeisprCF::kanAddRef(void) 
{     
return (++NumRefs);    
}    
//---------------------------------------------------------------
int TFormaImportSprProducerNeisprCF::kanRelease(void)  
{  
if (--NumRefs==0)   
	{  
	delete this;   
	}    
return NumRefs;  
}  
//---------------------------------------------------------------
int TFormaImportSprProducerNeisprCF::kanCreateInstance(REFIID id_interface, void ** ppv)  
{  
int result=0;  
		TFormaImportSprProducerNeisprImpl * ob=new TFormaImportSprProducerNeisprImpl();  
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
