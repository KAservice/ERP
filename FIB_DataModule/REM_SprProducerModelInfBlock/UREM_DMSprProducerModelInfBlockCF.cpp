#include "vcl.h"
#pragma hdrstop  
#include "UREM_DMSprProducerModelInfBlockCF.h"   
#include "UREM_DMSprProducerModelInfBlockImpl.h"  
#include "IREM_DMSprProducerModelInfBlock.h"  
#pragma package(smart_init)  
extern int NumObject;  
//---------------------------------------------------------------
TREM_DMSprProducerModelInfBlockCF::TREM_DMSprProducerModelInfBlockCF()   
{    
NumRefs=0; 
++NumObject; 
} 
//---------------------------------------------------------------
TREM_DMSprProducerModelInfBlockCF::~TREM_DMSprProducerModelInfBlockCF() 
{ 
--NumObject;  
} 
//---------------------------------------------------------------
int TREM_DMSprProducerModelInfBlockCF::kanQueryInterface(REFIID id_interface, void**ppv)  
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
int TREM_DMSprProducerModelInfBlockCF::kanAddRef(void) 
{     
return (++NumRefs);    
}    
//---------------------------------------------------------------
int TREM_DMSprProducerModelInfBlockCF::kanRelease(void)  
{  
if (--NumRefs==0)   
	{  
	delete this;   
	}    
return NumRefs;  
}  
//---------------------------------------------------------------
int TREM_DMSprProducerModelInfBlockCF::kanCreateInstance(REFIID id_interface, void ** ppv)  
{  
int result=0;  
		TREM_DMSprProducerModelInfBlockImpl * ob=new TREM_DMSprProducerModelInfBlockImpl();  
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
